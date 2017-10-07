#include <gtest/gtest.h>
#include <cmath>
#include "../../../vector_dense/vector_dense.h"

// local parameters

const uint64_t DIM_COMM(static_cast<uint64_t>(std::pow(10.0, 4.0)));
const double VAL_TEST1(123.456);
const uint64_t VAL_TEST2(123456);
const int64_t VAL_TEST3(123456);

// test set element via constructor and get it, double case

TEST(vd_set_element_via_constructor_and_get_it_double, set_get) {

    spl::vector_dense<double> vd(DIM_COMM, VAL_TEST1);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(VAL_TEST1, vd.get_element(i));
        EXPECT_EQ(VAL_TEST1, vd[i]);
        EXPECT_EQ(VAL_TEST1, vd(i));
    }

    EXPECT_EQ(vd, VAL_TEST1);
}

// test set element via constructor and get it, uint64_t case

TEST(vd_set_element_via_constructor_and_get_it_uint64_t, set_get) {

    spl::vector_dense<uint64_t> vd(DIM_COMM, VAL_TEST2);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(VAL_TEST2, vd.get_element(i));
        EXPECT_EQ(VAL_TEST2, vd[i]);
        EXPECT_EQ(VAL_TEST2, vd(i));
    }

    EXPECT_EQ(vd, VAL_TEST2);
}

// test set element via constructor and get it, int64_t case

TEST(vd_set_element_via_constructor_and_get_it_int64_t, set_get) {

    spl::vector_dense<uint64_t> vd(DIM_COMM, VAL_TEST3);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(VAL_TEST3, vd.get_element(i));
        EXPECT_EQ(VAL_TEST3, vd[i]);
        EXPECT_EQ(VAL_TEST3, vd(i));
    }

    EXPECT_EQ(vd, VAL_TEST3);
}

// test set dimension via constructor and get it, double case

TEST(vd_set_dimension_via_constructor_and_get_it_double, set_get) {

    spl::vector_dense<double> vd(DIM_COMM);

    EXPECT_EQ(DIM_COMM, vd.size());
}

// test set dimension via constructor and get it, uint64_t case

TEST(vd_set_dimension_via_constructor_and_get_it_uint64_t, set_get) {

    spl::vector_dense<uint64_t> vd(DIM_COMM);

    EXPECT_EQ(DIM_COMM, vd.size());
}

// test set dimension via constructor and get it, int64_t case

TEST(vd_set_dimension_via_constructor_and_get_it_int64_t, set_get) {

    spl::vector_dense<int64_t> vd(DIM_COMM);

    EXPECT_EQ(DIM_COMM, vd.size());
}

// test set dimension via allocate and get it, double case

TEST(vd_set_dimension_via_allocate_and_get_it_double, set_get) {

    spl::vector_dense<double> vd;
    vd.allocate(DIM_COMM);

    EXPECT_EQ(DIM_COMM, vd.size());
}

// test set dimension via allocate and get it, unit64_t case

TEST(vd_set_dimension_via_allocate_and_get_it_uint64_t, set_get) {

    spl::vector_dense<uint64_t> vd;
    vd.allocate(DIM_COMM);

    EXPECT_EQ(DIM_COMM, vd.size());
}

// test set dimension via allocate and get it, int64_t case

TEST(vd_set_dimension_via_allocate_and_get_it_int64_t, set_get) {

    spl::vector_dense<int64_t> vd;
    vd.allocate(DIM_COMM);

    EXPECT_EQ(DIM_COMM, vd.size());
}

// test set element and get it, double case

TEST(vd_set_element_and_get_it_double, set_get) {

    spl::vector_dense<double> vd(DIM_COMM);

    EXPECT_EQ(DIM_COMM, vd.size());

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        vd.set_element(i, static_cast<double>(i));
    }

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd.get_element(i), static_cast<double>(i));
        EXPECT_EQ(vd(i), static_cast<double>(i));
        EXPECT_EQ(vd[i], static_cast<double>(i));
    }

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        vd[i] = static_cast<double>(i);
    }

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd.get_element(i), static_cast<double>(i));
        EXPECT_EQ(vd(i), static_cast<double>(i));
        EXPECT_EQ(vd[i], static_cast<double>(i));
    }
}

