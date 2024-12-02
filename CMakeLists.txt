cmake_minimum_required(VERSION 3.26)
project(MyGame)

# C++ version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# includes yak
add_subdirectory(libs/yak)

# add source files
add_executable(game
    src/main.cpp
)

# link yak
target_link_libraries(game yak)

