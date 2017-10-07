#pragma once

#include <memory>
#include "vector_dense_declaration.h"
#include "../utilities/utils.h"

// constructor

template<typename T>
sepolia::vector_dense<T>::vector_dense():_dimension(0), _vdsp(0) {}

template<typename T>
sepolia::vector_dense<T>::vector_dense(const pgg::uli &dim, const T &) {
    _vdsp.reset(new T[dim], std::default_delete<T[]>());
    for (pgg::uli j = 0; j < dim; j++) {
        for (pgg::uli i = 0; i < dim; i++) {
            _vdsp.get()[i] = static_cast<T>(i+j);
        }
    }
}

// copy constructor

template<typename T>
sepolia::vector_dense<T>::vector_dense(const vector_dense <T> &vec) :
        _dimension(0), _vdsp(0) {}

// move constructor
