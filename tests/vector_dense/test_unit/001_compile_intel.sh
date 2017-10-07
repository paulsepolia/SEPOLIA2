#!/bin/bash

    rm x_intel_$1

    icpc -O3                             \
         -Wall                           \
         -std=gnu++17                    \
         -qopenmp                        \
         -D_GLIBCXX_PARALLEL             \
         -isystem                        \
         /opt/gtest/1.7.0/include        \
         -pthread                        \
         test_unit_$1.cpp                \
         driver_program.cpp              \
         /opt/gtest/1.7.0/lib/libgtest.a \
         -o x_intel_$1

    ./x_intel_$1
