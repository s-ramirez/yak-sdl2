cmake_minimum_required(VERSION 3.26)
project(yak)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(yak SHARED
    src/game.cpp
    src/common/input.cpp
)

target_include_directories(yak 
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)

# Find SDL2 package
find_package(SDL2 REQUIRED)

# Link SDL2 libraries
target_link_libraries(yak PUBLIC ${SDL2_LIBRARIES})

# Include directories
target_include_directories(yak PRIVATE ${SDL2_INCLUDE_DIRS})
