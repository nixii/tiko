cmake_minimum_required(VERSION 3.30)
project(tiko C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

file(GLOB_RECURSE SOURCE_FILES "src/*.c")

add_executable(tiko ${SOURCE_FILES})
