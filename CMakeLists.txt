cmake_minimum_required(VERSION 2.6)
project(wfn_tex)

set(CMAKE_CXX_FLAGS "-std=c++17 -g ${CMAKE_CXX_FLAGS}")
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

set(HEADERS
  src/animation.hpp
  src/texture.hpp
  src/loader.hpp

  src/stb_image.h
)

set(SOURCES
  src/loader.cpp
)

add_library(wfn_tex ${SOURCES} ${HEADERS})
