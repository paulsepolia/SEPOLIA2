#!/bin/bash

    icpc    -O3                         \
            -Wall                       \
            -std=gnu++17                \
            -qopenmp                    \
            -parallel                   \
            -D_GLIBCXX_PARALLEL         \
            -par-threshold100           \
            -qopt-report-phase=vec      \
            -qopt-report-phase=par      \
            -qopt-report-phase=openmp   \
            -qopt-report=0              \
            driver_program.cpp          \
            -o x_intel

    ./x_intel | grep false
