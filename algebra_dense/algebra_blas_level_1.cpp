#include "cblas.h"
#include "algebra_blas_level_1.h"
#include "../parameters/parameters.h"
#include "../utilities/functions.h"

// dot - double precision

double_t sep::dot(const sep::vector_dense<double_t> &vec1,
                  const sep::vector_dense<double_t> &vec2) {

    if (skz::DEBUG) {

        sep::check_allocation(vec1);
        sep::check_allocation(vec2);
        sep::check_equal_size(vec1, vec2);
    }

    const uint64_t DIM(vec1.size());
    const uint64_t ONE(1);

    return cblas_ddot(DIM, &vec1[0], ONE, &vec2[0], ONE);
}

double_t sep::dot(const std::vector<double_t> &vec1,
                  const std::vector<double_t> &vec2) {


    if (skz::DEBUG) {

        sep::check_equal_size(vec1, vec2);
    }

    const uint64_t DIM(vec1.size());
    const uint64_t ONE(1);

    return cblas_ddot(DIM, &vec1[0], ONE, &vec2[0], ONE);
}

// dot - single precision

float_t sep::dot(const sep::vector_dense<float_t> &vec1,
                 const sep::vector_dense<float_t> &vec2) {

    if (skz::DEBUG) {

        sep::check_allocation(vec1);
        sep::check_allocation(vec2);
        sep::check_equal_size(vec1, vec2);
    }

    const uint64_t DIM(vec1.size());
    const uint64_t ONE(1);

    return cblas_sdot(DIM, &vec1[0], ONE, &vec2[0], ONE);
}

float_t sep::dot(const std::vector<float_t> &vec1,
                 const std::vector<float_t> &vec2) {

    if (skz::DEBUG) {

        sep::check_equal_size(vec1, vec2);
    }

    const uint64_t DIM(vec1.size());
    const uint64_t ONE(1);

    return cblas_sdot(DIM, &vec1[0], ONE, &vec2[0], ONE);
}
