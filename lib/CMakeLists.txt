cmake_minimum_required(VERSION 3.22) 
message(STATUS "Hello from lib")

add_library(string_lib
    StringClass.cpp
    StringClass.hpp)