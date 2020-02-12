cmake_minimum_required(VERSION 3.5)
set(APP_NAME "blues51")
project(${APP_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall ")

# change this to  your $HOME directory
# set(HOME "/Users/je/cs312/_cs312")
set(HOME "/Volumes/COURSES/cs312-00-w20/StuWork/brownc2")
set(COMMON "${HOME}/common")
set(SOURCE_FILES
    ${COMMON}/hw332_CMidiPacket.cpp
    ${COMMON}/hw423_CMidiTrack.cpp
    ${COMMON}/hw411_rand_int.cpp
    ${COMMON}/hw421_CDelayMs.cpp
    ${COMMON}/hw422_CAppleMidiSynth.cpp
    ${COMMON}/hw511_CInstrument.cpp
    hw511_CBluesMelodyTrack.cpp
    hw511_CBluesBassTrack.cpp
    hw511_CBluesPianoTrack.cpp
    hw431_CDrumMachine.cpp
    hw431_CDrumTrack.cpp
    hw511_main.cpp
    c513_CMarkovBlues.cpp
)

include_directories(${COMMON})
add_executable(${APP_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE "-framework AudioToolbox")
target_link_libraries(${PROJECT_NAME} PRIVATE "-framework CoreMIDI")
target_link_libraries(${PROJECT_NAME} PRIVATE  "-framework CoreAudio")