#!/bin/bash

    g++-6.3.0   -O3                          \
                -Wall                        \
                -std=gnu++17                 \
                -fopenmp                     \
                -D_GLIBCXX_PARALLEL          \
                functions_speed_test_aux.cpp \
                test_speed_$1.cpp            \
                driver_program.cpp           \
                -o x_gnu_$1

    ./x_gnu_$1
