# Kinect-AR Mobile Robot Navigation and Localization System
# Drew Stebbins

# This CMakeList.txt file built off of CMake Example Project

CMAKE_MINIMUM_REQUIRED (VERSION 2.6)

# ARToolKitPlus installation directory (change to match yours)
set(ARTKP_DIR /home/astebbin/Downloads/ARToolKitPlus-2.2.1)

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

# Add subdirectories so those CMakeLists.txt files are parsed  
ADD_SUBDIRECTORY (src)
#ADD_SUBDIRECTORY (doc)

