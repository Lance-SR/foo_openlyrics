#include "stdafx.h"

#include "logging.h"
#include "lyric_data.h"
#include "lyric_search.h"
#include "parsers.h"
#include "sources/lyric_source.h"
#include "winstr_util.h"

static void ensure_windows_newlines(std::string& str)
{
    int replace_count = 0;
    size_t prev_index = 0;
    while(true)
    {
        size_t next_index = str.find('\n', prev_index);
        if(next_index == pfc::infinite_size)
        {
            break;
        }

        if((next_index == 0) || (str[next_index-1] != '\r'))
        {
            char cr = '\r';
            str.insert(next_index, 1, cr);
            replace_count++;
        }

        prev_index = next_index+1;
    }
}

static void internal_search_for_lyrics(LyricUpdateHandle* handle)
{
    LOG_INFO("Searching for lyrics...");

    // TODO: Return a progress percentage while searching, and show "Searching: 63%" along with a visual progress bar
    LyricSourceBase* success_source = nullptr;
    LyricDataRaw lyric_data_raw = {};
    for(GUID source_id : preferences::searching::active_sources())
    {
        LyricSourceBase* source = LyricSourceBase::get(source_id);
        assert(source != nullptr);

        try
        {
            lyric_data_raw = source->query(handle->get_track(), handle->get_checked_abort());
            if(!lyric_data_raw.text.empty())
            {
                success_source = source;
                LOG_INFO("Successfully retrieved lyrics from source: %s", tchar_to_string(source->friendly_name()).c_str());
                break;
            }
        }
        catch(const std::exception& e)
        {
            LOG_ERROR("Error while searching %s: %s", tchar_to_string(source->friendly_name()).c_str(), e.what());
        }
        catch(...)
        {
            std::string source_name = tchar_to_string(source->friendly_name());
            LOG_ERROR("Error of unrecognised type while searching %s", source_name.c_str());
        }

        std::string source_name = tchar_to_string(source->friendly_name());
        LOG_INFO("Failed to retrieve lyrics from source: %s", source_name.c_str());
    }
    ensure_windows_newlines(lyric_data_raw.text);

    LOG_INFO("Parsing lyrics text...");
    LyricData lyric_data = parsers::lrc::parse(lyric_data_raw);

    handle->set_result(std::move(lyric_data), true);
    LOG_INFO("Lyric loading complete");
}

void search_for_lyrics(LyricUpdateHandle* handle)
{
    fb2k::splitTask([handle](){
        internal_search_for_lyrics(handle);
    });
}


LyricUpdateHandle::LyricUpdateHandle(metadb_handle_ptr track) :
    m_track(track),
    m_mutex({}),
    m_lyrics(),
    m_abort(),
    m_complete(nullptr),
    m_status(Status::Running)
{
    InitializeCriticalSection(&m_mutex);
    m_complete = CreateEvent(nullptr, TRUE, FALSE, nullptr);
    assert(m_complete != nullptr);
}

LyricUpdateHandle::~LyricUpdateHandle()
{
    if(!m_abort.is_aborting())
    {
        m_abort.abort();
    }

    DWORD wait_result = WaitForSingleObject(m_complete, 30'000);
    if(wait_result != WAIT_OBJECT_0)
    {
        LOG_ERROR("Lyric search did not complete successfully during cleanup: %d", wait_result);
    }
    CloseHandle(m_complete);
    DeleteCriticalSection(&m_mutex);
}

bool LyricUpdateHandle::is_complete()
{
    EnterCriticalSection(&m_mutex);
    bool complete = ((m_status == Status::Complete) || (m_status == Status::Closed));
    LeaveCriticalSection(&m_mutex);
    return complete;
}

bool LyricUpdateHandle::has_result()
{
    EnterCriticalSection(&m_mutex);
    bool complete = ((m_status == Status::ResultAvailable) || (m_status == Status::Complete));
    LeaveCriticalSection(&m_mutex);
    return complete;
}

LyricData LyricUpdateHandle::get_result()
{
    assert(has_result());
    EnterCriticalSection(&m_mutex);
    LyricData result = std::move(m_lyrics);
    if(m_status == Status::ResultAvailable)
    {
        m_status = Status::Running;
    }
    else
    {
        m_status = Status::Closed;
    }
    LeaveCriticalSection(&m_mutex);
    return result;
}

abort_callback& LyricUpdateHandle::get_checked_abort()
{
    m_abort.check();
    return m_abort;
}

metadb_handle_ptr LyricUpdateHandle::get_track()
{
    return m_track;
}

void LyricUpdateHandle::set_result(LyricData&& data, bool final_result)
{
    EnterCriticalSection(&m_mutex);
    assert(m_status == Status::Running);
    m_lyrics = std::move(data);

    if(final_result)
    {
        m_status = Status::Complete;
        BOOL complete_success = SetEvent(m_complete);
        assert(complete_success);
    }
    else
    {
        m_status = Status::ResultAvailable;
    }

    LeaveCriticalSection(&m_mutex);
}

