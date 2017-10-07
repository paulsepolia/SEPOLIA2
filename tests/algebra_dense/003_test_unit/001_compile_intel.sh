#!/bin/bash

tests_all="blas"

if [ $1 = 'all' ]; then
    tests=$tests_all
else
    tests=$1
fi

for var in $tests
do

    ls x_intel_$var 2> /dev/null

    if [ $? -eq 0 ]; then
        rm x_intel_$var
    fi

    icpc    -c                                              \
            -O3                                             \
            -Wall                                           \
            -std=gnu++17                                    \
            -qopenmp                                        \
            -D_GLIBCXX_PARALLEL                             \
            -isystem                                        \
            /opt/gtest/1.7.0/include                        \
            -pthread                                        \
            ../../../algebra_dense/algebra_blas_level_1.cpp \
            unit_test_$var.cpp                              \
            driver_program.cpp


    icpc    algebra_blas_level_1.o                      \
            unit_test_$var.o                            \
            driver_program.o                            \
            /opt/mkl_pgg/libmkl_intel_lp64_2017_0_098.a \
            /opt/gtest/1.7.0/lib/libgtest.a             \
            -qopenmp                                    \
            -o x_intel_$var


    ./x_intel_$var

    rm *.o
done
