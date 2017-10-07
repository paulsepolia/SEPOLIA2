#!/bin/bash

    g++-6.3.0   -O3                 \
                -Wall               \
                -std=gnu++17        \
                -fopenmp            \
                -D_GLIBCXX_PARALLEL \
                driver_program.cpp  \
                -o x_gnu

    ./x_gnu | grep false
