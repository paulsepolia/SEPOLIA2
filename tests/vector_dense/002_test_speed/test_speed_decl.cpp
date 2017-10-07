#include <iostream>
#include <cmath>
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

    // speed test: declaration via default constructor

    fun_display_c();
    std::cout << "--> speed test: declaration via default constructor" << std::endl;

    fun_declaration_via_default_constructor(TRIALS, SETW);

    // speed test: declaration via full constructor

    fun_display_c();
    std::cout << "--> speed test: declaration via constructor full" << std::endl;

    fun_declaration_via_constructor_full(TRIALS, DIM_VEC, TEST_VALUE1, SETW);
}
