cmake_minimum_required(VERSION 3.27)
project(reverse)

set(CMAKE_CXX_STANDARD 17)

add_executable(reverse
        reverse.h
        reverse_test.cpp)
