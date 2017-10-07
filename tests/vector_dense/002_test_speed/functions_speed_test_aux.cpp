#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include "functions_speed_test_aux.h"
#include "../../../vector_dense/vector_dense.h"

//=============================//
// function to display results //
//=============================//

// fun_display_a

void fun_display_a(const uint64_t &trials,
                   const uint64_t &dim,
                   const double &time_tot,
                   const double_t &speed,
                   const uint32_t &wformat) {

    std::cout << "-->     trials |        dim |  time (ms) | speed (dbls/sec)" << std::endl;

    std::cout << "-->" << std::scientific << std::setprecision(0)
              << std::setw(wformat) << std::right << (trials * 1.0) << " |"
              << std::setw(wformat) << std::right << (dim * 1.0) << " |"
              << std::setprecision(2)
              << std::setw(wformat) << std::right << time_tot << " |"
              << std::setw(wformat) << std::right << speed << std::endl;
}

// fun_display_b

void fun_display_b(const uint64_t &trials,
                   const double &time_tot,
                   const double_t &speed,
                   const uint32_t &wformat) {

    std::cout << "-->     trials |  time (ms) | speed (decls/sec)" << std::endl;

    std::cout << "-->" << std::scientific << std::setprecision(0)
              << std::setw(wformat) << std::right << (trials * 1.0) << " |"
              << std::setprecision(2)
              << std::setw(wformat) << std::right << time_tot << " |"
              << std::setw(wformat) << std::right << speed << std::endl;
}

// fun_display_c

void fun_display_c() {

    static int index(0);
    std::cout << "---------------------------------------------------------->>  " << ++index << std::endl;
}

//=======================================//
// functions for vector dense speed test //
//=======================================//

// fun_declaration_via_default_constructor

