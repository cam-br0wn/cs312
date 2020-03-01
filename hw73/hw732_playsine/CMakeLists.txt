cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME hw732_playsine)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Like RtMidi, RtAudio needs this compiler define  -D__MACOSX_CORE__
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -D__MACOSX_CORE__")

# Change this path to your common folder
set(COMMON "/Volumes/COURSES/cs312-00-w20/StuWork/stritzelm/common")
set(LSF "${COMMON}/libsndfile")
set(ULL "/usr/local/lib")
set (RTA "{COMMON}/RtAudio")

set(SOURCE_FILES
  ${LSF}/sndfile.hh
  ${COMMON}/RtAudio/RtAudio.cpp
  ${PROJECT_NAME}.cpp
  )

add_executable( ${PROJECT_NAME} ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE ${COMMON} ${LSF} ${RTA})

target_link_libraries(${PROJECT_NAME}
    ${ULL}/libsndfile.1.dylib
    ${ULL}/librtaudio.6.1.0.dylib
    "-framework CoreAudio"
    "-framework CoreFoundation")
