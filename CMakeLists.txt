cmake_minimum_required(VERSION 3.16)
project(Modern_C_Programming_sec3 C)

set(CMAKE_C_STANDARD 11)
# set(CMAKE_C_FLAGS "-Wall -std=c11 -pedantic")

add_executable(stack main.c stack.h stack.c)
