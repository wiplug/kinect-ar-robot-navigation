# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/astebbin/kinect-ar-robot-navigation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/astebbin/kinect-ar-robot-navigation/build

# Include any dependencies generated for this target.
include src/CMakeFiles/example_client.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/example_client.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/example_client.dir/flags.make

src/CMakeFiles/example_client.dir/main.o: src/CMakeFiles/example_client.dir/flags.make
src/CMakeFiles/example_client.dir/main.o: ../src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/astebbin/kinect-ar-robot-navigation/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/example_client.dir/main.o"
	cd /home/astebbin/kinect-ar-robot-navigation/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/example_client.dir/main.o -c /home/astebbin/kinect-ar-robot-navigation/src/main.cpp

src/CMakeFiles/example_client.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example_client.dir/main.i"
	cd /home/astebbin/kinect-ar-robot-navigation/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/astebbin/kinect-ar-robot-navigation/src/main.cpp > CMakeFiles/example_client.dir/main.i

src/CMakeFiles/example_client.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example_client.dir/main.s"
	cd /home/astebbin/kinect-ar-robot-navigation/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/astebbin/kinect-ar-robot-navigation/src/main.cpp -o CMakeFiles/example_client.dir/main.s

src/CMakeFiles/example_client.dir/main.o.requires:
.PHONY : src/CMakeFiles/example_client.dir/main.o.requires

src/CMakeFiles/example_client.dir/main.o.provides: src/CMakeFiles/example_client.dir/main.o.requires
	$(MAKE) -f src/CMakeFiles/example_client.dir/build.make src/CMakeFiles/example_client.dir/main.o.provides.build
.PHONY : src/CMakeFiles/example_client.dir/main.o.provides

src/CMakeFiles/example_client.dir/main.o.provides.build: src/CMakeFiles/example_client.dir/main.o

# Object files for target example_client
example_client_OBJECTS = \
"CMakeFiles/example_client.dir/main.o"

# External object files for target example_client
example_client_EXTERNAL_OBJECTS =

src/example_client: src/CMakeFiles/example_client.dir/main.o
src/example_client: src/libKinectARNav.a
src/example_client: src/CMakeFiles/example_client.dir/build.make
src/example_client: src/CMakeFiles/example_client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable example_client"
	cd /home/astebbin/kinect-ar-robot-navigation/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example_client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/example_client.dir/build: src/example_client
.PHONY : src/CMakeFiles/example_client.dir/build

src/CMakeFiles/example_client.dir/requires: src/CMakeFiles/example_client.dir/main.o.requires
.PHONY : src/CMakeFiles/example_client.dir/requires

src/CMakeFiles/example_client.dir/clean:
	cd /home/astebbin/kinect-ar-robot-navigation/build/src && $(CMAKE_COMMAND) -P CMakeFiles/example_client.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/example_client.dir/clean

src/CMakeFiles/example_client.dir/depend:
	cd /home/astebbin/kinect-ar-robot-navigation/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/astebbin/kinect-ar-robot-navigation /home/astebbin/kinect-ar-robot-navigation/src /home/astebbin/kinect-ar-robot-navigation/build /home/astebbin/kinect-ar-robot-navigation/build/src /home/astebbin/kinect-ar-robot-navigation/build/src/CMakeFiles/example_client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/example_client.dir/depend
