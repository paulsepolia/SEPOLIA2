//#pragma once
//
//#include "vector_dense_declaration.h"
//#include "../parameters/parameters.h"
//#include "../utilities/exceptions.h"
//#include "../utilities/functions.h"
//
//// get_element
//
//template<typename T>
//inline T spl::vector_dense<T>::get_element(const uint64_t &index) const {
//
//    if (skz::DEBUG) {
//        spl::check_allocation(*this);
//        spl::check_if_is_in_range(this->size(), index);
//    }
//
//    return _vdp[index];
//}
