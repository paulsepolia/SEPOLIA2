//#pragma once
//
//#include "vector_dense_declaration.h"
//#include "../parameters/parameters.h"
//#include "../utilities/functions.h"
//
//// at
//
//template<typename T>
//T &spl::vector_dense<T>::at(const uint64_t &index) {
//
//    if (skz::DEBUG) {
//        spl::check_allocation(*this);
//        spl::check_if_is_in_range(this->size(), index);
//    }
//
//    return _vdp[index];
//}
//
//template<typename T>
//const T &spl::vector_dense<T>::at(const uint64_t &index) const {
//
//    if (skz::DEBUG) {
//        spl::check_allocation(*this);
//        spl::check_if_is_in_range(this->size(), index);
//    }
//
//    return _vdp[index];
//}
//
//// back
//
//template<typename T>
//T &spl::vector_dense<T>::back() {
//
//    if (skz::DEBUG) {
//        spl::check_allocation(*this);
//    }
//
//    return *(_vdp + _dimension - 1);
//}
//
//template<typename T>
//const T &spl::vector_dense<T>::back() const {
//
//    if (skz::DEBUG) {
//        spl::check_allocation(*this);
//    }
//
//    return *(_vdp + _dimension - 1);
//}
//
//// begin
//
//template<typename T>
//T *spl::vector_dense<T>::begin() {
//
//    if (skz::DEBUG) {
//        spl::check_allocation(*this);
//    }
//
//    return _vdp;
//}
//
//template<typename T>
//const T *spl::vector_dense<T>::begin() const {
//
//    if (skz::DEBUG) {
//        spl::check_allocation(*this);
//    }
//
//    return _vdp;
//}
//
//// clear
//
//template<typename T>
//void spl::vector_dense<T>::clear() noexcept {
//
//    this->deallocate();
//}
//
//// empty
//
//template<typename T>
//bool spl::vector_dense<T>::empty() const noexcept {
//
//    return _dimension == 0;
//}
//
//// end
//
//template<typename T>
//T *spl::vector_dense<T>::end() {
//
//    if (skz::DEBUG) {
//        spl::check_allocation(*this);
//    }
//
//    return _vdp + _dimension;
//}
//
//template<typename T>
//const T *spl::vector_dense<T>::end() const {
//
//    if (skz::DEBUG) {
//        spl::check_allocation(*this);
//    }
//
//    return _vdp + _dimension;
//}
//
//// front
//
//template<typename T>
//T &spl::vector_dense<T>::front() {
//
//    if (skz::DEBUG) {
//        spl::check_allocation(*this);
//    }
//
//    return *_vdp;
//}
//
//template<typename T>
//const T &spl::vector_dense<T>::front() const {
//
//    if (skz::DEBUG) {
//        spl::check_allocation(*this);
//    }
//
//    return *_vdp;
//}
//
//// size
//
//template<typename T>
//uint64_t spl::vector_dense<T>::size() const noexcept {
//
//    return _dimension;
//}
//
//// swap
//
//template<typename T>
//void spl::vector_dense<T>::swap(spl::vector_dense<T> &vec_in) {
//
//    spl::vector_dense<T> vec_tmp(std::move(*this));
//    *this = std::move(vec_in);
//    vec_in = std::move(vec_tmp);
//}
