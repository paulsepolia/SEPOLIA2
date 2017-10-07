#include <gtest/gtest.h>
#include <cmath>
#include "../../../vector_dense/vector_dense.h"

// local parameters

const uint64_t DIM(static_cast<uint64_t>(std::pow(10.0, 4.0)));
const double VAL(123.456);

// test constructor with no arguments

TEST(constructor_with_no_arguments, constructors) {

    spl::vector_dense<double> vd;

    EXPECT_EQ(vd.is_allocated(), false);
    EXPECT_EQ(vd.is_deallocated(), true);
}

// test constructor with one argument

TEST(constructor_with_one_argument, constructors) {

    spl::vector_dense<double> vd(DIM);

    EXPECT_EQ(vd.is_allocated(), true);
    EXPECT_EQ(vd.is_deallocated(), false);
}

// test constructor with two arguments

TEST(constructor_with_two_arguments, constructors) {

    spl::vector_dense<double> vd(DIM, VAL);

    EXPECT_EQ(vd.is_allocated(), true);
    EXPECT_EQ(vd.is_deallocated(), false);
}
