# If Player isn't installed to /usr, you'll have to edit this path to point
# to the location of UserPlayerC++.cmake and UsePlayerPlugin.cmake
SET (CMAKE_MODULE_PATH "/usr/local/share/cmake/Modules")

# These files include macros that make building against Player easier.  They provide
# the PLAYER_ADD* macros
INCLUDE (UsePlayerC++)
INCLUDE (UsePlayerPlugin)

include_directories("/usr/local/include")
#include_directories("${ARTKP_DIR}/include")
include_directories("/usr/include")

link_directories("/usr/local/lib")
#link_directories("${ARTKP_DIR}/build/lib")
link_directories("/usr/lib")

set(SOURCEFILES main.cpp)

#if (SDL_FOUND AND SDLMIXER_FOUND)
#    include_directories(${SDL_INCLUDE_DIR})
#    include_directories(${SDLMIXER_INCLUDE_DIR})
#    set(MIXERLIB ${SDL_LIBRARY} ${SDLMIXER_LIBRARY})
#    add_definitions("-DHAVE_SDLMIXER=1")
#endif (SDL_FOUND AND SDLMIXER_FOUND)


add_library(KinectARNav KinectARNav.cpp KinectReader.cpp Localizer.cpp Navigator.cpp Visualizer.cpp)
target_link_libraries(KinectARNav freenect opencv_core ARToolKitPlus json_spirit pthread)

PLAYER_ADD_PLAYERCPP_CLIENT ( ${PROJECT_NAME} SOURCES ${SOURCEFILES})
target_link_libraries(${PROJECT_NAME} KinectARNav pthread)

#add_executable(example_client main.cpp)
#target_link_libraries(example_client KinectARNav)
#target_link_libraries(test Xext X11 m ${MIXERLIB})

#install(TARGETS example_client DESTINATION bin)
install(TARGETS KinectARNav DESTINATION lib)
