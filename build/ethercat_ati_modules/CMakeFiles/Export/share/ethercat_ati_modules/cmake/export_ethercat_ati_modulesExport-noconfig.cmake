#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "ethercat_ati_modules::ethercat_ati_modules" for configuration ""
set_property(TARGET ethercat_ati_modules::ethercat_ati_modules APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(ethercat_ati_modules::ethercat_ati_modules PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libethercat_ati_modules.so"
  IMPORTED_SONAME_NOCONFIG "libethercat_ati_modules.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS ethercat_ati_modules::ethercat_ati_modules )
list(APPEND _IMPORT_CHECK_FILES_FOR_ethercat_ati_modules::ethercat_ati_modules "${_IMPORT_PREFIX}/lib/libethercat_ati_modules.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
