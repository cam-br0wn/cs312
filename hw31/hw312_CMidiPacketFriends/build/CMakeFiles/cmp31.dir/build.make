# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.16.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.16.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Volumes/COURSES/cs312-00-w20/StuWork/brownc2/cs312/cs312-00-w20/hw31/hw312_CMidiPacketFriends

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Volumes/COURSES/cs312-00-w20/StuWork/brownc2/cs312/cs312-00-w20/hw31/hw312_CMidiPacketFriends/build

# Include any dependencies generated for this target.
include CMakeFiles/cmp31.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cmp31.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cmp31.dir/flags.make

CMakeFiles/cmp31.dir/hw312_CMidiPacket.cpp.o: CMakeFiles/cmp31.dir/flags.make
CMakeFiles/cmp31.dir/hw312_CMidiPacket.cpp.o: ../hw312_CMidiPacket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Volumes/COURSES/cs312-00-w20/StuWork/brownc2/cs312/cs312-00-w20/hw31/hw312_CMidiPacketFriends/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cmp31.dir/hw312_CMidiPacket.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cmp31.dir/hw312_CMidiPacket.cpp.o -c /Volumes/COURSES/cs312-00-w20/StuWork/brownc2/cs312/cs312-00-w20/hw31/hw312_CMidiPacketFriends/hw312_CMidiPacket.cpp

CMakeFiles/cmp31.dir/hw312_CMidiPacket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cmp31.dir/hw312_CMidiPacket.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Volumes/COURSES/cs312-00-w20/StuWork/brownc2/cs312/cs312-00-w20/hw31/hw312_CMidiPacketFriends/hw312_CMidiPacket.cpp > CMakeFiles/cmp31.dir/hw312_CMidiPacket.cpp.i

CMakeFiles/cmp31.dir/hw312_CMidiPacket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cmp31.dir/hw312_CMidiPacket.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Volumes/COURSES/cs312-00-w20/StuWork/brownc2/cs312/cs312-00-w20/hw31/hw312_CMidiPacketFriends/hw312_CMidiPacket.cpp -o CMakeFiles/cmp31.dir/hw312_CMidiPacket.cpp.s

CMakeFiles/cmp31.dir/hw312_test_CMidiPacket.cpp.o: CMakeFiles/cmp31.dir/flags.make
CMakeFiles/cmp31.dir/hw312_test_CMidiPacket.cpp.o: ../hw312_test_CMidiPacket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Volumes/COURSES/cs312-00-w20/StuWork/brownc2/cs312/cs312-00-w20/hw31/hw312_CMidiPacketFriends/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cmp31.dir/hw312_test_CMidiPacket.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cmp31.dir/hw312_test_CMidiPacket.cpp.o -c /Volumes/COURSES/cs312-00-w20/StuWork/brownc2/cs312/cs312-00-w20/hw31/hw312_CMidiPacketFriends/hw312_test_CMidiPacket.cpp

CMakeFiles/cmp31.dir/hw312_test_CMidiPacket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cmp31.dir/hw312_test_CMidiPacket.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Volumes/COURSES/cs312-00-w20/StuWork/brownc2/cs312/cs312-00-w20/hw31/hw312_CMidiPacketFriends/hw312_test_CMidiPacket.cpp > CMakeFiles/cmp31.dir/hw312_test_CMidiPacket.cpp.i

CMakeFiles/cmp31.dir/hw312_test_CMidiPacket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cmp31.dir/hw312_test_CMidiPacket.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Volumes/COURSES/cs312-00-w20/StuWork/brownc2/cs312/cs312-00-w20/hw31/hw312_CMidiPacketFriends/hw312_test_CMidiPacket.cpp -o CMakeFiles/cmp31.dir/hw312_test_CMidiPacket.cpp.s

CMakeFiles/cmp31.dir/hw312_main.cpp.o: CMakeFiles/cmp31.dir/flags.make
CMakeFiles/cmp31.dir/hw312_main.cpp.o: ../hw312_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Volumes/COURSES/cs312-00-w20/StuWork/brownc2/cs312/cs312-00-w20/hw31/hw312_CMidiPacketFriends/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/cmp31.dir/hw312_main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cmp31.dir/hw312_main.cpp.o -c /Volumes/COURSES/cs312-00-w20/StuWork/brownc2/cs312/cs312-00-w20/hw31/hw312_CMidiPacketFriends/hw312_main.cpp

CMakeFiles/cmp31.dir/hw312_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cmp31.dir/hw312_main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Volumes/COURSES/cs312-00-w20/StuWork/brownc2/cs312/cs312-00-w20/hw31/hw312_CMidiPacketFriends/hw312_main.cpp > CMakeFiles/cmp31.dir/hw312_main.cpp.i

CMakeFiles/cmp31.dir/hw312_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cmp31.dir/hw312_main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Volumes/COURSES/cs312-00-w20/StuWork/brownc2/cs312/cs312-00-w20/hw31/hw312_CMidiPacketFriends/hw312_main.cpp -o CMakeFiles/cmp31.dir/hw312_main.cpp.s

# Object files for target cmp31
cmp31_OBJECTS = \
"CMakeFiles/cmp31.dir/hw312_CMidiPacket.cpp.o" \
"CMakeFiles/cmp31.dir/hw312_test_CMidiPacket.cpp.o" \
"CMakeFiles/cmp31.dir/hw312_main.cpp.o"

# External object files for target cmp31
cmp31_EXTERNAL_OBJECTS =

cmp31: CMakeFiles/cmp31.dir/hw312_CMidiPacket.cpp.o
cmp31: CMakeFiles/cmp31.dir/hw312_test_CMidiPacket.cpp.o
cmp31: CMakeFiles/cmp31.dir/hw312_main.cpp.o
cmp31: CMakeFiles/cmp31.dir/build.make
cmp31: CMakeFiles/cmp31.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Volumes/COURSES/cs312-00-w20/StuWork/brownc2/cs312/cs312-00-w20/hw31/hw312_CMidiPacketFriends/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable cmp31"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cmp31.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cmp31.dir/build: cmp31

.PHONY : CMakeFiles/cmp31.dir/build

CMakeFiles/cmp31.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cmp31.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cmp31.dir/clean

CMakeFiles/cmp31.dir/depend:
	cd /Volumes/COURSES/cs312-00-w20/StuWork/brownc2/cs312/cs312-00-w20/hw31/hw312_CMidiPacketFriends/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Volumes/COURSES/cs312-00-w20/StuWork/brownc2/cs312/cs312-00-w20/hw31/hw312_CMidiPacketFriends /Volumes/COURSES/cs312-00-w20/StuWork/brownc2/cs312/cs312-00-w20/hw31/hw312_CMidiPacketFriends /Volumes/COURSES/cs312-00-w20/StuWork/brownc2/cs312/cs312-00-w20/hw31/hw312_CMidiPacketFriends/build /Volumes/COURSES/cs312-00-w20/StuWork/brownc2/cs312/cs312-00-w20/hw31/hw312_CMidiPacketFriends/build /Volumes/COURSES/cs312-00-w20/StuWork/brownc2/cs312/cs312-00-w20/hw31/hw312_CMidiPacketFriends/build/CMakeFiles/cmp31.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cmp31.dir/depend

