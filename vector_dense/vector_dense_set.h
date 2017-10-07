#pragma once

#include "vector_dense_declaration.h"
#include "vector_dense_aux.h"
#include "../parameters/parameters.h"
#include "../utilities/exceptions.h"
#include "../utilities/functions.h"

// set_element

template<typename T>
inline void sep::vector_dense<T>::set_element(const uint64_t &index, const T &value) {

    if (skz::DEBUG) {
        sep::check_allocation(*this);
        sep::check_if_is_in_range(this->size(), index);
    }

    _vdsp.get()[index] = static_cast<T>(value);
}

// set vector to an element

template<typename T>
void sep::vector_dense<T>::set(const T &value) {

    if (skz::DEBUG) {
        sep::check_allocation(*this);
    }

    const uint64_t DIM(size());
    uint64_t i(0);
    const auto tmp(_vdsp.get());

#pragma omp parallel default(none)\
        num_threads(skz::NT1D)\
        shared(value)\
        private(i)
    {
#pragma omp for
        for (i = 0; i < DIM; i++) {
            tmp[i] = static_cast<T>(value);
        }
    }
}

// set vector to another vector

template<typename T>
void sep::vector_dense<T>::set(const sep::vector_dense<T> &vec) {

    if (skz::DEBUG) {
        sep::check_allocation(vec);
    }

    const uint64_t DIM(vec.size());
    deallocate();
    allocate(DIM);
    uint64_t i(0);
    const auto tmp1(_vdsp.get());
    const auto tmp2(vec._vdsp.get());

#pragma omp parallel default(none)\
        num_threads(skz::NT1D)\
        shared(vec)\
        private(i)
    {
#pragma omp for
        for (i = 0; i < DIM; i++) {
            tmp1[i] = tmp2[i];
        }
    }
}
