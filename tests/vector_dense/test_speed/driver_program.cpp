#include <parallel/algorithm>
#include "tests.h"

int main(int argc, char **argv) {

    // force parallel execution of the STL libraries

    __gnu_parallel::_Settings s;
    s.algorithm_strategy = __gnu_parallel::force_parallel;
    __gnu_parallel::_Settings::set(s);

    // run test here

    tests();

    return 0;
}