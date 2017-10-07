#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>

using std::cout;
using std::endl;
using std::chrono::duration;
using std::chrono::system_clock;
using std::chrono::duration_cast;

#include "../../../vector_dense/vector_dense.h"

using sepolia::vector_dense;
using pgg::E0001;
using pgg::E0002;

// help display function

void fc() {

    static uint32_t i(0);
    cout << " --> " << std::setw(3) << ++i << " --> ";
}

// main function

int main(int argc, char **argv) {

    __gnu_parallel::_Settings s;
    s.algorithm_strategy = __gnu_parallel::force_parallel;
    __gnu_parallel::_Settings::set(s);

    cout << std::boolalpha;
    cout << std::fixed;
    cout << std::setprecision(5);
    const uint64_t DIM(static_cast<uint64_t>(std::pow(10.0, 1.0)));
    const uint64_t DIM_LARGE(static_cast<uint64_t>(std::pow(10.0, 1.0)));
    const uint64_t DIM_SMALL(static_cast<uint64_t>(std::pow(10.0, 1.0)));
    vector_dense<double> vd(DIM, 2.0);
    const uint64_t TEST_INDEX(5);
    const uint64_t TEST_DIM(10);
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
        cout << vd.is_allocated() << endl;
        fc();
        cout << !vd.is_deallocated() << endl;
        fc();
        cout << vd.deallocate() << endl;
        fc();
        cout << vd.allocate(DIM) << endl;

        vd = TEST_VALUE1;

        fc();
        cout << (vd.get_element(TEST_INDEX) == TEST_VALUE1) << endl;

        vd.set_element(TEST_INDEX, TEST_VALUE1);

        fc();
        cout << (vd.get_element(TEST_INDEX) == TEST_VALUE1) << endl;

        vd = TEST_VALUE2;

        fc();
        cout << (vd.get_element(0) == TEST_VALUE2) << endl;

        vd.deallocate();
        vd.allocate(DIM_LARGE);

        vd = TEST_VALUE3;

        fc();
        cout << (vd.get_element(TEST_INDEX) == TEST_VALUE3) << endl;
        fc();
        cout << (vd.get_element(DIM_LARGE - 1) == TEST_VALUE3) << endl;

        vd.deallocate();
        vd.allocate(TEST_DIM);

        fc();
        cout << (vd.get_dimension() == TEST_DIM) << endl;

        for (uint64_t i = 0; i < DIM_SMALL; i++) {

            vd.deallocate();
            vd.allocate(DIM_LARGE);
            vd = TEST_VALUE1;

            if (i == DIM_SMALL - 1) {
                fc();
                cout << (vd.get_element(0) == TEST_VALUE1) << endl;
                fc();
                cout << (vd.get_element(DIM_LARGE - 1) == TEST_VALUE1) << endl;
            }
        }

        for (uint64_t i = 0; i < DIM_SMALL; i++) {
            vector_dense<double> vd_tmp(DIM_LARGE, TEST_VALUE3);
            vd = vd_tmp;

            if (i == DIM_SMALL - 1) {
                fc();
                cout << (vd.get_element(0) == TEST_VALUE3) << endl;
                fc();
                cout << (vd.get_element(DIM_LARGE - 1) == TEST_VALUE3) << endl;
            }
        }

        for (uint64_t i = 0; i < DIM_SMALL; i++) {
            vector_dense<double> vd_tmp(DIM_LARGE, TEST_VALUE3);
            vd = std::move(vd_tmp);

            if (i == DIM_SMALL - 1) {
                fc();
                cout << (vd.get_element(0) == TEST_VALUE3) << endl;
                fc();
                cout << (vd.get_element(DIM_LARGE - 1) == TEST_VALUE3) << endl;
            }
        }

        for (uint64_t i = 0; i < DIM_SMALL; i++) {
            vector_dense<double> vd_tmp(DIM_LARGE, TEST_VALUE3);
            vector_dense<double> vd(std::move(vd_tmp));

            if (i == DIM_SMALL - 1) {
                fc();
                cout << (vd.get_element(0) == TEST_VALUE3) << endl;
                fc();
                cout << (vd.get_element(DIM_LARGE - 1) == TEST_VALUE3) << endl;
            }
        }

        for (uint64_t i = 0; i < DIM_SMALL; i++) {
            vector_dense<double> vd_tmp(DIM_LARGE, TEST_VALUE3);
            vector_dense<double> vd(std::move(vd_tmp));

            if (i == DIM_SMALL - 1) {
                fc();
                cout << (vd.get_element(0) == TEST_VALUE3) << endl;
                fc();
                cout << (vd.get_element(DIM_LARGE - 1) == TEST_VALUE3) << endl;
            }
        }
    }

    //=====================================//
    // copy vs move constructor test light //
    //=====================================//

    {
        // using move constructor to create the v2 vector from v1

        auto t1(system_clock::now());

        for (uint64_t i = 0; i != DIM_SMALL; i++) {
            vector_dense<double> v1(DIM_LARGE, TEST_VALUE1);
            vector_dense<double> v2(std::move(v1));
        }

        auto t2(system_clock::now());
        auto time_span_move(duration_cast<duration<double, std::milli>>(t2 - t1));

        // using copy constructor to create the v2 vector from v1

        t1 = system_clock::now();

        for (uint64_t i = 0; i != DIM_SMALL; i++) {
            vector_dense<double> v1(DIM_LARGE, TEST_VALUE1);
            vector_dense<double> v2(v1);
        }

        t2 = system_clock::now();
        auto time_span_copy(duration_cast<duration<double, std::milli>>(t2 - t1));

        fc();
        cout << "OKAY IF --> "
             << ((time_span_move.count() * TEST_FACTOR0) <= time_span_copy.count()) << endl;
        fc();
        cout << "OKAY IF --> "
             << ((time_span_move.count() * TEST_FACTOR1) <= time_span_copy.count()) << endl;
        fc();
        cout << "OKAY IF --> "
             << ((time_span_move.count() * TEST_FACTOR2) >= time_span_copy.count()) << endl;
        fc();
        cout << "OKAY IF --> "
             << ((time_span_move.count() * TEST_FACTOR3) >= time_span_copy.count()) << endl;
        fc();
        cout << "OKAY IF --> "
             << ((time_span_move.count() * TEST_FACTOR4) >= time_span_copy.count()) << endl;
        fc();
        cout << "OKAY IF --> "
             << ((time_span_move.count() * TEST_FACTOR5) >= time_span_copy.count()) << endl;
    }

    //=====================================//
    // copy vs move constructor test heavy //
    //=====================================//

    {
        // using move constructor to create the v2 vector from v1

        auto t1(system_clock::now());

        for (uint64_t i = 0; i != DIM; i++) {
            vector_dense<double> v1(DIM_LARGE, TEST_VALUE1);
            vector_dense<double> v2(std::move(v1));
        }

        auto t2(system_clock::now());
        auto time_span_move(duration_cast<duration<double, std::milli>>(t2 - t1));

        // using copy constructor to create the v2 vector from v1

        t1 = system_clock::now();

        for (uint64_t i = 0; i != DIM; i++) {
            vector_dense<double> v1(DIM_LARGE, TEST_VALUE1);
            vector_dense<double> v2(v1);
        }

        t2 = system_clock::now();
        auto time_span_copy(duration_cast<duration<double, std::milli>>(t2 - t1));

        fc();
        cout << "OKAY IF --> "
             << ((time_span_move.count() * TEST_FACTOR0) <= time_span_copy.count()) << endl;
        fc();
        cout << "OKAY IF --> "
             << ((time_span_move.count() * TEST_FACTOR1) <= time_span_copy.count()) << endl;
        fc();
        cout << "OKAY IF --> "
             << ((time_span_move.count() * TEST_FACTOR2) >= time_span_copy.count()) << endl;
        fc();
        cout << "OKAY IF --> "
             << ((time_span_move.count() * TEST_FACTOR3) >= time_span_copy.count()) << endl;
        fc();
        cout << "OKAY IF --> "
             << ((time_span_move.count() * TEST_FACTOR4) >= time_span_copy.count()) << endl;
        fc();
        cout << "OKAY IF --> "
             << ((time_span_move.count() * TEST_FACTOR5) >= time_span_copy.count()) << endl;
    }

    //==============//
    // algebra test //
    //==============//

    {
        vector_dense<double> v1(DIM, TEST_VALUE1);
        const double val(TEST_VALUE2);
        vector_dense<double> v2;

        // plus

        for (uint64_t i = 0; i != DIM_LARGE; i++) {
            v2 = v1.plus(val);
        }

        fc();
        cout << ((v1.get_element(0) + val) == v2.get_element(0)) << endl;

        // subtract

        for (uint64_t i = 0; i != DIM; i++) {
            v2 = v1.subtract(val);
        }

        fc();
        cout << ((v1.get_element(0) - val) == v2.get_element(0)) << endl;

        // times

        for (uint64_t i = 0; i != DIM; i++) {
            v2 = v1.times(val);
        }

        fc();
        cout << ((v1.get_element(0) * val) == v2.get_element(0)) << endl;

        // divide

        for (uint64_t i = 0; i != DIM; i++) {
            v2 = v1.divide(val);
        }

        fc();
        cout << ((v1.get_element(0) / val) == v2.get_element(0)) << endl;

    }

    //=======================//
    // algebra parallel test //
    //=======================//

    {
        vector_dense<double> v1(DIM, TEST_VALUE1);
        const double val(TEST_VALUE2);
        vector_dense<double> v2;

        // plus

        for (uint64_t i = 0; i != DIM_LARGE; i++) {
            v2 = v1.plus(val, true);
        }

        fc();
        cout << ((v1.get_element(0) + val) == v2.get_element(0)) << endl;

        // subtract

        for (uint64_t i = 0; i != DIM; i++) {
            v2 = v1.subtract(val, true);
        }

        fc();
        cout << ((v1.get_element(0) - val) == v2.get_element(0)) << endl;

        // times

        for (uint64_t i = 0; i != DIM; i++) {
            v2 = v1.times(val, true);
        }

        fc();
        cout << ((v1.get_element(0) * val) == v2.get_element(0)) << endl;

        // divide

        for (uint64_t i = 0; i != DIM; i++) {
            v2 = v1.divide(val, true);
        }

        fc();
        cout << ((v1.get_element(0) / val) == v2.get_element(0)) << endl;
    }

    //==============//
    // algebra test //
    //==============//

    {
        vector_dense<double> v1(DIM, TEST_VALUE1);
        vector_dense<double> v2(DIM, TEST_VALUE2);
        vector_dense<double> v3;

        // plus

        for (uint64_t i = 0; i != DIM_LARGE; i++) {
            v3 = v1.plus(v2);
        }

        fc();
        cout << ((v1.get_element(TEST_INDEX) + v2.get_element(TEST_INDEX)) ==
                 v3.get_element(TEST_INDEX)) << endl;

        // subtract

        for (uint64_t i = 0; i != DIM; i++) {
            v3 = v1.subtract(v2);
        }

        fc();
        cout << ((v1.get_element(TEST_INDEX) - v2.get_element(TEST_INDEX)) ==
                 v3.get_element(TEST_INDEX)) << endl;

        // times

        for (uint64_t i = 0; i != DIM; i++) {
            v3 = v1.times(v2);
        }

        fc();
        cout << ((v1.get_element(TEST_INDEX) * v2.get_element(TEST_INDEX)) ==
                 v3.get_element(TEST_INDEX)) << endl;

        // divide

        for (uint64_t i = 0; i != DIM; i++) {
            v3 = v1.divide(v2);
        }

        fc();
        cout << ((v1.get_element(TEST_INDEX) / v2.get_element(TEST_INDEX)) ==
                 v3.get_element(TEST_INDEX)) << endl;
    }

    //=======================//
    // algebra parallel test //
    //=======================//

    {
        vector_dense<double> v1(DIM, TEST_VALUE1);
        vector_dense<double> v2(DIM, TEST_VALUE2);
        vector_dense<double> v3;

        // plus

        for (uint64_t i = 0; i != DIM_LARGE; i++) {
            v3 = v1.plus(v2, true);
        }

        fc();
        cout << ((v1.get_element(TEST_INDEX) + v2.get_element(TEST_INDEX)) ==
                 v3.get_element(TEST_INDEX)) << endl;

        // subtract

        for (uint64_t i = 0; i != DIM; i++) {
            v3 = v1.subtract(v2, true);
        }

        fc();
        cout << ((v1.get_element(TEST_INDEX) - v2.get_element(TEST_INDEX)) ==
                 v3.get_element(TEST_INDEX)) << endl;

        // times

        for (uint64_t i = 0; i != DIM; i++) {
            v3 = v1.times(v2, true);
        }

        fc();
        cout << ((v1.get_element(TEST_INDEX) * v2.get_element(TEST_INDEX)) ==
                 v3.get_element(TEST_INDEX)) << endl;

        // divide

        for (uint64_t i = 0; i != DIM; i++) {
            v3 = v1.divide(v2, true);
        }

        fc();
        cout << ((v1.get_element(TEST_INDEX) / v2.get_element(TEST_INDEX)) ==
                 v3.get_element(TEST_INDEX)) << endl;
    }

    //==============================//
    // algebra test using operators //
    //==============================//

    {
        vector_dense<double> v1(DIM, TEST_VALUE1);
        vector_dense<double> v2(DIM, TEST_VALUE2);
        vector_dense<double> v3;

        // plus

        for (uint64_t i = 0; i != DIM_LARGE; i++) {
            v3 = v1 + v2;
        }

        fc();
        cout << ((v1.get_element(TEST_INDEX) + v2.get_element(TEST_INDEX)) ==
                 v3.get_element(TEST_INDEX)) << endl;

        for (uint64_t i = 0; i != DIM_LARGE; i++) {
            v3 = v1 + TEST_VALUE3;
        }

        fc();
        cout << ((v1.get_element(TEST_INDEX) + TEST_VALUE3) ==
                 v3.get_element(TEST_INDEX)) << endl;

        for (uint64_t i = 0; i != DIM_LARGE; i++) {
            v3 = TEST_VALUE3 + v1;
        }

        fc();
        cout << ((v1.get_element(TEST_INDEX) + TEST_VALUE3) ==
                 v3.get_element(TEST_INDEX)) << endl;

        // subtract

        for (uint64_t i = 0; i != DIM_LARGE; i++) {
            v3 = v1 - v2;
        }

        fc();
        cout << ((v1.get_element(TEST_INDEX) - v2.get_element(TEST_INDEX)) ==
                 v3.get_element(TEST_INDEX)) << endl;

        for (uint64_t i = 0; i != DIM_LARGE; i++) {
            v3 = v1 - TEST_VALUE3;
        }

        fc();
        cout << ((v1.get_element(TEST_INDEX) - TEST_VALUE3) ==
                 v3.get_element(TEST_INDEX)) << endl;

        for (uint64_t i = 0; i != DIM_LARGE; i++) {
            v3 = TEST_VALUE3 - v1;
        }

        fc();
        cout << ((v1.get_element(TEST_INDEX) - TEST_VALUE3) ==
                 v3.get_element(TEST_INDEX)) << endl;

        // times

        for (uint64_t i = 0; i != DIM_LARGE; i++) {
            v3 = v1 * v2;
        }

        fc();
        cout << ((v1.get_element(TEST_INDEX) * v2.get_element(TEST_INDEX)) ==
                 v3.get_element(TEST_INDEX)) << endl;

        for (uint64_t i = 0; i != DIM_LARGE; i++) {
            v3 = v1 * TEST_VALUE3;
        }

        fc();
        cout << ((v1.get_element(TEST_INDEX) * TEST_VALUE3) ==
                 v3.get_element(TEST_INDEX)) << endl;

        for (uint64_t i = 0; i != DIM_LARGE; i++) {
            v3 = TEST_VALUE3 * v1;
        }

        fc();
        cout << ((v1.get_element(TEST_INDEX) * TEST_VALUE3) ==
                 v3.get_element(TEST_INDEX)) << endl;

        // divide

        for (uint64_t i = 0; i != DIM_LARGE; i++) {
            v3 = v1 / v2;
        }

        fc();
        cout << ((v1.get_element(TEST_INDEX) / v2.get_element(TEST_INDEX)) ==
                 v3.get_element(TEST_INDEX)) << endl;

        for (uint64_t i = 0; i != DIM_LARGE; i++) {
            v3 = v1 / TEST_VALUE3;
        }

        fc();
        cout << ((v1.get_element(TEST_INDEX) / TEST_VALUE3) ==
                 v3.get_element(TEST_INDEX)) << endl;

        for (uint64_t i = 0; i != DIM_LARGE; i++) {
            v3 = TEST_VALUE3 / v1;
        }

        fc();
        cout << ((TEST_VALUE3 / v1.get_element(TEST_INDEX)) ==
                 v3.get_element(TEST_INDEX)) << endl;
    }

    return 0;
}
