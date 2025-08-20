# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\snakeGame_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\snakeGame_autogen.dir\\ParseCache.txt"
  "snakeGame_autogen"
  )
endif()
