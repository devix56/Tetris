#
# Project setup
#
cmake_minimum_required(VERSION 3.20.4)
project(SimpleTetris
        VERSION 0.1
        LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

#
# Code properties/flags
#
# TODO


#
# Include source code/assets/libararies to executable
#
    # Source code
    file(GLOB_RECURSE SOURCE_FILES "src/*.cpp" "src/*.h")

    # Executable
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})

    # Libraries
        # raylib
        find_library(raylib libs/raylib)
        add_subdirectory(libs/raylib)

        ## rres
        set(RRES_LIB_PATH)
        add_library(rres INTERFACE)

        # Link libraries for compilation
        target_link_libraries(${PROJECT_NAME}
                raylib
                rres
        )

        # Include non-cmake libraries for code
        target_include_directories(rres INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/libs/rres)
        target_include_directories(
                "${CMAKE_PROJECT_NAME}" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/"
                "${CMAKE_PROJECT_NAME}" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/assets/"
        )

    # Assets
    file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

#
# Build flags
#
    # Debug build
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")

        # Logging
        define_property(GLOBAL PROPERTY DEBUG_LOGGING)
        set_property(GLOBAL PROPERTY DEBUG_LOGGING TRUE)

    endif()

    # Release build
    if(CMAKE_BUILD_TYPE STREQUAL "Release")

        # Hides console
        target_link_options(${PROJECT_NAME} PRIVATE -mwindows)

    endif()

#
# Compilation for different platforms
#
    # Windows
    if (WIN32)
        # do nothing
    endif ()

    # macOS
    if (APPLE)
        target_link_libraries(${PROJECT_NAME} "-framework IOKit")
        target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
        target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
    endif ()

    # Linux
    if (LINUX)
        # TODO compile Linux
    endif ()
