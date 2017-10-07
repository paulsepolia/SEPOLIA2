#include <gtest/gtest.h>
#include <cmath>
#include "../../../vector_dense/vector_dense.h"

using sepolia::vector_dense;

// local parameters

const uint64_t DIM_COMM(static_cast<uint64_t>(std::pow(10.0, 4.0)));
const double VAL_COMM(123.456);

// test is_allocated, is_deallocated, allocate and deallocate

TEST(vd_is_allocated_deallocated_allocate_deallocate, memory) {

    vector_dense<double> vd;

    EXPECT_EQ(vd.is_allocated(), false);
    EXPECT_EQ(vd.is_deallocated(), true);

    vd.allocate(DIM_COMM);

    EXPECT_EQ(vd.is_allocated(), true);
    EXPECT_EQ(vd.is_deallocated(), false);

    vd.deallocate();

    EXPECT_EQ(vd.is_allocated(), false);
    EXPECT_EQ(vd.is_deallocated(), true);
}

// test is_allocated, is_deallocated, allocate and deallocate via constructor

TEST(vd_allocate_deallocate_constructor, memory) {

    vector_dense<double> vd1(DIM_COMM);

    EXPECT_TRUE(vd1.is_allocated());
    EXPECT_FALSE(vd1.is_deallocated());
    EXPECT_TRUE(vd1.deallocate());
    EXPECT_FALSE(vd1.is_allocated());
    EXPECT_TRUE(vd1.is_deallocated());

    vector_dense<double> vd2(DIM_COMM, VAL_COMM);

    EXPECT_TRUE(vd2.is_allocated());
    EXPECT_FALSE(vd2.is_deallocated());
    EXPECT_TRUE(vd2.deallocate());
    EXPECT_FALSE(vd2.is_allocated());
    EXPECT_TRUE(vd2.is_deallocated());
}
