#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "ethercat_generic_slave::ethercat_generic_slave" for configuration ""
set_property(TARGET ethercat_generic_slave::ethercat_generic_slave APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(ethercat_generic_slave::ethercat_generic_slave PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libethercat_generic_slave.so"
  IMPORTED_SONAME_NOCONFIG "libethercat_generic_slave.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS ethercat_generic_slave::ethercat_generic_slave )
list(APPEND _IMPORT_CHECK_FILES_FOR_ethercat_generic_slave::ethercat_generic_slave "${_IMPORT_PREFIX}/lib/libethercat_generic_slave.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
