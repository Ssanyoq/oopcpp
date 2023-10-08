cmake_minimum_required(VERSION 3.26)
project(lab2)

set(CMAKE_CXX_STANDARD 14)

add_library(octet octet/octet.cpp octet/octet.h)

add_library(binary_number
        binary_number/binary.h binary_number/binary_methods.cpp
        binary_number/binary_operators.cpp)

add_library(catch2 catch2/catch_amalgamated.cpp catch2/catch_amalgamated.hpp)

add_library(utility util_functions/utils.cpp
        util_functions/utils.h
        util_functions/base_converters.cpp
        util_functions/base_converters.h)


add_executable(lab2 main.cpp
        dynamic/dynamic_octets.cpp
        dynamic/dynamic_octets.h)
target_link_libraries(lab2 octet binary_number utility)

add_executable(test test/octet_tests.cpp
        dynamic/dynamic_octets.cpp
        dynamic/dynamic_octets.h
        test/dynamic_tests.cpp)
target_link_libraries(test octet binary_number utility catch2)