cmake_minimum_required(VERSION 2.8)
set(APPNAME cmp22)
project(${APPNAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")
set(
  SOURCE_FILES
  hw222_CMidiPacket.cpp
  hw222_test_CMidiPacket.cpp
  hw222_main.cpp
  )
add_executable(${APPNAME} ${SOURCE_FILES})

