cmake_minimum_required(VERSION 3.22)

# set the project name
project(Example)

# specify C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# specify compiler flags
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wpedantic -Wunused -Wconversion")

# add the executable
add_executable(example example.cpp)

