#!/bin/bash

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
            test_speed_$1.cpp            \
            driver_program.cpp           \
            -o x_intel_par_$1

    ./x_intel_par_$1
