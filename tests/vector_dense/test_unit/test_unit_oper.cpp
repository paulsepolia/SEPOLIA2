#include <gtest/gtest.h>
#include <cmath>
#include "../../../vector_dense/vector_dense.h"

using sepolia::vector_dense;

// local parameters

const uint64_t DIM_COMM(static_cast<const uint64_t>(std::pow(10.0, 4.0)));
const double VAL_COMM(123.456);
const double VAL_TEST1(234.567);
const double VAL_TEST2(765.432);
const uint64_t INDEX1(11);
const uint64_t INDEX2(12);
const double ERROR_M10(std::pow(10.0, -10.0));
const double ERROR_M11(std::pow(10.0, -11.0));
const double ERROR_M12(std::pow(10.0, -12.0));

// test operator []

TEST(vd_test_operator_square_brackets, operators) {

    vector_dense<double> v1(DIM_COMM, VAL_TEST1);

    EXPECT_EQ(v1.get_element(INDEX1), v1[INDEX1]);
    EXPECT_EQ(v1.get_element(INDEX2), v1[INDEX2]);

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        EXPECT_EQ(v1.get_element(i), v1[i]);
    }
}

// test operator ()

TEST(vd_test_operator_curved_brackets, operators) {

    vector_dense<double> v1(DIM_COMM, VAL_TEST1);

    EXPECT_EQ(v1.get_element(INDEX1), v1(INDEX1));
    EXPECT_EQ(v1.get_element(INDEX2), v1(INDEX2));

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        EXPECT_EQ(v1.get_element(i), v1(i));
    }
}

// test operator () and []

TEST(vd_test_operator_curved_square_brackets, operators) {

    vector_dense<double> v1(DIM_COMM, VAL_TEST1);

    EXPECT_EQ(v1.get_element(INDEX1), v1(INDEX1));
    EXPECT_EQ(v1.get_element(INDEX2), v1(INDEX2));

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        EXPECT_EQ(v1[i], v1(i));
    }
}

// test set via operator []

TEST(vd_test_set_operator_square_brackets, operators_set) {

    vector_dense<double> v1(DIM_COMM, VAL_TEST2);

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        EXPECT_EQ(VAL_TEST2, v1(i));
    }

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        v1[i] = static_cast<double>(i);
        EXPECT_EQ(static_cast<double>(i), v1(i));
    }
}

// test operator ++

TEST(vd_test_operator_plus_plus, operators) {

    vector_dense<double> v1(DIM_COMM, VAL_TEST1);

    ++v1;

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        EXPECT_EQ(VAL_TEST1 + 1.0, v1(i));
    }

    v1++;

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        EXPECT_EQ(VAL_TEST1 + 2.0, v1(i));
    }

    v1.deallocate();
    v1.allocate(DIM_COMM);

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        v1[i] = std::sin(static_cast<double>(i));
    }

    v1++;

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)) + 1.0, v1(i), ERROR_M10);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) + 1.0, v1(i), ERROR_M11);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) + 1.0, v1(i), ERROR_M12);
    }

    ++v1;

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)) + 2.0, v1(i), ERROR_M10);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) + 2.0, v1(i), ERROR_M11);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) + 2.0, v1(i), ERROR_M12);
    }
}

// test operator --

TEST(vd_test_operator_minus_minus, operators) {

    vector_dense<double> v1(DIM_COMM, VAL_TEST1);

    --v1;

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        EXPECT_EQ(VAL_TEST1 - 1.0, v1(i));
    }

    v1--;

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        EXPECT_EQ(VAL_TEST1 - 2.0, v1(i));
    }

    v1.deallocate();
    v1.allocate(DIM_COMM);

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        v1[i] = std::sin(static_cast<double>(i));
    }

    v1--;

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)) - 1.0, v1(i), ERROR_M10);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) - 1.0, v1(i), ERROR_M11);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) - 1.0, v1(i), ERROR_M12);
    }

    --v1;

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)) - 2.0, v1(i), ERROR_M10);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) - 2.0, v1(i), ERROR_M11);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) - 2.0, v1(i), ERROR_M12);
    }

}

// test operator +=

TEST(vd_test_operator_plus_equal, operators) {

    vector_dense<double> v1(DIM_COMM, VAL_TEST1);
    vector_dense<double> v2(DIM_COMM, VAL_TEST2);

    v2 += v1;

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        EXPECT_EQ(VAL_TEST1 + VAL_TEST2, v2(i));
        EXPECT_EQ(VAL_TEST1, v1(i));
    }

    v1.deallocate();
    v1.allocate(DIM_COMM);
    v1 = VAL_TEST1;

    v1 += v1;

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        EXPECT_EQ(VAL_TEST1 + VAL_TEST1, v1(i));
    }

    v1.deallocate();
    v2.deallocate();
    v1.allocate(DIM_COMM);
    v2.allocate(DIM_COMM);

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        v1[i] = std::sin(static_cast<double>(i));
        v2[i] = std::cos(static_cast<double>(i));
    }

    v2 += v1;

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)), v1(i), ERROR_M12);
    }

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)) +
                    std::cos(static_cast<double>(i)),
                    v2(i), ERROR_M12);
    }
}

