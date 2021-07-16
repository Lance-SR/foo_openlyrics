#include "stdafx.h"

#define OPENLYRICS_VERSION "0.8-dev"

// Declaration of your component's version information
// Since foobar2000 v1.0 having at least one of these in your DLL is mandatory to let the troubleshooter tell different versions of your component apart.
// Note that it is possible to declare multiple components within one DLL, but it's strongly recommended to keep only one declaration per DLL.
// As for 1.1, the version numbers are used by the component update finder to find updates; for that to work, you must have ONLY ONE declaration per DLL. If there are multiple declarations, the component is assumed to be outdated and a version number of "0" is assumed, to overwrite the component with whatever is currently on the site assuming that it comes with proper version numbers.
DECLARE_COMPONENT_VERSION(
    "OpenLyrics",
    OPENLYRICS_VERSION,
    "foo_openlyrics " OPENLYRICS_VERSION "\n"
    "Open-source lyrics retrieval and display\n"
    "Source available at https://github.com/jacquesh/foo_openlyrics\n"
    "\n"
    "Changelog:\n"
    "Version 0.8-dev (" __DATE__ "):\n"
    "- Add a source for Musixmatch\n"
    "- Add an auto-edit to fix HTML-encoded characters (e.g &gt; to >)\n"
    "Version 0.7 (2021-07-04):\n"
    "- Add a source for QQ Music\n"
    "- Add a source for darklyrics.com\n"
    "- Add an auto-edit for removing duplicate blank lines\n"
    "- Open the lyric editor when the panel is double-clicked\n"
    "- Auto-trim leading & trailing whitespace in lyrics from online sources\n"
    "- Rename the 'Save to file' option to 'Save to text file' for clarity\n"
    "- Fix parsing LRC-tag-like lines as tags when in the middle of the text\n"
    "- Fix the editor's keyboard focus not starting on the actual text\n"
    "\n"
    "Version 0.6 (2021-05-23):\n"
    "- Add a context menu option to view saved lyrics for a track at any time\n"
    "- Add support for horizontal lyrics scrolling\n"
    "- Add a context menu with some very basic lyric 'auto-edits'\n"
    "- Add an option to exclude trailing brackets in titles when searching\n"
    "- Add support for the LRC 'offset' tag in timestamped lyrics\n"
    "- Add the ability to remove an 'offset' tag, updating timestamps instead\n"
    "- Add the ability to sync a line by adding/modifying an 'offset' tag\n"
    "- Change 'Open file location' button to disabled when there are no lyrics\n"
    "- Disable editor playback controls when not playing the edited track\n"
    "- Select the current line when opening the editor with synced lyrics\n"
    "- Trim surrounding whitespace from track metadata for internet searches\n"
    "- Fix the panel not updating when it should if playback is paused\n"
    "- Fix a degradation in scroll smoothness introduced in v0.5\n"
    "- Fix a potential crash when closing fb2k while the editor is open\n"
    "- Fix the editor pause/play button showing the wrong state during playback\n"
    "\n"
    "Version 0.5 (2021-04-25):\n"
    "- Add support for ColumnsUI\n"
    "- Add a preferences page for the font & colours used for the panel\n"
    "- Add a preferences page with configuration for lyric saving\n"
    "- Add the option to only auto-save synced lyrics\n"
    "- Add support for smoothly scrolling between lines of synced lyrics\n"
    "- Add wrapping for lines that do not fit into the available space\n"
    "- Change search to check the save location even if not configured to do so\n"
    "- Change save to not overwrite existing tags/files when auto-saving\n"
    "- Fix the source list selection clearing when an item is (de)activated\n"
    "- Fix the editor sometimes adding an extra blank line above the lyrics\n"
    "- Fix the panel continuing to show lyrics after playback stops\n"
    "- Fix failing to show lyrics if the panel is created during playback\n"
    "- Remove the option to not save any lyrics at all\n"
    "\n"
    "Version 0.4 (2021-04-11):\n"
    "- Add support for saving lyrics to ID3 tags\n"
    "- Add support for configuring which ID3 tags are searched or saved to\n"
    "- Add status-bar descriptions for lyric panel context menu entries\n"
    "- Add an line showing which source is currently being searched\n"
    "- Change lyric loading to not auto-reload whenever any lyrics file changes\n"
    "- Fix the release process producing incompatible *.fb2k-component archives\n"
    "- Fix config reset resetting to the last-saved value rather than the default\n"
    "- Fix a save format preview format error when playback is stopped\n"
    "- Some internal restructuring to better support future features\n"
    "\n"
    "Version 0.3 (2021-03-25):\n"
    "- Add built-in support for synchronising lines in the lyric editor\n"
    "- Add support for reading (unsynchronised) lyrics from ID3 tags\n"
    "\n"
    "Version 0.2 (2021-02-20):\n"
    "- Add support for LRC files with timestamps of the form [00.00.000]\n"
    "- Fix fallback to loading lyrics as plain text when LRC parsing fails\n"
    "- Fix saving lyrics for a track that has not yet saved any\n"
    "\n"
    "Version 0.1 (2021-01-23):\n"
    "- Initial release\n"
);


// This will prevent users from renaming your component around (important for proper troubleshooter behaviors) or loading multiple instances of it.
VALIDATE_COMPONENT_FILENAME("foo_openlyrics.dll");
