#include <gtest/gtest.h>
#include <cmath>
#include <cstdlib>
#include <parallel/algorithm>
#include "../../../vector_dense/vector_dense.h"

// local parameters

const uint64_t DIM_COMM(static_cast<uint64_t>(std::pow(10.0, 1.0)));
const uint64_t DIM1(static_cast<uint64_t>(std::pow(10.0, 2.0)));
const uint64_t DIM2(static_cast<uint64_t>(std::pow(10.0, 3.0)));
const double VAL_TEST1(123.456);
const uint64_t VAL_TEST2(123456);
const int64_t VAL_TEST3(123456);

// help functions and classes

bool sort_fun(double i, double j) { return (i < j); }

bool sort_fun_reverse(double i, double j) { return (i > j); }

struct sort_class {
    bool operator()(double i, double j) {
        return (i < j);
    }
};

struct sort_class_reverse {
    bool operator()(double i, double j) {
        return (i > j);
    }
};

double rand_num() {
    return static_cast<double>(std::rand() % 100);
}

// help functors

sort_class sort_obj;
sort_class_reverse sort_obj_reverse;

//==========//
// for_each //
//==========//

// test "for_each"

TEST(vd_for_each, STL_algorithms) {

    spl::vector_dense<double> vd1;
    spl::vector_dense<double> vd2;

    vd1.allocate(DIM_COMM);
    vd2.allocate(DIM_COMM);

    for (uint64_t i = 0; i < DIM_COMM; i++) {
        vd1[i] = static_cast<double>(i);
    }

    vd2 = vd1;
    vd2++;

    std::for_each(vd1.begin(), vd1.end(), [](double &x) { x++; });

    EXPECT_EQ(vd1, vd2);
}

//==========//
// generate //
//==========//

// test "generate"

TEST(vd_generate, STL_algorithms) {

    spl::vector_dense<double> vd;

    vd.allocate(DIM_COMM);

    double x(0);
    std::generate(vd.begin(), vd.end(), [&x] { return x++; });

    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end()));
    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end(), sort_obj));
    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end(), sort_fun));

    std::sort(vd.begin(), vd.end(), sort_obj_reverse);

    EXPECT_EQ(false, std::is_sorted(vd.begin(), vd.end()));
    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end(), sort_obj_reverse));
    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end(), sort_fun_reverse));
}

//============//
// generate_n //
//============//

// test "generate_n"

TEST(vd_generate_n, STL_algorithms) {

    spl::vector_dense<double> vd;

    vd.allocate(DIM_COMM);

    double x(0);
    std::generate_n(vd.begin(), DIM_COMM, [&x] { return x++; });

    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end()));
    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end(), sort_obj));
    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end(), sort_fun));

    std::sort(vd.begin(), vd.end(), sort_obj_reverse);

    EXPECT_EQ(false, std::is_sorted(vd.begin(), vd.end()));
    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end(), sort_obj_reverse));
    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end(), sort_fun_reverse));
}

//==========//
// includes //
//==========//

// test "includes" equal vectors

TEST(vd_includes_equal_vectors, STL_algorithms) {

    spl::vector_dense<double> vd1(DIM_COMM, VAL_TEST1);
    spl::vector_dense<double> vd2(DIM_COMM, VAL_TEST1);;

    EXPECT_TRUE(std::includes(vd1.begin(), vd1.end(), vd2.begin(), vd2.end()));
}

// test "includes" same vector

TEST(vd_includes_same_vector, STL_algorithms) {

    spl::vector_dense<double> vd1(DIM_COMM, VAL_TEST1);

    EXPECT_TRUE(std::includes(vd1.begin(), vd1.end(), vd1.begin(), vd1.end()));
}

// test "includes" sorted

TEST(vd_includes_sorted, STL_algorithms) {

    spl::vector_dense<double> vd1;
    spl::vector_dense<double> vd2;

    vd1.allocate(DIM2);
    vd2.allocate(DIM2 - 1);

    double x(0);
    std::generate_n(vd1.begin(), vd1.size(), [&x] { return x++; });

    x = 0;
    std::generate_n(vd2.begin(), vd2.size(), [&x] { return x++; });

    EXPECT_TRUE(std::includes(vd1.begin(), vd1.end(), vd2.begin(), vd2.end()));
}

