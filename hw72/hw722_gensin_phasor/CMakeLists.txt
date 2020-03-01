cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME hw722_gensin_phasor)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")

# CHANGE THE PATH TO YOUR COMMON FOLDER
set(COMMON "//Volumes/COURSES/cs312-00-w20/StuWork/stritzelm/common")
set(LIBSF "${COMMON}/libsndfile")
set(ULL "/usr/local/lib")

add_executable(
  ${PROJECT_NAME}
  ${LIBSF}/sndfile.hh
  ${PROJECT_NAME}.cpp
  )

target_include_directories(${PROJECT_NAME} PRIVATE ${COMMON} ${LIBSF})
target_link_libraries(${PROJECT_NAME} ${ULL}/libsndfile.1.dylib)
