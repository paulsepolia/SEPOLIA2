#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include "../../../vector_dense/vector_dense.h"

// help display function

void fc() {

    static uint32_t i(0);
    std::cout << " --> " << std::setw(3) << ++i << " --> ";
}

// main function

int main(int argc, char **argv) {

    __gnu_parallel::_Settings s;
    s.algorithm_strategy = __gnu_parallel::force_parallel;
    __gnu_parallel::_Settings::set(s);

    std::cout << std::boolalpha;
    std::cout << std::fixed;
    std::cout << std::setprecision(5);
    const uint64_t DIM(static_cast<uint64_t>(std::pow(10.0, 1.0)));
    const uint64_t DIM_LARGE(static_cast<uint64_t>(std::pow(10.0, 1.0)));
    const uint64_t DIM_SMALL(static_cast<uint64_t>(std::pow(10.0, 1.0)));
    sep::vector_dense<double> vd(DIM, 2.0);
    const uint64_t TEST_INDEX(5);
    const uint64_t TEST_DIM(DIM);
    const double TEST_VALUE1(1234.56789);
    const double TEST_VALUE2(9876.54321);
    const double TEST_VALUE3(0.1234567);
    const double TEST_FACTOR0(1.0);
    const double TEST_FACTOR1(2.0);
    const double TEST_FACTOR2(5.0);
    const double TEST_FACTOR3(std::pow(10.0, 1.0));
    const double TEST_FACTOR4(std::pow(10.0, 2.0));
    const double TEST_FACTOR5(std::pow(10.0, 3.0));

    //====================================//
    // allocations and deallocations test //
    //====================================//

    {
        fc();
        std::cout << vd.is_allocated() << std::endl;
        fc();
        std::cout << !vd.is_deallocated() << std::endl;
        fc();

        vd = TEST_VALUE1;

        fc();
        std::cout << (vd[TEST_INDEX] == TEST_VALUE1) << std::endl;

        vd[TEST_INDEX] = TEST_VALUE1;

        fc();
        std::cout << (vd[TEST_INDEX] == TEST_VALUE1) << std::endl;

        vd = TEST_VALUE2;

        fc();
        std::cout << (vd[0] == TEST_VALUE2) << std::endl;

        vd.deallocate();
        vd.allocate(DIM_LARGE);

        vd = TEST_VALUE3;

        fc();
        std::cout << (vd[TEST_INDEX] == TEST_VALUE3) << std::endl;
        fc();
        std::cout << (vd[DIM_LARGE - 1] == TEST_VALUE3) << std::endl;

        vd.deallocate();
        vd.allocate(TEST_DIM);

        fc();
        std::cout << (vd.size() == TEST_DIM) << std::endl;

        for (uint64_t i = 0; i < DIM_SMALL; i++) {

            vd.deallocate();
            vd.allocate(DIM_LARGE);
            vd = TEST_VALUE1;

            if (i == DIM_SMALL - 1) {
                fc();
                std::cout << (vd[0] == TEST_VALUE1) << std::endl;
                fc();
                std::cout << (vd[DIM_LARGE - 1] == TEST_VALUE1) << std::endl;
            }
        }

        for (uint64_t i = 0; i < DIM_SMALL; i++) {
            sep::vector_dense<double> vd_tmp(DIM_LARGE, TEST_VALUE3);
            vd = vd_tmp;

            if (i == DIM_SMALL - 1) {
                fc();
                std::cout << (vd[0] == TEST_VALUE3) << std::endl;
                fc();
                std::cout << (vd[DIM_LARGE - 1] == TEST_VALUE3) << std::endl;
            }
        }

        for (uint64_t i = 0; i < DIM_SMALL; i++) {
            sep::vector_dense<double> vd_tmp(DIM_LARGE, TEST_VALUE3);
            vd = std::move(vd_tmp);

            if (i == DIM_SMALL - 1) {
                fc();
                std::cout << (vd[0] == TEST_VALUE3) << std::endl;
                fc();
                std::cout << (vd[DIM_LARGE - 1] == TEST_VALUE3) << std::endl;
            }
        }

        for (uint64_t i = 0; i < DIM_SMALL; i++) {
            sep::vector_dense<double> vd_tmp(DIM_LARGE, TEST_VALUE3);
            sep::vector_dense<double> vd(std::move(vd_tmp));

            if (i == DIM_SMALL - 1) {
                fc();
                std::cout << (vd[0] == TEST_VALUE3) << std::endl;
                fc();
                std::cout << (vd[DIM_LARGE - 1] == TEST_VALUE3) << std::endl;
            }
        }

        for (uint64_t i = 0; i < DIM_SMALL; i++) {
            sep::vector_dense<double> vd_tmp(DIM_LARGE, TEST_VALUE3);
            sep::vector_dense<double> vd(std::move(vd_tmp));

            if (i == DIM_SMALL - 1) {
                fc();
                std::cout << (vd[0] == TEST_VALUE3) << std::endl;
                fc();
                std::cout << (vd[DIM_LARGE - 1] == TEST_VALUE3) << std::endl;
            }
        }
    }

    //=====================================//
    // copy vs move constructor test light //
    //=====================================//

    {
        // using move constructor to create the v2 vector from v1

        auto t1(std::chrono::system_clock::now());

        for (uint64_t i = 0; i != DIM_SMALL; i++) {
            sep::vector_dense<double> v1(DIM_LARGE, TEST_VALUE1);
            sep::vector_dense<double> v2(std::move(v1));
        }

        auto t2(std::chrono::system_clock::now());
        auto time_span_move(std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

        // using copy constructor to create the v2 vector from v1

        t1 = std::chrono::system_clock::now();

        for (uint64_t i = 0; i != DIM_SMALL; i++) {
            sep::vector_dense<double> v1(DIM_LARGE, TEST_VALUE1);
            sep::vector_dense<double> v2(v1);
        }

        t2 = std::chrono::system_clock::now();
        auto time_span_copy(std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

        fc();
        std::cout << "OKAY IF --> "
                  << ((time_span_move.count() * TEST_FACTOR0) <= time_span_copy.count()) << std::endl;
        fc();
        std::cout << "OKAY IF --> "
                  << ((time_span_move.count() * TEST_FACTOR1) <= time_span_copy.count()) << std::endl;
        fc();
        std::cout << "OKAY IF --> "
                  << ((time_span_move.count() * TEST_FACTOR2) >= time_span_copy.count()) << std::endl;
        fc();
        std::cout << "OKAY IF --> "
                  << ((time_span_move.count() * TEST_FACTOR3) >= time_span_copy.count()) << std::endl;
        fc();
        std::cout << "OKAY IF --> "
                  << ((time_span_move.count() * TEST_FACTOR4) >= time_span_copy.count()) << std::endl;
        fc();
        std::cout << "OKAY IF --> "
                  << ((time_span_move.count() * TEST_FACTOR5) >= time_span_copy.count()) << std::endl;
    }

    //=====================================//
    // copy vs move constructor test heavy //
    //=====================================//

    {
        // using move constructor to create the v2 vector from v1

        auto t1(std::chrono::system_clock::now());

        for (uint64_t i = 0; i != DIM; i++) {
            sep::vector_dense<double> v1(DIM_LARGE, TEST_VALUE1);
            sep::vector_dense<double> v2(std::move(v1));
        }

        auto t2(std::chrono::system_clock::now());
        auto time_span_move(std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

        // using copy constructor to create the v2 vector from v1

        t1 = std::chrono::system_clock::now();

        for (uint64_t i = 0; i != DIM; i++) {
            sep::vector_dense<double> v1(DIM_LARGE, TEST_VALUE1);
            sep::vector_dense<double> v2(v1);
        }

        t2 = std::chrono::system_clock::now();
        auto time_span_copy(std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

        fc();
        std::cout << "OKAY IF --> "
                  << ((time_span_move.count() * TEST_FACTOR0) <= time_span_copy.count()) << std::endl;
        fc();
        std::cout << "OKAY IF --> "
                  << ((time_span_move.count() * TEST_FACTOR1) <= time_span_copy.count()) << std::endl;
        fc();
        std::cout << "OKAY IF --> "
                  << ((time_span_move.count() * TEST_FACTOR2) >= time_span_copy.count()) << std::endl;
        fc();
        std::cout << "OKAY IF --> "
                  << ((time_span_move.count() * TEST_FACTOR3) >= time_span_copy.count()) << std::endl;
        fc();
        std::cout << "OKAY IF --> "
                  << ((time_span_move.count() * TEST_FACTOR4) >= time_span_copy.count()) << std::endl;
        fc();
        std::cout << "OKAY IF --> "
                  << ((time_span_move.count() * TEST_FACTOR5) >= time_span_copy.count()) << std::endl;
    }

    //==============//
    // algebra test //
    //==============//

    {
        sep::vector_dense<double> v1(DIM, TEST_VALUE1);
        const double val(TEST_VALUE2);
        sep::vector_dense<double> v2;

        // plus

        for (uint64_t i = 0; i != DIM_LARGE; i++) {
            v2 = v1 + val;
        }

        fc();
        std::cout << ((v1[0] + val) == v2[0]) << std::endl;

        // subtract

        for (uint64_t i = 0; i != DIM; i++) {
            v2 = v1 - val;
        }

        fc();
        std::cout << ((v1[0] - val) == v2[0]) << std::endl;

        // times

        for (uint64_t i = 0; i != DIM; i++) {
            v2 = v1 * val;
        }

        fc();
        std::cout << ((v1[0] * val) == v2[0]) << std::endl;

        // divide

        for (uint64_t i = 0; i != DIM; i++) {
            v2 = v1 / val;
        }

        fc();
        std::cout << ((v1[0] / val) == v2[0]) << std::endl;

    }

    //=======================//
    // algebra parallel test //
    //=======================//

    {
        sep::vector_dense<double> v1(DIM, TEST_VALUE1);
        const double val(TEST_VALUE2);
        sep::vector_dense<double> v2;

        // plus

        for (uint64_t i = 0; i != DIM_LARGE; i++) {
            v2 = v1 + val;
        }

        fc();
        std::cout << ((v1[0] + val) == v2[0]) << std::endl;

        // subtract

        for (uint64_t i = 0; i != DIM; i++) {
            v2 = v1 - val;
        }

        fc();
        std::cout << ((v1[0] - val) == v2[0]) << std::endl;

        // times

        for (uint64_t i = 0; i != DIM; i++) {
            v2 = v1 * val;
        }

        fc();
        std::cout << ((v1[0] * val) == v2[0]) << std::endl;

        // divide

        for (uint64_t i = 0; i != DIM; i++) {
            v2 = v1 / val;
        }

        fc();
        std::cout << ((v1[0] / val) == v2[0]) << std::endl;
    }

    //==============================//
    // algebra test using operators //
    //==============================//

    {
        sep::vector_dense<double> v1(DIM, TEST_VALUE1);
        sep::vector_dense<double> v2(DIM, TEST_VALUE2);
        sep::vector_dense<double> v3;

        // plus

        for (uint64_t i = 0; i != DIM_LARGE; i++) {
            v3 = v1 + v2;
        }

        fc();
        std::cout << ((v1[TEST_INDEX] + v2[TEST_INDEX]) == v3[TEST_INDEX]) << std::endl;

        for (uint64_t i = 0; i != DIM_LARGE; i++) {
            v3 = v1 + TEST_VALUE3;
        }

        fc();
        std::cout << ((v1[TEST_INDEX] + TEST_VALUE3) == v3[TEST_INDEX]) << std::endl;

        for (uint64_t i = 0; i != DIM_LARGE; i++) {
            v3 = TEST_VALUE3 + v1;
        }

        fc();
        std::cout << ((v1[TEST_INDEX] + TEST_VALUE3) == v3[TEST_INDEX]) << std::endl;

        // subtract

        for (uint64_t i = 0; i != DIM_LARGE; i++) {
            v3 = v1 - v2;
        }

        fc();
        std::cout << ((v1[TEST_INDEX] - v2[TEST_INDEX]) == v3[TEST_INDEX]) << std::endl;

        for (uint64_t i = 0; i != DIM_LARGE; i++) {
            v3 = v1 - TEST_VALUE3;
        }

        fc();
        std::cout << ((v1[TEST_INDEX] - TEST_VALUE3) == v3[TEST_INDEX]) << std::endl;

        for (uint64_t i = 0; i != DIM_LARGE; i++) {
            v3 = TEST_VALUE3 - v1;
        }

        fc();
        std::cout << ((v1[TEST_INDEX] - TEST_VALUE3) == v3[TEST_INDEX]) << std::endl;

        // times

        for (uint64_t i = 0; i != DIM_LARGE; i++) {
            v3 = v1 * v2;
        }

        fc();
        std::cout << ((v1[TEST_INDEX] * v2[TEST_INDEX]) == v3[TEST_INDEX]) << std::endl;

        for (uint64_t i = 0; i != DIM_LARGE; i++) {
            v3 = v1 * TEST_VALUE3;
        }

        fc();
        std::cout << ((v1[TEST_INDEX] * TEST_VALUE3) == v3[TEST_INDEX]) << std::endl;

        for (uint64_t i = 0; i != DIM_LARGE; i++) {
            v3 = TEST_VALUE3 * v1;
        }

        fc();
        std::cout << ((v1[TEST_INDEX] * TEST_VALUE3) == v3[TEST_INDEX]) << std::endl;

        // divide

        for (uint64_t i = 0; i != DIM_LARGE; i++) {
            v3 = v1 / v2;
        }

        fc();
        std::cout << ((v1[TEST_INDEX] / v2[TEST_INDEX]) == v3[TEST_INDEX]) << std::endl;

        for (uint64_t i = 0; i != DIM_LARGE; i++) {
            v3 = v1 / TEST_VALUE3;
        }

        fc();
        std::cout << ((v1[TEST_INDEX] / TEST_VALUE3) == v3[TEST_INDEX]) << std::endl;

        for (uint64_t i = 0; i != DIM_LARGE; i++) {
            v3 = TEST_VALUE3 / v1;
        }

        fc();
        std::cout << ((TEST_VALUE3 / v1[TEST_INDEX]) == v3[TEST_INDEX]) << std::endl;
    }

    //=================//
    // exceptions test //
    //=================//

    {
        fc();
        std::cout << (vd.size() == TEST_DIM) << std::endl;

        // get_element

        try {
            sep::vector_dense<double> vd1;
            vd1[TEST_DIM];
        }
        catch (const sep::is_not_allocated &a) {
            fc();
            std::cout << (a.what() == skz::E0001) << std::endl;
        }

        try {
            sep::vector_dense<double> vd2(TEST_DIM, TEST_VALUE1);
            vd2[TEST_DIM];
        }
        catch (const sep::index_out_of_range &a) {
            fc();
            std::cout << (a.what() == skz::E0002) << std::endl;
        }

        // []

        try {
            sep::vector_dense<double> vd1;
            vd1[1];
        }
        catch (const sep::is_not_allocated &a) {
            fc();
            std::cout << (a.what() == skz::E0001) << std::endl;
        }

        try {
            sep::vector_dense<double> vd2(TEST_DIM, TEST_VALUE1);
            vd2[TEST_DIM];
        }
        catch (const sep::index_out_of_range &a) {
            fc();
            std::cout << (a.what() == skz::E0002) << std::endl;
        }

        // ()

        try {
            sep::vector_dense<double> vd1;
            vd1(1);
        }
        catch (const sep::is_not_allocated &a) {
            fc();
            std::cout << (a.what() == skz::E0001) << std::endl;
        }

        try {
            sep::vector_dense<double> vd2(TEST_DIM, TEST_VALUE1);
            vd2(TEST_DIM);
        }
        catch (const sep::index_out_of_range &a) {
            fc();
            std::cout << (a.what() == skz::E0002) << std::endl;
        }

        // at() non-const ref

        try {
            sep::vector_dense<double> vd1;
            vd1(1);
        }
        catch (const sep::is_not_allocated &a) {
            fc();
            std::cout << (a.what() == skz::E0001) << std::endl;
        }

        // at() non-const ref

        try {
            sep::vector_dense<double> vd2(TEST_DIM, TEST_VALUE1);
            vd2(TEST_DIM);
        }
        catch (const sep::index_out_of_range &a) {
            fc();
            std::cout << (a.what() == skz::E0002) << std::endl;
        }

        try {
            sep::vector_dense<double> vd1;
            vd1(1);
        }
        catch (const sep::is_not_allocated &a) {
            fc();
            std::cout << (a.what() == skz::E0001) << std::endl;
        }

        // at() - const ref

        try {
            const sep::vector_dense<double> vd2;
            vd2(TEST_DIM);
        }
        catch (const sep::is_not_allocated &a) {
            fc();
            std::cout << (a.what() == skz::E0001) << std::endl;
        }

        try {
            const sep::vector_dense<double> vd2(TEST_DIM, TEST_VALUE1);
            vd2(TEST_DIM);
        }
        catch (const sep::index_out_of_range &a) {
            fc();
            std::cout << (a.what() == skz::E0002) << std::endl;
        }
    }

    return 0;
}