// test set element and get it, uint64_t case

TEST(vd_set_element_and_get_it_uint64_t, set_get) {

    spl::vector_dense<uint64_t> vd(DIM_COMM);

    EXPECT_EQ(DIM_COMM, vd.size());

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        vd.set_element(i, i);
    }

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd.get_element(i), i);
        EXPECT_EQ(vd(i), i);
        EXPECT_EQ(vd[i], i);
    }

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        vd[i] = i;
    }

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd.get_element(i), i);
        EXPECT_EQ(vd(i), i);
        EXPECT_EQ(vd[i], i);
    }
}

// test set element and get it, int64_t case

TEST(vd_set_element_and_get_it_int64_t, set_get) {

    spl::vector_dense<int64_t> vd(DIM_COMM);

    EXPECT_EQ(DIM_COMM, vd.size());

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        vd.set_element(i, i);
    }

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd.get_element(i), i);
        EXPECT_EQ(vd(i), i);
        EXPECT_EQ(vd[i], i);
    }

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        vd[i] = i;
    }

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd.get_element(i), i);
        EXPECT_EQ(vd(i), i);
        EXPECT_EQ(vd[i], i);
    }
}

// test set the vector to another vector using operator = and get some elements, double case

TEST(vd_set_vector_to_another_using_assignment_operator_double, set_get) {

    spl::vector_dense<double> vd1(DIM_COMM, VAL_TEST1);
    spl::vector_dense<double> vd2;

    EXPECT_EQ(DIM_COMM, vd1.size());

    vd2 = vd1;

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd1.get_element(i), VAL_TEST1);
        EXPECT_EQ(vd2.get_element(i), VAL_TEST1);
        EXPECT_EQ(vd1(i), VAL_TEST1);
        EXPECT_EQ(vd2(i), VAL_TEST1);
        EXPECT_EQ(vd1[i], VAL_TEST1);
        EXPECT_EQ(vd2[i], VAL_TEST1);
    }

    EXPECT_EQ(vd1.size(), DIM_COMM);
}

// test set the vector to another vector using operator = and get some elements, uint64_t case

TEST(vd_set_vector_to_another_using_assignment_operator_uint64_t, set_get) {

    spl::vector_dense<uint64_t> vd1(DIM_COMM, VAL_TEST2);
    spl::vector_dense<uint64_t> vd2;

    EXPECT_EQ(DIM_COMM, vd1.size());

    vd2 = vd1;

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd1.get_element(i), VAL_TEST2);
        EXPECT_EQ(vd2.get_element(i), VAL_TEST2);
        EXPECT_EQ(vd1(i), VAL_TEST2);
        EXPECT_EQ(vd2(i), VAL_TEST2);
        EXPECT_EQ(vd1[i], VAL_TEST2);
        EXPECT_EQ(vd2[i], VAL_TEST2);
    }

    EXPECT_EQ(vd1.size(), DIM_COMM);
}

// test set the vector to another vector using operator = and get some elements, int64_t case

TEST(vd_set_vector_to_another_using_assignment_operator_int64_t, set_get) {

    spl::vector_dense<int64_t> vd1(DIM_COMM, VAL_TEST3);
    spl::vector_dense<int64_t> vd2;

    EXPECT_EQ(DIM_COMM, vd1.size());

    vd2 = vd1;

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd1.get_element(i), VAL_TEST3);
        EXPECT_EQ(vd2.get_element(i), VAL_TEST3);
        EXPECT_EQ(vd1(i), VAL_TEST3);
        EXPECT_EQ(vd2(i), VAL_TEST3);
        EXPECT_EQ(vd1[i], VAL_TEST3);
        EXPECT_EQ(vd2[i], VAL_TEST3);
    }

    EXPECT_EQ(vd1.size(), DIM_COMM);
}

// test set the vector to element and get some elements, double case

