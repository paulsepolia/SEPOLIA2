#include <gtest/gtest.h>
#include <cmath>
#include "../../../vector_dense/vector_dense.h"

// local parameters

const uint64_t DIM_COMM(static_cast<uint64_t>(std::pow(10.0, 1.0)));
const uint64_t DIM1(static_cast<uint64_t>(std::pow(10.0, 2.0)));
const uint64_t DIM2(static_cast<uint64_t>(std::pow(10.0, 3.0)));
const double VAL_TEST1(123.456);
const uint64_t VAL_TEST2(123456);
const int64_t VAL_TEST3(123456);

// test "at" modify and access elements

TEST(vd_at_modify_access_elements, STL_members) {

    sep::vector_dense<double> vd(DIM_COMM);

    for (uint64_t i = 0; i < DIM_COMM; i++) {
        vd.at(i) = VAL_TEST1;
        EXPECT_EQ(VAL_TEST1, vd.at(i));
    }
}

// test "at" access elements in const vector

TEST(vd_at_access_elements_const_vector, STL_members) {

    const sep::vector_dense<double> vd(DIM_COMM, VAL_TEST1);

    for (uint64_t i = 0; i < DIM_COMM; i++) { ;
        EXPECT_EQ(VAL_TEST1, vd.at(i));
    }
}

// test "back" access element

TEST(vd_back_access_element, STL_members) {

    sep::vector_dense<double> vd(DIM_COMM);

    for (uint64_t i = 0; i < DIM_COMM; i++) {
        vd.at(i) = static_cast<double>(i);
    }

    EXPECT_EQ(vd.back(), static_cast<double>(DIM_COMM - 1));
    EXPECT_EQ(vd.back(), vd.at(DIM_COMM - 1));
    EXPECT_EQ(vd.back(), vd[DIM_COMM - 1]);
    EXPECT_EQ(vd.back(), vd(DIM_COMM - 1));
}

// test "back" access element in const vector

TEST(vd_back_access_element_const_vector, STL_members) {

    const sep::vector_dense<double> vd(DIM_COMM, 100.0);

    EXPECT_EQ(vd.back(), 100.0);
    EXPECT_EQ(vd.back(), vd.at(DIM_COMM - 1));
    EXPECT_EQ(vd.back(), vd[DIM_COMM - 1]);
    EXPECT_EQ(vd.back(), vd(DIM_COMM - 1));
}

// test "begin" access elements

TEST(vd_begin_access_elements, STL_members) {

    sep::vector_dense<double> vd(DIM_COMM);

    for (uint64_t i = 0; i < DIM_COMM; i++) {
        vd.at(i) = static_cast<double>(i);
    }

    for (uint64_t i = 0; i < DIM_COMM; i++) {
        EXPECT_EQ(*(vd.begin() + i), vd.at(i));
    }
}

// test "begin" access elements in const vector

TEST(vd_begin_access_elements_const_vector, STL_members) {

    const sep::vector_dense<double> vd(DIM_COMM, VAL_TEST1);

    for (uint64_t i = 0; i < DIM_COMM; i++) {
        EXPECT_EQ(*(vd.begin() + i), vd.at(i));
    }
}

// test "begin" modify elements

TEST(vd_begin_modify_elements, STL_members) {

    sep::vector_dense<double> vd(DIM_COMM);

    for (uint64_t i = 0; i < DIM_COMM; i++) {
        *(vd.begin() + i) = static_cast<double>(i);
    }

    for (uint64_t i = 0; i < DIM_COMM; i++) {
        EXPECT_EQ(vd.at(i), static_cast<double>(i));
    }
}

// test "clear" default constructor

TEST(vd_clear_default_constructor, STL_members) {

    sep::vector_dense<double> vd;

    vd.clear();

    EXPECT_EQ(vd.size(), 0);
    EXPECT_EQ(vd.size(), 0);
    EXPECT_EQ(vd.is_allocated(), false);
    EXPECT_EQ(vd.is_deallocated(), true);

    vd.allocate(DIM_COMM);

    vd.clear();

    EXPECT_EQ(vd.size(), 0);
    EXPECT_EQ(vd.size(), 0);
    EXPECT_EQ(vd.is_allocated(), false);
    EXPECT_EQ(vd.is_deallocated(), true);

    vd.allocate(DIM_COMM);

    vd.deallocate();

    EXPECT_EQ(vd.size(), 0);
    EXPECT_EQ(vd.size(), 0);
    EXPECT_EQ(vd.is_allocated(), false);
    EXPECT_EQ(vd.is_deallocated(), true);
}

