#pragma once

#include "../vector_dense/vector_dense.h"
#include "exceptions.h"

namespace spl {

    template<typename T>
    inline void check_allocation(const vector_dense<T> &vec) {

        if (!vec.is_allocated()) throw is_not_allocated();
    }

    template<typename T>
    inline void check_equal_size(const vector_dense<T> &vec1, const vector_dense<T> &vec2) {

        if (vec1.size() != vec2.size()) throw vectors_are_not_of_equal_size();
    }

    template<typename T>
    inline void check_equal_size(const std::vector<T> &vec1, const std::vector<T> &vec2) {

        if (vec1.size() != vec2.size()) throw vectors_are_not_of_equal_size();
    }

    inline void check_if_is_in_range(const uint64_t &size, const uint64_t &index) {

        if (index >= size) throw index_out_of_range();
    }

}