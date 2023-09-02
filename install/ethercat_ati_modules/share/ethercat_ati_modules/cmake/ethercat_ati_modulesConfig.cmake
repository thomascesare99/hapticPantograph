# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_ethercat_ati_modules_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED ethercat_ati_modules_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(ethercat_ati_modules_FOUND FALSE)
  elseif(NOT ethercat_ati_modules_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(ethercat_ati_modules_FOUND FALSE)
  endif()
  return()
endif()
set(_ethercat_ati_modules_CONFIG_INCLUDED TRUE)

# output package information
if(NOT ethercat_ati_modules_FIND_QUIETLY)
  message(STATUS "Found ethercat_ati_modules: 1.2.0 (${ethercat_ati_modules_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'ethercat_ati_modules' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${ethercat_ati_modules_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(ethercat_ati_modules_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "ament_cmake_export_include_directories-extras.cmake;ament_cmake_export_libraries-extras.cmake;ament_cmake_export_targets-extras.cmake")
foreach(_extra ${_extras})
  include("${ethercat_ati_modules_DIR}/${_extra}")
endforeach()