TEST(vd_set_vector_to_element_using_assignment_operator_double, set_get) {

    spl::vector_dense<double> vd1;
    vd1.allocate(DIM_COMM);

    EXPECT_EQ(DIM_COMM, vd1.size());

    vd1 = VAL_TEST1;

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd1.get_element(i), VAL_TEST1);
        EXPECT_EQ(vd1(i), VAL_TEST1);
        EXPECT_EQ(vd1[i], VAL_TEST1);
    }

    spl::vector_dense<double> vd2;
    vd2 = vd1;

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd2.get_element(i), VAL_TEST1);
        EXPECT_EQ(vd2(i), VAL_TEST1);
        EXPECT_EQ(vd2[i], VAL_TEST1);
    }

    EXPECT_EQ(vd2.size(), DIM_COMM);
}

// test set the vector to element and get some elements, uint64_t case

TEST(vd_set_vector_to_element_using_assignment_operator_uint64_t, set_get) {

    spl::vector_dense<uint64_t> vd1;
    vd1.allocate(DIM_COMM);

    EXPECT_EQ(DIM_COMM, vd1.size());

    vd1 = VAL_TEST2;

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd1.get_element(i), VAL_TEST2);
        EXPECT_EQ(vd1(i), VAL_TEST2);
        EXPECT_EQ(vd1[i], VAL_TEST2);
    }

    spl::vector_dense<uint64_t> vd2;
    vd2 = vd1;

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd2.get_element(i), VAL_TEST2);
        EXPECT_EQ(vd2(i), VAL_TEST2);
        EXPECT_EQ(vd2[i], VAL_TEST2);
    }

    EXPECT_EQ(vd2.size(), DIM_COMM);
}

// test set the vector to element and get some elements, int64_t case

TEST(vd_set_vector_to_element_using_assignment_operator_int64_t, set_get) {

    spl::vector_dense<int64_t> vd1;
    vd1.allocate(DIM_COMM);

    EXPECT_EQ(DIM_COMM, vd1.size());

    vd1 = VAL_TEST3;

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd1.get_element(i), VAL_TEST3);
        EXPECT_EQ(vd1(i), VAL_TEST3);
        EXPECT_EQ(vd1[i], VAL_TEST3);
    }

    spl::vector_dense<int64_t> vd2;
    vd2 = vd1;

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd2.get_element(i), VAL_TEST3);
        EXPECT_EQ(vd2(i), VAL_TEST3);
        EXPECT_EQ(vd2[i], VAL_TEST3);
    }

    EXPECT_EQ(vd2.size(), DIM_COMM);
}

// test set the vector via copy constructor and get some elements, double case

TEST(vd_set_vector_via_copy_constructor_double, set_get) {

    spl::vector_dense<double> vd1(DIM_COMM, VAL_TEST1);

    EXPECT_EQ(DIM_COMM, vd1.size());

    spl::vector_dense<double> vd2(vd1);

    EXPECT_EQ(vd1.size(), DIM_COMM);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd1.get_element(i), VAL_TEST1);
        EXPECT_EQ(vd2.get_element(i), VAL_TEST1);
        EXPECT_EQ(vd1(i), VAL_TEST1);
        EXPECT_EQ(vd2(i), VAL_TEST1);
        EXPECT_EQ(vd1[i], VAL_TEST1);
        EXPECT_EQ(vd2[i], VAL_TEST1);
    }
}

// test set the vector via copy constructor and get some elements, uint64_t case

TEST(vd_set_vector_via_copy_constructor_uint64_t, set_get) {

    spl::vector_dense<uint64_t> vd1(DIM_COMM, VAL_TEST2);

    EXPECT_EQ(DIM_COMM, vd1.size());

    spl::vector_dense<uint64_t> vd2(vd1);

    EXPECT_EQ(vd1.size(), DIM_COMM);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd1.get_element(i), VAL_TEST2);
        EXPECT_EQ(vd2.get_element(i), VAL_TEST2);
        EXPECT_EQ(vd1(i), VAL_TEST2);
        EXPECT_EQ(vd2(i), VAL_TEST2);
        EXPECT_EQ(vd1[i], VAL_TEST2);
        EXPECT_EQ(vd2[i], VAL_TEST2);
    }
}

// test set the vector via copy constructor and get some elements, int64_t case

