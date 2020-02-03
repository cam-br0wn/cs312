cmake_minimum_required(VERSION 3.5)
set(APPNAME "hw414_CMeasuresBeatTrack")
project(${APPNAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall ")

# JE sets FOR_CLASS to 0
# YOU set FOR_CLASS to 1
set(FOR_CLASS 1)
if(${FOR_CLASS})
  set( HOME "/Volumes/COURSES/cs312-00-w20/StuWork/brownc2" )
elseif(NOT ${FOR_CLASS})
  set( HOME "/Users/je/cs312/_cs312")
endif(${FOR_CLASS})
set(COMMON "${HOME}/common")

set(SOURCES_FILES
  ${COMMON}/hw332_CMidiPacket.cpp
  ${COMMON}/hw411_rand_int.cpp
  ${COMMON}/hw332_CMidiPacket.cpp
  ${COMMON}/hw411_rand_int.cpp
  ${COMMON}/hw413_CMidiTrack.cpp
  hw414_main.cpp
  hw414_CMeasuresBeatTrack.cpp
)

include_directories(${COMMON})
add_executable(${APPNAME} ${SOURCES_FILES})