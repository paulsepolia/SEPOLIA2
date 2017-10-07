#pragma once

#include <memory>
#include "vector_dense_declaration.h"

using sepolia::vector_dense;

// constructor with no arguments

template<typename T>
vector_dense<T>::vector_dense():_dimension(0), _vdsp(0) {}

// constructor with two arguments, the last one is optional

template<typename T>
vector_dense<T>::vector_dense(const uint64_t &dim, const T &val) {

    _dimension = dim;

    _vdsp.reset(new T[dim], std::default_delete<T[]>());

    for (uint64_t i = 0; i < dim; i++) {
        _vdsp.get()[i] = static_cast<T>(val);
    }
}

// copy constructor

template<typename T>
vector_dense<T>::vector_dense(const vector_dense<T> &vec) :
        _dimension(vec._dimension),
        _vdsp(0) {

    _vdsp.reset(new T[this->_dimension], std::default_delete<T[]>());

    for (uint64_t i = 0; i < this->_dimension; i++) {
        _vdsp.get()[i] = vec._vdsp.get()[i];
    }
}

// move constructor

template<typename T>
vector_dense<T>::vector_dense(vector_dense<T> &&vec) :
        _dimension(vec._dimension),
        _vdsp(0) {

    _vdsp.reset(new T[this->_dimension], std::default_delete<T[]>());
    _vdsp = vec._vdsp;
    _dimension = vec._dimension;
    vec.deallocate();
}
