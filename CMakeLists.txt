cmake_minimum_required(VERSION 3.27)
project(PSTest)

set(CMAKE_CXX_STANDARD 17)

add_executable(28278 28278.cpp
        test.cpp)

add_executable(test test.cpp)
add_executable(Out test.cpp)
