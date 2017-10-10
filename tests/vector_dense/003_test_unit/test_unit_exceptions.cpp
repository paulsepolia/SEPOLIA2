#include <gtest/gtest.h>
#include <cmath>
#include "../../../vector_dense/vector_dense.h"
#include "../../../utilities/exceptions.h"

// local parameters

const uint64_t DIM_COMM(static_cast<uint64_t>(std::pow(10.0, 4.0)));
const double VAL_COMM(123.456);

// test exception not allocation, default constructor, any throw

TEST(exception_not_alloc_default_constructor_any_throw, exception) {

    sep::vector_dense<double> vd1;

    EXPECT_ANY_THROW(vd1(0));
    EXPECT_ANY_THROW(vd1[0]);
    EXPECT_ANY_THROW(vd1.at(0));

    const sep::vector_dense<double> vd2;

    EXPECT_ANY_THROW(vd2(0));
    EXPECT_ANY_THROW(vd2[0]);
    EXPECT_ANY_THROW(vd2.at(0));
}

// test exception not allocation, constructor with one, any throw

TEST(exception_not_alloc_constructor_one_any_throw, exception) {

    sep::vector_dense<double> vd1(DIM_COMM);
    vd1.deallocate();

    EXPECT_ANY_THROW(vd1(0));
    EXPECT_ANY_THROW(vd1[0]);
    EXPECT_ANY_THROW(vd1.at(0));
}

// test exception not allocation, constructor with two, any throw

TEST(exception_not_alloc_constructor_two_any_throw, exception) {

    sep::vector_dense<double> vd1(DIM_COMM, VAL_COMM);
    vd1.deallocate();

    EXPECT_ANY_THROW(vd1(0));
    EXPECT_ANY_THROW(vd1[0]);
    EXPECT_ANY_THROW(vd1.at(0));
}

// test exception not allocation, default constructor, specific throw

TEST(exception_not_alloc_default_constructor_specific_throw, exception) {

    sep::vector_dense<double> vd1;

    EXPECT_THROW(vd1(0), sep::is_not_allocated);
    EXPECT_THROW(vd1[0], sep::is_not_allocated);
    EXPECT_THROW(vd1.at(0), sep::is_not_allocated);

    const sep::vector_dense<double> vd2;

    EXPECT_THROW(vd2(0), sep::is_not_allocated);
    EXPECT_THROW(vd2[0], sep::is_not_allocated);
    EXPECT_THROW(vd2.at(0), sep::is_not_allocated);
}

// test exception not allocation, constructor one, specific throw

TEST(exception_not_alloc_constructor_one_specific_throw, exception) {

    sep::vector_dense<double> vd1(DIM_COMM);

    vd1.deallocate();

    EXPECT_THROW(vd1(0), sep::is_not_allocated);
    EXPECT_THROW(vd1[0], sep::is_not_allocated);
    EXPECT_THROW(vd1.at(0), sep::is_not_allocated);
}

// test exception not allocation, constructor two, specific throw

TEST(exception_not_alloc_constructor_two_specific_throw, exception) {

    sep::vector_dense<double> vd1(DIM_COMM, VAL_COMM);

    vd1.deallocate();

    EXPECT_THROW(vd1(0), sep::is_not_allocated);
    EXPECT_THROW(vd1[0], sep::is_not_allocated);
    EXPECT_THROW(vd1.at(0), sep::is_not_allocated);
}

// test exception out of range, default constructor, any throw

TEST(exception_out_of_range_default_constructor_any_throw, exception) {

    sep::vector_dense<double> vd1;
    vd1.allocate(DIM_COMM);

    EXPECT_ANY_THROW(vd1(DIM_COMM));
    EXPECT_ANY_THROW(vd1[DIM_COMM]);
    EXPECT_ANY_THROW(vd1.at(DIM_COMM));

    const sep::vector_dense<double> vd2;
    vd1.allocate(DIM_COMM);

    EXPECT_ANY_THROW(vd2(DIM_COMM));
    EXPECT_ANY_THROW(vd2[DIM_COMM]);
    EXPECT_ANY_THROW(vd2.at(DIM_COMM));
}

// test exception out of range, constructor with one, any throw

TEST(exception_out_of_range_constructor_one_any_throw, exception) {

    sep::vector_dense<double> vd1(DIM_COMM);

    EXPECT_ANY_THROW(vd1(DIM_COMM));
    EXPECT_ANY_THROW(vd1[DIM_COMM]);
    EXPECT_ANY_THROW(vd1.at(DIM_COMM));

    const sep::vector_dense<double> vd2(DIM_COMM);

    EXPECT_ANY_THROW(vd2(DIM_COMM));
    EXPECT_ANY_THROW(vd2[DIM_COMM]);
    EXPECT_ANY_THROW(vd2.at(DIM_COMM));
}

// test exception out of range, constructor with two, any throw

TEST(exception_out_of_range_constructor_two_any_throw, exception) {

    sep::vector_dense<double> vd1(DIM_COMM, VAL_COMM);

    EXPECT_ANY_THROW(vd1(DIM_COMM));
    EXPECT_ANY_THROW(vd1[DIM_COMM]);
    EXPECT_ANY_THROW(vd1.at(DIM_COMM));

    const sep::vector_dense<double> vd2(DIM_COMM, VAL_COMM);

    EXPECT_ANY_THROW(vd2(DIM_COMM));
    EXPECT_ANY_THROW(vd2[DIM_COMM]);
    EXPECT_ANY_THROW(vd2.at(DIM_COMM));
}

// test exception out of range, default constructor, specific throw

TEST(exception_out_of_range_default_constructor_specific_throw, exception) {

    sep::vector_dense<double> vd1;
    vd1.allocate(DIM_COMM);

    EXPECT_THROW(vd1(DIM_COMM), sep::index_out_of_range);
    EXPECT_THROW(vd1[DIM_COMM], sep::index_out_of_range);
    EXPECT_THROW(vd1.at(DIM_COMM), sep::index_out_of_range);
}

// test exception out of range, constructor one, specific throw

TEST(exception_out_of_range_constructor_one_specific_throw, exception) {

    sep::vector_dense<double> vd1(DIM_COMM);

    EXPECT_THROW(vd1(DIM_COMM), sep::index_out_of_range);
    EXPECT_THROW(vd1[DIM_COMM], sep::index_out_of_range);
    EXPECT_THROW(vd1.at(DIM_COMM), sep::index_out_of_range);

    const sep::vector_dense<double> vd2(DIM_COMM);

    EXPECT_THROW(vd2(DIM_COMM), sep::index_out_of_range);
    EXPECT_THROW(vd2[DIM_COMM], sep::index_out_of_range);
    EXPECT_THROW(vd2.at(DIM_COMM), sep::index_out_of_range);
}

// test exception out of range, constructor two, specific throw

TEST(exception_out_of_range_constructor_two_specific_throw, exception) {

    sep::vector_dense<double> vd1(DIM_COMM, VAL_COMM);

    EXPECT_THROW(vd1(DIM_COMM), sep::index_out_of_range);
    EXPECT_THROW(vd1[DIM_COMM], sep::index_out_of_range);
    EXPECT_THROW(vd1.at(DIM_COMM), sep::index_out_of_range);

    const sep::vector_dense<double> vd2(DIM_COMM, VAL_COMM);

    EXPECT_THROW(vd2(DIM_COMM), sep::index_out_of_range);
    EXPECT_THROW(vd2[DIM_COMM], sep::index_out_of_range);
    EXPECT_THROW(vd2.at(DIM_COMM), sep::index_out_of_range);
}

