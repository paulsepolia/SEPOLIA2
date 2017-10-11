#include <iostream>
#include <cmath>
#include "tests.h"
#include "functions_speed_test_aux.h"

void tests() {

    // local parameters

    const double TEST_VALUE1(1234.56789);
    const uint32_t SETW(11);
    const auto DIM_VEC(static_cast<uint64_t>(std::pow(10.0, 6.0)));
    const auto TRIALS(static_cast<uint32_t>(std::pow(10.0, 2.0)));

    //==================//
    // speed tests here //
    //==================//

    // speed test: set via assignment operator

    fun_display_c();
    std::cout << "--> speed test: set via assignment operator" << std::endl;

    fun_set_via_assignment_operator(TRIALS, DIM_VEC, TEST_VALUE1, SETW);

    // speed test: set vector element by element

    fun_display_c();
    std::cout << "--> speed test: set vector element by element" << std::endl;

    fun_set_vector_element_by_element(TRIALS, DIM_VEC, SETW);
}