// test "clear"  constructor with one argument

TEST(vd_clear_constructor_with_one_argument, STL_members) {

    sep::vector_dense<double> vd(DIM_COMM);

    vd.clear();

    EXPECT_EQ(vd.size(), 0);
    EXPECT_EQ(vd.size(), 0);
    EXPECT_EQ(vd.is_allocated(), false);
    EXPECT_EQ(vd.is_deallocated(), true);

    vd.allocate(DIM_COMM);

    vd.clear();

    EXPECT_EQ(vd.size(), 0);
    EXPECT_EQ(vd.size(), 0);
    EXPECT_EQ(vd.is_allocated(), false);
    EXPECT_EQ(vd.is_deallocated(), true);

    vd.allocate(DIM_COMM);

    vd.deallocate();

    EXPECT_EQ(vd.size(), 0);
    EXPECT_EQ(vd.size(), 0);
    EXPECT_EQ(vd.is_allocated(), false);
    EXPECT_EQ(vd.is_deallocated(), true);
}

// test "clear" constructor with two arguments

TEST(vd_clear_constructor_with_two_arguments, STL_members) {

    sep::vector_dense<double> vd(DIM_COMM, VAL_TEST1);

    vd.clear();

    EXPECT_EQ(vd.size(), 0);
    EXPECT_EQ(vd.size(), 0);
    EXPECT_EQ(vd.is_allocated(), false);
    EXPECT_EQ(vd.is_deallocated(), true);

    vd.allocate(DIM_COMM);

    vd.clear();

    EXPECT_EQ(vd.size(), 0);
    EXPECT_EQ(vd.size(), 0);
    EXPECT_EQ(vd.is_allocated(), false);
    EXPECT_EQ(vd.is_deallocated(), true);

    vd.allocate(DIM_COMM);

    vd.deallocate();

    EXPECT_EQ(vd.size(), 0);
    EXPECT_EQ(vd.size(), 0);
    EXPECT_EQ(vd.is_allocated(), false);
    EXPECT_EQ(vd.is_deallocated(), true);
}

// test "end" access elements

TEST(vd_end_access_elements, STL_members) {

    sep::vector_dense<double> vd(DIM_COMM);

    for (uint64_t i = 0; i < DIM_COMM; i++) {
        vd.at(i) = static_cast<double>(i);
    }

    for (uint64_t i = 0; i < DIM_COMM; i++) {
        EXPECT_EQ(*(vd.end() - 1 - i), vd.at(DIM_COMM - 1 - i));
    }
}

// test "end" access elements in const vector

TEST(vd_end_access_elements_const_vector, STL_members) {

    const sep::vector_dense<double> vd(DIM_COMM, VAL_TEST1);

    for (uint64_t i = 0; i < DIM_COMM; i++) {
        EXPECT_EQ(*(vd.end() - 1 - i), vd.at(DIM_COMM - 1 - i));
    }
}

// test "end" modify elements

TEST(vd_end_modify_elements, STL_members) {

    sep::vector_dense<double> vd(DIM_COMM);

    for (uint64_t i = 0; i < DIM_COMM; i++) {
        *(vd.end() - 1 - i) = static_cast<double>(DIM_COMM - 1 - i);
    }

    for (uint64_t i = 0; i < DIM_COMM; i++) {
        EXPECT_EQ(vd.at(i), static_cast<double>(i));
    }
}

// test "begin_end" for loop

TEST(vd_begin_end_for_loop, STL_members) {

    sep::vector_dense<double> vd(DIM_COMM);

    double val(0);
    for (auto it = vd.begin(); it != vd.end(); it++) {
        *it = val;
        val++;
    }

    for (uint64_t i = 0; i < DIM_COMM; i++) {
        EXPECT_EQ(vd[i], static_cast<double>(i));
    }
}

// test "begin_end" for loop in const vector

TEST(vd_begin_end_for_loop_const_vector, STL_members) {

    const sep::vector_dense<double> vd(DIM_COMM, VAL_TEST1);

    for (auto it = vd.begin(); it != vd.end(); it++) {
        EXPECT_EQ(*it, VAL_TEST1);
    }
}

// test "empty"

