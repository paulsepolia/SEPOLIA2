#pragma once

#include <memory>
#include "vector_dense_declaration.h"

// constructor with no arguments

template<typename T>
spl::vector_dense<T>::vector_dense(): _dimension(0),
                                      _is_alloc(false) {

    _vdsp.reset();
}

// constructor with two arguments, the last one is optional

template<typename T>
spl::vector_dense<T>::vector_dense(const uint64_t &dim, const T &val) :
        _dimension(dim),
        _is_alloc(true) {

    _vdsp.reset(new T[dim]);

    const auto tmp(_vdsp.get());

    for (uint64_t i = 0; i < dim; i++) {
        tmp[i] = static_cast<T>(val);
    }
}

// copy constructor

template<typename T>
spl::vector_dense<T>::vector_dense(const spl::vector_dense<T> &vec) :
        _dimension(vec._dimension),
        _is_alloc(vec._is_alloc) {

    _vdsp.reset(new T[vec._dimension]);

    const auto tmp1(_vdsp.get());
    const auto tmp2(vec._vdsp.get());

    for (uint64_t i = 0; i < _dimension; i++) {
        tmp1[i] = tmp2[i];
    }
}

// move constructor

template<typename T>
spl::vector_dense<T>::vector_dense(spl::vector_dense<T> &&vec) noexcept :
        _dimension(vec._dimension),
        _is_alloc(vec._is_alloc) {

    _vdsp.reset();
    _vdsp = std::move(vec._vdsp.get());
    vec._is_alloc = false;
    vec._dimension = 0;
}

// destructor

template<typename T>
spl::vector_dense<T>::~vector_dense() {
    _vdsp.reset();
}