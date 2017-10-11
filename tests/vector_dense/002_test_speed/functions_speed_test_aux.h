#pragma once

#include "../../../parameters/parameters.h"

//=======================================//
// help functions to display the results //
//=======================================//

// fun_display_a

void fun_display_a(const uint64_t &, const uint64_t &,
                   const double &, const double_t &, const uint32_t &);

// fun_display_b

void fun_display_b(const uint64_t &, const double &, const double_t &, const uint32_t &);

// fun_display_c

void fun_display_c();

//===========================//
// main test speed functions //
//===========================//

// fun_declaration_via_default_constructor

void fun_declaration_via_default_constructor(const uint64_t &, const uint32_t &);

//=====//
// set //
//=====//

// fun_alloc_set_via_constructor

void fun_alloc_set_via_constructor(const uint64_t &, const uint64_t &, const double &, const uint32_t &);

// fun_alloc_set_dealloc

void fun_alloc_set_dealloc(const uint64_t &, const uint64_t &, const double &, const uint32_t &);

// fun_declaration_via_constructor_full

void fun_declaration_via_constructor_full(const uint64_t &, const uint64_t &, const double &, const uint32_t &);

// fun_set_via_assignment_operator

void fun_set_via_assignment_operator(const uint64_t &, const uint64_t &, const double &, const uint32_t &);

// fun_set_vector_element_by_element

void fun_set_vector_element_by_element(const uint64_t &, const uint64_t &, const uint32_t &);

//=====//
// get //
//=====//

// fun_get_vector_element_by_element_square

void fun_get_vector_element_by_element_square(const uint64_t &, const uint64_t &, const uint32_t &);

// fun_get_vector_element_by_element_curly

void fun_get_vector_element_by_element_curly(const uint64_t &, const uint64_t &, const uint32_t &);

//======//
// plus //
//======//

void fun_add_vector_vector_using_operator(const uint64_t &, const uint64_t &, const uint32_t &);

void fun_add_vector_vector_element_by_element_square(const uint64_t &, const uint64_t &, const uint32_t &);

void fun_add_vector_vector_element_by_element_curly(const uint64_t &, const uint64_t &, const uint32_t &);

//=======//
// times //
//=======//

void fun_times_vector_vector_using_operator(const uint64_t &, const uint64_t &, const uint32_t &);

void fun_times_vector_vector_element_by_element_square(const uint64_t &, const uint64_t &, const uint32_t &);

void fun_times_vector_vector_element_by_element_curly(const uint64_t &, const uint64_t &, const uint32_t &);

//==========//
// subtract //
//==========//

void fun_subtract_vector_vector_using_operator(const uint64_t &, const uint64_t &, const uint32_t &);

void fun_subtract_vector_vector_element_by_element_square(const uint64_t &, const uint64_t &, const uint32_t &);

void fun_subtract_vector_vector_element_by_element_curly(const uint64_t &, const uint64_t &, const uint32_t &);

//========//
// divide //
//========//

void fun_divide_vector_vector_using_operator(const uint64_t &, const uint64_t &, const uint32_t &);

void fun_divide_vector_vector_element_by_element_square(const uint64_t &, const uint64_t &, const uint32_t &);

void fun_divide_vector_vector_element_by_element_curly(const uint64_t &, const uint64_t &, const uint32_t &);