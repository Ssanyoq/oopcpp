cmake_minimum_required(VERSION 3.26)
project(lab2)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab2
        octet/octet.cpp
        binary_number/binary_methods.cpp
        octet/octet.h
        binary_number/binary.h
        util_functions/utils.cpp
        util_functions/utils.h
        binary_number/binary_operators.cpp
        main.cpp
        util_functions/base_converters.cpp
        util_functions/base_converters.h
)