TEST(vd_empty, STL_members) {

    sep::vector_dense<double> vd1(DIM_COMM, VAL_TEST1);

    EXPECT_FALSE(vd1.empty());

    sep::vector_dense<double> vd2(DIM_COMM);

    EXPECT_FALSE(vd2.empty());

    sep::vector_dense<double> vd3;

    EXPECT_TRUE(vd3.empty());
}

// test "empty" for const vectors

TEST(vd_empty_const_vectors, STL_members) {

    const sep::vector_dense<double> vd1(DIM_COMM, VAL_TEST1);

    EXPECT_FALSE(vd1.empty());

    const sep::vector_dense<double> vd2(DIM_COMM);

    EXPECT_FALSE(vd2.empty());

    const sep::vector_dense<double> vd3;

    EXPECT_TRUE(vd3.empty());
}

// test "for-loop" with begin() and end()

TEST(vd_for_loop_begin_end, STL_members) {

    sep::vector_dense<double> vd(DIM_COMM, VAL_TEST1);

    for (auto it = vd.begin(); it != vd.end(); it++) {
        EXPECT_EQ(*it, VAL_TEST1);
    }

    vd.deallocate();
    vd.allocate(DIM2);
    double val(0);

    for (auto it = vd.begin(); it != vd.end(); it++) {
        *it = ++val;
        EXPECT_EQ(*it, val);
    }

    for (uint64_t i = 0; i != vd.size(); i++) {
        EXPECT_EQ(vd[i], static_cast<double>(i + 1));
    }
}

// test "for-loop" with auto

TEST(vd_for_loop_auto, STL_members) {

    sep::vector_dense<double> vd(DIM_COMM, VAL_TEST1);

    for (const auto &elem: vd) {
        EXPECT_EQ(elem, VAL_TEST1);
    }

    vd.deallocate();
    vd.allocate(DIM2);
    double val(0);

    for (auto &elem: vd) {
        elem = ++val;
    }

    val = 0;
    for (auto &elem: vd) {
        EXPECT_EQ(elem, ++val);
    }

    for (uint64_t i = 0; i != vd.size(); i++) {
        EXPECT_EQ(vd[i], static_cast<double>(i + 1));
    }
}

// test "front" access element

TEST(vd_front_access_element, STL_members) {

    sep::vector_dense<double> vd(DIM_COMM);

    for (uint64_t i = 0; i < DIM_COMM; i++) {
        vd.at(i) = static_cast<double>(i);
    }

    EXPECT_EQ(vd.front(), static_cast<double>(0));
    EXPECT_EQ(vd.front(), vd.at(0));
    EXPECT_EQ(vd.front(), vd[0]);
    EXPECT_EQ(vd.front(), vd(0));
}

// test "front" access element in const vector

TEST(vd_front_access_element_const_vector, STL_members) {

    const sep::vector_dense<double> vd(DIM_COMM, 100.0);

    EXPECT_EQ(vd.front(), 100.0);
    EXPECT_EQ(vd.front(), vd.at(0));
    EXPECT_EQ(vd.front(), vd[0]);
    EXPECT_EQ(vd.front(), vd(0));
}

// test "size" default constructor

TEST(vd_size_default_constructor, STL_members) {

    sep::vector_dense<double> vd;

    EXPECT_EQ(vd.size(), 0);

    vd.allocate(DIM_COMM);
    EXPECT_EQ(vd.size(), DIM_COMM);

    vd.deallocate();
    EXPECT_EQ(vd.size(), 0);
}

// test "size" constructor with one argument

TEST(vd_size_constructor_one_argument, STL_members) {

    sep::vector_dense<double> vd(DIM_COMM);

    EXPECT_EQ(vd.size(), DIM_COMM);

    vd.deallocate();
    EXPECT_EQ(vd.size(), 0);

    vd.allocate(DIM_COMM + 100);
    EXPECT_EQ(vd.size(), DIM_COMM + 100);
}

// test "size" constructor with two arguments

TEST(vd_size_constructor_two_arguments, STL_members) {

    sep::vector_dense<double> vd(DIM_COMM, VAL_TEST1);

    EXPECT_EQ(vd.size(), DIM_COMM);

    vd.deallocate();
    EXPECT_EQ(vd.size(), 0);

    vd.allocate(DIM_COMM + 100);
    EXPECT_EQ(vd.size(), DIM_COMM + 100);
}

