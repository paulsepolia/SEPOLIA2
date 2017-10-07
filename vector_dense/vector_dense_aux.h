#pragma once

#include <parallel/algorithm>
#include "vector_dense_declaration.h"
#include "../utilities/exceptions.h"
#include "../parameters/parameters.h"

template<typename T>
inline void spl::vector_dense<T>::vector_dense_transform(spl::vector_dense<T> &vec_in_out,
                                                         std::function<T(T, T)> my_function,
                                                         const bool &par_flag) const {

    if (par_flag) {
        std::__parallel::transform(_vdp,
                                   _vdp + _dimension,
                                   vec_in_out._vdp,
                                   vec_in_out._vdp,
                                   my_function);
    } else {
        std::__parallel::transform(_vdp,
                                   _vdp + _dimension,
                                   vec_in_out._vdp,
                                   vec_in_out._vdp,
                                   my_function,
                                   __gnu_parallel::sequential_tag());
    }
}

template<typename T>
inline void spl::vector_dense<T>::vector_dense_transform(const spl::vector_dense<T> &vec_in,
                                                         spl::vector_dense<T> &vec_out,
                                                         std::function<T(T, T)> my_function,
                                                         const bool &par_flag) const {
    if (par_flag) {
        std::__parallel::transform(_vdp,
                                   _vdp + _dimension,
                                   vec_in._vdp,
                                   vec_out._vdp,
                                   my_function);
    } else {
        std::__parallel::transform(_vdp,
                                   _vdp + _dimension,
                                   vec_in._vdp,
                                   vec_out._vdp,
                                   my_function,
                                   __gnu_parallel::sequential_tag());
    }
}

template<typename T>
bool spl::vector_dense<T>::equal_exact(const spl::vector_dense<T> &vec) const {
    if (_dimension != vec._dimension) return false;

    bool flg(false);
    const uint64_t DIM(_dimension);
    uint64_t i(0);

#pragma omp parallel default(none)\
        num_threads(skz::NT1D)\
        private(i)\
        shared(vec)\
        shared(flg)
    {
#pragma omp for
        for (i = 0; i < DIM; i++) {

            if (!(_vdp[i] < vec._vdp[i]) &&
                !(_vdp[i] > vec._vdp[i])) {
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
bool spl::vector_dense<T>::equal_exact(const T &val) const {

    if (_dimension == 0) return false;

    spl::vector_dense<T> vec_tmp(_dimension, val);

    return equal_exact(vec_tmp);
}
