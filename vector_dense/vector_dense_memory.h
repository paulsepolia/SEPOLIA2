#pragma once

#include "vector_dense_declaration.h"
#include "../utilities/exceptions.h"

// allocate memory

template<typename T>
inline void spl::vector_dense<T>::allocate(const uint64_t &dim) {

    _dimension = dim;
    _vdsp.reset(new T[dim]);
    _is_alloc = true;
}

// is allocated

template<typename T>
inline bool spl::vector_dense<T>::is_allocated() const {

    return _is_alloc;
}

// deallocate memory

template<typename T>
inline void spl::vector_dense<T>::deallocate() {

    _dimension = 0;
    _vdsp.reset();
    _is_alloc = false;
}

// check deallocation

template<typename T>
inline bool spl::vector_dense<T>::is_deallocated() const {

    return !_is_alloc;
}
