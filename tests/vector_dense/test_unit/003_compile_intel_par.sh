#!/bin/bash

    rm x_intel_par_$1

    icpc -O3                             \
         -Wall                           \
         -std=gnu++17                    \
         -qopenmp                        \
         -parallel                       \
         -D_GLIBCXX_PARALLEL             \
         -par-threshold0                 \
         -qopt-report-phase=vec          \
         -qopt-report-phase=par          \
         -qopt-report-phase=openmp       \
         -qopt-report=1                  \
         -isystem                        \
         /opt/gtest/1.7.0/include        \
         -pthread                        \
         test_unit_$1.cpp                \
         driver_program.cpp              \
         /opt/gtest/1.7.0/lib/libgtest.a \
         -o x_intel_par_$1

    ./x_intel_par_$1
