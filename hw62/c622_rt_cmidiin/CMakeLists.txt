cmake_minimum_required(VERSION 3.5)
set(APPNAME "cmidiin")
project("{$APPNAME}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -D __MACOSX_CORE__ ")

### set for your path
set( HOME "/Volumes/cs312-00-w20/StuWork/brownc2" )

set(COMMON "${HOME}/common")
set(RTM "${COMMON}/RtMidi")
set(SOURCE_FILES
    ${RTM}/RtMidi.cpp
    c622_rt_cmidiin.cpp
)

include_directories(${COMMON} ${RTM} )
add_executable(${APPNAME} ${SOURCE_FILES})

# target_link_libraries must come after add_executable
target_link_libraries(${APPNAME} "-framework CoreMIDI")
target_link_libraries(${APPNAME} "-framework CoreAudio")
target_link_libraries(${APPNAME} "-framework CoreFoundation")