#include <gtest/gtest.h>
#include <cmath>
#include "../../../vector_dense/vector_dense.h"

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

TEST(vd_test_add_with_number_double, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_COMM);
    sep::vector_dense<double> v2;

    v2 = v1.plus(VAL_TEST1);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(v2.get_element(i), v1.get_element(i) + VAL_TEST1);
        EXPECT_EQ(v2(i), v1(i) + VAL_TEST1);
        EXPECT_EQ(v2[i], v1[i] + VAL_TEST1);
        EXPECT_EQ(v2[i], VAL_TEST1 + VAL_COMM);
        EXPECT_EQ(v1[i], VAL_COMM);
    }

    EXPECT_EQ(v2, VAL_TEST1 + VAL_COMM);
    EXPECT_EQ(v1, VAL_COMM);
}

// test add a vector with a number, uint64_t case

TEST(vd_test_add_with_number_uint64t, algop) {

    sep::vector_dense<uint64_t> v1(DIM_COMM, VAL_TEST3);
    sep::vector_dense<uint64_t> v2;

    v2 = v1.plus(VAL_TEST4);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(v2.get_element(i), v1.get_element(i) + VAL_TEST4);
        EXPECT_EQ(v2(i), v1(i) + VAL_TEST4);
        EXPECT_EQ(v2[i], v1[i] + VAL_TEST4);
        EXPECT_EQ(v2[i], VAL_TEST3 + VAL_TEST4);
        EXPECT_EQ(v1[i], VAL_TEST3);
    }

    EXPECT_EQ(v1, VAL_TEST3);
    EXPECT_EQ(v2, v1 + VAL_TEST4);
}

// test add a vector with a number in parallel, double case

TEST(vd_test_add_with_number_parallel_double, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_COMM);
    sep::vector_dense<double> v2;

    v2 = v1.plus(VAL_TEST1, true);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(v2.get_element(i), v1.get_element(i) + VAL_TEST1);
        EXPECT_EQ(v2(i), v1(i) + VAL_TEST1);
        EXPECT_EQ(v2[i], v1[i] + VAL_TEST1);
        EXPECT_EQ(v2[i], VAL_TEST1 + VAL_COMM);
        EXPECT_EQ(v1[i], VAL_COMM);
    }

    EXPECT_EQ(v1, VAL_COMM);
    EXPECT_EQ(v2, VAL_TEST1 + VAL_COMM);
}

// test add a vector with a number in parallel, uint64_t case

TEST(vd_test_add_with_number_parallel_uint64t, algop) {

    sep::vector_dense<uint64_t> v1(DIM_COMM, VAL_TEST3);
    sep::vector_dense<uint64_t> v2;

    v2 = v1.plus(VAL_TEST4, true);

    for (uint64_t i = 0; i < DIM_COMM; i++) {
        EXPECT_EQ(v2.get_element(i), v1.get_element(i) + VAL_TEST4);
        EXPECT_EQ(v2(i), v1(i) + VAL_TEST4);
        EXPECT_EQ(v2[i], v1[i] + VAL_TEST4);
        EXPECT_EQ(v2[i], VAL_TEST3 + VAL_TEST4);
        EXPECT_EQ(v1[i], VAL_TEST3);
    }

    EXPECT_EQ(v1, VAL_TEST3);
    EXPECT_EQ(v2, VAL_TEST3 + VAL_TEST4);
}

// test add a vector with another vector, double case

TEST(vd_test_add_with_vector_double, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_TEST1);
    sep::vector_dense<double> v2(DIM_COMM, VAL_TEST2);
    sep::vector_dense<double> v3;

    v3 = v1.plus(v2);

    EXPECT_TRUE(v3.is_allocated());

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(v3.get_element(i), v1.get_element(i) + v2.get_element(i));
        EXPECT_EQ(v3[i], v1[i] + v2[i]);
        EXPECT_EQ(v3(i), v1(i) + v2(i));
    }

    EXPECT_EQ(v3, v1 + v2);
}

// test add a vector with another vector, uint64_t case

TEST(vd_test_add_with_vector_uint64t, algop) {

    sep::vector_dense<uint64_t> v1(DIM_COMM, VAL_TEST3);
    sep::vector_dense<uint64_t> v2(DIM_COMM, VAL_TEST4);
    sep::vector_dense<uint64_t> v3;

    v3 = v1.plus(v2);

    EXPECT_TRUE(v3.is_allocated());

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(v3.get_element(i), v1.get_element(i) + v2.get_element(i));
        EXPECT_EQ(v3[i], v1[i] + v2[i]);
        EXPECT_EQ(v3(i), v1(i) + v2(i));
    }

    EXPECT_EQ(v3, v1 + v2);
}

// test add a vector with another vector in parallel, double case

