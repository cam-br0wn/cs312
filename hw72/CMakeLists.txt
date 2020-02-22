cmake_minimum_required(VERSION 3.5)

set(APP_NAME hw721_gensin)
project(hw721_gensin)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")

### USE YOUR PATHNAME TO COMMON
set(COMMON "/Users/je/cs312/_cs312/common")
set(LIBSF "${COMMON}/libsndfile")

add_executable( ${APP_NAME}
  ${LIBSF}/sndfile.hh
  ${APP_NAME}.cpp
  )

target_include_directories(${APP_NAME} PRIVATE ${COMMON} ${LIBSF})
target_link_libraries(${APP_NAME} ${LIBSF}/libsndfile.dylib)