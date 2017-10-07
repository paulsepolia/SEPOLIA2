#!/bin/bash

tests_all="algop alloc decl get set"

if [ $1 = 'all' ]; then
    tests=$tests_all
else
    tests=$1
fi

for val in $tests
do
    icpc    -O3                          \
            -Wall                        \
            -std=gnu++17                 \
            -qopenmp                     \
            -parallel                    \
            -D_GLIBCXX_PARALLEL          \
            -par-threshold100            \
            -qopt-report-phase=vec       \
            -qopt-report-phase=par       \
            -qopt-report-phase=openmp    \
            -qopt-report=0               \
            functions_speed_test_aux.cpp \
            test_speed_$val.cpp          \
            driver_program.cpp           \
            -o x_intel_$val

    ./x_intel_$val

done
