cmake_minimum_required(VERSION 3.16)
project(QUICKSORT LANGUAGES C CXX)

# C = C lauguage / CXX = C++
#setting standard liberary, C
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

#setting standard liberary, C++
set(CMAKE_CXX_STANDARD 99)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_subdirectory(tests)
add_subdirectory(Sources)
