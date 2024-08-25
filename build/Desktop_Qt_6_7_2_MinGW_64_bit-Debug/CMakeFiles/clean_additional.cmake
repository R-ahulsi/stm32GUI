# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\PerformanceMonitor_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\PerformanceMonitor_autogen.dir\\ParseCache.txt"
  "PerformanceMonitor_autogen"
  )
endif()
