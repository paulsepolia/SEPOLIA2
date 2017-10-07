#include <gtest/gtest.h>
#include <cmath>
#include "../../../vector_dense/vector_dense.h"

// local parameters

const uint64_t DIM_COMM(static_cast<uint64_t>(std::pow(10.0, 4.0)));
const double VAL_COMM(123.456);

// test constructor with no arguments

TEST(constructor_with_no_arguments, constructors) {

    spl::vector_dense<double> vd;

    EXPECT_EQ(vd.is_allocated(), false);
    EXPECT_EQ(vd.is_deallocated(), true);
}

// test constructor with two arguments but one active

TEST(constructor_with_tow_arguments_one_set, constructors) {

    spl::vector_dense<double> vd(DIM_COMM);

    EXPECT_EQ(vd.is_allocated(), true);
    EXPECT_EQ(vd.is_deallocated(), false);
}

// test constructor with two arguments

TEST(constructor_with_two_arguments, constructors) {

    spl::vector_dense<double> vd(DIM_COMM, VAL_COMM);

    EXPECT_EQ(vd.is_allocated(), true);
    EXPECT_EQ(vd.is_deallocated(), false);
}
