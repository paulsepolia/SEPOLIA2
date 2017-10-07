#pragma once

#include "vector_dense_declaration.h"
#include "../utilities/exceptions.h"

// allocate memory

template<typename T>
inline void spl::vector_dense<T>::allocate(const uint64_t &dim) {

    if (_is_alloc) delete[] _vdp;

    _dimension = dim;
    _vdp = new T[dim];
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

    if (_is_alloc) delete[] _vdp;

    _dimension = 0;
    _vdp = 0;
    _is_alloc = false;
}

// check deallocation

template<typename T>
inline bool spl::vector_dense<T>::is_deallocated() const {

    return !_is_alloc;
}
