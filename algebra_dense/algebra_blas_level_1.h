#pragma once

#include <vector>
#include "../vector_dense/vector_dense.h"

namespace sep {

    // dot - double

    double dot(const sep::vector_dense<double> &, const sep::vector_dense<double> &);

    double dot(const std::vector<double> &, const std::vector<double> &);

    // dot - single

    float_t dot(const sep::vector_dense<float_t> &, const sep::vector_dense<float_t> &);

    float_t dot(const std::vector<float_t> &, const std::vector<float_t> &);
}