#!/bin/bash

tests_all="algop alloc decl get set"

if [ $1 = 'all' ]; then
    tests=$tests_all
else
    tests=$1
fi

for val in $tests
do
    g++-7.1.0   -O3                          \
                -Wall                        \
                -std=gnu++14                 \
                -fopenmp                     \
                -D_GLIBCXX_PARALLEL          \
                functions_speed_test_aux.cpp \
                test_speed_$val.cpp          \
                driver_program.cpp           \
                -o x_gnu_$val

    ./x_gnu_$val
done