TEST(vd_test_add_with_vector_parallel_double, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_TEST1);
    sep::vector_dense<double> v2(DIM_COMM, VAL_TEST2);
    sep::vector_dense<double> v3;

    v3 = v1.plus(v2, true);

    EXPECT_TRUE(v3.is_allocated());

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(v3.get_element(i), v1.get_element(i) + v2.get_element(i));
        EXPECT_EQ(v3[i], v1[i] + v2[i]);
        EXPECT_EQ(v3(i), v1(i) + v2(i));
    }

    EXPECT_EQ(v3, v1 + v2);
}

// test add a vector with another vector in parallel, uint64_t case

TEST(vd_test_add_with_vector_parallel_uint64_t, algop) {

    sep::vector_dense<uint64_t> v1(DIM_COMM, VAL_TEST3);
    sep::vector_dense<uint64_t> v2(DIM_COMM, VAL_TEST4);
    sep::vector_dense<uint64_t> v3;

    v3 = v1.plus(v2, true);

    EXPECT_TRUE(v3.is_allocated());

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(v3.get_element(i), v1.get_element(i) + v2.get_element(i));
        EXPECT_EQ(v3[i], v1[i] + v2[i]);
        EXPECT_EQ(v3(i), v1(i) + v2(i));
    }

    EXPECT_EQ(v3, v1 + v2);
}

// test add a vector with a number and return to it, double case

TEST(vd_test_add_with_number_return_to_same_double, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_COMM);

    v1 = v1.plus(VAL_TEST1);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(v1.get_element(i), VAL_COMM + VAL_TEST1);
        EXPECT_EQ(v1(i), VAL_COMM + VAL_TEST1);
        EXPECT_EQ(v1[i], VAL_COMM + VAL_TEST1);
    }

    EXPECT_EQ(v1, VAL_COMM + VAL_TEST1);
}

// test add a vector with a number and return to it, uint64_t case

TEST(vd_test_add_with_number_return_to_same_uint64_t, algop) {

    sep::vector_dense<uint64_t> v1(DIM_COMM, VAL_TEST3);

    v1 = v1.plus(VAL_TEST4);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(v1.get_element(i), VAL_TEST3 + VAL_TEST4);
        EXPECT_EQ(v1(i), VAL_TEST3 + VAL_TEST4);
        EXPECT_EQ(v1[i], VAL_TEST3 + VAL_TEST4);
    }

    EXPECT_EQ(v1, VAL_TEST3 + VAL_TEST4);
}

// test add a vector with a number and return to it in parallel, double case

TEST(vd_test_add_with_number_return_to_same_in_parallel_double, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_COMM);

    v1 = v1.plus(VAL_TEST1, true);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(v1.get_element(i), VAL_TEST1 + VAL_COMM);
        EXPECT_EQ(v1(i), VAL_TEST1 + VAL_COMM);
        EXPECT_EQ(v1[i], VAL_TEST1 + VAL_COMM);
    }

    EXPECT_EQ(v1, VAL_TEST1 + VAL_COMM);
}

// test add a vector with a number and return to it in parallel, uint64_t case

TEST(vd_test_add_with_number_return_to_same_in_parallel_uint64_t, algop) {

    sep::vector_dense<uint64_t> v1(DIM_COMM, VAL_TEST3);

    v1 = v1.plus(VAL_TEST4, true);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(v1.get_element(i), VAL_TEST3 + VAL_TEST4);
        EXPECT_EQ(v1(i), VAL_TEST3 + VAL_TEST4);
        EXPECT_EQ(v1[i], VAL_TEST3 + VAL_TEST4);
    }

    EXPECT_EQ(v1, VAL_TEST3 + VAL_TEST4);
}

// test add a vector with another vector and return to it, double case

TEST(vd_test_add_with_vector_return_to_same_double, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_TEST1);
    sep::vector_dense<double> v2(DIM_COMM, VAL_TEST2);

    v1 = v1.plus(v2);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(v1.get_element(i), VAL_TEST1 + VAL_TEST2);
        EXPECT_EQ(v2.get_element(i), VAL_TEST2);
        EXPECT_EQ(v1(i), VAL_TEST1 + VAL_TEST2);
        EXPECT_EQ(v2(i), VAL_TEST2);
        EXPECT_EQ(v1[i], VAL_TEST1 + VAL_TEST2);
        EXPECT_EQ(v2[i], VAL_TEST2);
    }

    EXPECT_EQ(v1, VAL_TEST1 + VAL_TEST2);
    EXPECT_EQ(v2, VAL_TEST2);

    v1.deallocate();
    v2.deallocate();
    v1.allocate(DIM_COMM);
    v2.allocate(DIM_COMM);

    v1 = VAL_TEST1;
    v2 = VAL_TEST2;

    v2 = v1.plus(v2);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(v2.get_element(i), VAL_TEST1 + VAL_TEST2);
        EXPECT_EQ(v1.get_element(i), VAL_TEST1);
        EXPECT_EQ(v2(i), VAL_TEST1 + VAL_TEST2);
        EXPECT_EQ(v1(i), VAL_TEST1);
        EXPECT_EQ(v2[i], VAL_TEST1 + VAL_TEST2);
        EXPECT_EQ(v1[i], VAL_TEST1);
    }

    EXPECT_EQ(v2, VAL_TEST1 + VAL_TEST2);
    EXPECT_EQ(v1, VAL_TEST1);
}

