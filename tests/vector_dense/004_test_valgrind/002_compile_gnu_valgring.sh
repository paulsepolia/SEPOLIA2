#!/bin/bash

    g++-7.1.0   -g                  \
                -O0                 \
                -Wall               \
                -std=gnu++14        \
                -fopenmp            \
                driver_program.cpp  \
                -o x_gnu_valgrind

    valgrind --leak-check=yes ./x_gnu_valgrind 2>&1 | grep -E '(definitely lost|false)'
