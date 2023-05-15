cmake_minimum_required(VERSION 3.24)
project(cpp0_struct)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp0_struct main.cpp include/Box.h src/Box.cpp)