// test add a vector with another vector and return to it, uint64_t case

TEST(vd_test_add_with_vector_return_to_same_uint64_t, algop) {

    sep::vector_dense<uint64_t> v1(DIM_COMM, VAL_TEST3);
    sep::vector_dense<uint64_t> v2(DIM_COMM, VAL_TEST4);

    v1 = v1.plus(v2);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(v1.get_element(i), VAL_TEST3 + VAL_TEST4);
        EXPECT_EQ(v2.get_element(i), VAL_TEST4);
        EXPECT_EQ(v1(i), VAL_TEST3 + VAL_TEST4);
        EXPECT_EQ(v2(i), VAL_TEST4);
        EXPECT_EQ(v1[i], VAL_TEST3 + VAL_TEST4);
        EXPECT_EQ(v2[i], VAL_TEST4);
    }

    EXPECT_EQ(v1, VAL_TEST3 + VAL_TEST4);
    EXPECT_EQ(v2, VAL_TEST4);

    v1.deallocate();
    v2.deallocate();
    v1.allocate(DIM_COMM);
    v2.allocate(DIM_COMM);

    v1 = VAL_TEST3;
    v2 = VAL_TEST4;

    v2 = v1.plus(v2);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(v2.get_element(i), VAL_TEST3 + VAL_TEST4);
        EXPECT_EQ(v1.get_element(i), VAL_TEST3);
        EXPECT_EQ(v2(i), VAL_TEST3 + VAL_TEST4);
        EXPECT_EQ(v1(i), VAL_TEST3);
        EXPECT_EQ(v2[i], VAL_TEST3 + VAL_TEST4);
        EXPECT_EQ(v1[i], VAL_TEST3);
    }

    EXPECT_EQ(v2, VAL_TEST3 + VAL_TEST4);
    EXPECT_EQ(v1, VAL_TEST3);
}

// test add a vector with another vector and return to it in parallel, double case

TEST(vd_test_add_with_vector_return_to_same_parallel_double, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_TEST1);
    sep::vector_dense<double> v2(DIM_COMM, VAL_TEST2);

    v1 = v1.plus(v2, true);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(v1.get_element(i), VAL_TEST1 + VAL_TEST2);
        EXPECT_EQ(v2.get_element(i), VAL_TEST2);
        EXPECT_EQ(v1(i), VAL_TEST1 + VAL_TEST2);
        EXPECT_EQ(v2(i), VAL_TEST2);
        EXPECT_EQ(v1[i], VAL_TEST1 + VAL_TEST2);
        EXPECT_EQ(v2[i], VAL_TEST2);
    }

    EXPECT_EQ(v1, VAL_TEST1 + VAL_TEST2);
    EXPECT_EQ(v2, VAL_TEST2);

    v1.deallocate();
    v2.deallocate();
    v1.allocate(DIM_COMM);
    v2.allocate(DIM_COMM);

    v1 = VAL_TEST1;
    v2 = VAL_TEST2;

    v2 = v1.plus(v2);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(v2.get_element(i), VAL_TEST1 + VAL_TEST2);
        EXPECT_EQ(v1.get_element(i), VAL_TEST1);
        EXPECT_EQ(v2(i), VAL_TEST1 + VAL_TEST2);
        EXPECT_EQ(v1(i), VAL_TEST1);
        EXPECT_EQ(v2[i], VAL_TEST1 + VAL_TEST2);
        EXPECT_EQ(v1[i], VAL_TEST1);
    }

    EXPECT_EQ(v2, VAL_TEST1 + VAL_TEST2);
    EXPECT_EQ(v1, VAL_TEST1);

}

// test add a vector with another vector and return to it in parallel, uint64_t case

TEST(vd_test_add_with_vector_return_to_same_parallel_uint64_t, algop) {

    sep::vector_dense<uint64_t> v1(DIM_COMM, VAL_TEST3);
    sep::vector_dense<uint64_t> v2(DIM_COMM, VAL_TEST4);

    v1 = v1.plus(v2, true);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(v1.get_element(i), VAL_TEST3 + VAL_TEST4);
        EXPECT_EQ(v2.get_element(i), VAL_TEST4);
        EXPECT_EQ(v1(i), VAL_TEST3 + VAL_TEST4);
        EXPECT_EQ(v2(i), VAL_TEST4);
        EXPECT_EQ(v1[i], VAL_TEST3 + VAL_TEST4);
        EXPECT_EQ(v2[i], VAL_TEST4);
    }

    EXPECT_EQ(v1, VAL_TEST3 + VAL_TEST4);
    EXPECT_EQ(v2, VAL_TEST4);

    v1.deallocate();
    v2.deallocate();
    v1.allocate(DIM_COMM);
    v2.allocate(DIM_COMM);

    v1 = VAL_TEST3;
    v2 = VAL_TEST4;

    v2 = v1.plus(v2);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(v2.get_element(i), VAL_TEST3 + VAL_TEST4);
        EXPECT_EQ(v1.get_element(i), VAL_TEST3);
        EXPECT_EQ(v2(i), VAL_TEST3 + VAL_TEST4);
        EXPECT_EQ(v1(i), VAL_TEST3);
        EXPECT_EQ(v2[i], VAL_TEST3 + VAL_TEST4);
        EXPECT_EQ(v1[i], VAL_TEST3);
    }

    EXPECT_EQ(v2, VAL_TEST3 + VAL_TEST4);
    EXPECT_EQ(v1, VAL_TEST3);
}

