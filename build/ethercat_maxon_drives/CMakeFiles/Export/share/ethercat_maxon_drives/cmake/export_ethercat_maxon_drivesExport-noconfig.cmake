#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "ethercat_maxon_drives::ethercat_maxon_drives" for configuration ""
set_property(TARGET ethercat_maxon_drives::ethercat_maxon_drives APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(ethercat_maxon_drives::ethercat_maxon_drives PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libethercat_maxon_drives.so"
  IMPORTED_SONAME_NOCONFIG "libethercat_maxon_drives.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS ethercat_maxon_drives::ethercat_maxon_drives )
list(APPEND _IMPORT_CHECK_FILES_FOR_ethercat_maxon_drives::ethercat_maxon_drives "${_IMPORT_PREFIX}/lib/libethercat_maxon_drives.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
