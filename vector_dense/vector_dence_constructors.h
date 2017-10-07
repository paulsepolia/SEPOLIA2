#pragma once

#include <memory>
#include "vector_dense_declaration.h"

// constructor with no arguments

template<typename T>
spl::vector_dense<T>::vector_dense(): _dimension(0), _vdp(0), _is_alloc(false) {}

// constructor with two arguments, the last one is optional

template<typename T>
spl::vector_dense<T>::vector_dense(const uint64_t &dim, const T &val) :
        _dimension(dim), _vdp(new T[dim]), _is_alloc(true) {

    for (uint64_t i = 0; i < dim; i++) {
        _vdp[i] = static_cast<T>(val);
    }
}

// copy constructor

template<typename T>
spl::vector_dense<T>::vector_dense(const spl::vector_dense<T> &vec) :
        _dimension(vec._dimension), _vdp(new T[vec._dimension]), _is_alloc(vec._is_alloc) {

    for (uint64_t i = 0; i < _dimension; i++) {
        _vdp[i] = vec[i];
    }
}

// move constructor

template<typename T>
spl::vector_dense<T>::vector_dense(spl::vector_dense<T> &&vec) :
        _dimension(vec._dimension), _vdp(0), _is_alloc(vec._is_alloc) {

    _vdp = std::move(vec._vdp);
    vec._is_alloc = false;
    vec._dimension = 0;
}

// destructor

template<typename T>
spl::vector_dense<T>::~vector_dense() {
    if (_is_alloc) delete[] _vdp;
    _is_alloc = false;
}