/// TODO : add uint64_t cases below

// test subtract from a vector a number

TEST(vd_test_subtract_a_number, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_COMM);
    sep::vector_dense<double> v2;

    v2 = v1.subtract(VAL_TEST1);

    EXPECT_EQ(v2.get_element(INDEX1), v1.get_element(INDEX1) - VAL_TEST1);
}

// test subtract from vector a number in parallel

TEST(vd_test_subtract_a_number_parallel, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_COMM);
    sep::vector_dense<double> v2;

    v2 = v1.subtract(VAL_TEST1, true);

    EXPECT_EQ(v2.get_element(INDEX1), v1.get_element(INDEX1) - VAL_TEST1);
}

// test subtract a vector from another vector

TEST(vd_test_subtract_with_vector, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_TEST1);
    sep::vector_dense<double> v2(DIM_COMM, VAL_TEST2);
    sep::vector_dense<double> v3;

    v3 = v1.subtract(v2);

    EXPECT_TRUE(v3.is_allocated());
    EXPECT_EQ(v3.get_element(INDEX1), v1.get_element(INDEX1) - v2.get_element(INDEX1));
}

// test subtract a vector from another vector in parallel

TEST(vd_test_subtract_with_vector_parallel, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_TEST1);
    sep::vector_dense<double> v2(DIM_COMM, VAL_TEST2);
    sep::vector_dense<double> v3;

    v3 = v1.subtract(v2, true);

    EXPECT_TRUE(v3.is_allocated());
    EXPECT_EQ(v3.get_element(INDEX1), v1.get_element(INDEX1) - v2.get_element(INDEX1));
}

// test subtract from vector a number and return to it

TEST(vd_test_subtract_a_number_to_same, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_COMM);

    v1 = v1.subtract(VAL_TEST1);

    EXPECT_EQ(v1.get_element(INDEX1), VAL_COMM - VAL_TEST1);
    EXPECT_EQ(v1.get_element(INDEX2), VAL_COMM - VAL_TEST1);
}

// test subtract from vector a number and return to it in parallel

TEST(vd_test_subtract_a_number_to_same_in_parallel, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_COMM);

    v1 = v1.subtract(VAL_TEST1, true);

    EXPECT_EQ(v1.get_element(INDEX1), VAL_COMM - VAL_TEST1);
    EXPECT_EQ(v1.get_element(INDEX2), VAL_COMM - VAL_TEST1);
}

// test subtract a vector from another vector and return to it

TEST(vd_test_subtract_with_vector_return_to_same, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_TEST1);
    sep::vector_dense<double> v2(DIM_COMM, VAL_TEST2);

    v1 = v1.subtract(v2);

    EXPECT_EQ(v1.get_element(INDEX1), VAL_TEST1 - VAL_TEST2);
    EXPECT_EQ(v1.get_element(INDEX2), VAL_TEST1 - VAL_TEST2);
    EXPECT_EQ(v2.get_element(INDEX1), VAL_TEST2);
    EXPECT_EQ(v2.get_element(INDEX2), VAL_TEST2);

    v1.deallocate();
    v2.deallocate();
    v1.allocate(DIM_COMM);
    v2.allocate(DIM_COMM);

    v1 = VAL_TEST1;
    v2 = VAL_TEST2;
    v2 = v1.subtract(v2);

    EXPECT_EQ(v2.get_element(INDEX1), VAL_TEST1 - VAL_TEST2);
    EXPECT_EQ(v2.get_element(INDEX2), VAL_TEST1 - VAL_TEST2);
    EXPECT_EQ(v1.get_element(INDEX1), VAL_TEST1);
    EXPECT_EQ(v1.get_element(INDEX2), VAL_TEST1);
}

// test subtract a vector from another vector and return to it in parallel

TEST(vd_test_subtract_with_vector_return_to_same_parallel, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_TEST1);
    sep::vector_dense<double> v2(DIM_COMM, VAL_TEST2);

    v1 = v1.subtract(v2, true);

    EXPECT_EQ(v1.get_element(INDEX1), VAL_TEST1 - VAL_TEST2);
    EXPECT_EQ(v1.get_element(INDEX2), VAL_TEST1 - VAL_TEST2);
    EXPECT_EQ(v2.get_element(INDEX1), VAL_TEST2);
    EXPECT_EQ(v2.get_element(INDEX2), VAL_TEST2);

    v1.deallocate();
    v2.deallocate();
    v1.allocate(DIM_COMM);
    v2.allocate(DIM_COMM);

    v1 = VAL_TEST1;
    v2 = VAL_TEST2;
    v2 = v1.subtract(v2, true);

    EXPECT_EQ(v2.get_element(INDEX1), VAL_TEST1 - VAL_TEST2);
    EXPECT_EQ(v2.get_element(INDEX2), VAL_TEST1 - VAL_TEST2);
    EXPECT_EQ(v1.get_element(INDEX1), VAL_TEST1);
    EXPECT_EQ(v1.get_element(INDEX2), VAL_TEST1);
}

