#include <gtest/gtest.h>
#include <cmath>
#include "../../../vector_dense/vector_dense.h"
#include "../../../utilities/functions.h"
#include "../../../utilities/exceptions.h"

// local parameters

const uint64_t DIM_COMM(static_cast<const uint64_t>(std::pow(10.0, 4.0)));
const double VAL_COMM(123.456);
const double VAL_TEST1(234.567);
const double VAL_TEST2(765.432);
const uint64_t VAL_TEST3(123456);
const uint64_t VAL_TEST4(876543);
const uint64_t INDEX1(11);
const uint64_t INDEX2(12);

// test add a vector with a number, double case

TEST(vd_test_check_allocation, utils) {

    spl::vector_dense<double> v1;

    EXPECT_THROW(spl::check_allocation(v1), spl::is_not_allocated);
}