// test "includes" sorted reversed

TEST(vd_includes_sorted_reverse, STL_algorithms) {

    spl::vector_dense<double> vd1;
    spl::vector_dense<double> vd2;

    vd1.allocate(DIM2);
    vd2.allocate(DIM2);

    double x(0);
    std::generate_n(vd1.begin(), vd1.size(), [&x] { return x--; });

    x = 0;
    std::generate_n(vd2.begin(), vd2.size(), [&x] { return x--; });

    EXPECT_TRUE(std::includes(vd1.begin(), vd1.end(), vd2.begin(), vd2.end(), sort_obj_reverse));
}

//===========//
// is_sorted //
//===========//

// test "is_sorted" default

TEST(vd_is_sorted_default, STL_algorithms) {

    spl::vector_dense<double> vd;

    vd.allocate(DIM_COMM);
    vd = VAL_TEST1;

    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end()));
    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end(), sort_obj));
    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end(), sort_fun));

    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end(), sort_obj_reverse));
    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end(), sort_fun_reverse));
}

// test "is_sorted" non-default

TEST(vd_is_sorted_non_default, STL_algorithms) {

    spl::vector_dense<double> vd;

    vd.allocate(DIM_COMM);

    std::generate(vd.begin(), vd.end(), rand_num);

    EXPECT_EQ(false, std::is_sorted(vd.begin(), vd.end()));
    EXPECT_EQ(false, std::is_sorted(vd.begin(), vd.end(), sort_obj));
    EXPECT_EQ(false, std::is_sorted(vd.begin(), vd.end(), sort_fun));

    std::sort(vd.begin(), vd.end());

    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end()));
    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end(), sort_obj));
    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end(), sort_fun));
}

// test "is_sorted" non-default reverse

TEST(vd_is_sorted_non_default_reverse, STL_algorithms) {

    spl::vector_dense<double> vd;

    vd.allocate(DIM_COMM);

    std::generate(vd.begin(), vd.end(), rand_num);

    EXPECT_EQ(false, std::is_sorted(vd.begin(), vd.end(), sort_obj_reverse));
    EXPECT_EQ(false, std::is_sorted(vd.begin(), vd.end(), sort_fun_reverse));

    std::sort(vd.begin(), vd.end(), sort_obj_reverse);

    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end(), sort_obj_reverse));
    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end(), sort_fun_reverse));
}

//=========//
// reverse //
//=========//

// test "reverse" constructor default

TEST(vd_reverse_constructor_default, STL_algorithms) {

    spl::vector_dense<double> vd1;
    spl::vector_dense<double> vd2;

    vd1.allocate(DIM_COMM);
    vd2.allocate(DIM_COMM);

    for (uint64_t i = 0; i < DIM_COMM; i++) {
        vd1[i] = static_cast<double>(i);
    }

    vd2 = vd1;

    std::reverse(vd1.begin(), vd1.end());

    for (uint64_t i = 0; i < DIM_COMM; i++) {
        EXPECT_EQ(DIM_COMM - 1 - i, vd1[i]);
    }

    std::reverse(vd1.begin(), vd1.end());

    EXPECT_EQ(vd1, vd2);
}

// test "reverse" constructor one

TEST(vd_reverse_constructor_one, STL_algorithms) {

    spl::vector_dense<double> vd1(DIM_COMM);
    spl::vector_dense<double> vd2(DIM_COMM);

    for (uint64_t i = 0; i < DIM_COMM; i++) {
        vd1[i] = static_cast<double>(i);
    }

    vd2 = vd1;

    std::reverse(vd1.begin(), vd1.end());

    for (uint64_t i = 0; i < DIM_COMM; i++) {
        EXPECT_EQ(DIM_COMM - 1 - i, vd1[i]);
    }

    std::reverse(vd1.begin(), vd1.end());

    EXPECT_EQ(vd1, vd2);
}

