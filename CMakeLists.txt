# Project setup
cmake_minimum_required(VERSION 3.20.4)
project(SimpleTetris CXX)
set(CMAKE_CXX_STANDARD 14)

## Code properties/flags
    # Debugging
    define_property(GLOBAL PROPERTY DEBUG_LOGGING)
    set_property(GLOBAL PROPERTY DEBUG_LOGGING FALSE)

## Include libraries
    # raylib
    add_subdirectory(libs/raylib)
    find_library(raylib libs/raylib)

## Source files
set(SOURCE_FILES
        src/main.cpp
        src/grid/grid.h src/grid/grid.cpp
        src/block/block.h src/block/block.cpp src/block/blocks.cpp
        src/util/position.h src/util/position.cpp
        src/util/colors.h src/util/colors.cpp
        src/game/game.cpp src/game/game.h
        src/game/game_ui.cpp src/game/game_ui.h
        src/resourcehandling/fontshandler.cpp src/resourcehandling/fontshandler.h
        src/resourcehandling/musichandler.cpp src/resourcehandling/musichandler.h
)

# Compile files
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} raylib)
target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/")
