cmake_minimum_required(VERSION 3.14)
project (Vecotr2 VERSION 1.0)

add_library(
    Math
    ./source/MathLib.cpp
)

add_executable(
    test
    ./test/test.cpp
)

target_link_libraries(
    test
    Math
)