// test "reverse" constructor two

TEST(vd_reverse_constructor_two, STL_algorithms) {

    spl::vector_dense<double> vd1(DIM_COMM, VAL_TEST1);
    spl::vector_dense<double> vd2(DIM_COMM, VAL_TEST1);

    EXPECT_EQ(vd1, vd2);

    std::reverse(vd1.begin(), vd1.end());

    EXPECT_EQ(vd1, vd2);

    std::reverse(vd1.begin(), vd1.end());

    EXPECT_EQ(vd1, vd2);
}

//==============//
// reverse_copy //
//==============//

// test "reverse_copy" constructor default

TEST(vd_reverse_copy_constructor_default, STL_algorithms) {

    spl::vector_dense<double> vd1;
    spl::vector_dense<double> vd2;

    vd1.allocate(DIM_COMM);
    vd2.allocate(DIM_COMM);

    for (uint64_t i = 0; i < DIM_COMM; i++) {
        vd1[i] = static_cast<double>(i);
    }

    std::reverse_copy(vd1.begin(), vd1.end(), vd2.begin());

    for (uint64_t i = 0; i < DIM_COMM; i++) {
        EXPECT_EQ(DIM_COMM - 1 - i, vd2[i]);
    }

    std::reverse(vd2.begin(), vd2.end());

    EXPECT_EQ(vd1, vd2);
}

// test "reverse_copy" constructor one

TEST(vd_reverse_copy_constructor_one, STL_algorithms) {

    spl::vector_dense<double> vd1(DIM_COMM);
    spl::vector_dense<double> vd2(DIM_COMM);

    for (uint64_t i = 0; i < DIM_COMM; i++) {
        vd1[i] = static_cast<double>(i);
    }

    for (uint64_t i = 0; i < DIM_COMM; i++) {
        vd1[i] = static_cast<double>(i);
    }

    std::reverse_copy(vd1.begin(), vd1.end(), vd2.begin());

    for (uint64_t i = 0; i < DIM_COMM; i++) {
        EXPECT_EQ(DIM_COMM - 1 - i, vd2[i]);
    }

    std::reverse(vd2.begin(), vd2.end());

    EXPECT_EQ(vd1, vd2);
}

// test "reverse_copy" constructor two

TEST(vd_reverse_copy_constructor_two, STL_algorithms) {

    spl::vector_dense<double> vd1(DIM_COMM, VAL_TEST1);
    spl::vector_dense<double> vd2(DIM_COMM, VAL_TEST1);

    EXPECT_EQ(vd1, vd2);

    vd2 = VAL_TEST2;

    EXPECT_EQ(vd2, VAL_TEST2);

    std::reverse_copy(vd1.begin(), vd1.end(), vd2.begin());

    EXPECT_EQ(vd1, vd2);
}

//======//
// sort //
//======//

// test "sort" default

TEST(vd_sort_default, STL_algorithms) {

    spl::vector_dense<double> vd;

    vd.allocate(DIM_COMM);

    for (uint64_t i = 0; i != vd.size(); i++) {
        vd[i] = static_cast<double>(i);
    }

    std::reverse(vd.begin(), vd.end());

    std::sort(vd.begin(), vd.end());

    for (uint64_t i = 0; i != vd.size(); i++) {
        EXPECT_EQ(i, vd[i]);
    }
}

// test "sort" non-default

TEST(vd_sort_non_default, STL_algorithms) {

    spl::vector_dense<double> vd;

    vd.allocate(DIM_COMM);

    for (uint64_t i = 0; i != vd.size(); i++) {
        vd[i] = static_cast<double>(i);
    }

    std::reverse(vd.begin(), vd.end());

    std::sort(vd.begin(), vd.end(), sort_fun);

    for (uint64_t i = 0; i != vd.size(); i++) {
        EXPECT_EQ(i, vd[i]);
    }

    std::reverse(vd.begin(), vd.end());

    std::sort(vd.begin(), vd.end(), sort_obj);

    for (uint64_t i = 0; i != vd.size(); i++) {
        EXPECT_EQ(i, vd[i]);
    }
}
