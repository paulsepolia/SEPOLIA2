cmake_minimum_required(VERSION 3.6)
project(SEPOLIA2)

set(CMAKE_CXX_STANDARD 14)
include_directories(/opt/gtest/1.7.0/include/)

set(SOURCE_FILES
        vector_dense
        parameters
        utilities
        tests/vector_dense/001_test_program
        tests/vector_dense/002_test_speed
        tests/vector_dense/003_test_unit
        tests/vector_dense/002_test_speed/functions_speed_test_aux.cpp
        tests/vector_dense/002_test_speed/functions_speed_test_aux.h
        tests/vector_dense/002_test_speed/test_speed_decl.cpp
        tests/vector_dense/002_test_speed/test_speed_algop.cpp
        tests/vector_dense/002_test_speed/tests.h
        tests/vector_dense/003_test_unit/test_unit_stl_members.cpp
        algebra_dense utilities/functions.h)

add_executable(SEPOLIA2 ${SOURCE_FILES})
