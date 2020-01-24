cmake_minimum_required(VERSION 2.8)
set(APPNAME "testCMP22")
project(${APPNAME})

# edit next line
set(HOME "/Volumes/COURSES/cs312-00-w20/StuWork/brownc2/cs312/cs312-00-w20/")
set(COMMON "${HOME}/common")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall ")
set(SOURCE_FILES
    ${COMMON}/hw222_CMidiPacket.cpp
     hw231_testCMP22.cpp
   )

include_directories(${COMMON})
add_executable(${APPNAME} ${SOURCE_FILES})