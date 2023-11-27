# Project setup
cmake_minimum_required(VERSION 3.20.4)
project(SimpleTetris CXX)
set(CMAKE_CXX_STANDARD 17)

## Code properties/flags

    # Debugging
    define_property(GLOBAL PROPERTY DEBUG_LOGGING)
    set_property(GLOBAL PROPERTY DEBUG_LOGGING FALSE)

## Include libraries
    # raylib
    add_subdirectory(libs/raylib)
    find_library(raylib libs/raylib)

## Source files
file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp") # SOURCE_FILES is a list of all .cpp files

# Link source files to executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

## Link and compile sources
    if(CMAKE_BUILD_TYPE STREQUAL "Release")
        target_link_options(${PROJECT_NAME} PRIVATE -mwindows) # Hide console on Release
    endif()

    # Link libraries
    find_library(raylib libs/raylib)
    target_link_libraries(${PROJECT_NAME} raylib)

    # Link assets
    target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/")
    #target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC RESOURCES_PATH="./assets/") # Uncomment this line to setup the ASSETS_PATH macro to the final assets directory when you share the game

    # Link sources files
    target_sources("${CMAKE_PROJECT_NAME}" PRIVATE ${SOURCE_FILES})
    target_include_directories("${CMAKE_PROJECT_NAME}" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")