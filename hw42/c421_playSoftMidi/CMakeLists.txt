cmake_minimum_required(VERSION 2.8)
set(APPNAME "c421_playMIDI")
project(${APPNAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall ")

set(SOURCE_FILES
  c421_playSoftMidi.cpp
)

add_executable(${APPNAME} ${SOURCE_FILES})

# add framework libraries to your project.
target_link_libraries(${PROJECT_NAME} PRIVATE "-framework CoreServices")
target_link_libraries(${PROJECT_NAME} PRIVATE  "-framework AudioUnit")
target_link_libraries(${PROJECT_NAME} PRIVATE  "-framework AudioToolbox")