// test "swap" default constructor, same size

TEST(vd_swap_default_constructor_same_size, STL_members) {

    sep::vector_dense<double> vd1;

    vd1.allocate(DIM_COMM);
    vd1 = VAL_TEST1;

    sep::vector_dense<double> vd2;

    vd2.allocate(DIM_COMM);
    vd2 = VAL_TEST2;

    vd1.swap(vd2);

    EXPECT_EQ(vd1, VAL_TEST2);
    EXPECT_EQ(vd2, VAL_TEST1);
    EXPECT_EQ(vd1.size(), DIM_COMM);
    EXPECT_EQ(vd2.size(), DIM_COMM);
    EXPECT_EQ(vd1.is_allocated(), true);
    EXPECT_EQ(vd2.is_allocated(), true);
}

// test "swap" default constructor, different size

TEST(vd_swap_default_constructor_different_size, STL_members) {

    sep::vector_dense<double> vd1;

    vd1.allocate(DIM1);
    vd1 = VAL_TEST1;

    sep::vector_dense<double> vd2;

    vd2.allocate(DIM2);
    vd2 = VAL_TEST2;

    vd1.swap(vd2);

    EXPECT_EQ(vd1, VAL_TEST2);
    EXPECT_EQ(vd2, VAL_TEST1);
    EXPECT_EQ(vd1.size(), DIM2);
    EXPECT_EQ(vd2.size(), DIM1);
    EXPECT_EQ(vd1.is_allocated(), true);
    EXPECT_EQ(vd2.is_allocated(), true);
}

// test "swap" constructor one, same size

TEST(vd_swap_constructor_one_same_size, STL_members) {

    sep::vector_dense<double> vd1(DIM_COMM);

    vd1 = VAL_TEST1;

    sep::vector_dense<double> vd2(DIM_COMM);

    vd2 = VAL_TEST2;

    vd1.swap(vd2);

    EXPECT_EQ(vd1, VAL_TEST2);
    EXPECT_EQ(vd2, VAL_TEST1);
    EXPECT_EQ(vd1.size(), DIM_COMM);
    EXPECT_EQ(vd2.size(), DIM_COMM);
    EXPECT_EQ(vd1.is_allocated(), true);
    EXPECT_EQ(vd2.is_allocated(), true);
}

// test "swap" constructor one, different size

TEST(vd_swap_constructor_one_different_size, STL_members) {

    sep::vector_dense<double> vd1(DIM1);

    vd1 = VAL_TEST1;

    sep::vector_dense<double> vd2(DIM2);

    vd2 = VAL_TEST2;

    vd1.swap(vd2);

    EXPECT_EQ(vd1, VAL_TEST2);
    EXPECT_EQ(vd2, VAL_TEST1);
    EXPECT_EQ(vd1.size(), DIM2);
    EXPECT_EQ(vd2.size(), DIM1);
    EXPECT_EQ(vd1.is_allocated(), true);
    EXPECT_EQ(vd2.is_allocated(), true);
}

// test "swap" constructor two, same size

TEST(vd_swap_constructor_two_same_size, STL_members) {

    sep::vector_dense<double> vd1(DIM_COMM, VAL_TEST1);
    sep::vector_dense<double> vd2(DIM_COMM, VAL_TEST2);

    vd1.swap(vd2);

    EXPECT_EQ(vd1, VAL_TEST2);
    EXPECT_EQ(vd2, VAL_TEST1);
    EXPECT_EQ(vd1.size(), DIM_COMM);
    EXPECT_EQ(vd2.size(), DIM_COMM);
    EXPECT_EQ(vd1.is_allocated(), true);
    EXPECT_EQ(vd2.is_allocated(), true);
}

// test "swap" constructor two, different size

TEST(vd_swap_constructor_two_different_size, STL_members) {

    sep::vector_dense<double> vd1(DIM1, VAL_TEST1);
    sep::vector_dense<double> vd2(DIM2, VAL_TEST2);

    vd1.swap(vd2);

    EXPECT_EQ(vd1, VAL_TEST2);
    EXPECT_EQ(vd2, VAL_TEST1);
    EXPECT_EQ(vd1.size(), DIM2);
    EXPECT_EQ(vd2.size(), DIM1);
    EXPECT_EQ(vd1.is_allocated(), true);
    EXPECT_EQ(vd2.is_allocated(), true);
}
