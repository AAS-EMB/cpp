cmake_minimum_required(VERSION 3.16)
project(cppExamples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

add_subdirectory(sort/bubble)
add_subdirectory(sort/selection)
add_subdirectory(sort/insertion)
