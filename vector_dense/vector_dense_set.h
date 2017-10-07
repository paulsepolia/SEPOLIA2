#pragma once

#include "vector_dense_declaration.h"
#include "vector_dense_aux.h"
#include "../parameters/parameters.h"
#include "../utilities/exceptions.h"

using sepolia::vector_dense;
using pgg::DEBUG;
using pgg::NT1D;

// set_element

template<typename T>
inline void vector_dense<T>::set_element(const uint64_t &index, const T &value) {

    if (DEBUG) {
        check_allocation();
        check_if_is_in_range(index);
    }

    _vdsp.get()[index] = static_cast<T>(value);
}

// set vector to an element

template<typename T>
void vector_dense<T>::set(const T &value) {

    if (DEBUG) {
        check_allocation();
    }

    const uint64_t DIM(get_dimension());
    uint64_t i(0);

#pragma omp parallel default(none)\
        num_threads(NT1D)\
        shared(value)\
        private(i)
    {
#pragma omp for
        for (i = 0; i < DIM; i++) {
            _vdsp.get()[i] = static_cast<T>(value);
        }
    }
}

// set vector to another vector

template<typename T>
void vector_dense<T>::set(const vector_dense<T> &vec) {

    if (DEBUG) {
        vec.check_allocation();
    }

    const uint64_t DIM(vec.get_dimension());
    deallocate();
    allocate(DIM);
    uint64_t i(0);

#pragma omp parallel default(none)\
        num_threads(NT1D)\
        shared(vec)\
        private(i)
    {
#pragma omp for
        for (i = 0; i < DIM; i++) {
            _vdsp.get()[i] = vec._vdsp.get()[i];
        }
    }
}

