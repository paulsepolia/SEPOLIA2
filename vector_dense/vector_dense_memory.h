#pragma once

#include "vector_dense_declaration.h"
#include "../utilities/exceptions.h"

using sepolia::vector_dense;

// allocate memory

template<typename T>
inline bool vector_dense<T>::allocate(const uint64_t &dim) {

    _vdsp.reset(new T[dim], std::default_delete<T[]>());
    _dimension = dim;

    return static_cast<bool>(_vdsp);
}

// is allocated

template<typename T>
inline bool vector_dense<T>::is_allocated() const {

    return static_cast<bool>(_vdsp);
}

// deallocate memory

template<typename T>
inline bool vector_dense<T>::deallocate() {

    _vdsp.reset();
    _dimension = 0;

    return !static_cast<bool>(_vdsp);
}

// check deallocation

template<typename T>
inline bool vector_dense<T>::is_deallocated() const {

    return !static_cast<bool>(_vdsp);
}
