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

    // speed test: set via assignment operator

    fun_display_c();
    cout << "--> speed test: set via assignment operator" << endl;

    fun_set_via_assignment_operator(TRIALS, DIM_VEC, TEST_VALUE1, SETW);

    // speed test: set vector element by element

    fun_display_c();
    cout << "--> speed test: set vector element by element" << endl;

    fun_set_vector_element_by_element(TRIALS, DIM_VEC, SETW);

    // speed test: set vector element by element square

    fun_display_c();
    cout << "--> speed test: set vector element by element square" << endl;

    fun_set_vector_element_by_element_square(TRIALS, DIM_VEC, SETW);
}
