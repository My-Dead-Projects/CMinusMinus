cmake_minimum_required(VERSION 3.9)
project(CMinusMinus)

set(CMAKE_CXX_STANDARD 14)

add_executable(CMinusMinus main.cpp FileUtils.cpp FileUtils.h StringUtils.h StringUtils.cpp Symbol.cpp Symbol.h)

configure_file(${CMAKE_SOURCE_DIR}/main.cmm ${CMAKE_BINARY_DIR}/main.cmm COPYONLY)
