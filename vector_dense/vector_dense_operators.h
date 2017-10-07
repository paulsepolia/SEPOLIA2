#pragma once

#include "vector_dense_declaration.h"

using sepolia::vector_dense;

// copy assignment operator

template<typename T>
vector_dense<T> &vector_dense<T>::operator=(const vector_dense<T> &vec) {

    set(vec);

    return *this;
}

// element assignment operator

template<typename T>
vector_dense<T> &vector_dense<T>::operator=(const T &val) {

    set(val);

    return *this;
}

// move assignment operator

template<typename T>
vector_dense<T> &vector_dense<T>::operator=(vector_dense<T> &&vec) {

    if (this != &vec) {
        deallocate();
        _vdsp = vec._vdsp;
        _dimension = vec._dimension;
        vec.deallocate();
    }

    return *this;
}

// operator + # 1

template<typename T>
vector_dense<T> vector_dense<T>::operator+(const vector_dense<T> &vec) const {

    vector_dense<T> vec_tmp(vec.get_dimension());
    vec_tmp = plus(vec, true);

    return std::move(vec_tmp);
}

// operator + # 2

template<typename T>
vector_dense<T> vector_dense<T>::operator+(const T &val) const {

    vector_dense<T> vec_tmp(get_dimension());
    vec_tmp = plus(val, true);

    return std::move(vec_tmp);
}

// operator + # 3

namespace sepolia {

    template<typename T>
    vector_dense<T> operator+(const T &val, const vector_dense<T> &vec) {

        vector_dense<T> vec_tmp(vec.get_dimension());
        vec_tmp = vec.plus(val, true);

        return std::move(vec_tmp);
    }
}

// operator - # 1

template<typename T>
vector_dense<T> vector_dense<T>::operator-(const vector_dense<T> &vec) const {

    vector_dense<T> vec_tmp(vec.get_dimension());
    vec_tmp = subtract(vec, true);

    return std::move(vec_tmp);
}

// operator - # 2

template<typename T>
vector_dense<T> vector_dense<T>::operator-(const T &val) const {

    vector_dense<T> vec_tmp(get_dimension());
    vec_tmp = subtract(val, true);

    return std::move(vec_tmp);
}

// operator - # 3

namespace sepolia {

    template<typename T>
    vector_dense<T> operator-(const T &val, const vector_dense<T> &vec) {

        vector_dense<T> vec_tmp(vec.get_dimension());
        vec_tmp = vec.subtract(val, true);

        return std::move(vec_tmp);
    }
}

// operator * # 1

template<typename T>
vector_dense<T> vector_dense<T>::operator*(const vector_dense<T> &vec) const {

    vector_dense<T> vec_tmp(vec.get_dimension());
    vec_tmp = times(vec, true);

    return std::move(vec_tmp);
}

// operator * # 2

template<typename T>
vector_dense<T> vector_dense<T>::operator*(const T &val) const {

    vector_dense<T> vec_tmp(get_dimension());
    vec_tmp = times(val, true);

    return std::move(vec_tmp);
}

// operator * # 3

namespace sepolia {

    template<typename T>
    vector_dense<T> operator*(const T &val, const vector_dense<T> &vec) {

        vector_dense<T> vec_tmp(vec.get_dimension());
        vec_tmp = vec.times(val, true);

        return std::move(vec_tmp);
    }
}

// operator / # 1

template<typename T>
vector_dense<T> vector_dense<T>::operator/(const vector_dense<T> &vec) const {

    vector_dense<T> vec_tmp(vec.get_dimension());
    vec_tmp = std::move(divide(vec, true));

    return std::move(vec_tmp);
}

// operator / # 2

template<typename T>
vector_dense<T> vector_dense<T>::operator/(const T &val) const {

    vector_dense<T> vec_tmp(get_dimension());
    vec_tmp = divide(val, true);

    return std::move(vec_tmp);
}

// operator / # 3

namespace sepolia {

    template<typename T>
    vector_dense<T> operator/(const T &val, const vector_dense<T> &vec) {

        vector_dense<T> vec_tmp(vec.get_dimension(), val);

        vec_tmp = vec_tmp.divide(vec, true);

        return std::move(vec_tmp);
    }
}

// operator ()

template<typename T>
inline T vector_dense<T>::operator()(const uint64_t &index) const {

    return _vdsp.get()[index];
}

// operator []

template<typename T>
inline T &vector_dense<T>::operator[](const uint64_t &index) const {

    return _vdsp.get()[index];
}

// operator += # 1

template<typename T>
vector_dense<T> vector_dense<T>::operator+=(const vector_dense<T> &vec) {

    *this = std::move(plus(vec));

    return *this;
}

// operator += # 2

template<typename T>
vector_dense<T> vector_dense<T>::operator+=(const T &val) {

    *this = std::move(plus(val));

    return *this;
}

// operator -= # 1

template<typename T>
vector_dense<T> vector_dense<T>::operator-=(const vector_dense<T> &vec) {

    *this = std::move(subtract(vec));

    return *this;
}

// operator -= # 2

template<typename T>
vector_dense<T> vector_dense<T>::operator-=(const T &val) {

    *this = std::move(subtract(val));

    return *this;
}

// operator *= # 1

template<typename T>
vector_dense<T> vector_dense<T>::operator*=(const vector_dense<T> &vec) {

    *this = std::move(times(vec));

    return *this;
}

// operator *= # 2

template<typename T>
vector_dense<T> vector_dense<T>::operator*=(const T &val) {

    *this = std::move(times(val));

    return *this;
}

// operator /= # 1

template<typename T>
vector_dense<T> vector_dense<T>::operator/=(const vector_dense<T> &vec) {

    *this = std::move(divide(vec));

    return *this;
}

// operator /= # 2

template<typename T>
vector_dense<T> vector_dense<T>::operator/=(const T &val) {

    *this = std::move(divide(val));

    return *this;
}

// operator ++ # 1

template<typename T>
vector_dense<T> vector_dense<T>::operator++() {

    *this = std::move(plus(static_cast<T>(1.0)));

    return *this;
}

// operator ++ # 2

template<typename T>
vector_dense<T> vector_dense<T>::operator++(int) {

    *this = std::move(plus(static_cast<T>(1.0)));

    return *this;
}

// operator -- # 1

template<typename T>
vector_dense<T> vector_dense<T>::operator--() {

    *this = std::move(subtract(static_cast<T>(1.0)));

    return *this;
}

// operator -- # 2

template<typename T>
vector_dense<T> vector_dense<T>::operator--(int) {

    *this = std::move(subtract(static_cast<T>(1.0)));

    return *this;
}

// operator == # 1

template<typename T1>
bool vector_dense<T1>::operator==(const vector_dense<T1> &vec) const {

    return equal_exact(vec);
}

// operator == # 2

template<typename T>
bool vector_dense<T>::operator==(const T &val) const {
    return equal_exact(val);
}

// operator != # 1

template<typename T>
bool vector_dense<T>::operator!=(const vector_dense<T> &vec) const {
    return !equal_exact(vec);
}

// operator != # 2

template<typename T>
bool vector_dense<T>::operator!=(const T &val) const {
    return !equal_exact(val);
}
