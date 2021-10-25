cmake_minimum_required(VERSION 3.10)
project(OneginSort)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(OneginSort
        include/OneginSort.h
        src/MakeStringFunc.cpp
        src/OneginSort.cpp
        src/SortFunc.cpp)
