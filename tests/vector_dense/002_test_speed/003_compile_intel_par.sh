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
            -par-threshold0              \
            -qopt-report-phase=vec       \
            -qopt-report-phase=par       \
            -qopt-report-phase=openmp    \
            -qopt-report=1               \
            functions_speed_test_aux.cpp \
            test_speed_$val.cpp          \
            driver_program.cpp           \
            -o x_intel_par_$val

    ./x_intel_par_$val

done
