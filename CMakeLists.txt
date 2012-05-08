# Kinect-AR Mobile Robot Navigation and Localization System
# Drew Stebbins

# This CMakeList.txt file built off of CMake Example Project

# Require
IF (WIN32)
    # Require 2.6 for Windows
    CMAKE_MINIMUM_REQUIRED (VERSION 2.6 FATAL_ERROR)
ELSE (WIN32)
    CMAKE_MINIMUM_REQUIRED (VERSION 2.4.7 FATAL_ERROR)
ENDIF (WIN32)

# Set your project name and version
PROJECT (Kinect-AR-Nav)
SET(PROJECT_VERSION 0.0.1 CACHE STRING "Kinect-AR Nav Version Number")

set(CMAKE_BUILD_TYPE Debug)

# Build flags for different configurations
# Use is determined by the option CMAKE_BUILD_TYPE
set(CMAKE_C_FLAGS_DEBUG "-g -Wall ")

set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall ")

# link to OpenGL and GLUT libraries
#find_package(GLUT)
#find_package(OpenGL)

#find_package(SDL_mixer)
#find_package(SDL)

# look in the right place for resource files regardless of build location
cmake_policy(SET CMP0005 NEW) # please escape quotes
add_definitions("-DRESOURCE_DIR=\"${CMAKE_SOURCE_DIR}\"")

# Add an uninstall target (for "make uninstall")
#CONFIGURE_FILE(
#  "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
#  "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
#  IMMEDIATE @ONLY)
#ADD_CUSTOM_TARGET(uninstall
#  "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake")

# Add subdirectories so those CMakeLists.txt files are parsed  
ADD_SUBDIRECTORY (src)
#ADD_SUBDIRECTORY (doc)

