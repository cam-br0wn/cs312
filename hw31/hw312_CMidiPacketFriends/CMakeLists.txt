cmake_minimum_required( VERSION 2.8 )
set( APPNAME "cmp31" )
project( ${APPNAME} )

#edit next line
#set( HOME "/Volumes/cs312-00-w20/StuWork/<your_email_name>" )
set( HOME "/Users/je" )
set( COMMON "${HOME}/cs312/common" )

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall " )
set( SOURCE_FILES
 	hw312_CMidiPacket.cpp
	hw312_test_CMidiPacket.cpp
	hw312_main.cpp
)

include_directories( ${COMMON} )

add_executable( ${APPNAME} ${SOURCE_FILES} )
