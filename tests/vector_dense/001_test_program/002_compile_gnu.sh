#!/bin/bash

    g++-7.2.0   -O3                 \
                -Wall               \
                -std=gnu++14        \
                -fopenmp            \
                -D_GLIBCXX_PARALLEL \
                driver_program.cpp  \
                -o x_gnu

    ./x_gnu | grep false