// test times a vector with number

TEST(vd_test_times_a_number, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_COMM);
    sep::vector_dense<double> v2;

    v2 = v1.times(VAL_TEST1);

    EXPECT_EQ(v2.get_element(INDEX1), v1.get_element(INDEX1) * VAL_TEST1);
}

// test times from vector a number in parallel

TEST(vd_test_times_a_number_parallel, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_COMM);
    sep::vector_dense<double> v2;

    v2 = v1.times(VAL_TEST1, true);

    EXPECT_EQ(v2.get_element(INDEX1), v1.get_element(INDEX1) * VAL_TEST1);
}

// test times a vector with another vector

TEST(vd_test_times_with_vector, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_TEST1);
    sep::vector_dense<double> v2(DIM_COMM, VAL_TEST2);
    sep::vector_dense<double> v3;

    v3 = v1.times(v2);

    EXPECT_TRUE(v3.is_allocated());
    EXPECT_EQ(v3.get_element(INDEX1), v1.get_element(INDEX1) * v2.get_element(INDEX1));
}

// test times a vector with another vector in parallel

TEST(vd_test_times_with_vector_parallel, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_TEST1);
    sep::vector_dense<double> v2(DIM_COMM, VAL_TEST2);
    sep::vector_dense<double> v3;

    v3 = v1.times(v2, true);

    EXPECT_TRUE(v3.is_allocated());
    EXPECT_EQ(v3.get_element(INDEX1), v1.get_element(INDEX1) * v2.get_element(INDEX1));
}

// test times a number with a vector and return to it

TEST(vd_test_times_a_number_to_same, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_COMM);

    v1 = v1.times(VAL_TEST1);

    EXPECT_EQ(v1.get_element(INDEX1), VAL_COMM * VAL_TEST1);
    EXPECT_EQ(v1.get_element(INDEX2), VAL_COMM * VAL_TEST1);
}

// test times a number with a vector and return to it in parallel

TEST(vd_test_times_a_number_to_same_in_parallel, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_COMM);

    v1 = v1.times(VAL_TEST1, true);

    EXPECT_EQ(v1.get_element(INDEX1), VAL_COMM * VAL_TEST1);
    EXPECT_EQ(v1.get_element(INDEX2), VAL_COMM * VAL_TEST1);
}

// test times a vector with another vector and return to it

TEST(vd_test_times_a_vector_return_to_same, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_TEST1);
    sep::vector_dense<double> v2(DIM_COMM, VAL_TEST2);

    v1 = v1.times(v2);

    EXPECT_EQ(v1.get_element(INDEX1), VAL_TEST1 * VAL_TEST2);
    EXPECT_EQ(v1.get_element(INDEX2), VAL_TEST1 * VAL_TEST2);
    EXPECT_EQ(v2.get_element(INDEX1), VAL_TEST2);
    EXPECT_EQ(v2.get_element(INDEX2), VAL_TEST2);

    v1.deallocate();
    v2.deallocate();
    v1.allocate(DIM_COMM);
    v2.allocate(DIM_COMM);

    v1 = VAL_TEST1;
    v2 = VAL_TEST2;
    v2 = v1.times(v2);

    EXPECT_EQ(v2.get_element(INDEX1), VAL_TEST1 * VAL_TEST2);
    EXPECT_EQ(v2.get_element(INDEX2), VAL_TEST1 * VAL_TEST2);
    EXPECT_EQ(v1.get_element(INDEX1), VAL_TEST1);
    EXPECT_EQ(v1.get_element(INDEX2), VAL_TEST1);
}

// test times a vector with another vector and return to it in parallel

TEST(vd_test_times_with_vector_return_to_same_parallel, algop) {
    sep::vector_dense<double> v1(DIM_COMM, VAL_TEST1);
    sep::vector_dense<double> v2(DIM_COMM, VAL_TEST2);

    v1 = v1.times(v2, true);

    EXPECT_EQ(v1.get_element(INDEX1), VAL_TEST1 * VAL_TEST2);
    EXPECT_EQ(v1.get_element(INDEX2), VAL_TEST1 * VAL_TEST2);
    EXPECT_EQ(v2.get_element(INDEX1), VAL_TEST2);
    EXPECT_EQ(v2.get_element(INDEX2), VAL_TEST2);

    v1.deallocate();
    v2.deallocate();
    v1.allocate(DIM_COMM);
    v2.allocate(DIM_COMM);

    v1 = VAL_TEST1;
    v2 = VAL_TEST2;
    v2 = v1.times(v2, true);

    EXPECT_EQ(v2.get_element(INDEX1), VAL_TEST1 * VAL_TEST2);
    EXPECT_EQ(v2.get_element(INDEX2), VAL_TEST1 * VAL_TEST2);
    EXPECT_EQ(v1.get_element(INDEX1), VAL_TEST1);
    EXPECT_EQ(v1.get_element(INDEX2), VAL_TEST1);
}

