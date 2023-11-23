cmake_minimum_required(VERSION 3.20.4)
project(Tetris CXX)

set(CMAKE_CXX_STANDARD 14)

define_property(GLOBAL
                PROPERTY DEBUG_LOGGING)
set_property(GLOBAL
             PROPERTY DEBUG_LOGGING FALSE)

# Setting parameters for raylib
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # or games

add_subdirectory(libs/raylib)

add_executable(${PROJECT_NAME} src/main.cpp src/grid/grid.h src/grid/grid.cpp src/block/block.h src/util/position.h src/util/position.cpp src/util/colors.h src/util/colors.cpp src/block/block.cpp src/block/blocks.cpp src/game/game.cpp src/game/game.h src/game/game_ui.cpp src/game/game_ui.h src/resourcehandling/fontshandler.cpp src/resourcehandling/fontshandler.h src/resourcehandling/musichandler.cpp src/resourcehandling/musichandler.h)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/") # Set the asset path macro to the absolute path on the dev machine
#target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="relative-path-to-assets-in-the-game-package") # Set the asset path macro in release mode