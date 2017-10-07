#pragma once

#include <parallel/algorithm>
#include "vector_dense_declaration.h"
#include "../utilities/exceptions.h"
#include "../parameters/parameters.h"

using sepolia::vector_dense;
using pgg::NT1D;

template<typename T>
inline void vector_dense<T>::check_allocation() const {
    if (is_deallocated()) throw is_not_allocated();
}

template<typename T>
inline void vector_dense<T>::check_if_is_in_range(const uint64_t &index) const {
    if (index >= _dimension) throw index_out_of_range();
}

template<typename T>
inline void vector_dense<T>::vector_dense_transform(vector_dense<T> &vec_in_out,
                                                    std::function<T(T, T)> my_function,
                                                    const bool &par_flag) const {

    if (par_flag) {
        std::__parallel::transform(&_vdsp.get()[0],
                                   &_vdsp.get()[_dimension],
                                   &vec_in_out._vdsp.get()[0],
                                   &vec_in_out._vdsp.get()[0],
                                   my_function);
    } else {
        std::__parallel::transform(&_vdsp.get()[0],
                                   &_vdsp.get()[_dimension],
                                   &vec_in_out._vdsp.get()[0],
                                   &vec_in_out._vdsp.get()[0],
                                   my_function,
                                   __gnu_parallel::sequential_tag());
    }
}

template<typename T>
inline void vector_dense<T>::vector_dense_transform(const vector_dense<T> &vec_in,
                                                    vector_dense<T> &vec_out,
                                                    std::function<T(T, T)> my_function,
                                                    const bool &par_flag) const {
    if (par_flag) {
        std::__parallel::transform(&_vdsp.get()[0],
                                   &_vdsp.get()[_dimension],
                                   &vec_in._vdsp.get()[0],
                                   &vec_out._vdsp.get()[0],
                                   my_function);
    } else {
        std::__parallel::transform(&_vdsp.get()[0],
                                   &_vdsp.get()[_dimension],
                                   &vec_in._vdsp.get()[0],
                                   &vec_out._vdsp.get()[0],
                                   my_function,
                                   __gnu_parallel::sequential_tag());
    }
}

template<typename T>
bool vector_dense<T>::equal_exact(const vector_dense<T> &vec) const {
    if (_dimension != vec._dimension) return false;

    bool flg(false);
    const uint64_t DIM(_dimension);
    uint64_t i(0);

#pragma omp parallel default(none)\
        num_threads(NT1D)\
        private(i)\
        shared(vec)\
        shared(flg)
    {
#pragma omp for
        for (i = 0; i < DIM; i++) {

            if (!(_vdsp.get()[i] < vec._vdsp.get()[i]) &&
                !(_vdsp.get()[i] > vec._vdsp.get()[i])) {
#pragma omp critical
                    flg = true;
#pragma omp cancel for
            }
#pragma omp cancellation point for
        }
    }

    return flg;
}

template<typename T>
bool vector_dense<T>::equal_exact(const T &val) const {

    if (_dimension == 0) return false;

    vector_dense<T> vec_tmp(_dimension, val);

    return equal_exact(vec_tmp);
}
