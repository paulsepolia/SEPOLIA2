#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

#include "tests.h"
#include "functions_speed_test_aux.h"

void tests() {

    // local parameters

    const double TEST_VALUE1(1234.56789);
    const uint32_t SETW(11);
    const uint64_t DIM_VEC(static_cast<uint64_t>(std::pow(10.0, 4.0)));
    const uint64_t TRIALS(static_cast<uint32_t>(std::pow(10.0, 2.0)));

    //==================//
    // speed tests here //
    //==================//

    // speed test: allocation via constructor, set and auto-deallocation

    fun_display_c();
    cout << "--> speed test: allocation via constructor, set and auto-deallocation" << endl;

    fun_alloc_set_via_constructor(TRIALS, DIM_VEC, TEST_VALUE1, SETW);

    // speed test: allocation, set and deallocation

    fun_display_c();
    cout << "--> speed test: allocation, set and deallocation" << endl;

    fun_alloc_set_dealloc(TRIALS, DIM_VEC, TEST_VALUE1, SETW);
}