// test operator -=

TEST(vd_test_operator_minus_equal, operators) {

    vector_dense<double> v1(DIM_COMM, VAL_TEST1);
    vector_dense<double> v2(DIM_COMM, VAL_TEST2);

    v2 -= v1;

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        EXPECT_EQ(VAL_TEST2 - VAL_TEST1, v2(i));
        EXPECT_EQ(VAL_TEST1, v1(i));
    }

    v1.deallocate();
    v1.allocate(DIM_COMM);
    v1 = VAL_TEST1;

    v1 -= v1;

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        EXPECT_EQ(VAL_TEST1 - VAL_TEST1, v1(i));
    }

    v1.deallocate();
    v2.deallocate();
    v1.allocate(DIM_COMM);
    v2.allocate(DIM_COMM);

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        v1[i] = std::sin(static_cast<double>(i));
        v2[i] = std::cos(static_cast<double>(i));
    }

    v2 -= v1;

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)), v1(i), ERROR_M12);
    }

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        EXPECT_NEAR(std::cos(static_cast<double>(i)) -
                    std::sin(static_cast<double>(i)),
                    v2(i), ERROR_M12);
    }

    v2 -= v2;

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        EXPECT_EQ(0, v2(i));
    }
}

// test operator *=

TEST(vd_test_operator_times_equal, operators) {

    vector_dense<double> v1(DIM_COMM, VAL_TEST1);
    vector_dense<double> v2(DIM_COMM, VAL_TEST2);

    v2 *= v1;

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        EXPECT_EQ(VAL_TEST1 * VAL_TEST2, v2(i));
        EXPECT_EQ(VAL_TEST1, v1(i));
    }

    v1.deallocate();
    v1.allocate(DIM_COMM);
    v1 = VAL_TEST1;

    v1 *= v1;

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        EXPECT_EQ(VAL_TEST1 * VAL_TEST1, v1(i));
    }

    v1.deallocate();
    v2.deallocate();
    v1.allocate(DIM_COMM);
    v2.allocate(DIM_COMM);

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        v1[i] = std::sin(static_cast<double>(i));
        v2[i] = std::cos(static_cast<double>(i));
    }

    v2 *= v1;

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)), v1(i), ERROR_M12);
    }

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        EXPECT_NEAR(std::cos(static_cast<double>(i)) *
                    std::sin(static_cast<double>(i)),
                    v2(i), ERROR_M12);
    }

    v2 *= v2;

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        EXPECT_NEAR(std::cos(static_cast<double>(i)) *
                    std::sin(static_cast<double>(i)) *
                    std::cos(static_cast<double>(i)) *
                    std::sin(static_cast<double>(i)), v2(i), ERROR_M12);
    }
}

// test operator /=

TEST(vd_test_operator_divide_equal, operators) {

    vector_dense<double> v1(DIM_COMM, VAL_TEST1);
    vector_dense<double> v2(DIM_COMM, VAL_TEST2);

    v2 /= v1;

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        EXPECT_EQ(VAL_TEST2 / VAL_TEST1, v2(i));
        EXPECT_EQ(VAL_TEST1, v1(i));
    }

    v1.deallocate();
    v1.allocate(DIM_COMM);
    v1 = VAL_TEST1;

    v1 /= v1;

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        EXPECT_EQ(VAL_TEST1 / VAL_TEST1, v1(i));
    }

    v1.deallocate();
    v2.deallocate();
    v1.allocate(DIM_COMM);
    v2.allocate(DIM_COMM);

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        v1[i] = static_cast<double>(i + 1);
        v2[i] = static_cast<double>(i + 2);
    }

    v2 /= v1;

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        EXPECT_NEAR(i + 1, v1(i), ERROR_M12);
    }

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        EXPECT_NEAR((i + 2.0) / (i + 1.0), v2(i), ERROR_M12);
    }

    v2 /= v2;

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        EXPECT_NEAR(1.0, v2(i), ERROR_M12);
    }
}

// test operator ==

TEST(vd_test_operator_equal, operators) {

    vector_dense<double> v1(DIM_COMM, VAL_TEST1);
    vector_dense<double> v2(DIM_COMM, VAL_TEST1);

    EXPECT_EQ(v2, v1);
    EXPECT_EQ(v1, v2);
    EXPECT_TRUE(v2 == v1);
    EXPECT_TRUE(v1 == v2);

    v1 = VAL_TEST1;
    v2 = VAL_TEST2;

    EXPECT_FALSE(v2 == v1);
    EXPECT_FALSE(v1 == v2);

    EXPECT_EQ(v1, VAL_TEST1);
    EXPECT_EQ(v2, VAL_TEST2);
}

// test operator !=

TEST(vd_test_operator_not_equal, operators) {

    vector_dense<double> v1(DIM_COMM, VAL_TEST1);
    vector_dense<double> v2(DIM_COMM, VAL_TEST2);

    EXPECT_NE(v2, v1);
    EXPECT_NE(v1, v2);

    EXPECT_TRUE(v2 != v1);
    EXPECT_TRUE(v1 != v2);

    EXPECT_NE(v2, VAL_TEST1);
    EXPECT_NE(v1, VAL_TEST2);
}
