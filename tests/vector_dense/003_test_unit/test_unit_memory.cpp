#include <gtest/gtest.h>
#include <cmath>
#include "../../../vector_dense/vector_dense.h"

// local parameters

const uint64_t DIM(static_cast<uint64_t>(std::pow(10.0, 4.0)));
const double VAL(123.456);

// test is_allocated, is_deallocated, allocate and deallocate

TEST(vd_is_allocated_deallocated_allocate_deallocate, memory) {

    sep::vector_dense<double> vd;

    EXPECT_EQ(vd.is_allocated(), false);
    EXPECT_EQ(vd.is_deallocated(), true);

    vd.allocate(DIM);

    EXPECT_EQ(vd.is_allocated(), true);
    EXPECT_EQ(vd.is_deallocated(), false);

    vd.deallocate();

    EXPECT_EQ(vd.is_allocated(), false);
    EXPECT_EQ(vd.is_deallocated(), true);
}

// test is_allocated, is_deallocated,
// allocate and deallocate via constructor with one argument

TEST(vd_allocate_deallocate_constructor_one_argument, memory) {

    sep::vector_dense<double> vd(DIM);

    EXPECT_TRUE(vd.is_allocated());
    EXPECT_FALSE(vd.is_deallocated());

    vd.deallocate();

    EXPECT_FALSE(vd.is_allocated());
    EXPECT_TRUE(vd.is_deallocated());
}

// test is_allocated, is_deallocated,
// allocate and deallocate via constructor with two arguments

TEST(vd_allocate_deallocate_constructor_two_arguments, memory) {

    sep::vector_dense<double> vd(DIM, VAL);

    EXPECT_TRUE(vd.is_allocated());
    EXPECT_FALSE(vd.is_deallocated());

    vd.deallocate();

    EXPECT_FALSE(vd.is_allocated());
    EXPECT_TRUE(vd.is_deallocated());
}
