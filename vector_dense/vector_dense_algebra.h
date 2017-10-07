#pragma once

#include "vector_dense_declaration.h"
#include "vector_dense_aux.h"

using sepolia::vector_dense;

// plus

template<typename T>
vector_dense<T> vector_dense<T>::plus(const T &val,
                                      const bool &par_flag) const {

    vector_dense<T> vec_out(get_dimension(), val);

    vector_dense_transform(vec_out, std::plus<T>(), par_flag);

    return std::move(vec_out);
}

// plus

template<typename T>
vector_dense<T> vector_dense<T>::plus(const vector_dense<T> &vec_in,
                                      const bool &par_flag) const {

    vector_dense<T> vec_out(get_dimension(), static_cast<T>(0.0));

    vector_dense_transform(vec_in, vec_out, std::plus<T>(), par_flag);

    return std::move(vec_out);
}

// times

template<typename T>
vector_dense<T> vector_dense<T>::times(const T &val,
                                       const bool &par_flag) const {

    vector_dense<T> vec_out(get_dimension(), val);

    vector_dense_transform(vec_out, std::multiplies<T>(), par_flag);

    return std::move(vec_out);
}

// times

template<typename T>
vector_dense<T> vector_dense<T>::times(const vector_dense<T> &vec_in,
                                       const bool &par_flag) const {

    vector_dense<T> vec_out(get_dimension(), static_cast<T>(0.0));

    vector_dense_transform(vec_in, vec_out, std::multiplies<T>(), par_flag);

    return std::move(vec_out);
}


// subtract

template<typename T>
vector_dense<T> vector_dense<T>::subtract(const T &val,
                                          const bool &par_flag) const {

    vector_dense<T> vec_out(get_dimension(), val);

    vector_dense_transform(vec_out, std::minus<T>(), par_flag);

    return std::move(vec_out);
}

// subtract

template<typename T>
vector_dense<T> vector_dense<T>::subtract(const vector_dense<T> &vec_in,
                                          const bool &par_flag) const {

    vector_dense<T> vec_out(get_dimension(), static_cast<T>(0.0));

    vector_dense_transform(vec_in, vec_out, std::minus<T>(), par_flag);

    return std::move(vec_out);
}

// divide

template<typename T>
vector_dense<T> vector_dense<T>::divide(const T &val, const bool &par_flag) const {

    vector_dense<T> vec_out(get_dimension(), val);

    vector_dense_transform(vec_out, std::divides<T>(), par_flag);

    return std::move(vec_out);
}

// divide

template<typename T>
vector_dense<T> vector_dense<T>::divide(const vector_dense<T> &vec_in,
                                        const bool &par_flag) const {

    vector_dense<T> vec_out(get_dimension(), static_cast<T>(0.0));

    vector_dense_transform(vec_in, vec_out, std::divides<T>(), par_flag);

    return std::move(vec_out);
}
