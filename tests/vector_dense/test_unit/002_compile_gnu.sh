#!/bin/bash

    rm x_gnu_$1

    g++-6.3.0   -O3                             \
                -Wall                           \
                -std=gnu++17                    \
                -fopenmp                        \
                -D_GLIBCXX_PARALLEL             \
                -isystem                        \
                /opt/gtest/1.7.0/include        \
                -pthread                        \
                test_unit_$1.cpp                \
                driver_program.cpp              \
                /opt/gtest/1.7.0/lib/libgtest.a \
                -o x_gnu_$1

    ./x_gnu_$1
