//#pragma once
//
//#include "vector_dense_declaration.h"
//#include "../parameters/parameters.h"
//#include "../utilities/functions.h"
//
//// copy std::vector assignment operator
//
//template<typename T>
//spl::vector_dense<T> &spl::vector_dense<T>::operator=(const std::vector<T> &vec_std) {
//
//    const auto DIM(vec_std.size());
//
//    this->deallocate();
//    this->allocate(DIM);
//
//    std::copy(vec_std.begin(), vec_std.end(), this->begin());
//
//    return *this;
//}
//
//// move std::vector assignment operator
//
//template<typename T>
//spl::vector_dense<T> &spl::vector_dense<T>::operator=(std::vector<T> &&vec_std) {
//
//    const auto DIM(vec_std.size());
//
//    this->deallocate();
//    this->allocate(DIM);
//
//    std::move(vec_std.begin(), vec_std.end(), this->begin());
//
//    return *this;
//}
//
//// copy assignment operator
//
//template<typename T>
//spl::vector_dense<T> &spl::vector_dense<T>::operator=(const spl::vector_dense<T> &vec) {
//
//    if (skz::DEBUG) {
//        spl::check_allocation(vec);
//    }
//
//    set(vec);
//
//    return *this;
//}
//
//// element assignment operator
//
//template<typename T>
//spl::vector_dense<T> &spl::vector_dense<T>::operator=(const T &val) {
//
//    if (skz::DEBUG) {
//        spl::check_allocation(*this);
//    }
//
//    set(val);
//
//    return *this;
//}
//
//// move assignment operator
//
//template<typename T>
//spl::vector_dense<T> &spl::vector_dense<T>::operator=(spl::vector_dense<T> &&vec) {
//
//    if (skz::DEBUG) {
//        spl::check_allocation(vec);
//    }
//
//    if (this != &vec) {
//        deallocate();
//        _vdp = vec._vdp;
//        _is_alloc = vec._is_alloc;
//        _dimension = vec._dimension;
//        vec._dimension = 0;
//        vec._is_alloc = false;
//    }
//
//    return *this;
//}
//
//// operator + # 1
//
//template<typename T>
//spl::vector_dense<T> spl::vector_dense<T>::operator+(const spl::vector_dense<T> &vec) const {
//
//    spl::vector_dense<T> vec_tmp(vec.size());
//    vec_tmp = plus(vec, true);
//
//    return std::move(vec_tmp);
//}
//
//// operator + # 2
//
//template<typename T>
//spl::vector_dense<T> spl::vector_dense<T>::operator+(const T &val) const {
//
//    spl::vector_dense<T> vec_tmp(size());
//    vec_tmp = plus(val, true);
//
//    return std::move(vec_tmp);
//}
//
//// operator + # 3
//
//namespace spl {
//
//    template<typename T>
//    vector_dense <T> operator+(const T &val, const vector_dense <T> &vec) {
//
//        vector_dense<T> vec_tmp(vec.size());
//        vec_tmp = vec.plus(val, true);
//
//        return std::move(vec_tmp);
//    }
//}
//
//// operator - # 1
//
//template<typename T>
//spl::vector_dense<T> spl::vector_dense<T>::operator-(const spl::vector_dense<T> &vec) const {
//
//    spl::vector_dense<T> vec_tmp(vec.size());
//    vec_tmp = subtract(vec, true);
//
//    return std::move(vec_tmp);
//}
//
//// operator - # 2
//
//template<typename T>
//spl::vector_dense<T> spl::vector_dense<T>::operator-(const T &val) const {
//
//    spl::vector_dense<T> vec_tmp(size());
//    vec_tmp = subtract(val, true);
//
//    return std::move(vec_tmp);
//}
//
//// operator - # 3
//
//namespace spl {
//
//    template<typename T>
//    vector_dense <T> operator-(const T &val, const vector_dense <T> &vec) {
//
//        vector_dense<T> vec_tmp(vec.size());
//        vec_tmp = vec.subtract(val, true);
//
//        return std::move(vec_tmp);
//    }
//}
//
//// operator * # 1
//
//template<typename T>
//spl::vector_dense<T> spl::vector_dense<T>::operator*(const spl::vector_dense<T> &vec) const {
//
//    spl::vector_dense<T> vec_tmp(vec.size());
//    vec_tmp = times(vec, true);
//
//    return std::move(vec_tmp);
//}
//
//// operator * # 2
//
//template<typename T>
//spl::vector_dense<T> spl::vector_dense<T>::operator*(const T &val) const {
//
//    spl::vector_dense<T> vec_tmp(size());
//    vec_tmp = times(val, true);
//
//    return std::move(vec_tmp);
//}
//
//// operator * # 3
//
//namespace spl {
//
//    template<typename T>
//    vector_dense <T> operator*(const T &val, const vector_dense <T> &vec) {
//
//        vector_dense<T> vec_tmp(vec.size());
//        vec_tmp = vec.times(val, true);
//
//        return std::move(vec_tmp);
//    }
//}
//
//// operator / # 1
//
//template<typename T>
//spl::vector_dense<T> spl::vector_dense<T>::operator/(const spl::vector_dense<T> &vec) const {
//
//    spl::vector_dense<T> vec_tmp(vec.size());
//    vec_tmp = std::move(divide(vec, true));
//
//    return std::move(vec_tmp);
//}
//
//// operator / # 2
//
//template<typename T>
//spl::vector_dense<T> spl::vector_dense<T>::operator/(const T &val) const {
//
//    spl::vector_dense<T> vec_tmp(size());
//    vec_tmp = divide(val, true);
//
//    return std::move(vec_tmp);
//}
//
//// operator / # 3
//
//namespace spl {
//
//    template<typename T>
//    vector_dense <T> operator/(const T &val, const vector_dense <T> &vec) {
//
//        vector_dense<T> vec_tmp(vec.size(), val);
//
//        vec_tmp = vec_tmp.divide(vec, true);
//
//        return std::move(vec_tmp);
//    }
//}
//
//// operator ()
//
//template<typename T>
//inline T spl::vector_dense<T>::operator()(const uint64_t &index) const {
//
//    if (skz::DEBUG) {
//        spl::check_allocation(*this);
//        spl::check_if_is_in_range(this->size(), index);
//    }
//
//    return _vdp[index];
//}
//
//// operator []
//
//template<typename T>
//inline T &spl::vector_dense<T>::operator[](const uint64_t &index) const {
//
//    if (skz::DEBUG) {
//        spl::check_allocation(*this);
//        spl::check_if_is_in_range(this->size(), index);
//    }
//
//    return _vdp[index];
//}
//
//// operator += # 1
//
//template<typename T>
//spl::vector_dense<T> spl::vector_dense<T>::operator+=(const spl::vector_dense<T> &vec) {
//
//    *this = std::move(plus(vec));
//
//    return *this;
//}
//
//// operator += # 2
//
//template<typename T>
//spl::vector_dense<T> spl::vector_dense<T>::operator+=(const T &val) {
//
//    *this = std::move(plus(val));
//
//    return *this;
//}
//
//// operator -= # 1
//
//template<typename T>
//spl::vector_dense<T> spl::vector_dense<T>::operator-=(const spl::vector_dense<T> &vec) {
//
//    *this = std::move(subtract(vec));
//
//    return *this;
//}
//
//// operator -= # 2
//
//template<typename T>
//spl::vector_dense<T> spl::vector_dense<T>::operator-=(const T &val) {
//
//    *this = std::move(subtract(val));
//
//    return *this;
//}
//
//// operator *= # 1
//
//template<typename T>
//spl::vector_dense<T> spl::vector_dense<T>::operator*=(const spl::vector_dense<T> &vec) {
//
//    *this = std::move(times(vec));
//
//    return *this;
//}
//
//// operator *= # 2
//
//template<typename T>
//spl::vector_dense<T> spl::vector_dense<T>::operator*=(const T &val) {
//
//    *this = std::move(times(val));
//
//    return *this;
//}
//
//// operator /= # 1
//
//template<typename T>
//spl::vector_dense<T> spl::vector_dense<T>::operator/=(const spl::vector_dense<T> &vec) {
//
//    *this = std::move(divide(vec));
//
//    return *this;
//}
//
//// operator /= # 2
//
//template<typename T>
//spl::vector_dense<T> spl::vector_dense<T>::operator/=(const T &val) {
//
//    *this = std::move(divide(val));
//
//    return *this;
//}
//
//// operator ++ # 1
//
//template<typename T>
//spl::vector_dense<T> spl::vector_dense<T>::operator++() {
//
//    *this = std::move(plus(static_cast<T>(1.0)));
//
//    return *this;
//}
//
//// operator ++ # 2
//
//template<typename T>
//spl::vector_dense<T> spl::vector_dense<T>::operator++(int) {
//
//    *this = std::move(plus(static_cast<T>(1.0)));
//
//    return *this;
//}
//
//// operator -- # 1
//
//template<typename T>
//spl::vector_dense<T> spl::vector_dense<T>::operator--() {
//
//    *this = std::move(subtract(static_cast<T>(1.0)));
//
//    return *this;
//}
//
//// operator -- # 2
//
//template<typename T>
//spl::vector_dense<T> spl::vector_dense<T>::operator--(int) {
//
//    *this = std::move(subtract(static_cast<T>(1.0)));
//
//    return *this;
//}
//
//// operator == # 1
//
//template<typename T1>
//bool spl::vector_dense<T1>::operator==(const spl::vector_dense<T1> &vec) const {
//
//    return equal_exact(vec);
//}
//
//// operator == # 2
//
//template<typename T>
//bool spl::vector_dense<T>::operator==(const T &val) const {
//    return equal_exact(val);
//}
//
//// operator != # 1
//
//template<typename T>
//bool spl::vector_dense<T>::operator!=(const spl::vector_dense<T> &vec) const {
//    return !equal_exact(vec);
//}
//
//// operator != # 2
//
//template<typename T>
//bool spl::vector_dense<T>::operator!=(const T &val) const {
//    return !equal_exact(val);
//}