void fun_declaration_via_default_constructor(const uint64_t &trials, const uint32_t &wformat) {

    auto t1(std::chrono::system_clock::now());

    const auto TRIALS(trials);

    for (uint64_t i = 1; i <= TRIALS; i++) {
        spl::vector_dense<double> v1;
    }

    auto t2(std::chrono::system_clock::now());
    auto time_span_alloc_via_constructor(
            std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

    const auto TIME_TOTAL(time_span_alloc_via_constructor.count());
    const auto SPEED(TRIALS / (TIME_TOTAL / 1000.0));

    fun_display_b(TRIALS, TIME_TOTAL, SPEED, wformat);
}

//=====//
// set //
//=====//

void fun_alloc_set_via_constructor(const uint64_t &trials,
                                   const uint64_t &vec_size,
                                   const double &val,
                                   const uint32_t &wformat) {

    auto t1(std::chrono::system_clock::now());

    const auto TRIALS(trials);
    const auto DIM_VEC(vec_size);
    const auto TEST_VAL(val);

    for (uint64_t i = 1; i <= TRIALS; i++) {
        spl::vector_dense<double> v1(DIM_VEC, TEST_VAL);
    }

    auto t2(std::chrono::system_clock::now());
    auto time_span_alloc_via_constructor(
            std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

    const auto TIME_TOTAL(time_span_alloc_via_constructor.count());
    const auto SPEED((DIM_VEC * TRIALS) / (TIME_TOTAL / 1000.0));

    fun_display_a(TRIALS, DIM_VEC, TIME_TOTAL, SPEED, wformat);
}

void fun_alloc_set_dealloc(const uint64_t &trials,
                           const uint64_t &vec_size,
                           const double &val,
                           const uint32_t &wformat) {

    auto t1(std::chrono::system_clock::now());

    const auto TRIALS(trials);
    const auto DIM_VEC(vec_size);
    const auto TEST_VAL(val);

    for (uint64_t i = 1; i <= TRIALS; i++) {
        spl::vector_dense<double> v1;
        v1.allocate(DIM_VEC);
        v1 = TEST_VAL;
    }

    auto t2(std::chrono::system_clock::now());
    auto time_span_alloc_via_constructor(
            std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

    const auto TIME_TOTAL(time_span_alloc_via_constructor.count());
    const auto SPEED((DIM_VEC * TRIALS) / (TIME_TOTAL / 1000.0));

    fun_display_a(TRIALS, DIM_VEC, TIME_TOTAL, SPEED, wformat);
}

void fun_declaration_via_constructor_full(const uint64_t &trials,
                                          const uint64_t &vec_size,
                                          const double &val,
                                          const uint32_t &wformat) {
    const auto TRIALS(trials);
    const auto DIM_VEC(vec_size);
    const auto TEST_VAL(val);

    spl::vector_dense<double> v1;
    v1.allocate(DIM_VEC);
    v1 = TEST_VAL;

    auto t1(std::chrono::system_clock::now());

    for (uint64_t i = 1; i <= TRIALS; i++) {
        spl::vector_dense<double> v2(v1);
    }

    auto t2(std::chrono::system_clock::now());
    auto time_span_alloc_via_constructor(
            std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

    const auto TIME_TOTAL(time_span_alloc_via_constructor.count());
    const auto SPEED((DIM_VEC * TRIALS) / (TIME_TOTAL / 1000.0));

    fun_display_a(TRIALS, DIM_VEC, TIME_TOTAL, SPEED, wformat);
}

void fun_set_via_assignment_operator(const uint64_t &trials,
                                     const uint64_t &vec_size,
                                     const double &val,
                                     const uint32_t &wformat) {
    const auto TRIALS(trials);
    const auto DIM_VEC(vec_size);
    const auto TEST_VAL(val);

    spl::vector_dense<double> v1;
    v1.allocate(DIM_VEC);
    v1 = TEST_VAL;

    auto t1(std::chrono::system_clock::now());

    for (uint64_t i = 1; i <= TRIALS; i++) {
        spl::vector_dense<double> v2;
        v2 = v1;
    }

    auto t2(std::chrono::system_clock::now());
    auto time_span_alloc_via_constructor(
            std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

    const auto TIME_TOTAL(time_span_alloc_via_constructor.count());
    const auto SPEED((DIM_VEC * TRIALS) / (TIME_TOTAL / 1000.0));

    fun_display_a(TRIALS, DIM_VEC, TIME_TOTAL, SPEED, wformat);
}

void fun_set_vector_element_by_element(const uint64_t &trials,
                                       const uint64_t &vec_size,
                                       const uint32_t &wformat) {
    const auto TRIALS(trials);
    const auto DIM_VEC(vec_size);
    const auto TEST_VAL(1234.5678);

    spl::vector_dense<double> v1(DIM_VEC);

    auto t1(std::chrono::system_clock::now());

    for (uint64_t i = 1; i <= TRIALS; i++) {
        for (uint64_t j = 0; j < DIM_VEC; j++) {
            v1.set_element(j, TEST_VAL);
        }
    }

    auto t2(std::chrono::system_clock::now());
    auto time_span_alloc_via_constructor(
            std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

    const auto TIME_TOTAL(time_span_alloc_via_constructor.count());
    const auto SPEED((DIM_VEC * TRIALS) / (TIME_TOTAL / 1000.0));

    fun_display_a(TRIALS, DIM_VEC, TIME_TOTAL, SPEED, wformat);
}

void fun_set_vector_element_by_element_square(const uint64_t &trials,
                                              const uint64_t &vec_size,
                                              const uint32_t &wformat) {
    const auto TRIALS(trials);
    const auto DIM_VEC(vec_size);
    const auto TEST_VAL(1234.5678);

    spl::vector_dense<double> v1(DIM_VEC);

    auto t1(std::chrono::system_clock::now());

    for (uint64_t i = 1; i <= TRIALS; i++) {
        for (uint64_t j = 0; j < DIM_VEC; j++) {
            v1[j] = TEST_VAL;
        }
    }

    auto t2(std::chrono::system_clock::now());
    auto time_span_alloc_via_constructor(
            std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

    const auto TIME_TOTAL(time_span_alloc_via_constructor.count());
    const auto SPEED((DIM_VEC * TRIALS) / (TIME_TOTAL / 1000.0));

    fun_display_a(TRIALS, DIM_VEC, TIME_TOTAL, SPEED, wformat);
}

//=====//
// get //
//=====//

void fun_get_vector_element_by_element_square(const uint64_t &trials,
                                              const uint64_t &vec_size,
                                              const uint32_t &wformat) {
    const auto TRIALS(trials);
    const auto DIM_VEC(vec_size);
    const auto TEST_VAL(1234.5678);

    spl::vector_dense<double> v1(DIM_VEC, TEST_VAL);
    spl::vector_dense<double> v2(DIM_VEC);

    auto t1(std::chrono::system_clock::now());

    for (uint64_t i = 1; i <= TRIALS; i++) {
        for (uint64_t j = 0; j < DIM_VEC; j++) {
            v2[j] = v1[j];
        }
    }

    auto t2(std::chrono::system_clock::now());
    auto time_span_alloc_via_constructor(
            std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

    const auto TIME_TOTAL(time_span_alloc_via_constructor.count());
    const auto SPEED((DIM_VEC * TRIALS) / (TIME_TOTAL / 1000.0));

    fun_display_a(TRIALS, DIM_VEC, TIME_TOTAL, SPEED, wformat);
}

void fun_get_vector_element_by_element_curly(const uint64_t &trials,
                                             const uint64_t &vec_size,
                                             const uint32_t &wformat) {
    const auto TRIALS(trials);
    const auto DIM_VEC(vec_size);
    const auto TEST_VAL(1234.5678);

    spl::vector_dense<double> v1(DIM_VEC, TEST_VAL);
    spl::vector_dense<double> v2(DIM_VEC);

    auto t1(std::chrono::system_clock::now());

    for (uint64_t i = 1; i <= TRIALS; i++) {
        for (uint64_t j = 0; j < DIM_VEC; j++) {
            v2[j] = v1(j);
        }
    }

    auto t2(std::chrono::system_clock::now());
    auto time_span_alloc_via_constructor(
            std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

    const auto TIME_TOTAL(time_span_alloc_via_constructor.count());
    const auto SPEED((DIM_VEC * TRIALS) / (TIME_TOTAL / 1000.0));

    fun_display_a(TRIALS, DIM_VEC, TIME_TOTAL, SPEED, wformat);
}

//======//
// plus //
//======//

void fun_add_vector_vector_using_operator(const uint64_t &trials,
                                          const uint64_t &vec_size,
                                          const uint32_t &wformat) {
    const auto TRIALS(trials);
    const auto DIM_VEC(vec_size);
    const auto TEST_VAL1(1234.5678);
    const auto TEST_VAL2(8765.4321);

    spl::vector_dense<double> v1(DIM_VEC, TEST_VAL1);
    spl::vector_dense<double> v2(DIM_VEC, TEST_VAL2);
    spl::vector_dense<double> v3(DIM_VEC);

    auto t1(std::chrono::system_clock::now());

    for (uint64_t i = 1; i <= TRIALS; i++) {
        v3 = v1 + v2;
    }

    auto t2(std::chrono::system_clock::now());
    auto time_span_alloc_via_constructor(
            std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

    const auto TIME_TOTAL(time_span_alloc_via_constructor.count());
    const auto SPEED((DIM_VEC * TRIALS) / (TIME_TOTAL / 1000.0));

    fun_display_a(TRIALS, DIM_VEC, TIME_TOTAL, SPEED, wformat);
}

void fun_add_vector_vector_element_by_element(const uint64_t &trials,
                                              const uint64_t &vec_size,
                                              const uint32_t &wformat) {
    const auto TRIALS(trials);
    const auto DIM_VEC(vec_size);
    const auto TEST_VAL1(1234.5678);
    const auto TEST_VAL2(8765.4321);

    spl::vector_dense<double> v1(DIM_VEC, TEST_VAL1);
    spl::vector_dense<double> v2(DIM_VEC, TEST_VAL2);
    spl::vector_dense<double> v3(DIM_VEC);

    auto t1(std::chrono::system_clock::now());

    for (uint64_t i = 1; i <= TRIALS; i++) {
        for (uint64_t j = 0; j < DIM_VEC; j++) {
            v3[j] = v1[j] + v2[j];
        }
    }

    auto t2(std::chrono::system_clock::now());
    auto time_span_alloc_via_constructor(
            std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

    const auto TIME_TOTAL(time_span_alloc_via_constructor.count());
    const auto SPEED((DIM_VEC * TRIALS) / (TIME_TOTAL / 1000.0));

    fun_display_a(TRIALS, DIM_VEC, TIME_TOTAL, SPEED, wformat);
}

void fun_add_vector_vector_plus_true(const uint64_t &trials,
                                     const uint64_t &vec_size,
                                     const uint32_t &wformat) {
    const auto TRIALS(trials);
    const auto DIM_VEC(vec_size);
    const auto TEST_VAL1(1234.5678);
    const auto TEST_VAL2(8765.4321);

    spl::vector_dense<double> v1(DIM_VEC, TEST_VAL1);
    spl::vector_dense<double> v2(DIM_VEC, TEST_VAL2);
    spl::vector_dense<double> v3(DIM_VEC);

    auto t1(std::chrono::system_clock::now());

    for (uint64_t i = 1; i <= TRIALS; i++) {
        v3 = v1.plus(v2, true);
    }

    auto t2(std::chrono::system_clock::now());
    auto time_span_alloc_via_constructor(
            std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

    const auto TIME_TOTAL(time_span_alloc_via_constructor.count());
    const auto SPEED((DIM_VEC * TRIALS) / (TIME_TOTAL / 1000.0));

    fun_display_a(TRIALS, DIM_VEC, TIME_TOTAL, SPEED, wformat);
}

void fun_add_vector_vector_plus_false(const uint64_t &trials,
                                      const uint64_t &vec_size,
                                      const uint32_t &wformat) {
    const auto TRIALS(trials);
    const auto DIM_VEC(vec_size);
    const auto TEST_VAL1(1234.5678);
    const auto TEST_VAL2(8765.4321);

    spl::vector_dense<double> v1(DIM_VEC, TEST_VAL1);
    spl::vector_dense<double> v2(DIM_VEC, TEST_VAL2);
    spl::vector_dense<double> v3(DIM_VEC);

    auto t1(std::chrono::system_clock::now());

    for (uint64_t i = 1; i <= TRIALS; i++) {
        v3 = v1.plus(v2, false);
    }

    auto t2(std::chrono::system_clock::now());
    auto time_span_alloc_via_constructor(
            std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

    const auto TIME_TOTAL(time_span_alloc_via_constructor.count());
    const auto SPEED((DIM_VEC * TRIALS) / (TIME_TOTAL / 1000.0));

    fun_display_a(TRIALS, DIM_VEC, TIME_TOTAL, SPEED, wformat);
}

//=======//
// times //
//=======//

void fun_times_vector_vector_using_operator(const uint64_t &trials,
                                            const uint64_t &vec_size,
                                            const uint32_t &wformat) {
    const auto TRIALS(trials);
    const auto DIM_VEC(vec_size);
    const auto TEST_VAL1(1234.5678);
    const auto TEST_VAL2(8765.4321);

    spl::vector_dense<double> v1(DIM_VEC, TEST_VAL1);
    spl::vector_dense<double> v2(DIM_VEC, TEST_VAL2);
    spl::vector_dense<double> v3(DIM_VEC);

    auto t1(std::chrono::system_clock::now());

    for (uint64_t i = 1; i <= TRIALS; i++) {
        v3 = v1 * v2;
    }

    auto t2(std::chrono::system_clock::now());
    auto time_span_alloc_via_constructor(
            std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

    const auto TIME_TOTAL(time_span_alloc_via_constructor.count());
    const auto SPEED((DIM_VEC * TRIALS) / (TIME_TOTAL / 1000.0));

    fun_display_a(TRIALS, DIM_VEC, TIME_TOTAL, SPEED, wformat);
}

void fun_times_vector_vector_element_by_element(const uint64_t &trials,
                                                const uint64_t &vec_size,
                                                const uint32_t &wformat) {
    const auto TRIALS(trials);
    const auto DIM_VEC(vec_size);
    const auto TEST_VAL1(1234.5678);
    const auto TEST_VAL2(8765.4321);

    spl::vector_dense<double> v1(DIM_VEC, TEST_VAL1);
    spl::vector_dense<double> v2(DIM_VEC, TEST_VAL2);
    spl::vector_dense<double> v3(DIM_VEC);

    auto t1(std::chrono::system_clock::now());

    for (uint64_t i = 1; i <= TRIALS; i++) {
        for (uint64_t j = 0; j < DIM_VEC; j++) {
            v3[j] = v1[j] * v2[j];
        }
    }

    auto t2(std::chrono::system_clock::now());
    auto time_span_alloc_via_constructor(
            std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

    const auto TIME_TOTAL(time_span_alloc_via_constructor.count());
    const auto SPEED((DIM_VEC * TRIALS) / (TIME_TOTAL / 1000.0));

    fun_display_a(TRIALS, DIM_VEC, TIME_TOTAL, SPEED, wformat);
}

void fun_times_vector_vector_times_true(const uint64_t &trials,
                                        const uint64_t &vec_size,
                                        const uint32_t &wformat) {
    const auto TRIALS(trials);
    const auto DIM_VEC(vec_size);
    const auto TEST_VAL1(1234.5678);
    const auto TEST_VAL2(8765.4321);

    spl::vector_dense<double> v1(DIM_VEC, TEST_VAL1);
    spl::vector_dense<double> v2(DIM_VEC, TEST_VAL2);
    spl::vector_dense<double> v3(DIM_VEC);

    auto t1(std::chrono::system_clock::now());

    for (uint64_t i = 1; i <= TRIALS; i++) {
        v3 = v1.times(v2, true);
    }

    auto t2(std::chrono::system_clock::now());
    auto time_span_alloc_via_constructor(
            std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

    const auto TIME_TOTAL(time_span_alloc_via_constructor.count());
    const auto SPEED((DIM_VEC * TRIALS) / (TIME_TOTAL / 1000.0));

    fun_display_a(TRIALS, DIM_VEC, TIME_TOTAL, SPEED, wformat);
}

void fun_times_vector_vector_times_false(const uint64_t &trials,
                                         const uint64_t &vec_size,
                                         const uint32_t &wformat) {
    const auto TRIALS(trials);
    const auto DIM_VEC(vec_size);
    const auto TEST_VAL1(1234.5678);
    const auto TEST_VAL2(8765.4321);

    spl::vector_dense<double> v1(DIM_VEC, TEST_VAL1);
    spl::vector_dense<double> v2(DIM_VEC, TEST_VAL2);
    spl::vector_dense<double> v3(DIM_VEC);

    auto t1(std::chrono::system_clock::now());

    for (uint64_t i = 1; i <= TRIALS; i++) {
        v3 = v1.times(v2, false);
    }

    auto t2(std::chrono::system_clock::now());
    auto time_span_alloc_via_constructor(
            std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

    const auto TIME_TOTAL(time_span_alloc_via_constructor.count());
    const auto SPEED((DIM_VEC * TRIALS) / (TIME_TOTAL / 1000.0));

    fun_display_a(TRIALS, DIM_VEC, TIME_TOTAL, SPEED, wformat);
}

//==========//
// subtract //
//==========//

void fun_subtract_vector_vector_using_operator(const uint64_t &trials,
                                               const uint64_t &vec_size,
                                               const uint32_t &wformat) {
    const auto TRIALS(trials);
    const auto DIM_VEC(vec_size);
    const auto TEST_VAL1(1234.5678);
    const auto TEST_VAL2(8765.4321);

    spl::vector_dense<double> v1(DIM_VEC, TEST_VAL1);
    spl::vector_dense<double> v2(DIM_VEC, TEST_VAL2);
    spl::vector_dense<double> v3(DIM_VEC);

    auto t1(std::chrono::system_clock::now());

    for (uint64_t i = 1; i <= TRIALS; i++) {
        v3 = v1 - v2;
    }

    auto t2(std::chrono::system_clock::now());
    auto time_span_alloc_via_constructor(
            std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

    const auto TIME_TOTAL(time_span_alloc_via_constructor.count());
    const auto SPEED((DIM_VEC * TRIALS) / (TIME_TOTAL / 1000.0));

    fun_display_a(TRIALS, DIM_VEC, TIME_TOTAL, SPEED, wformat);
}

void fun_subtract_vector_vector_element_by_element(const uint64_t &trials,
                                                   const uint64_t &vec_size,
                                                   const uint32_t &wformat) {
    const auto TRIALS(trials);
    const auto DIM_VEC(vec_size);
    const auto TEST_VAL1(1234.5678);
    const auto TEST_VAL2(8765.4321);

    spl::vector_dense<double> v1(DIM_VEC, TEST_VAL1);
    spl::vector_dense<double> v2(DIM_VEC, TEST_VAL2);
    spl::vector_dense<double> v3(DIM_VEC);

    auto t1(std::chrono::system_clock::now());

    for (uint64_t i = 1; i <= TRIALS; i++) {
        for (uint64_t j = 0; j < DIM_VEC; j++) {
            v3[j] = v1[j] - v2[j];
        }
    }

    auto t2(std::chrono::system_clock::now());
    auto time_span_alloc_via_constructor(
            std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

    const auto TIME_TOTAL(time_span_alloc_via_constructor.count());
    const auto SPEED((DIM_VEC * TRIALS) / (TIME_TOTAL / 1000.0));

    fun_display_a(TRIALS, DIM_VEC, TIME_TOTAL, SPEED, wformat);
}

void fun_subtract_vector_vector_subtract_true(const uint64_t &trials,
                                              const uint64_t &vec_size,
                                              const uint32_t &wformat) {
    const auto TRIALS(trials);
    const auto DIM_VEC(vec_size);
    const auto TEST_VAL1(1234.5678);
    const auto TEST_VAL2(8765.4321);

    spl::vector_dense<double> v1(DIM_VEC, TEST_VAL1);
    spl::vector_dense<double> v2(DIM_VEC, TEST_VAL2);
    spl::vector_dense<double> v3(DIM_VEC);

    auto t1(std::chrono::system_clock::now());

    for (uint64_t i = 1; i <= TRIALS; i++) {
        v3 = v1.subtract(v2, true);
    }

    auto t2(std::chrono::system_clock::now());
    auto time_span_alloc_via_constructor(
            std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

    const auto TIME_TOTAL(time_span_alloc_via_constructor.count());
    const auto SPEED((DIM_VEC * TRIALS) / (TIME_TOTAL / 1000.0));

    fun_display_a(TRIALS, DIM_VEC, TIME_TOTAL, SPEED, wformat);
}

void fun_subtract_vector_vector_subtract_false(const uint64_t &trials,
                                               const uint64_t &vec_size,
                                               const uint32_t &wformat) {
    const auto TRIALS(trials);
    const auto DIM_VEC(vec_size);
    const auto TEST_VAL1(1234.5678);
    const auto TEST_VAL2(8765.4321);

    spl::vector_dense<double> v1(DIM_VEC, TEST_VAL1);
    spl::vector_dense<double> v2(DIM_VEC, TEST_VAL2);
    spl::vector_dense<double> v3(DIM_VEC);

    auto t1(std::chrono::system_clock::now());

    for (uint64_t i = 1; i <= TRIALS; i++) {
        v3 = v1.subtract(v2, false);
    }

    auto t2(std::chrono::system_clock::now());
    auto time_span_alloc_via_constructor(
            std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

    const auto TIME_TOTAL(time_span_alloc_via_constructor.count());
    const auto SPEED((DIM_VEC * TRIALS) / (TIME_TOTAL / 1000.0));

    fun_display_a(TRIALS, DIM_VEC, TIME_TOTAL, SPEED, wformat);
}

//========//
// divide //
//========//

void fun_divide_vector_vector_using_operator(const uint64_t &trials,
                                             const uint64_t &vec_size,
                                             const uint32_t &wformat) {
    const auto TRIALS(trials);
    const auto DIM_VEC(vec_size);
    const auto TEST_VAL1(1234.5678);
    const auto TEST_VAL2(8765.4321);

    spl::vector_dense<double> v1(DIM_VEC, TEST_VAL1);
    spl::vector_dense<double> v2(DIM_VEC, TEST_VAL2);
    spl::vector_dense<double> v3(DIM_VEC);

    auto t1(std::chrono::system_clock::now());

    for (uint64_t i = 1; i <= TRIALS; i++) {
        v3 = v1 / v2;
    }

    auto t2(std::chrono::system_clock::now());
    auto time_span_alloc_via_constructor(
            std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

    const auto TIME_TOTAL(time_span_alloc_via_constructor.count());
    const auto SPEED((DIM_VEC * TRIALS) / (TIME_TOTAL / 1000.0));

    fun_display_a(TRIALS, DIM_VEC, TIME_TOTAL, SPEED, wformat);
}

void fun_divide_vector_vector_element_by_element(const uint64_t &trials,
                                                 const uint64_t &vec_size,
                                                 const uint32_t &wformat) {
    const auto TRIALS(trials);
    const auto DIM_VEC(vec_size);
    const auto TEST_VAL1(1234.5678);
    const auto TEST_VAL2(8765.4321);

    spl::vector_dense<double> v1(DIM_VEC, TEST_VAL1);
    spl::vector_dense<double> v2(DIM_VEC, TEST_VAL2);
    spl::vector_dense<double> v3(DIM_VEC);

    auto t1(std::chrono::system_clock::now());

    for (uint64_t i = 1; i <= TRIALS; i++) {
        for (uint64_t j = 0; j < DIM_VEC; j++) {
            v3[j] = v1[j] / v2[j];
        }
    }

    auto t2(std::chrono::system_clock::now());
    auto time_span_alloc_via_constructor(
            std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

    const auto TIME_TOTAL(time_span_alloc_via_constructor.count());
    const auto SPEED((DIM_VEC * TRIALS) / (TIME_TOTAL / 1000.0));

    fun_display_a(TRIALS, DIM_VEC, TIME_TOTAL, SPEED, wformat);
}

void fun_divide_vector_vector_divide_true(const uint64_t &trials,
                                          const uint64_t &vec_size,
                                          const uint32_t &wformat) {
    const auto TRIALS(trials);
    const auto DIM_VEC(vec_size);
    const auto TEST_VAL1(1234.5678);
    const auto TEST_VAL2(8765.4321);

    spl::vector_dense<double> v1(DIM_VEC, TEST_VAL1);
    spl::vector_dense<double> v2(DIM_VEC, TEST_VAL2);
    spl::vector_dense<double> v3(DIM_VEC);

    auto t1(std::chrono::system_clock::now());

    for (uint64_t i = 1; i <= TRIALS; i++) {
        v3 = v1.divide(v2, true);
    }

    auto t2(std::chrono::system_clock::now());
    auto time_span_alloc_via_constructor(
            std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

    const auto TIME_TOTAL(time_span_alloc_via_constructor.count());
    const auto SPEED((DIM_VEC * TRIALS) / (TIME_TOTAL / 1000.0));

    fun_display_a(TRIALS, DIM_VEC, TIME_TOTAL, SPEED, wformat);
}

void fun_divide_vector_vector_divide_false(const uint64_t &trials,
                                           const uint64_t &vec_size,
                                           const uint32_t &wformat) {
    const auto TRIALS(trials);
    const auto DIM_VEC(vec_size);
    const auto TEST_VAL1(1234.5678);
    const auto TEST_VAL2(8765.4321);

    spl::vector_dense<double> v1(DIM_VEC, TEST_VAL1);
    spl::vector_dense<double> v2(DIM_VEC, TEST_VAL2);
    spl::vector_dense<double> v3(DIM_VEC);

    auto t1(std::chrono::system_clock::now());

    for (uint64_t i = 1; i <= TRIALS; i++) {
        v3 = v1.divide(v2, false);
    }

    auto t2(std::chrono::system_clock::now());
    auto time_span_alloc_via_constructor(
            std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

    const auto TIME_TOTAL(time_span_alloc_via_constructor.count());
    const auto SPEED((DIM_VEC * TRIALS) / (TIME_TOTAL / 1000.0));

    fun_display_a(TRIALS, DIM_VEC, TIME_TOTAL, SPEED, wformat);
}