TEST(vd_set_vector_via_copy_constructor_int64_t, set_get) {

    spl::vector_dense<int64_t> vd1(DIM_COMM, VAL_TEST3);

    EXPECT_EQ(DIM_COMM, vd1.size());

    spl::vector_dense<int64_t> vd2(vd1);

    EXPECT_EQ(vd1.size(), DIM_COMM);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd1.get_element(i), VAL_TEST3);
        EXPECT_EQ(vd2.get_element(i), VAL_TEST3);
        EXPECT_EQ(vd1(i), VAL_TEST3);
        EXPECT_EQ(vd2(i), VAL_TEST3);
        EXPECT_EQ(vd1[i], VAL_TEST3);
        EXPECT_EQ(vd2[i], VAL_TEST3);
    }
}

// test set the vector via move constructor and get some elements, double case

TEST(vd_set_vector_via_move_constructor_double, set_get) {

    spl::vector_dense<double> vd1(DIM_COMM, VAL_TEST1);

    EXPECT_EQ(DIM_COMM, vd1.size());

    spl::vector_dense<double> vd2(std::move(vd1));

    EXPECT_EQ(vd1.is_allocated(), false);
    EXPECT_EQ(vd1.is_deallocated(), true);
    EXPECT_EQ(vd1.size(), 0);
    EXPECT_EQ(vd2.is_allocated(), true);
    EXPECT_EQ(vd2.is_deallocated(), false);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd2.get_element(i), VAL_TEST1);
        EXPECT_EQ(vd2(i), VAL_TEST1);
        EXPECT_EQ(vd2[i], VAL_TEST1);
    }
}

// test set the vector via move constructor and get some elements, uint64_t case

TEST(vd_set_vector_via_move_constructor_uint64_t, set_get) {

    spl::vector_dense<uint64_t> vd1(DIM_COMM, VAL_TEST2);

    EXPECT_EQ(DIM_COMM, vd1.size());

    spl::vector_dense<uint64_t> vd2(std::move(vd1));

    EXPECT_EQ(vd1.is_allocated(), false);
    EXPECT_EQ(vd1.is_deallocated(), true);
    EXPECT_EQ(vd1.size(), 0);
    EXPECT_EQ(vd2.is_allocated(), true);
    EXPECT_EQ(vd2.is_deallocated(), false);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd2.get_element(i), VAL_TEST2);
        EXPECT_EQ(vd2(i), VAL_TEST2);
        EXPECT_EQ(vd2[i], VAL_TEST2);
    }
}

// test set the vector via move constructor and get some elements, int64_t case

TEST(vd_set_vector_via_move_constructor_int64_t, set_get) {

    spl::vector_dense<int64_t> vd1(DIM_COMM, VAL_TEST3);

    EXPECT_EQ(DIM_COMM, vd1.size());

    spl::vector_dense<int64_t> vd2(std::move(vd1));

    EXPECT_EQ(vd1.is_allocated(), false);
    EXPECT_EQ(vd1.is_deallocated(), true);
    EXPECT_EQ(vd1.size(), 0);
    EXPECT_EQ(vd2.is_allocated(), true);
    EXPECT_EQ(vd2.is_deallocated(), false);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd2.get_element(i), VAL_TEST3);
        EXPECT_EQ(vd2(i), VAL_TEST3);
        EXPECT_EQ(vd2[i], VAL_TEST3);
    }
}

// test set the vector via move assignment operator and get some elements, double case

TEST(vd_set_vector_via_move_assignment_operator_double, set_get) {

    spl::vector_dense<double> vd1(DIM_COMM, VAL_TEST1);

    EXPECT_EQ(DIM_COMM, vd1.size());

    spl::vector_dense<double> vd2;
    vd2 = std::move(vd1);

    EXPECT_EQ(vd1.is_allocated(), false);
    EXPECT_EQ(vd1.is_deallocated(), true);
    EXPECT_EQ(vd1.size(), 0);
    EXPECT_EQ(vd2.is_allocated(), true);
    EXPECT_EQ(vd2.is_deallocated(), false);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd2.get_element(i), VAL_TEST1);
        EXPECT_EQ(vd2(i), VAL_TEST1);
        EXPECT_EQ(vd2[i], VAL_TEST1);
    }
}

// test set the vector via move assignment operator and get some elements, uint64_t case

