#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

#include "tests.h"
#include "functions_speed_test_aux.h"

void tests() {

    // local parameters

    const uint32_t SETW(11);
    const uint64_t DIM_VEC(static_cast<uint64_t>(std::pow(10.0, 4.0)));
    const uint64_t TRIALS(static_cast<uint32_t>(std::pow(10.0, 2.0)));

    //==================//
    // speed tests here //
    //==================//

    //======//
    // plus //
    //======//

    // speed test: add vector-vector using operator +

    fun_display_c();
    cout << "--> speed test: add vector-vector using operator +" << endl;

    fun_add_vector_vector_using_operator(TRIALS, DIM_VEC, SETW);

    // speed test: add vector-vector element by element

    fun_display_c();
    cout << "--> speed test: add vector-vector element by element" << endl;

    fun_add_vector_vector_element_by_element(TRIALS, DIM_VEC, SETW);

    // speed test: add vector-vector plus true

    fun_display_c();
    cout << "--> speed test: add vector-vector plus true" << endl;

    fun_add_vector_vector_plus_true(TRIALS, DIM_VEC, SETW);

    // speed test: add vector-vector plus false

    fun_display_c();
    cout << "--> speed test: add vector-vector plus false" << endl;

    fun_add_vector_vector_plus_false(TRIALS, DIM_VEC, SETW);

    //=======//
    // times //
    //=======//

    // speed test: times vector-vector using operator *

    fun_display_c();
    cout << "--> speed test: times vector-vector using operator *" << endl;

    fun_times_vector_vector_using_operator(TRIALS, DIM_VEC, SETW);

    // speed test: times vector-vector element by element

    fun_display_c();
    cout << "--> speed test: times vector-vector element by element" << endl;

    fun_times_vector_vector_element_by_element(TRIALS, DIM_VEC, SETW);

    // speed test: times vector-vector times true

    fun_display_c();
    cout << "--> speed test: times vector-vector times true" << endl;

    fun_times_vector_vector_times_true(TRIALS, DIM_VEC, SETW);

    // speed test: times vector-vector times false

    fun_display_c();
    cout << "--> speed test: times vector-vector times false" << endl;

    fun_times_vector_vector_times_false(TRIALS, DIM_VEC, SETW);

    //==========//
    // subtract //
    //==========//

    // speed test: subtract vector-vector using operator -

    fun_display_c();
    cout << "--> speed test: subtract vector-vector using operator -" << endl;

    fun_subtract_vector_vector_using_operator(TRIALS, DIM_VEC, SETW);

    // speed test: subtract vector-vector element by element

    fun_display_c();
    cout << "--> speed test: subtract vector-vector element by element" << endl;

    fun_subtract_vector_vector_element_by_element(TRIALS, DIM_VEC, SETW);

    // speed test: subtract vector-vector subtract true

    fun_display_c();
    cout << "--> speed test: subtract vector-vector subtract true" << endl;

    fun_subtract_vector_vector_subtract_true(TRIALS, DIM_VEC, SETW);

    // speed test: subtract vector-vector subtract false

    fun_display_c();
    cout << "--> speed test: subtract vector-vector subtract false" << endl;

    fun_subtract_vector_vector_subtract_false(TRIALS, DIM_VEC, SETW);

    //========//
    // divide //
    //========//

    // speed test: divide vector-vector using operator /

    fun_display_c();
    cout << "--> speed test: divide vector-vector using operator /" << endl;

    fun_divide_vector_vector_using_operator(TRIALS, DIM_VEC, SETW);

    // speed test: divide vector-vector element by element

    fun_display_c();
    cout << "--> speed test: divide vector-vector element by element" << endl;

    fun_divide_vector_vector_element_by_element(TRIALS, DIM_VEC, SETW);

    // speed test: divide vector-vector divide true

    fun_display_c();
    cout << "--> speed test: divide vector-vector divide true" << endl;

    fun_divide_vector_vector_divide_true(TRIALS, DIM_VEC, SETW);

    // speed test: divide vector-vector divide false

    fun_display_c();
    cout << "--> speed test: divide vector-vector divide false" << endl;

    fun_divide_vector_vector_divide_false(TRIALS, DIM_VEC, SETW);
}
