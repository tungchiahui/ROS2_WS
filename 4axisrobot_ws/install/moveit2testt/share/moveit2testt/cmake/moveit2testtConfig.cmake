# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_moveit2testt_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED moveit2testt_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(moveit2testt_FOUND FALSE)
  elseif(NOT moveit2testt_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(moveit2testt_FOUND FALSE)
  endif()
  return()
endif()
set(_moveit2testt_CONFIG_INCLUDED TRUE)

# output package information
if(NOT moveit2testt_FIND_QUIETLY)
  message(STATUS "Found moveit2testt: 0.3.0 (${moveit2testt_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'moveit2testt' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${moveit2testt_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(moveit2testt_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${moveit2testt_DIR}/${_extra}")
endforeach()
