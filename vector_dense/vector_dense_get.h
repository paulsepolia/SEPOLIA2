#pragma once

#include "vector_dense_declaration.h"
#include "../parameters/parameters.h"
#include "../utilities/exceptions.h"

using sepolia::vector_dense;
using pgg::DEBUG;

// get_dimension

template<typename T>
inline uint64_t vector_dense<T>::get_dimension() const {

    return _dimension;
}

// get_element

template<typename T>
inline T vector_dense<T>::get_element(const uint64_t &index) const {

    if (DEBUG) {
        check_allocation();
        check_if_is_in_range(index);
    }

    return _vdsp.get()[index];
}
