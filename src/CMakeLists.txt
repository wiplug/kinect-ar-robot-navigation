# If Player isn't installed to /usr, you'll have to edit this path to point
# to the location of UserPlayerC++.cmake and UsePlayerPlugin.cmake
SET (CMAKE_MODULE_PATH "/usr/local/share/cmake/Modules")

# These files include macros that make building against Player easier.  They provide
# the PLAYER_ADD* macros
INCLUDE (UsePlayerC++)
INCLUDE (UsePlayerPlugin)

set(SOURCEFILES main.cpp)

#if (SDL_FOUND AND SDLMIXER_FOUND)
#    include_directories(${SDL_INCLUDE_DIR})
#    include_directories(${SDLMIXER_INCLUDE_DIR})
#    set(MIXERLIB ${SDL_LIBRARY} ${SDLMIXER_LIBRARY})
#    add_definitions("-DHAVE_SDLMIXER=1")
#endif (SDL_FOUND AND SDLMIXER_FOUND)

PLAYER_ADD_PLAYERCPP_CLIENT ( ${PROJECT_NAME} SOURCES ${SOURCEFILES})
#target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARY} ${GLUT_LIBRARY} Xext X11 m png ${MIXERLIB})

add_executable(client main.cpp)
#target_link_libraries(test Xext X11 m ${MIXERLIB})
