# CMakeLists_normal.txt

cmake_minimum_required( VERSION 2.8 )
set( APPNAME "CMP32friends" )
project( ${APPNAME} )

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall " )
set( SOURCE_FILES
  hw322_CMidiPacket.cpp
  hw322_CMP32friends.cpp 
)

add_executable( ${APPNAME} ${SOURCE_FILES} )