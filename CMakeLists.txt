cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)
project(breakout)

add_executable(breakout
  src/main.cpp
  src/ball.cpp
  src/paddle.cpp
  src/brick.cpp
  src/particle.cpp
  include/ball.h
  include/graphics.h
  include/utils.h
  include/paddle.h
  include/brick.h
  include/particle.h
)

find_library(SDL2_LIB
  NAMES SDL2.lib
  HINTS ENV{CMAKE_PREFIX_PATH}
  PATH_SUFFIXES SDL2-2.0.14/lib/x64
)
find_library(SDL2MAIN_LIB
  NAMES SDL2main.lib
  HINTS ENV{CMAKE_PREFIX_PATH}
  PATH_SUFFIXES SDL2-2.0.14/lib/x64
)

find_path(SDL2_INCLUDE_DIR
  NAMES SDL.h
  HINTS ENV{CMAKE_PREFIX_PATH}
  PATH_SUFFIXES SDL2-2.0.14/include
)

include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(breakout ${SDL2_LIB} ${SDL2MAIN_LIB})
