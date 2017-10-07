#!/bin/bash

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
            test_speed_$1.cpp            \
            driver_program.cpp           \
            -o x_intel_$1

    ./x_intel_$1
