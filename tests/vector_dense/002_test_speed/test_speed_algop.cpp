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

    //======//
    // plus //
    //======//

    // speed test: add vector-vector using operator +

    fun_display_c();
    std::cout << "--> speed test: add vector-vector using operator +" << std::endl;

    fun_add_vector_vector_using_operator(TRIALS, DIM_VEC, SETW);

    // speed test: add vector-vector element by element square

    fun_display_c();
    std::cout << "--> speed test: add vector-vector element by element square" << std::endl;

    fun_add_vector_vector_element_by_element_square(TRIALS, DIM_VEC, SETW);

    // speed test: add vector-vector element by element curly

    fun_display_c();
    std::cout << "--> speed test: add vector-vector element by element curly" << std::endl;

    fun_add_vector_vector_element_by_element_curly(TRIALS, DIM_VEC, SETW);

    //=======//
    // times //
    //=======//

    // speed test: times vector-vector using operator *

    fun_display_c();
    std::cout << "--> speed test: times vector-vector using operator *" << std::endl;

    fun_times_vector_vector_using_operator(TRIALS, DIM_VEC, SETW);

    // speed test: times vector-vector element by element square

    fun_display_c();
    std::cout << "--> speed test: times vector-vector element by element square" << std::endl;

    fun_times_vector_vector_element_by_element_square(TRIALS, DIM_VEC, SETW);

    // speed test: times vector-vector element by element square

    fun_display_c();
    std::cout << "--> speed test: times vector-vector element by element curly" << std::endl;

    fun_times_vector_vector_element_by_element_curly(TRIALS, DIM_VEC, SETW);

    //==========//
    // subtract //
    //==========//

    // speed test: subtract vector-vector using operator -

    fun_display_c();
    std::cout << "--> speed test: subtract vector-vector using operator -" << std::endl;

    fun_subtract_vector_vector_using_operator(TRIALS, DIM_VEC, SETW);

    // speed test: subtract vector-vector element by element square

    fun_display_c();
    std::cout << "--> speed test: subtract vector-vector element by element square" << std::endl;

    fun_subtract_vector_vector_element_by_element_square(TRIALS, DIM_VEC, SETW);

    // speed test: subtract vector-vector element by element curly

    fun_display_c();
    std::cout << "--> speed test: subtract vector-vector element by element curly" << std::endl;

    fun_subtract_vector_vector_element_by_element_curly(TRIALS, DIM_VEC, SETW);

    //========//
    // divide //
    //========//

    // speed test: divide vector-vector using operator /

    fun_display_c();
    std::cout << "--> speed test: divide vector-vector using operator /" << std::endl;

    fun_divide_vector_vector_using_operator(TRIALS, DIM_VEC, SETW);

    // speed test: divide vector-vector element by element square

    fun_display_c();
    std::cout << "--> speed test: divide vector-vector element by element square" << std::endl;

    fun_divide_vector_vector_element_by_element_square(TRIALS, DIM_VEC, SETW);

    // speed test: divide vector-vector element by element square

    fun_display_c();
    std::cout << "--> speed test: divide vector-vector element by element curly" << std::endl;

    fun_divide_vector_vector_element_by_element_curly(TRIALS, DIM_VEC, SETW);
}