TEST(vd_set_vector_via_move_assignment_operator_uint64_t, set_get) {

    spl::vector_dense<uint64_t> vd1(DIM_COMM, VAL_TEST2);

    EXPECT_EQ(DIM_COMM, vd1.size());

    spl::vector_dense<uint64_t> vd2;
    vd2 = std::move(vd1);

    EXPECT_EQ(vd1.is_allocated(), false);
    EXPECT_EQ(vd1.is_deallocated(), true);
    EXPECT_EQ(vd1.size(), 0);
    EXPECT_EQ(vd2.is_allocated(), true);
    EXPECT_EQ(vd2.is_deallocated(), false);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd2.get_element(i), VAL_TEST2);
        EXPECT_EQ(vd2(i), VAL_TEST2);
        EXPECT_EQ(vd2[i], VAL_TEST2);
    }
}

// test set the vector via move assignment operator and get some elements, int64_t case

TEST(vd_set_vector_via_move_assignment_operator_int64_t, set_get) {

    spl::vector_dense<int64_t> vd1(DIM_COMM, VAL_TEST3);

    EXPECT_EQ(DIM_COMM, vd1.size());

    spl::vector_dense<int64_t> vd2;
    vd2 = std::move(vd1);

    EXPECT_EQ(vd1.is_allocated(), false);
    EXPECT_EQ(vd1.is_deallocated(), true);
    EXPECT_EQ(vd1.size(), 0);
    EXPECT_EQ(vd2.is_allocated(), true);
    EXPECT_EQ(vd2.is_deallocated(), false);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd2.get_element(i), VAL_TEST3);
        EXPECT_EQ(vd2(i), VAL_TEST3);
        EXPECT_EQ(vd2[i], VAL_TEST3);
    }
}

// test set the vector via std::vector copy

TEST(vd_set_vector_via_std_vector_copy, set_get) {

    spl::vector_dense<double> vd;
    std::vector<double> vec_std;

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        vec_std.push_back(static_cast<double>(i));
    }

    vd = vec_std;

    EXPECT_EQ(vd.is_allocated(), true);
    EXPECT_EQ(vd.size(), DIM_COMM);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd.get_element(i), static_cast<double>(i));
        EXPECT_EQ(vd[i], static_cast<double>(i));
        EXPECT_EQ(vd(i), static_cast<double>(i));
        EXPECT_EQ(vec_std[i], static_cast<double>(i));
    }
}

// test set the vector via std::vector copy

TEST(vd_set_vector_via_std_vector_copy_already_alloc, set_get) {

    spl::vector_dense<double> vd(DIM_COMM + 100);
    std::vector<double> vec_std;

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        vec_std.push_back(static_cast<double>(i));
    }

    vd = vec_std;

    EXPECT_EQ(vd.is_allocated(), true);
    EXPECT_EQ(vd.size(), DIM_COMM);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd.get_element(i), static_cast<double>(i));
        EXPECT_EQ(vd[i], static_cast<double>(i));
        EXPECT_EQ(vd(i), static_cast<double>(i));
        EXPECT_EQ(vec_std[i], static_cast<double>(i));
    }
}

// test set the vector via std::vector move

TEST(vd_set_vector_via_std_vector_move, set_get) {

    spl::vector_dense<double> vd;
    std::vector<double> vec_std;

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        vec_std.push_back(static_cast<double>(i));
    }

    vd = std::move(vec_std);

    EXPECT_EQ(vd.is_allocated(), true);
    EXPECT_EQ(vd.size(), DIM_COMM);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd.get_element(i), static_cast<double>(i));
        EXPECT_EQ(vd[i], static_cast<double>(i));
        EXPECT_EQ(vd(i), static_cast<double>(i));
    }
}

// test set the vector via std::vector move

TEST(vd_set_vector_via_std_vector_move_already_alloc, set_get) {

    spl::vector_dense<double> vd(DIM_COMM + 100);
    std::vector<double> vec_std;

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        vec_std.push_back(static_cast<double>(i));
    }

    vd = std::move(vec_std);

    EXPECT_EQ(vd.is_allocated(), true);
    EXPECT_EQ(vd.size(), DIM_COMM);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd.get_element(i), static_cast<double>(i));
        EXPECT_EQ(vd[i], static_cast<double>(i));
        EXPECT_EQ(vd(i), static_cast<double>(i));
    }
}
