cmake_minimum_required(VERSION 3.22)
project(Movie)

set(CMAKE_CXX_STANDARD 14)

add_executable(Movie main.cpp movie.cpp movie.h movielist.cpp movielist.h console.h)
