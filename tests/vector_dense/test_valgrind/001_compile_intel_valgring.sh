#!/bin/bash

    icpc    -g                          \
            -O0                         \
            -Wall                       \
            -std=gnu++17                \
            -qopenmp                    \
            -parallel                   \
            -par-threshold0             \
            -qopt-report-phase=vec      \
            -qopt-report-phase=par      \
            -qopt-report-phase=openmp   \
            -qopt-report=0              \
            driver_program.cpp          \
            -o x_intel_valgrind

    valgrind --leak-check=yes ./x_intel_valgrind 2>&1 | grep -E '(definitely lost|false)'
