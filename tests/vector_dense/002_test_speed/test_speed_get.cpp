#include <iostream>
#include <cmath>
#include "tests.h"
#include "functions_speed_test_aux.h"

void tests() {

    // local parameters

    const uint32_t SETW(11);
    const auto DIM_VEC(static_cast<uint64_t>(std::pow(10.0, 6.0)));
    const auto TRIALS(static_cast<uint32_t>(std::pow(10.0, 2.0)));

    //==================//
    // speed tests here //
    //==================//

    // speed test: get vector element by element square

    fun_display_c();
    std::cout << "--> speed test: get vector element by element square" << std::endl;

    fun_get_vector_element_by_element_square(TRIALS, DIM_VEC, SETW);

    // speed test: get vector element by element curly

    fun_display_c();
    std::cout << "--> speed test: get vector element by element curly" << std::endl;

    fun_get_vector_element_by_element_curly(TRIALS, DIM_VEC, SETW);
}
