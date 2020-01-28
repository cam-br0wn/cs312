# CMakeLists_gtest.txt

cmake_minimum_required(VERSION 3.0)
set(APPNAME "gtestCMP32")
project(${APPNAME})

# JE sets to 0
# Matt sets to 1
# Cam sets to 2
set(FOR_USER 2)
set( HOME "/Volumes/COURSES/cs312-00-w20/StuWork/brownc2" )
set(GTEST_INC "${HOME}/common/googletest/include/")
set(GTEST_LIB "${HOME}/common/googletest/lib")
#if(${FOR_USER} EQUAL 0)
#  set( HOME "/Users/je/cs312/_cs312" )
#  set(GTEST_INC "${HOME}/common/googletest/include/")
#  set(GTEST_LIB "${HOME}/common/googletest/lib")
#elseif(${FOR_USER} EQUAL 1)
#  set( HOME "/Volumes/COURSES/cs312-00-w20/StuWork/stritzelm" )
#  set(GTEST_INC "${HOME}/common/googletest/include/")
#  set(GTEST_LIB "${HOME}/common/googletest/lib")
#elseif(${FOR_USER} EQUAL 2)
#  set( HOME "/Volumes/COURSES/cs312-00-w20/StuWork/brownc2" )
#  set(GTEST_INC "${HOME}/cs312/common/googletest/include/")
#  set(GTEST_LIB "${HOME}/cs312/common/googletest/lib")
#endif(${FOR_USER} EQUAL 0)

include_directories(${GTEST_INC})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++17 -Wall ")
set(SOURCE_FILES
  hw322_CMidiPacket.cpp
  hw322_gtests.cpp
)
add_executable(${APPNAME} ${SOURCE_FILES})
set(LINK_LIBS
    ${GTEST_LIB}/libgtest_main.a
    ${GTEST_LIB}/libgtest.a
)
target_link_libraries(${APPNAME} ${LINK_LIBS})
add_test(NAME CMP32_test COMMAND ${APPNAME})