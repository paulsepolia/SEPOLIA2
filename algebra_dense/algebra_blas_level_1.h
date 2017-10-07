#pragma once

#include <vector>
#include "../vector_dense/vector_dense.h"

namespace spl {

    // dot - double

    double dot(const spl::vector_dense<double> &, const spl::vector_dense<double> &);

    double dot(const std::vector<double> &, const std::vector<double> &);

    // dot - single

    float_t dot(const spl::vector_dense<float_t> &, const spl::vector_dense<float_t> &);

    float_t dot(const std::vector<float_t> &, const std::vector<float_t> &);
}