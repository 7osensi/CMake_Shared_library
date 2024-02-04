cmake_minimum_required(VERSION 3.22) 
project (STRING_LAB)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SRC_FILE 
    main.cpp)

add_executable(StringLib ${SRC_FILE})

target_include_directories(StringLib PUBLIC include/ lib/) # Include these files to make on the same path

add_subdirectory(${CMAKE_SOURCE_DIR}/lib) # Include directory to the main directory

target_link_libraries(StringLib PUBLIC string_lib) # Link the lib with the exe