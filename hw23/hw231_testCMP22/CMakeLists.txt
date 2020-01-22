cmake_minimum_required(VERSION 2.8)
set(APPNAME "testCMP22")
project(${APPNAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall ")
set(SOURCE_FILES
  hw231_testCMP22.cpp)
add_executable(${APPNAME} ${SOURCE_FILES})