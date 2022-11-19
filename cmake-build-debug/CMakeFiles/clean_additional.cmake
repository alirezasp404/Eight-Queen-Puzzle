# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "8_Queen_autogen"
  "CMakeFiles\\8_Queen_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\8_Queen_autogen.dir\\ParseCache.txt"
  )
endif()