// test divide a vector with number

TEST(vd_test_divide_a_number, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_COMM);
    sep::vector_dense<double> v2;

    v2 = v1.divide(VAL_TEST1);

    EXPECT_EQ(v2.get_element(INDEX1), v1.get_element(INDEX1) / VAL_TEST1);
}

// test divide a vector with a number in parallel

TEST(vd_test_divide_a_number_parallel, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_COMM);
    sep::vector_dense<double> v2;

    v2 = v1.divide(VAL_TEST1, true);

    EXPECT_EQ(v2.get_element(INDEX1), v1.get_element(INDEX1) / VAL_TEST1);
}

// test divide a vector with another vector

TEST(vd_test_divide_with_vector, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_TEST1);
    sep::vector_dense<double> v2(DIM_COMM, VAL_TEST2);
    sep::vector_dense<double> v3;

    v3 = v1.divide(v2);

    EXPECT_TRUE(v3.is_allocated());
    EXPECT_EQ(v3.get_element(INDEX1), v1.get_element(INDEX1) / v2.get_element(INDEX1));
}

// test divide a vector with another vector in parallel

TEST(vd_test_divide_with_vector_parallel, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_TEST1);
    sep::vector_dense<double> v2(DIM_COMM, VAL_TEST2);
    sep::vector_dense<double> v3;

    v3 = v1.divide(v2, true);

    EXPECT_TRUE(v3.is_allocated());
    EXPECT_EQ(v3.get_element(INDEX1), v1.get_element(INDEX1) / v2.get_element(INDEX1));
}

// test divide a number with a vector and return to it

TEST(vd_test_divide_a_number_to_same, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_COMM);

    v1 = v1.divide(VAL_TEST1);

    EXPECT_EQ(v1.get_element(INDEX1), VAL_COMM / VAL_TEST1);
    EXPECT_EQ(v1.get_element(INDEX2), VAL_COMM / VAL_TEST1);
}

// test divide a number with a vector and return to it in parallel

TEST(vd_test_divide_a_number_to_same_in_parallel, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_COMM);

    v1 = v1.divide(VAL_TEST1, true);

    EXPECT_EQ(v1.get_element(INDEX1), VAL_COMM / VAL_TEST1);
    EXPECT_EQ(v1.get_element(INDEX2), VAL_COMM / VAL_TEST1);
}

// test divide a vector with another vector and return to it

TEST(vd_test_divide_a_vector_return_to_same, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_TEST1);
    sep::vector_dense<double> v2(DIM_COMM, VAL_TEST2);

    v1 = v1.divide(v2);

    EXPECT_EQ(v1.get_element(INDEX1), VAL_TEST1 / VAL_TEST2);
    EXPECT_EQ(v1.get_element(INDEX2), VAL_TEST1 / VAL_TEST2);
    EXPECT_EQ(v2.get_element(INDEX1), VAL_TEST2);
    EXPECT_EQ(v2.get_element(INDEX2), VAL_TEST2);

    v1.deallocate();
    v2.deallocate();
    v1.allocate(DIM_COMM);
    v2.allocate(DIM_COMM);

    v1 = VAL_TEST1;
    v2 = VAL_TEST2;
    v2 = v1.divide(v2);

    EXPECT_EQ(v2.get_element(INDEX1), VAL_TEST1 / VAL_TEST2);
    EXPECT_EQ(v2.get_element(INDEX2), VAL_TEST1 / VAL_TEST2);
    EXPECT_EQ(v1.get_element(INDEX1), VAL_TEST1);
    EXPECT_EQ(v1.get_element(INDEX2), VAL_TEST1);
}

// test divide a vector with another vector and return to it in parallel

TEST(vd_test_divide_with_vector_return_to_same_parallel, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_TEST1);
    sep::vector_dense<double> v2(DIM_COMM, VAL_TEST2);

    v1 = v1.divide(v2, true);

    EXPECT_EQ(v1.get_element(INDEX1), VAL_TEST1 / VAL_TEST2);
    EXPECT_EQ(v1.get_element(INDEX2), VAL_TEST1 / VAL_TEST2);
    EXPECT_EQ(v2.get_element(INDEX1), VAL_TEST2);
    EXPECT_EQ(v2.get_element(INDEX2), VAL_TEST2);

    v1.deallocate();
    v2.deallocate();
    v1.allocate(DIM_COMM);
    v2.allocate(DIM_COMM);

    v1 = VAL_TEST1;
    v2 = VAL_TEST2;
    v2 = v1.divide(v2, true);

    EXPECT_EQ(v2.get_element(INDEX1), VAL_TEST1 / VAL_TEST2);
    EXPECT_EQ(v2.get_element(INDEX2), VAL_TEST1 / VAL_TEST2);
    EXPECT_EQ(v1.get_element(INDEX1), VAL_TEST1);
    EXPECT_EQ(v1.get_element(INDEX2), VAL_TEST1);
}

