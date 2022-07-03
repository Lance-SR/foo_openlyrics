# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


set(CPACK_BUILD_SOURCE_DIRS "B:/Work/Experiments/foo_openlyrics/3rdparty/tidy-html5-5.8.0;B:/Work/Experiments/foo_openlyrics/3rdparty/tidy-html5-5.8.0/cmakebuilddir")
set(CPACK_CMAKE_GENERATOR "Visual Studio 17 2022")
set(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
set(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
set(CPACK_DEBIAN_PACKAGE_HOMEPAGE "http://www.html-tidy.org")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "maintainer@htacg.org")
set(CPACK_DEBIAN_PACKAGE_SECTION "Libraries")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_FILE "C:/Program Files/CMake/share/cmake-3.21/Templates/CPack.GenericDescription.txt")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_SUMMARY "tidy built using CMake")
set(CPACK_GENERATOR "NSIS;WIX;ZIP")
set(CPACK_INSTALL_CMAKE_PROJECTS "B:/Work/Experiments/foo_openlyrics/3rdparty/tidy-html5-5.8.0/cmakebuilddir;tidy;ALL;/")
set(CPACK_INSTALL_PREFIX "C:/Program Files (x86)/tidy")
set(CPACK_MODULE_PATH "")
set(CPACK_NSIS_DISPLAY_NAME "tidy 5.8.0")
set(CPACK_NSIS_INSTALLER_ICON_CODE "")
set(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES")
set(CPACK_NSIS_PACKAGE_NAME "tidy 5.8.0")
set(CPACK_NSIS_UNINSTALL_NAME "Uninstall")
set(CPACK_OUTPUT_CONFIG_FILE "B:/Work/Experiments/foo_openlyrics/3rdparty/tidy-html5-5.8.0/cmakebuilddir/CPackConfig.cmake")
set(CPACK_PACKAGE_CONTACT "maintainer@htacg.org")
set(CPACK_PACKAGE_DEFAULT_LOCATION "/")
set(CPACK_PACKAGE_DESCRIPTION_FILE "B:/Work/Experiments/foo_openlyrics/3rdparty/tidy-html5-5.8.0/README/README.html")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "tidy - HTML syntax checker")
set(CPACK_PACKAGE_FILE_NAME "tidy-5.8.0-win32")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "tidy 5.8.0")
set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "tidy 5.8.0")
set(CPACK_PACKAGE_NAME "tidy")
set(CPACK_PACKAGE_RELOCATABLE "true")
set(CPACK_PACKAGE_VENDOR "HTML Tidy Advocacy Community Group")
set(CPACK_PACKAGE_VERSION "5.8.0")
set(CPACK_PACKAGE_VERSION_MAJOR "5")
set(CPACK_PACKAGE_VERSION_MINOR "8")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_RESOURCE_FILE_LICENSE "B:/Work/Experiments/foo_openlyrics/3rdparty/tidy-html5-5.8.0/README/LICENSE.txt")
set(CPACK_RESOURCE_FILE_README "B:/Work/Experiments/foo_openlyrics/3rdparty/tidy-html5-5.8.0/README/README.html")
set(CPACK_RESOURCE_FILE_WELCOME "B:/Work/Experiments/foo_openlyrics/3rdparty/tidy-html5-5.8.0/README/README.html")
set(CPACK_RPM_EXCLUDE_FROM_AUTO_FILELIST_ADDITION "/usr/share/man;/usr/share/man/man1")
set(CPACK_SET_DESTDIR "OFF")
set(CPACK_SOURCE_GENERATOR "ZIP")
set(CPACK_SOURCE_IGNORE_FILES "B:/Work/Experiments/foo_openlyrics/3rdparty/tidy-html5-5.8.0/test/;B:/Work/Experiments/foo_openlyrics/3rdparty/tidy-html5-5.8.0/build/;B:/Work/Experiments/foo_openlyrics/3rdparty/tidy-html5-5.8.0/.git/")
set(CPACK_SOURCE_OUTPUT_CONFIG_FILE "B:/Work/Experiments/foo_openlyrics/3rdparty/tidy-html5-5.8.0/cmakebuilddir/CPackSourceConfig.cmake")
set(CPACK_SYSTEM_NAME "win32")
set(CPACK_THREADS "1")
set(CPACK_TOPLEVEL_TAG "win32")
set(CPACK_WIX_SIZEOF_VOID_P "4")
set(CPACK_WIX_UPGRADE_GUID "D809598A-B513-4752-B268-0BAC403B00E4")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "B:/Work/Experiments/foo_openlyrics/3rdparty/tidy-html5-5.8.0/cmakebuilddir/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()
