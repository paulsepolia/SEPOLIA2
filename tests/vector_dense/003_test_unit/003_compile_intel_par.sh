#!/bin/bash

tests_all="algop constructors exceptions memory oper set_get speed stl_algos stl_members utils"

if [ $1 = 'all' ]; then
    tests=$tests_all
else
    tests=$1
fi

for var in $tests
do

    ls x_intel_par_$var 2> /dev/null

    if [ $? -eq 0 ]; then
        rm x_intel_par_$var
    fi

    icpc -O3                             \
         -Wall                           \
         -std=gnu++17                    \
         -qopenmp                        \
         -parallel                       \
         -D_GLIBCXX_PARALLEL             \
         -par-threshold0                 \
         -qopt-report=0                  \
         -isystem                        \
         /opt/gtest/1.7.0/include        \
         -pthread                        \
         test_unit_$var.cpp              \
         driver_program.cpp              \
         /opt/gtest/1.7.0/lib/libgtest.a \
         -o x_intel_par_$var

    ./x_intel_par_$var

done

