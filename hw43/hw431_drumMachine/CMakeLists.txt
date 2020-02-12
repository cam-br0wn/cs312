cmake_minimum_required(VERSION 3.5)
set(APPNAME "drum_machine")
project(${APPNAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall ")

set(FOR_CLASS 1)
if(${FOR_CLASS})
  set( HOME "/Volumes/COURSES/cs312-00-w20/StuWork/brownc2" )
elseif(NOT ${FOR_CLASS})
  set( HOME "/Users/je/cs312/_cs312")
endif(${FOR_CLASS})
set(COMMON "${HOME}/common")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall ")
set(SOURCE_FILES
   ${COMMON}/hw332_CMidiPacket.cpp
   ${COMMON}/hw423_CMidiTrack.cpp
   ${COMMON}/hw421_CDelayMs.cpp
   ${COMMON}/hw422_CAppleMidiSynth.cpp
   hw431_CDrumMachine.cpp
   hw431_CDrumTrack.cpp
   hw431_main.cpp
)

include_directories(${COMMON})
add_executable(${APPNAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE "-framework CoreServices")
target_link_libraries(${PROJECT_NAME} PRIVATE  "-framework AudioUnit")
target_link_libraries(${PROJECT_NAME} PRIVATE  "-framework AudioToolbox")