// test add a vector with a number using operator

TEST(vd_test_add_with_number_operator, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_COMM);
    sep::vector_dense<double> v2;

    v2 = v1 + VAL_TEST1;

    EXPECT_EQ(v2.get_element(INDEX1), v1.get_element(INDEX1) + VAL_TEST1);
}

// test add a vector with another vector using operator

TEST(vd_test_add_with_vector_operator, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_TEST1);
    sep::vector_dense<double> v2(DIM_COMM, VAL_TEST2);
    sep::vector_dense<double> v3;

    v3 = v1 + v2;

    EXPECT_TRUE(v3.is_allocated());
    EXPECT_EQ(v3.get_element(INDEX1), v1.get_element(INDEX1) + v2.get_element(INDEX1));
}

// test add a vector with a number and return to it using operator

TEST(vd_test_add_with_number_return_to_same_operator, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_COMM);

    v1 = v1 + VAL_TEST1;

    EXPECT_EQ(v1.get_element(INDEX1), VAL_COMM + VAL_TEST1);
    EXPECT_EQ(v1.get_element(INDEX2), VAL_COMM + VAL_TEST1);
}

// test add a vector with another vector and return to it using operator

TEST(vd_test_add_with_vector_return_to_same_operator, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_TEST1);
    sep::vector_dense<double> v2(DIM_COMM, VAL_TEST2);

    v1 = v1 + v2;

    EXPECT_EQ(v1.get_element(INDEX1), VAL_TEST1 + VAL_TEST2);
    EXPECT_EQ(v1.get_element(INDEX2), VAL_TEST1 + VAL_TEST2);
    EXPECT_EQ(v2.get_element(INDEX1), VAL_TEST2);
    EXPECT_EQ(v2.get_element(INDEX2), VAL_TEST2);

    v1.deallocate();
    v2.deallocate();
    v1.allocate(DIM_COMM);
    v2.allocate(DIM_COMM);

    v1 = VAL_TEST1;
    v2 = VAL_TEST2;
    v2 = v1 + v2;

    EXPECT_EQ(v2.get_element(INDEX1), VAL_TEST1 + VAL_TEST2);
    EXPECT_EQ(v2.get_element(INDEX2), VAL_TEST1 + VAL_TEST2);
    EXPECT_EQ(v1.get_element(INDEX1), VAL_TEST1);
    EXPECT_EQ(v1.get_element(INDEX2), VAL_TEST1);
}

// test subtract from a vector a number using operator

TEST(vd_test_subtract_a_number_operator, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_COMM);
    sep::vector_dense<double> v2;

    v2 = v1 - VAL_TEST1;

    EXPECT_EQ(v2.get_element(INDEX1), v1.get_element(INDEX1) - VAL_TEST1);
}

// test subtract a vector from another vector using operator

TEST(vd_test_subtract_with_vector_operator, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_TEST1);
    sep::vector_dense<double> v2(DIM_COMM, VAL_TEST2);
    sep::vector_dense<double> v3;

    v3 = v1 - v2;

    EXPECT_TRUE(v3.is_allocated());
    EXPECT_EQ(v3.get_element(INDEX1), v1.get_element(INDEX1) - v2.get_element(INDEX1));
}

// test subtract from vector a number and return to it using operator

TEST(vd_test_subtract_a_number_to_same_operator, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_COMM);

    v1 = v1 - VAL_TEST1;

    EXPECT_EQ(v1.get_element(INDEX1), VAL_COMM - VAL_TEST1);
    EXPECT_EQ(v1.get_element(INDEX2), VAL_COMM - VAL_TEST1);
}

// test subtract a vector from another vector and return to it using operator

TEST(vd_test_subtract_with_vector_return_to_same_operator, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_TEST1);
    sep::vector_dense<double> v2(DIM_COMM, VAL_TEST2);

    v1 = v1 - v2;

    EXPECT_EQ(v1.get_element(INDEX1), VAL_TEST1 - VAL_TEST2);
    EXPECT_EQ(v1.get_element(INDEX2), VAL_TEST1 - VAL_TEST2);
    EXPECT_EQ(v2.get_element(INDEX1), VAL_TEST2);
    EXPECT_EQ(v2.get_element(INDEX2), VAL_TEST2);

    v1.deallocate();
    v2.deallocate();
    v1.allocate(DIM_COMM);
    v2.allocate(DIM_COMM);
    v1 = VAL_TEST1;
    v2 = VAL_TEST2;

    v2 = v1.subtract(v2);

    EXPECT_EQ(v2.get_element(INDEX1), VAL_TEST1 - VAL_TEST2);
    EXPECT_EQ(v2.get_element(INDEX2), VAL_TEST1 - VAL_TEST2);
    EXPECT_EQ(v1.get_element(INDEX1), VAL_TEST1);
    EXPECT_EQ(v1.get_element(INDEX2), VAL_TEST1);
}

