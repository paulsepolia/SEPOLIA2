#!/bin/bash

    icpc    -O3                         \
            -Wall                       \
            -std=gnu++17                \
            -qopenmp                    \
            -parallel                   \
            -D_GLIBCXX_PARALLEL         \
            -par-threshold0             \
            -qopt-report-phase=vec      \
            -qopt-report-phase=par      \
            -qopt-report-phase=openmp   \
            -qopt-report=0              \
            driver_program.cpp          \
            -o x_intel_par

    ./x_intel_par | grep false
