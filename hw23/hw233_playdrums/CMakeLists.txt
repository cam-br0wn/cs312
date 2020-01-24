cmake_minimum_required(VERSION 2.8)
set(APPNAME "playDrums")
project(${APPNAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall ")
set(SOURCE_FILES
  hw222_CMidiPacket.cpp
	hw233_main.cpp
	hw233_playdrums.cpp)
add_executable(${APPNAME} ${SOURCE_FILES})
