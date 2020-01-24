cmake_minimum_required(VERSION 2.8)
set(APPNAME "scifiSounds")
project(${APPNAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall ")
set(SOURCE_FILES
  hw222_CMidiPacket.cpp
  hw234_main.cpp
  hw234_scifiSounds.cpp)
add_executable(${APPNAME} ${SOURCE_FILES})