// test times a vector with number using operator

TEST(vd_test_times_a_number_operator, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_COMM);
    sep::vector_dense<double> v2;

    v2 = v1 * VAL_TEST1;

    EXPECT_EQ(v2.get_element(INDEX1), v1.get_element(INDEX1) * VAL_TEST1);
}

// test times a vector with another vector using operator

TEST(vd_test_times_with_vector_operator, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_TEST1);
    sep::vector_dense<double> v2(DIM_COMM, VAL_TEST2);
    sep::vector_dense<double> v3;

    v3 = v1 * v2;

    EXPECT_TRUE(v3.is_allocated());
    EXPECT_EQ(v3.get_element(INDEX1), v1.get_element(INDEX1) * v2.get_element(INDEX1));
}

// test times a number with a vector and return to it using operator

TEST(vd_test_times_a_number_to_same_operator, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_COMM);

    v1 = v1 * VAL_TEST1;

    EXPECT_EQ(v1.get_element(INDEX1), VAL_COMM * VAL_TEST1);
    EXPECT_EQ(v1.get_element(INDEX2), VAL_COMM * VAL_TEST1);
}

// test times a vector with another vector and return to it using operator

TEST(vd_test_times_a_vector_return_to_same_operator, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_TEST1);
    sep::vector_dense<double> v2(DIM_COMM, VAL_TEST2);

    v1 = v1 * v2;

    EXPECT_EQ(v1.get_element(INDEX1), VAL_TEST1 * VAL_TEST2);
    EXPECT_EQ(v1.get_element(INDEX2), VAL_TEST1 * VAL_TEST2);
    EXPECT_EQ(v2.get_element(INDEX1), VAL_TEST2);
    EXPECT_EQ(v2.get_element(INDEX2), VAL_TEST2);

    v1.deallocate();
    v2.deallocate();
    v1.allocate(DIM_COMM);
    v2.allocate(DIM_COMM);
    v1 = VAL_TEST1;
    v2 = VAL_TEST2;

    v2 = v1 * v2;

    EXPECT_EQ(v2.get_element(INDEX1), VAL_TEST1 * VAL_TEST2);
    EXPECT_EQ(v2.get_element(INDEX2), VAL_TEST1 * VAL_TEST2);
    EXPECT_EQ(v1.get_element(INDEX1), VAL_TEST1);
    EXPECT_EQ(v1.get_element(INDEX2), VAL_TEST1);
}

// test divide a vector with number using operator

TEST(vd_test_divide_a_number_operator, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_COMM);
    sep::vector_dense<double> v2;

    v2 = v1 / VAL_TEST1;

    EXPECT_EQ(v2.get_element(INDEX1), v1.get_element(INDEX1) / VAL_TEST1);
}

// test divide a vector with another vector using operator

TEST(vd_test_divide_with_vector_operator, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_TEST1);
    sep::vector_dense<double> v2(DIM_COMM, VAL_TEST2);
    sep::vector_dense<double> v3;

    v3 = v1 / v2;

    EXPECT_TRUE(v3.is_allocated());
    EXPECT_EQ(v3.get_element(INDEX1), v1.get_element(INDEX1) / v2.get_element(INDEX1));
}

// test divide a number with a vector and return to it using operator

TEST(vd_test_divide_with_number_to_same_operator, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_COMM);

    v1 = v1 / VAL_TEST1;

    EXPECT_EQ(v1.get_element(INDEX1), VAL_COMM / VAL_TEST1);
    EXPECT_EQ(v1.get_element(INDEX2), VAL_COMM / VAL_TEST1);
}

// test divide a vector with another vector and return to it using operator

TEST(vd_test_divide_a_vector_return_to_same_operator, algop) {

    sep::vector_dense<double> v1(DIM_COMM, VAL_TEST1);
    sep::vector_dense<double> v2(DIM_COMM, VAL_TEST2);

    v1 = v1 / v2;

    EXPECT_EQ(v1.get_element(INDEX1), VAL_TEST1 / VAL_TEST2);
    EXPECT_EQ(v1.get_element(INDEX2), VAL_TEST1 / VAL_TEST2);
    EXPECT_EQ(v2.get_element(INDEX1), VAL_TEST2);
    EXPECT_EQ(v2.get_element(INDEX2), VAL_TEST2);

    v1.deallocate();
    v2.deallocate();
    v1.allocate(DIM_COMM);
    v2.allocate(DIM_COMM);

    v1 = VAL_TEST1;
    v2 = VAL_TEST2;
    v2 = v1 / v2;

    EXPECT_EQ(v2.get_element(INDEX1), VAL_TEST1 / VAL_TEST2);
    EXPECT_EQ(v2.get_element(INDEX2), VAL_TEST1 / VAL_TEST2);
    EXPECT_EQ(v1.get_element(INDEX1), VAL_TEST1);
    EXPECT_EQ(v1.get_element(INDEX2), VAL_TEST1);
}
