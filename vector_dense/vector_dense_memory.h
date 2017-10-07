#pragma once

#include "vector_dense_declaration.h"
#include "../utilities/utils.h"

// allocate memory

template<typename T>
bool sepolia::vector_dense<T>::allocate(const pgg::uli &dim) {
    _vdsp.reset(new T[dim], std::default_delete<T[]>());
    return static_cast<bool>(_vdsp);
}

// check allocation

template<typename T>
bool sepolia::vector_dense<T>::is_allocated() const {
    return static_cast<bool>(_vdsp);
}

// deallocate memory

template<typename T>
bool sepolia::vector_dense<T>::deallocate() {
    _vdsp.reset();
    return !static_cast<bool>(_vdsp);
}

// check deallocation

template<typename T>
bool sepolia::vector_dense<T>::is_deallocated() const {
    return !static_cast<bool>(_vdsp);
}
