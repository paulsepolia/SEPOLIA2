cmake_minimum_required(VERSION 3.6)
project(SEPOLIA2)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp vector_dense/vector_dense_declaration.h parameters/parameters.h vector_dense/vector_dence_constructors.h vector_dense/vector_dense_memory.h vector_dense/vector_dense.h utilities/utils.h)
add_executable(SEPOLIA2 ${SOURCE_FILES})