#pragma once

#include "vector_dense_declaration.h"
#include "vector_dense_aux.h"

// plus

template<typename T>
spl::vector_dense<T> spl::vector_dense<T>::plus(const T &val,
                                                const bool &par_flag) const {

    spl::vector_dense<T> vec_out(size(), val);

    vector_dense_transform(vec_out, std::plus<T>(), par_flag);

    return std::move(vec_out);
}

// plus

template<typename T>
spl::vector_dense<T> spl::vector_dense<T>::plus(const spl::vector_dense<T> &vec_in,
                                                const bool &par_flag) const {

    spl::vector_dense<T> vec_out(size(), static_cast<T>(0.0));

    vector_dense_transform(vec_in, vec_out, std::plus<T>(), par_flag);

    return std::move(vec_out);
}

// times

template<typename T>
spl::vector_dense<T> spl::vector_dense<T>::times(const T &val,
                                                 const bool &par_flag) const {

    spl::vector_dense<T> vec_out(size(), val);

    vector_dense_transform(vec_out, std::multiplies<T>(), par_flag);

    return std::move(vec_out);
}

// times

template<typename T>
spl::vector_dense<T> spl::vector_dense<T>::times(const spl::vector_dense<T> &vec_in,
                                                 const bool &par_flag) const {

    spl::vector_dense<T> vec_out(size(), static_cast<T>(0.0));

    vector_dense_transform(vec_in, vec_out, std::multiplies<T>(), par_flag);

    return std::move(vec_out);
}


// subtract

template<typename T>
spl::vector_dense<T> spl::vector_dense<T>::subtract(const T &val,
                                                    const bool &par_flag) const {

    spl::vector_dense<T> vec_out(size(), val);

    vector_dense_transform(vec_out, std::minus<T>(), par_flag);

    return std::move(vec_out);
}

// subtract

template<typename T>
spl::vector_dense<T> spl::vector_dense<T>::subtract(const spl::vector_dense<T> &vec_in,
                                                    const bool &par_flag) const {

    spl::vector_dense<T> vec_out(size(), static_cast<T>(0.0));

    vector_dense_transform(vec_in, vec_out, std::minus<T>(), par_flag);

    return std::move(vec_out);
}

// divide

template<typename T>
spl::vector_dense<T> spl::vector_dense<T>::divide(const T &val, const bool &par_flag) const {

    spl::vector_dense<T> vec_out(size(), val);

    vector_dense_transform(vec_out, std::divides<T>(), par_flag);

    return std::move(vec_out);
}

// divide

template<typename T>
spl::vector_dense<T> spl::vector_dense<T>::divide(const spl::vector_dense<T> &vec_in,
                                                  const bool &par_flag) const {

    spl::vector_dense<T> vec_out(size(), static_cast<T>(0.0));

    vector_dense_transform(vec_in, vec_out, std::divides<T>(), par_flag);

    return std::move(vec_out);
}
