cmake_minimum_required(VERSION 3.21)
project(P04 C)

set(CMAKE_C_STANDARD 99)

add_library(P04 library.c header.h modularize/src/read.c modularize/src/read.h modularize/src/rectang.c modularize/src/rectang.h modularize/src/triangle.c)
