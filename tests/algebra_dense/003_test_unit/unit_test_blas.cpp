#include <cmath>
#include "gtest/gtest.h"
#include "../../../vector_dense/vector_dense.h"
#include "../../../algebra_dense/algebra_blas_level_1.h"

// local parameters

const uint64_t DIM_COMM(static_cast<uint64_t>(pow(10.0, 3.0)));
const double ERROR_10E4(pow(10.0, -4.0));
const double ERROR_10E5(pow(10.0, -5.0));
const double ERROR_10E6(pow(10.0, -6.0));
const double ERROR_10E7(pow(10.0, -7.0));
const double ERROR_10E8(pow(10.0, -8.0));
const double VAL_TEST1(1234.5678);
const double VAL_TEST2(8765.4321);
const double VAL_TEST3(1.0);
const double VAL_TEST4(2.0);

// vector_dense dot double - one value

TEST(vector_dense_dot_double_one_value, algebra_dense_blas) {

    spl::vector_dense<double> vec1;
    spl::vector_dense<double> vec2;

    vec1.allocate(DIM_COMM);
    vec2.allocate(DIM_COMM);

    vec1 = VAL_TEST1;
    vec2 = VAL_TEST2;

    const double RES(spl::dot(vec1, vec2));

    EXPECT_NEAR(VAL_TEST1 * VAL_TEST2 * DIM_COMM, RES, ERROR_10E5);
}

// vector_dense dot float - one value

TEST(vector_dense_dot_float_one_value, algebra_dense_blas) {

    spl::vector_dense<float> vec1;
    spl::vector_dense<float> vec2;

    vec1.allocate(DIM_COMM);
    vec2.allocate(DIM_COMM);

    vec1 = VAL_TEST3;
    vec2 = VAL_TEST4;

    const double RES(spl::dot(vec1, vec2));

    EXPECT_NEAR(VAL_TEST3 * VAL_TEST4 * DIM_COMM, RES, ERROR_10E5);
}

// vector dense - dot double - many values

TEST(vector_dense_dot_double_many_values, algebra_dense_blas) {

    spl::vector_dense<double> vec1;
    spl::vector_dense<double> vec2;

    vec1.allocate(DIM_COMM);
    vec2.allocate(DIM_COMM);

    for (uint64_t i = 0; i != vec1.size(); i++) {

        vec1[i] = std::sin(static_cast<double>(i));
        vec2[i] = std::cos(static_cast<double>(i));
    }

    const double RES(spl::dot(vec1, vec2));
    double sum(0);

    for (uint64_t i = 0; i != DIM_COMM; i++) {

        sum = sum + (std::sin(static_cast<double>(i)) * std::cos(static_cast<double>(i)));
    }

    EXPECT_NEAR(RES, sum, ERROR_10E5);
}

// vector dense - dot float - many values

TEST(vector_dense_dot_float_many_values, algebra_dense_blas) {

    spl::vector_dense<float> vec1;
    spl::vector_dense<float> vec2;

    vec1.allocate(DIM_COMM);
    vec2.allocate(DIM_COMM);

    for (uint64_t i = 0; i != vec1.size(); i++) {

        vec1[i] = std::sin(static_cast<float>(i));
        vec2[i] = std::cos(static_cast<float>(i));
    }

    const float RES(spl::dot(vec1, vec2));
    float sum(0);

    for (uint64_t i = 0; i != DIM_COMM; i++) {

        sum = sum + (std::sin(static_cast<float>(i)) * std::cos(static_cast<float>(i)));
    }

    EXPECT_NEAR(RES, sum, ERROR_10E5);
}

// vector - stl - dot double - one value

TEST(vector_stl_dot_double_one_value, algebra_dense_blas) {

    std::vector<double> vec1;
    std::vector<double> vec2;

    vec1.resize(DIM_COMM, VAL_TEST1);
    vec2.resize(DIM_COMM, VAL_TEST2);

    const double RES(spl::dot(vec1, vec2));

    EXPECT_NEAR(VAL_TEST1 * VAL_TEST2 * DIM_COMM, RES, ERROR_10E5);
}

// vector - stl - dot float - one value

TEST(vector_stl_dot_float_one_value, algebra_dense_blas) {

    std::vector<float> vec1;
    std::vector<float> vec2;

    vec1.resize(DIM_COMM, VAL_TEST3);
    vec2.resize(DIM_COMM, VAL_TEST4);

    const float RES(spl::dot(vec1, vec2));

    EXPECT_NEAR(VAL_TEST3 * VAL_TEST4 * DIM_COMM, RES, ERROR_10E5);
}

// vector - stl - dot double - many values

TEST(vector_stl_dot_double_many_values, algebra_dense_blas) {

    std::vector<double> vec1;
    std::vector<double> vec2;

    vec1.resize(DIM_COMM);
    vec2.resize(DIM_COMM);

    for (uint64_t i = 0; i != vec1.size(); i++) {

        vec1[i] = std::sin(static_cast<double>(i));
        vec2[i] = std::cos(static_cast<double>(i));
    }

    const double RES(spl::dot(vec1, vec2));
    double sum(0);

    for (uint64_t i = 0; i != DIM_COMM; i++) {

        sum = sum + (std::sin(static_cast<double>(i)) * std::cos(static_cast<double>(i)));
    }

    EXPECT_NEAR(RES, sum, ERROR_10E5);
}

// vector - stl - dot float - many values

TEST(vector_stl_dot_float_many_values, algebra_dense_blas) {

    std::vector<float> vec1;
    std::vector<float> vec2;

    vec1.resize(DIM_COMM);
    vec2.resize(DIM_COMM);

    for (uint64_t i = 0; i != vec1.size(); i++) {

        vec1[i] = std::sin(static_cast<float>(i));
        vec2[i] = std::cos(static_cast<float>(i));
    }

    const float RES(spl::dot(vec1, vec2));
    float sum(0);

    for (uint64_t i = 0; i != DIM_COMM; i++) {

        sum = sum + (std::sin(static_cast<float>(i)) * std::cos(static_cast<float>(i)));
    }

    EXPECT_NEAR(RES, sum, ERROR_10E5);
}


//
//==========//
// test # 4 //
//==========//
//
//TEST(VectorTest4, Dot)
//{
//     VectorDense<double> vecA;
//     VectorDense<double> vecB;
//     MatrixDense<double> matA;
//
//     EXPECT_TRUE(vecA.DeallocatedQ());
//     EXPECT_TRUE(vecB.DeallocatedQ());
//     EXPECT_TRUE(matA.DeallocatedQ());
//
//     const int ELEMS_A = 10;
//     const int ELEMS_B = 1000;
//
//     vecA.Allocate(ELEMS_A);
//     vecB.Allocate(ELEMS_B);
//     matA.Allocate(ELEMS_A, ELEMS_B);
//
//     EXPECT_TRUE(vecA.AllocatedQ());
//     EXPECT_TRUE(vecB.AllocatedQ());
//     EXPECT_TRUE(matA.AllocatedQ());
//
//     for (int i = 0; i != ELEMS_B; ++i) {
//          vecB.SetElement(i, sin(static_cast<double>(i)));
//     }
//
//     for (int i = 0; i != ELEMS_B*ELEMS_A; ++i) {
//          matA.SetElement(i, cos(static_cast<double>(i)));
//     }
//
//     vecA.DotGSL(matA, vecB);
//
//     const double corr[ELEMS_A] = {
//          -0.013000956337400969716, -413.04095342736712548,
//          -464.55817876109059451, -109.47464548253968530,
//          341.42567875364489603, 493.49596116134191391,
//          213.63792682857131289, -253.20496126031645456,
//          -498.43227128017131844, -307.41079937172321604
//     };
//
//     for(int i = 0; i != ELEMS_A; ++i) {
//          EXPECT_TRUE((corr[i]-vecA[i]) < pow(10.0, -10.0));
//     }
//}
//
////==========//
//// test # 5 //
////==========//
//
//TEST(VectorTest5, Dot)
//{
//     VectorDense<double> vecA;
//     VectorDense<double> vecB;
//     MatrixDense<double> matA;
//
//     EXPECT_TRUE(vecA.DeallocatedQ());
//     EXPECT_TRUE(vecB.DeallocatedQ());
//     EXPECT_TRUE(matA.DeallocatedQ());
//
//     const int ELEMS_A = 10;
//     const int ELEMS_B = 1000;
//
//     vecA.Allocate(ELEMS_A);
//     vecB.Allocate(ELEMS_B);
//     matA.Allocate(ELEMS_A, ELEMS_B);
//
//     EXPECT_TRUE(vecA.AllocatedQ());
//     EXPECT_TRUE(vecB.AllocatedQ());
//     EXPECT_TRUE(matA.AllocatedQ());
//
//     for (int i = 0; i != ELEMS_B; ++i) {
//          vecB.SetElement(i, sin(static_cast<double>(i)));
//     }
//
//     for (int i = 0; i != ELEMS_B*ELEMS_A; ++i) {
//          matA.SetElement(i, cos(static_cast<double>(i)));
//     }
//
//     vecA.DotBLAS(matA, vecB);
//
//     const double corr[ELEMS_A] = {
//          -0.013000956337400969716, -413.04095342736712548,
//          -464.55817876109059451, -109.47464548253968530,
//          341.42567875364489603, 493.49596116134191391,
//          213.63792682857131289, -253.20496126031645456,
//          -498.43227128017131844, -307.41079937172321604
//     };
//
//     for(int i = 0; i != ELEMS_A; ++i) {
//          EXPECT_TRUE((corr[i]-vecA[i]) < pow(10.0, -10.0));
//     }
//}
//
////==========//
//// test # 6 //
////==========//
//
//TEST(VectorTest6, Dot)
//{
//     VectorDense<double> vecA;
//     VectorDense<double> vecB;
//     MatrixDense<double> matA;
//
//     EXPECT_TRUE(vecA.DeallocatedQ());
//     EXPECT_TRUE(vecB.DeallocatedQ());
//     EXPECT_TRUE(matA.DeallocatedQ());
//
//     const int ELEMS_A = 10;
//     const int ELEMS_B = 1000;
//
//     vecA.Allocate(ELEMS_A);
//     vecB.Allocate(ELEMS_B);
//     matA.Allocate(ELEMS_A, ELEMS_B);
//
//     EXPECT_TRUE(vecA.AllocatedQ());
//     EXPECT_TRUE(vecB.AllocatedQ());
//     EXPECT_TRUE(matA.AllocatedQ());
//
//     for (int i = 0; i != ELEMS_B; ++i) {
//          vecB.SetElement(i, sin(static_cast<double>(i)));
//     }
//
//     for (int i = 0; i != ELEMS_B*ELEMS_A; ++i) {
//          matA.SetElement(i, cos(static_cast<double>(i)));
//     }
//
//     vecA.Dot(matA, vecB, "WithRows");
//
//     const double corr[ELEMS_A] = {
//          -0.013000956337400969716, -413.04095342736712548,
//          -464.55817876109059451, -109.47464548253968530,
//          341.42567875364489603, 493.49596116134191391,
//          213.63792682857131289, -253.20496126031645456,
//          -498.43227128017131844, -307.41079937172321604
//     };
//
//     for(int i = 0; i != ELEMS_A; ++i) {
//          EXPECT_TRUE((corr[i]-vecA[i]) < pow(10.0, -10.0));
//     }
//}
//
////==========//
//// test # 7 //
////==========//
//
//TEST(VectorTest7, Dot)
//{
//     VectorDense<double> vecA;
//     VectorDense<double> vecB;
//     MatrixDense<double> matA;
//
//     EXPECT_TRUE(vecA.DeallocatedQ());
//     EXPECT_TRUE(vecB.DeallocatedQ());
//     EXPECT_TRUE(matA.DeallocatedQ());
//
//     const int ELEMS_A = 10;
//     const int ELEMS_B = 10;
//
//     vecA.Allocate(ELEMS_A);
//     vecB.Allocate(ELEMS_B);
//     matA.Allocate(ELEMS_A, ELEMS_B);
//
//     EXPECT_TRUE(vecA.AllocatedQ());
//     EXPECT_TRUE(vecB.AllocatedQ());
//     EXPECT_TRUE(matA.AllocatedQ());
//
//     for (int i = 0; i != ELEMS_B; ++i) {
//          vecB.SetElement(i, sin(static_cast<double>(i)));
//     }
//
//     for (int i = 0; i != ELEMS_B*ELEMS_A; ++i) {
//          matA.SetElement(i, cos(static_cast<double>(i)));
//     }
//
//     // # 1
//
//     vecA.Dot(matA, vecB, "WithColumns");
//
//     const double corr[ELEMS_A] = {
//          -0.3454781443936671, -0.1019678318253387, 0.2352912350744567,
//          0.3562246255479217, 0.1496467381066567, -0.1945156702185772,
//          -0.3598412683998245, -0.1943304639073055, 0.1498468729007396,
//          0.3562556858181048
//     };
//
//     for(int i = 0; i != ELEMS_A; ++i) {
//          EXPECT_TRUE((corr[i]-vecA[i]) < pow(10.0, -10.0));
//     }
//
//     // # 2
//
//     vecA.Dot(matA, vecB, "WithRows", "GSL");
//
//     const double corr2[ELEMS_A] = {
//          -0.1332197783447333, 2.671656845240047, -4.350202610261541,
//          4.628605466729006, -3.417259522658326, 1.106044879126973,
//          1.561157986745827, -3.725891317264447, 4.691420662753688,
//          -4.146983700810754
//     };
//
//     for(int i = 0; i != ELEMS_A; ++i) {
//          EXPECT_TRUE((corr2[i]-vecA[i]) < pow(10.0, -10.0));
//     }
//
//     // # 3
//
//     vecA.Dot(matA, vecB, "WithRows", "BLAS");
//
//     for(int i = 0; i != ELEMS_A; ++i) {
//          EXPECT_TRUE((corr2[i]-vecA[i]) < pow(10.0, -10.0));
//     }
//}
//
////==========//
//// test # 8 //
////==========//
//
//TEST(VectorTest8, Dot)
//{
//     VectorDense<double> vecA;
//     VectorDense<double> vecB;
//     MatrixDense<double> matA;
//
//     EXPECT_TRUE(vecA.DeallocatedQ());
//     EXPECT_TRUE(vecB.DeallocatedQ());
//     EXPECT_TRUE(matA.DeallocatedQ());
//
//     const int ELEMS_A = 10;
//     const int ELEMS_B = 20;
//
//     vecA.Allocate(ELEMS_A);
//     vecB.Allocate(ELEMS_B);
//     matA.Allocate(ELEMS_B, ELEMS_A);
//
//     EXPECT_TRUE(vecA.AllocatedQ());
//     EXPECT_TRUE(vecB.AllocatedQ());
//     EXPECT_TRUE(matA.AllocatedQ());
//
//     for (int i = 0; i != ELEMS_B; ++i) {
//          vecB.SetElement(i, sin(static_cast<double>(i)));
//     }
//
//     for (int i = 0; i != ELEMS_B*ELEMS_A; ++i) {
//          matA.SetElement(i, cos(static_cast<double>(i)));
//     }
//
//     // # 1
//
//     vecA.Dot(matA, vecB, "WithColumns", "GSL");
//
//     const double corr[ELEMS_A] = {-0.30954436029720900162, -0.48502368596743207457,
//                                   -0.21457447156052705936, 0.25315352243825139799,
//                                   0.48813333538458521522, 0.27432561092054338018,
//                                   -0.19169581510647377821, -0.48147299277514408727,
//                                   -0.32858612131281527168, 0.12640131473197932762
//                                  };
//
//     for(int i = 0; i != ELEMS_A; ++i) {
//          EXPECT_TRUE((corr[i]-vecA[i]) < pow(10.0, -10.0));
//     }
//
//     // # 2
//
//     vecA.Dot(matA, vecB, "WithColumns", "BLAS");
//
//     for(int i = 0; i != ELEMS_A; ++i) {
//          EXPECT_TRUE((corr[i]-vecA[i]) < pow(10.0, -10.0));
//     }
//
//     // # 3
//
//     vecA.Dot(matA, vecB, "WithColumns");
//
//     for(int i = 0; i != ELEMS_A; ++i) {
//          EXPECT_TRUE((corr[i]-vecA[i]) < pow(10.0, -10.0));
//     }
//}
//
////==========//
//// test # 9 //
////==========//
//
//TEST(VectorTest9, Dot)
//{
//     VectorDense<double> vecA;
//     VectorDense<double> vecB;
//     MatrixDense<double> matA;
//
//     EXPECT_TRUE(vecA.DeallocatedQ());
//     EXPECT_TRUE(vecB.DeallocatedQ());
//     EXPECT_TRUE(matA.DeallocatedQ());
//
//     const int ELEMS_A = 10;
//     const int ELEMS_B = 10;
//
//     vecA.Allocate(ELEMS_A);
//     vecB.Allocate(ELEMS_B);
//     matA.Allocate(ELEMS_A, ELEMS_B);
//
//     EXPECT_TRUE(vecA.AllocatedQ());
//     EXPECT_TRUE(vecB.AllocatedQ());
//     EXPECT_TRUE(matA.AllocatedQ());
//
//     for (int i = 0; i != ELEMS_B; ++i) {
//          vecB.SetElement(i, sin(static_cast<double>(i)));
//     }
//
//     for (int i = 0; i != ELEMS_B*ELEMS_A; ++i) {
//          matA.SetElement(i, cos(static_cast<double>(i)));
//     }
//
//     // # 1
//
//     vecA.Dot(matA, vecB, "WithColumns");
//
//     const double corr[ELEMS_A] = {
//          -0.3454781443936671, -0.1019678318253387, 0.2352912350744567,
//          0.3562246255479217, 0.1496467381066567, -0.1945156702185772,
//          -0.3598412683998245, -0.1943304639073055, 0.1498468729007396,
//          0.3562556858181048
//     };
//
//     for(int i = 0; i != ELEMS_A; ++i) {
//          EXPECT_TRUE((corr[i]-vecA[i]) < pow(10.0, -10.0));
//     }
//
//     // # 2
//
//     for (int i = 0; i != ELEMS_B; ++i) {
//          vecB.SetElement(i, sin(static_cast<double>(i)));
//     }
//
//     vecB.Dot(matA, vecB, "WithRows", "GSL");
//
//     const double corr2[ELEMS_A] = {
//          -0.1332197783447333, 2.671656845240047, -4.350202610261541,
//          4.628605466729006, -3.417259522658326, 1.106044879126973,
//          1.561157986745827, -3.725891317264447, 4.691420662753688,
//          -4.146983700810754
//     };
//
//     for(int i = 0; i != ELEMS_A; ++i) {
//          EXPECT_TRUE((corr2[i]-vecB[i]) < pow(10.0, -10.0));
//     }
//
//     // # 3
//
//     for (int i = 0; i != ELEMS_B; ++i) {
//          vecB.SetElement(i, sin(static_cast<double>(i)));
//     }
//
//     vecB.Dot(matA, vecB, "WithRows", "BLAS");
//
//     for(int i = 0; i != ELEMS_A; ++i) {
//          EXPECT_TRUE((corr2[i]-vecB[i]) < pow(10.0, -10.0));
//     }
//
//     // # 4
//
//     for (int i = 0; i != ELEMS_B; ++i) {
//          vecB.SetElement(i, sin(static_cast<double>(i)));
//     }
//
//     vecB.Dot(matA, vecB);
//
//     for(int i = 0; i != ELEMS_A; ++i) {
//          EXPECT_TRUE((corr2[i]-vecB[i]) < pow(10.0, -10.0));
//     }
//}
//
////===========//
//// test # 10 //
////===========//
//
//TEST(VectorTest10, DotComplex)
//{
//     VectorDense<complex<double>> vecA;
//     VectorDense<complex<double>> vecB;
//
//     const int ELEMS = 100;
//
//     vecA.Allocate(ELEMS);
//     vecB.Allocate(ELEMS);
//
//     vecA = 1.234;
//     vecB = 2.345;
//
//     complex<double> tmp_double = vecA.Dot(vecB);
//
//     EXPECT_TRUE((1.234*2.345*100.0-std::real(tmp_double)) < pow(10.0, -14.0));
//}
//
////===========//
//// test # 11 //
////===========//
//
//TEST(VectorTest11, DotComplex)
//{
//     VectorDense<complex<double>> vecA;
//     VectorDense<complex<double>> vecB;
//
//     EXPECT_TRUE(vecA.DeallocatedQ());
//     EXPECT_TRUE(vecB.DeallocatedQ());
//
//     const int ELEMS = 10000;
//
//     vecA.Allocate(ELEMS);
//     vecB.Allocate(ELEMS);
//
//     EXPECT_TRUE(vecA.AllocatedQ());
//     EXPECT_TRUE(vecB.AllocatedQ());
//
//     vecA = {1.0, 2.0};
//     vecB = {2.0, 3.0};
//
//     complex<double> tmp_cmplxA = vecA.Dot(vecB);
//     complex<double> tmp_cmplxB;
//
//     complex<double> tmpA = {1.0, 2.0};
//     complex<double> tmpB = {2.0, 3.0};
//
//     tmp_cmplxB = {0.0, 0.0};
//
//     for (int i = 0; i != ELEMS; ++i) {
//          tmp_cmplxB = tmp_cmplxB + tmpA*tmpB;
//     }
//
//     EXPECT_TRUE(std::real((tmp_cmplxA-tmp_cmplxB)) < pow(10.0, -10.0));
//     EXPECT_TRUE(std::imag((tmp_cmplxA-tmp_cmplxB)) < pow(10.0, -10.0));
//}
//
////===========//
//// test # 12 //
////===========//
//
//TEST(VectorTest12, DotComplex)
//{
//     VectorDense<complex<double>> vecA;
//     VectorDense<complex<double>> vecB;
//
//     EXPECT_TRUE(vecA.DeallocatedQ());
//     EXPECT_TRUE(vecB.DeallocatedQ());
//
//     const int ELEMS = 10000;
//
//     vecA.Allocate(ELEMS);
//     vecB.Allocate(ELEMS);
//
//     EXPECT_TRUE(vecA.AllocatedQ());
//     EXPECT_TRUE(vecB.AllocatedQ());
//
//     for (int i = 0; i != ELEMS; ++i) {
//          vecA.SetElement(i, sin(static_cast<complex<double>>(i)));
//          vecB.SetElement(i, cos(static_cast<complex<double>>(i)));
//     }
//
//     complex<double> tmp_cmplxA = vecA.Dot(vecB);
//     const complex<double> tmp_cmplxB = -0.11551041567000858692;
//
//     EXPECT_TRUE(std::real(tmp_cmplxA-tmp_cmplxB) < pow(10.0, -14.0));
//}
//
////===========//
//// test # 13 //
////===========//
//
//TEST(VectorTest13, DotComplex)
//{
//     VectorDense<complex<double>> vecA;
//     VectorDense<complex<double>> vecB;
//     MatrixDense<complex<double>> matA;
//
//     EXPECT_TRUE(vecA.DeallocatedQ());
//     EXPECT_TRUE(vecB.DeallocatedQ());
//     EXPECT_TRUE(matA.DeallocatedQ());
//
//     const int ELEMS_A = 10;
//     const int ELEMS_B = 1000;
//
//     vecA.Allocate(ELEMS_A);
//     vecB.Allocate(ELEMS_B);
//     matA.Allocate(ELEMS_A, ELEMS_B);
//
//     EXPECT_TRUE(vecA.AllocatedQ());
//     EXPECT_TRUE(vecB.AllocatedQ());
//     EXPECT_TRUE(matA.AllocatedQ());
//
//     for (int i = 0; i != ELEMS_B; ++i) {
//          vecB.SetElement(i, sin(static_cast<complex<double>>(i)));
//     }
//
//     for (int i = 0; i != ELEMS_B*ELEMS_A; ++i) {
//          matA.SetElement(i, cos(static_cast<complex<double>>(i)));
//     }
//
//     vecA.Dot(matA, vecB);
//
//     const double corr[ELEMS_A] = {
//          -0.013000956337400969716, -413.04095342736712548,
//          -464.55817876109059451, -109.47464548253968530,
//          341.42567875364489603, 493.49596116134191391,
//          213.63792682857131289, -253.20496126031645456,
//          -498.43227128017131844, -307.41079937172321604
//     };
//
//     for(int i = 0; i != ELEMS_A; ++i) {
//          EXPECT_TRUE((corr[i]-std::real(vecA[i])) < pow(10.0, -10.0));
//     }
//}
//
////===========//
//// test # 14 //
////===========//
//
//TEST(VectorTest14, DotComplex)
//{
//     VectorDense<complex<double>> vecA;
//     VectorDense<complex<double>> vecB;
//     MatrixDense<complex<double>> matA;
//
//     EXPECT_TRUE(vecA.DeallocatedQ());
//     EXPECT_TRUE(vecB.DeallocatedQ());
//     EXPECT_TRUE(matA.DeallocatedQ());
//
//     const int ELEMS_A = 10;
//     const int ELEMS_B = 1000;
//
//     vecA.Allocate(ELEMS_A);
//     vecB.Allocate(ELEMS_B);
//     matA.Allocate(ELEMS_A, ELEMS_B);
//
//     EXPECT_TRUE(vecA.AllocatedQ());
//     EXPECT_TRUE(vecB.AllocatedQ());
//     EXPECT_TRUE(matA.AllocatedQ());
//
//     for (int i = 0; i != ELEMS_B; ++i) {
//          vecB.SetElement(i, sin(static_cast<complex<double>>(i)));
//     }
//
//     for (int i = 0; i != ELEMS_B*ELEMS_A; ++i) {
//          matA.SetElement(i, cos(static_cast<complex<double>>(i)));
//     }
//
//     vecA.Dot(matA, vecB, "WithRows");
//
//     const double corr[ELEMS_A] = {
//          -0.013000956337400969716, -413.04095342736712548,
//          -464.55817876109059451, -109.47464548253968530,
//          341.42567875364489603, 493.49596116134191391,
//          213.63792682857131289, -253.20496126031645456,
//          -498.43227128017131844, -307.41079937172321604
//     };
//
//     for(int i = 0; i != ELEMS_A; ++i) {
//          EXPECT_TRUE((corr[i]-std::real(vecA[i])) < pow(10.0, -10.0));
//     }
//}
//
////===========//
//// test # 15 //
////===========//
//
//TEST(VectorTest15, DotComplex)
//{
//     VectorDense<complex<double>> vecA;
//     VectorDense<complex<double>> vecB;
//     MatrixDense<complex<double>> matA;
//
//     EXPECT_TRUE(vecA.DeallocatedQ());
//     EXPECT_TRUE(vecB.DeallocatedQ());
//     EXPECT_TRUE(matA.DeallocatedQ());
//
//     const int ELEMS_A = 10;
//     const int ELEMS_B = 10;
//
//     vecA.Allocate(ELEMS_A);
//     vecB.Allocate(ELEMS_B);
//     matA.Allocate(ELEMS_A, ELEMS_B);
//
//     EXPECT_TRUE(vecA.AllocatedQ());
//     EXPECT_TRUE(vecB.AllocatedQ());
//     EXPECT_TRUE(matA.AllocatedQ());
//
//     for (int i = 0; i != ELEMS_B; ++i) {
//          vecB.SetElement(i, sin(static_cast<complex<double>>(i)));
//     }
//
//     for (int i = 0; i != ELEMS_B*ELEMS_A; ++i) {
//          matA.SetElement(i, cos(static_cast<complex<double>>(i)));
//     }
//
//     // # 1
//
//     vecA.Dot(matA, vecB, "WithColumns");
//
//     const double corr[ELEMS_A] = {
//          -0.3454781443936671, -0.1019678318253387, 0.2352912350744567,
//          0.3562246255479217, 0.1496467381066567, -0.1945156702185772,
//          -0.3598412683998245, -0.1943304639073055, 0.1498468729007396,
//          0.3562556858181048
//     };
//
//     for(int i = 0; i != ELEMS_A; ++i) {
//          EXPECT_TRUE((corr[i]-std::real(vecA[i])) < pow(10.0, -10.0));
//     }
//}
//
////===========//
//// test # 16 //
////===========//
//
//TEST(VectorTest16, DotComplex)
//{
//     MatrixDense<complex<double>> matA;
//     MatrixDense<complex<double>> matB;
//     MatrixDense<complex<double>> matC;
//
//     const pgg::MAI DIM = 100;
//
//     matA.Allocate(DIM);
//     matB.Allocate(DIM);
//     matC.Allocate(DIM);
//
//     // build
//
//     matC = {0.0, 0.0};
//
//     for (pgg::MAI i = 0; i != DIM; ++i) {
//          for (pgg::MAI j = 0; j != DIM; ++j) {
//               complex<double> tmp_cmplxA = { static_cast<double>(i),
//                                              static_cast<double>(j)
//                                            };
//
//               complex<double> tmp_cmplxB = { sin(static_cast<double>(i)),
//                                              cos(static_cast<double>(j))
//                                            };
//
//               matA.SetElement(i, j, tmp_cmplxA);
//               matB.SetElement(i, j, tmp_cmplxB);
//          }
//     }
//
//     // # 1
//
//     matC.Dot(matA, matB);
//
//     const complex<double> corr[DIM] = { complex<double>(-4950.,-54.1556827284055),
//                                         complex<double>(-2674.4964140472916,
//                                                   -54.1556827284055),
//                                         complex<double>(2059.9268409083543,
//                                                   -54.1556827284055),
//                                         complex<double>(4900.4628581722045,
//                                                   -54.1556827284055),
//                                         complex<double>(3235.5359232748788,
//                                                   -54.1556827284055),
//                                         complex<double>(-1404.1278180429697,
//                                                   -54.1556827284055),
//                                         complex<double>(-4752.842918919313,
//                                                   -54.1556827284055),
//                                         complex<double>(-3731.816158999358,
//                                                   -54.1556827284055),
//                                         complex<double>(720.2251673526373,
//                                                   -54.1556827284055),
//                                         complex<double>(4510.094796329151,
//                                                   -54.1556827284055),
//                                         complex<double>(4153.404068928439,
//                                                   -54.1556827284055),
//                                         complex<double>(-21.90720504085138,
//                                                   -54.1556827284055),
//                                         complex<double>(-4177.0770957258355,
//                                                   -54.1556827284055),
//                                         complex<double>(-4491.861568178471,
//                                                   -54.1556827284055),
//                                         complex<double>(-676.8492301287763,
//                                                   -54.1556827284055),
//                                         complex<double>(3760.4551686511654,
//                                                   -54.1556827284055),
//                                         complex<double>(4740.414427600754,
//                                                   -54.1556827284055),
//                                         complex<double>(1362.0585233554048,
//                                                   -54.1556827284055),
//                                         complex<double>(-3268.5677058081965,
//                                                   -54.1556827284055),
//                                         complex<double>(-4894.087860024013,
//                                                   -54.1556827284055),
//                                         complex<double>(-2020.0062059762902,
//                                                   -54.1556827284055),
//                                         complex<double>(2711.2598381101284,
//                                                   -54.1556827284055),
//                                         complex<double>(4949.806090653454,
//                                                   -54.1556827284055),
//                                         complex<double>(2637.523450650318,
//                                                   -54.1556827284055),
//                                         complex<double>(-2099.6860863181355,
//                                                   -54.1556827284055),
//                                         complex<double>(-4906.4539187241935,
//                                                   -54.1556827284055),
//                                         complex<double>(-3202.25064552677,
//                                                   -54.1556827284055),
//                                         complex<double>(1446.087103232489,
//                                                   -54.1556827284055),
//                                         complex<double>(4764.899038252153,
//                                                   -54.1556827284055),
//                                         complex<double>(3702.8847719605515,
//                                                   -54.1556827284055),
//                                         complex<double>(-763.544676943541,
//                                                   -54.1556827284055),
//                                         complex<double>(-4527.97467113243,
//                                                   -54.1556827284055),
//                                         complex<double>(-4129.405634507225,
//                                                   -54.1556827284055),
//                                         complex<double>(65.71989875414442,
//                                                   -54.1556827284055),
//                                         complex<double>(4200.422860183797,
//                                                   -54.1556827284055),
//                                         complex<double>(4473.276415202959,
//                                                   -54.1556827284055),
//                                         complex<double>(633.4202636556531,
//                                                   -54.1556827284055),
//                                         complex<double>(-3788.7995571294496,
//                                                   -54.1556827284055),
//                                         complex<double>(-4727.6145380341095,
//                                                   -54.1556827284055),
//                                         complex<double>(-1319.8825151816895,
//                                                   -54.1556827284055),
//                                         complex<double>(3301.3434051786967,
//                                                   -54.1556827284055),
//                                         complex<double>(4887.329423742941,
//                                                   -54.1556827284055),
//                                         complex<double>(1979.9273091923387,
//                                                   -54.1556827284055),
//                                         complex<double>(-2747.8108425270966,
//                                                   -54.1556827284055),
//                                         complex<double>(-4949.224377806071,
//                                                   -54.1556827284055),
//                                         complex<double>(-2600.34384464776,
//                                                   -54.1556827284055),
//                                         complex<double>(2139.280827179652,
//                                                   -54.1556827284055),
//                                         complex<double>(4912.060572297103,
//                                                   -54.1556827284055),
//                                         complex<double>(3168.7144803725387,
//                                                   -54.1556827284055),
//                                         complex<double>(-1487.9330915310034,
//                                                   -54.1556827284055),
//                                         complex<double>(-4776.581841035962,
//                                                   -54.1556827284055),
//                                         complex<double>(-3673.663274228223,
//                                                   -54.1556827284055),
//                                         complex<double>(806.8043649387419,
//                                                   -54.1556827284055),
//                                         complex<double>(4545.499791749989,
//                                                   -54.1556827284055),
//                                         complex<double>(4105.083672672596,
//                                                   -54.1556827284055),
//                                         complex<double>(-109.52744349668089,
//                                                   -54.1556827284055),
//                                         complex<double>(-4223.439533226792,
//                                                   -54.1556827284055),
//                                         complex<double>(-4454.340793497509,
//                                                   -54.1556827284055),
//                                         complex<double>(-589.9416704716555,
//                                                   -54.1556827284055),
//                                         complex<double>(3816.8471037304334,
//                                                   -54.1556827284055),
//                                         complex<double>(4714.444253055023,
//                                                   -54.1556827284055),
//                                         complex<double>(1277.6030978944239,
//                                                   -54.1556827284055),
//                                         complex<double>(-3333.860453501752,
//                                                   -54.1556827284055),
//                                         complex<double>(-4880.18807883362,
//                                                   -54.1556827284055),
//                                         complex<double>(-1939.6932906262723,
//                                                   -54.1556827284055),
//                                         complex<double>(2784.146563628951,
//                                                   -54.1556827284055),
//                                         complex<double>(4948.254907033432,
//                                                   -54.1556827284055),
//                                         complex<double>(2562.960508958049,
//                                                   -54.1556827284055),
//                                         complex<double>(-2178.707961355402,
//                                                   -54.1556827284055),
//                                         complex<double>(-4917.282379625245,
//                                                   -54.1556827284055),
//                                         complex<double>(-3134.9300552771842,
//                                                   -54.1556827284055),
//                                         complex<double>(1529.6625044220498,
//                                                   -54.1556827284055),
//                                         complex<double>(4787.890411955718,
//                                                   -54.1556827284055),
//                                         complex<double>(3644.1539552252143,
//                                                   -54.1556827284055),
//                                         complex<double>(-850.0008420623489,
//                                                   -54.1556827284055),
//                                         complex<double>(-4562.668785137508,
//                                                   -54.1556827284055),
//                                         complex<double>(-4080.4400889824105,
//                                                   -54.1556827284055),
//                                         complex<double>(153.3264070695216,
//                                                   -54.1556827284055),
//                                         complex<double>(4246.12531156269,
//                                                   -54.1556827284055),
//                                         complex<double>(4435.0561866152675,
//                                                   -54.1556827284055),
//                                         complex<double>(546.4168570032856,
//                                                   -54.1556827284055),
//                                         complex<double>(-3844.5956110070747,
//                                                   -54.1556827284055),
//                                         complex<double>(-4700.9046045185905,
//                                                   -54.1556827284055),
//                                         complex<double>(-1235.2235839680238,
//                                                   -54.1556827284055),
//                                         complex<double>(3366.116303157327,
//                                                   -54.1556827284055),
//                                         complex<double>(4872.664384800508,
//                                                   -54.1556827284055),
//                                         complex<double>(1899.3073025012227,
//                                                   -54.1556827284055),
//                                         complex<double>(-2820.2641546132936,
//                                                   -54.1556827284055),
//                                         complex<double>(-4946.897754290866,
//                                                   -54.1556827284055),
//                                         complex<double>(-2525.3763724612622,
//                                                   -54.1556827284055),
//                                         complex<double>(2217.964399839392,
//                                                   -54.1556827284055),
//                                         complex<double>(4922.118931594598,
//                                                   -54.1556827284055),
//                                         complex<double>(3100.9000171561775,
//                                                   -54.1556827284055),
//                                         complex<double>(-1571.2720725225251,
//                                                   -54.1556827284055),
//                                         complex<double>(-4798.823865016438,
//                                                   -54.1556827284055),
//                                         complex<double>(-3614.359126924357,
//                                                   -54.1556827284055),
//                                         complex<double>(893.1307239908655,
//                                                   -54.1556827284055),
//                                         complex<double>(4579.48030615225,
//                                                   -54.1556827284055),
//                                         complex<double>(4055.476814192723,
//                                                   -54.1556827284055),
//                                         complex<double>(-197.11335794603752,
//                                                   -54.1556827284055)
//                                       };
//
//     for(int i = 0; i != DIM; ++i) {
//          EXPECT_TRUE(std::real(corr[i]-matC(0,i)) < pow(10.0, -10.0));
//     }
//
//     for(int i = 0; i != DIM; ++i) {
//          EXPECT_TRUE(std::imag(corr[i]-matC(0,i)) < pow(10.0, -6.0));
//     }
//}
//
////===========//
//// test # 17 //
////===========//
//
//TEST(VectorTest17, DotComplex)
//{
//     MatrixDense<complex<double>> matA;
//
//     const pgg::MAI DIM = 100;
//
//     matA.Allocate(DIM);
//
//     // build
//
//     for (pgg::MAI i = 0; i != DIM; ++i) {
//          for (pgg::MAI j = 0; j != DIM; ++j) {
//
//               complex<double> tmp_cmplxA = { static_cast<double>(i),
//                                              static_cast<double>(j)
//                                            };
//
//               matA.SetElement(i, j, tmp_cmplxA);
//          }
//     }
//
//     // # 1
//
//     matA.Dot(matA, matA);
//
//     const complex<double> corr[DIM] = { complex<double>(0.,328350.),
//                                         complex<double>(-4950.,328350.),
//                                         complex<double>(-9900.,328350.),
//                                         complex<double>(-14850.,328350.),
//                                         complex<double>(-19800.,328350.),
//                                         complex<double>(-24750.,328350.),
//                                         complex<double>(-29700.,328350.),
//                                         complex<double>(-34650.,328350.),
//                                         complex<double>(-39600.,328350.),
//                                         complex<double>(-44550.,328350.),
//                                         complex<double>(-49500.,328350.),
//                                         complex<double>(-54450.,328350.),
//                                         complex<double>(-59400.,328350.),
//                                         complex<double>(-64350.,328350.),
//                                         complex<double>(-69300.,328350.),
//                                         complex<double>(-74250.,328350.),
//                                         complex<double>(-79200.,328350.),
//                                         complex<double>(-84150.,328350.),
//                                         complex<double>(-89100.,328350.),
//                                         complex<double>(-94050.,328350.),
//                                         complex<double>(-99000.,328350.),
//                                         complex<double>(-103950.,328350.),
//                                         complex<double>(-108900.,328350.),
//                                         complex<double>(-113850.,328350.),
//                                         complex<double>(-118800.,328350.),
//                                         complex<double>(-123750.,328350.),
//                                         complex<double>(-128700.,328350.),
//                                         complex<double>(-133650.,328350.),
//                                         complex<double>(-138600.,328350.),
//                                         complex<double>(-143550.,328350.),
//                                         complex<double>(-148500.,328350.),
//                                         complex<double>(-153450.,328350.),
//                                         complex<double>(-158400.,328350.),
//                                         complex<double>(-163350.,328350.),
//                                         complex<double>(-168300.,328350.),
//                                         complex<double>(-173250.,328350.),
//                                         complex<double>(-178200.,328350.),
//                                         complex<double>(-183150.,328350.),
//                                         complex<double>(-188100.,328350.),
//                                         complex<double>(-193050.,328350.),
//                                         complex<double>(-198000.,328350.),
//                                         complex<double>(-202950.,328350.),
//                                         complex<double>(-207900.,328350.),
//                                         complex<double>(-212850.,328350.),
//                                         complex<double>(-217800.,328350.),
//                                         complex<double>(-222750.,328350.),
//                                         complex<double>(-227700.,328350.),
//                                         complex<double>(-232650.,328350.),
//                                         complex<double>(-237600.,328350.),
//                                         complex<double>(-242550.,328350.),
//                                         complex<double>(-247500.,328350.),
//                                         complex<double>(-252450.,328350.),
//                                         complex<double>(-257400.,328350.),
//                                         complex<double>(-262350.,328350.),
//                                         complex<double>(-267300.,328350.),
//                                         complex<double>(-272250.,328350.),
//                                         complex<double>(-277200.,328350.),
//                                         complex<double>(-282150.,328350.),
//                                         complex<double>(-287100.,328350.),
//                                         complex<double>(-292050.,328350.),
//                                         complex<double>(-297000.,328350.),
//                                         complex<double>(-301950.,328350.),
//                                         complex<double>(-306900.,328350.),
//                                         complex<double>(-311850.,328350.),
//                                         complex<double>(-316800.,328350.),
//                                         complex<double>(-321750.,328350.),
//                                         complex<double>(-326700.,328350.),
//                                         complex<double>(-331650.,328350.),
//                                         complex<double>(-336600.,328350.),
//                                         complex<double>(-341550.,328350.),
//                                         complex<double>(-346500.,328350.),
//                                         complex<double>(-351450.,328350.),
//                                         complex<double>(-356400.,328350.),
//                                         complex<double>(-361350.,328350.),
//                                         complex<double>(-366300.,328350.),
//                                         complex<double>(-371250.,328350.),
//                                         complex<double>(-376200.,328350.),
//                                         complex<double>(-381150.,328350.),
//                                         complex<double>(-386100.,328350.),
//                                         complex<double>(-391050.,328350.),
//                                         complex<double>(-396000.,328350.),
//                                         complex<double>(-400950.,328350.),
//                                         complex<double>(-405900.,328350.),
//                                         complex<double>(-410850.,328350.),
//                                         complex<double>(-415800.,328350.),
//                                         complex<double>(-420750.,328350.),
//                                         complex<double>(-425700.,328350.),
//                                         complex<double>(-430650.,328350.),
//                                         complex<double>(-435600.,328350.),
//                                         complex<double>(-440550.,328350.),
//                                         complex<double>(-445500.,328350.),
//                                         complex<double>(-450450.,328350.),
//                                         complex<double>(-455400.,328350.),
//                                         complex<double>(-460350.,328350.),
//                                         complex<double>(-465300.,328350.),
//                                         complex<double>(-470250.,328350.),
//                                         complex<double>(-475200.,328350.),
//                                         complex<double>(-480150.,328350.),
//                                         complex<double>(-485100.,328350.),
//                                         complex<double>(-490050.,328350.)
//                                       };
//
//     // test
//
//     for(int i = 0; i != DIM; ++i) {
//          EXPECT_TRUE(std::real(corr[i]-matA(0,i)) < pow(10.0, -10.0));
//     }
//
//     for(int i = 0; i != DIM; ++i) {
//          EXPECT_TRUE(std::imag(corr[i]-matA(0,i)) < pow(10.0, -10.0));
//     }
//
//}
//
////===========//
//// test # 18 //
////===========//
//
//TEST(VectorTest18, DotComplex)
//{
//     MatrixDense<complex<double>> matA;
//
//     const pgg::MAI DIM = 100;
//
//     matA.Allocate(DIM);
//
//     // build
//
//     for (pgg::MAI i = 0; i != DIM; ++i) {
//          for (pgg::MAI j = 0; j != DIM; ++j) {
//
//               complex<double> tmp_cmplxA = { static_cast<double>(i),
//                                              static_cast<double>(j)
//                                            };
//
//               matA.SetElement(i, j, tmp_cmplxA);
//          }
//     }
//
//     // # 1
//
//     matA.Dot(matA);
//
//     const complex<double> corr[DIM] = { complex<double>(0.,328350.),
//                                         complex<double>(-4950.,328350.),
//                                         complex<double>(-9900.,328350.),
//                                         complex<double>(-14850.,328350.),
//                                         complex<double>(-19800.,328350.),
//                                         complex<double>(-24750.,328350.),
//                                         complex<double>(-29700.,328350.),
//                                         complex<double>(-34650.,328350.),
//                                         complex<double>(-39600.,328350.),
//                                         complex<double>(-44550.,328350.),
//                                         complex<double>(-49500.,328350.),
//                                         complex<double>(-54450.,328350.),
//                                         complex<double>(-59400.,328350.),
//                                         complex<double>(-64350.,328350.),
//                                         complex<double>(-69300.,328350.),
//                                         complex<double>(-74250.,328350.),
//                                         complex<double>(-79200.,328350.),
//                                         complex<double>(-84150.,328350.),
//                                         complex<double>(-89100.,328350.),
//                                         complex<double>(-94050.,328350.),
//                                         complex<double>(-99000.,328350.),
//                                         complex<double>(-103950.,328350.),
//                                         complex<double>(-108900.,328350.),
//                                         complex<double>(-113850.,328350.),
//                                         complex<double>(-118800.,328350.),
//                                         complex<double>(-123750.,328350.),
//                                         complex<double>(-128700.,328350.),
//                                         complex<double>(-133650.,328350.),
//                                         complex<double>(-138600.,328350.),
//                                         complex<double>(-143550.,328350.),
//                                         complex<double>(-148500.,328350.),
//                                         complex<double>(-153450.,328350.),
//                                         complex<double>(-158400.,328350.),
//                                         complex<double>(-163350.,328350.),
//                                         complex<double>(-168300.,328350.),
//                                         complex<double>(-173250.,328350.),
//                                         complex<double>(-178200.,328350.),
//                                         complex<double>(-183150.,328350.),
//                                         complex<double>(-188100.,328350.),
//                                         complex<double>(-193050.,328350.),
//                                         complex<double>(-198000.,328350.),
//                                         complex<double>(-202950.,328350.),
//                                         complex<double>(-207900.,328350.),
//                                         complex<double>(-212850.,328350.),
//                                         complex<double>(-217800.,328350.),
//                                         complex<double>(-222750.,328350.),
//                                         complex<double>(-227700.,328350.),
//                                         complex<double>(-232650.,328350.),
//                                         complex<double>(-237600.,328350.),
//                                         complex<double>(-242550.,328350.),
//                                         complex<double>(-247500.,328350.),
//                                         complex<double>(-252450.,328350.),
//                                         complex<double>(-257400.,328350.),
//                                         complex<double>(-262350.,328350.),
//                                         complex<double>(-267300.,328350.),
//                                         complex<double>(-272250.,328350.),
//                                         complex<double>(-277200.,328350.),
//                                         complex<double>(-282150.,328350.),
//                                         complex<double>(-287100.,328350.),
//                                         complex<double>(-292050.,328350.),
//                                         complex<double>(-297000.,328350.),
//                                         complex<double>(-301950.,328350.),
//                                         complex<double>(-306900.,328350.),
//                                         complex<double>(-311850.,328350.),
//                                         complex<double>(-316800.,328350.),
//                                         complex<double>(-321750.,328350.),
//                                         complex<double>(-326700.,328350.),
//                                         complex<double>(-331650.,328350.),
//                                         complex<double>(-336600.,328350.),
//                                         complex<double>(-341550.,328350.),
//                                         complex<double>(-346500.,328350.),
//                                         complex<double>(-351450.,328350.),
//                                         complex<double>(-356400.,328350.),
//                                         complex<double>(-361350.,328350.),
//                                         complex<double>(-366300.,328350.),
//                                         complex<double>(-371250.,328350.),
//                                         complex<double>(-376200.,328350.),
//                                         complex<double>(-381150.,328350.),
//                                         complex<double>(-386100.,328350.),
//                                         complex<double>(-391050.,328350.),
//                                         complex<double>(-396000.,328350.),
//                                         complex<double>(-400950.,328350.),
//                                         complex<double>(-405900.,328350.),
//                                         complex<double>(-410850.,328350.),
//                                         complex<double>(-415800.,328350.),
//                                         complex<double>(-420750.,328350.),
//                                         complex<double>(-425700.,328350.),
//                                         complex<double>(-430650.,328350.),
//                                         complex<double>(-435600.,328350.),
//                                         complex<double>(-440550.,328350.),
//                                         complex<double>(-445500.,328350.),
//                                         complex<double>(-450450.,328350.),
//                                         complex<double>(-455400.,328350.),
//                                         complex<double>(-460350.,328350.),
//                                         complex<double>(-465300.,328350.),
//                                         complex<double>(-470250.,328350.),
//                                         complex<double>(-475200.,328350.),
//                                         complex<double>(-480150.,328350.),
//                                         complex<double>(-485100.,328350.),
//                                         complex<double>(-490050.,328350.)
//                                       };
//
//     // test
//
//     for(int i = 0; i != DIM; ++i) {
//          EXPECT_TRUE(std::real(corr[i]-matA(0,i)) < pow(10.0, -10.0));
//     }
//
//     for(int i = 0; i != DIM; ++i) {
//          EXPECT_TRUE(std::imag(corr[i]-matA(0,i)) < pow(10.0, -10.0));
//     }
//}
//
////===========//
//// test # 19 //
////===========//
//
//TEST(VectorTest19, DotComplex)
//{
//     MatrixDense<complex<double>> matA;
//
//     const pgg::MAI DIM = 100;
//
//     matA.Allocate(DIM);
//
//     // build
//
//     for (pgg::MAI i = 0; i != DIM; ++i) {
//          for (pgg::MAI j = 0; j != DIM; ++j) {
//
//               complex<double> tmp_cmplxA = { static_cast<double>(i),
//                                              static_cast<double>(j)
//                                            };
//
//               matA.SetElement(i, j, tmp_cmplxA);
//          }
//     }
//
//     // # 1
//
//     matA.Dot();
//
//     const complex<double> corr[DIM] = { complex<double>(0.,328350.),
//                                         complex<double>(-4950.,328350.),
//                                         complex<double>(-9900.,328350.),
//                                         complex<double>(-14850.,328350.),
//                                         complex<double>(-19800.,328350.),
//                                         complex<double>(-24750.,328350.),
//                                         complex<double>(-29700.,328350.),
//                                         complex<double>(-34650.,328350.),
//                                         complex<double>(-39600.,328350.),
//                                         complex<double>(-44550.,328350.),
//                                         complex<double>(-49500.,328350.),
//                                         complex<double>(-54450.,328350.),
//                                         complex<double>(-59400.,328350.),
//                                         complex<double>(-64350.,328350.),
//                                         complex<double>(-69300.,328350.),
//                                         complex<double>(-74250.,328350.),
//                                         complex<double>(-79200.,328350.),
//                                         complex<double>(-84150.,328350.),
//                                         complex<double>(-89100.,328350.),
//                                         complex<double>(-94050.,328350.),
//                                         complex<double>(-99000.,328350.),
//                                         complex<double>(-103950.,328350.),
//                                         complex<double>(-108900.,328350.),
//                                         complex<double>(-113850.,328350.),
//                                         complex<double>(-118800.,328350.),
//                                         complex<double>(-123750.,328350.),
//                                         complex<double>(-128700.,328350.),
//                                         complex<double>(-133650.,328350.),
//                                         complex<double>(-138600.,328350.),
//                                         complex<double>(-143550.,328350.),
//                                         complex<double>(-148500.,328350.),
//                                         complex<double>(-153450.,328350.),
//                                         complex<double>(-158400.,328350.),
//                                         complex<double>(-163350.,328350.),
//                                         complex<double>(-168300.,328350.),
//                                         complex<double>(-173250.,328350.),
//                                         complex<double>(-178200.,328350.),
//                                         complex<double>(-183150.,328350.),
//                                         complex<double>(-188100.,328350.),
//                                         complex<double>(-193050.,328350.),
//                                         complex<double>(-198000.,328350.),
//                                         complex<double>(-202950.,328350.),
//                                         complex<double>(-207900.,328350.),
//                                         complex<double>(-212850.,328350.),
//                                         complex<double>(-217800.,328350.),
//                                         complex<double>(-222750.,328350.),
//                                         complex<double>(-227700.,328350.),
//                                         complex<double>(-232650.,328350.),
//                                         complex<double>(-237600.,328350.),
//                                         complex<double>(-242550.,328350.),
//                                         complex<double>(-247500.,328350.),
//                                         complex<double>(-252450.,328350.),
//                                         complex<double>(-257400.,328350.),
//                                         complex<double>(-262350.,328350.),
//                                         complex<double>(-267300.,328350.),
//                                         complex<double>(-272250.,328350.),
//                                         complex<double>(-277200.,328350.),
//                                         complex<double>(-282150.,328350.),
//                                         complex<double>(-287100.,328350.),
//                                         complex<double>(-292050.,328350.),
//                                         complex<double>(-297000.,328350.),
//                                         complex<double>(-301950.,328350.),
//                                         complex<double>(-306900.,328350.),
//                                         complex<double>(-311850.,328350.),
//                                         complex<double>(-316800.,328350.),
//                                         complex<double>(-321750.,328350.),
//                                         complex<double>(-326700.,328350.),
//                                         complex<double>(-331650.,328350.),
//                                         complex<double>(-336600.,328350.),
//                                         complex<double>(-341550.,328350.),
//                                         complex<double>(-346500.,328350.),
//                                         complex<double>(-351450.,328350.),
//                                         complex<double>(-356400.,328350.),
//                                         complex<double>(-361350.,328350.),
//                                         complex<double>(-366300.,328350.),
//                                         complex<double>(-371250.,328350.),
//                                         complex<double>(-376200.,328350.),
//                                         complex<double>(-381150.,328350.),
//                                         complex<double>(-386100.,328350.),
//                                         complex<double>(-391050.,328350.),
//                                         complex<double>(-396000.,328350.),
//                                         complex<double>(-400950.,328350.),
//                                         complex<double>(-405900.,328350.),
//                                         complex<double>(-410850.,328350.),
//                                         complex<double>(-415800.,328350.),
//                                         complex<double>(-420750.,328350.),
//                                         complex<double>(-425700.,328350.),
//                                         complex<double>(-430650.,328350.),
//                                         complex<double>(-435600.,328350.),
//                                         complex<double>(-440550.,328350.),
//                                         complex<double>(-445500.,328350.),
//                                         complex<double>(-450450.,328350.),
//                                         complex<double>(-455400.,328350.),
//                                         complex<double>(-460350.,328350.),
//                                         complex<double>(-465300.,328350.),
//                                         complex<double>(-470250.,328350.),
//                                         complex<double>(-475200.,328350.),
//                                         complex<double>(-480150.,328350.),
//                                         complex<double>(-485100.,328350.),
//                                         complex<double>(-490050.,328350.)
//                                       };
//
//     // test
//
//     for(int i = 0; i != DIM; ++i) {
//          EXPECT_TRUE(std::real(corr[i]-matA(0,i)) < pow(10.0, -10.0));
//     }
//
//     for(int i = 0; i != DIM; ++i) {
//          EXPECT_TRUE(std::imag(corr[i]-matA(0,i)) < pow(10.0, -10.0));
//     }
//}
//
////===========//
//// test # 20 //
////===========//
//
//TEST(VectorTest20, DotComplex)
//{
//     MatrixDense<complex<double>> matA;
//     VectorDense<complex<double>> vecA;
//     VectorDense<complex<double>> vecB;
//
//     const pgg::MAI DIM = 100;
//
//     matA.Allocate(DIM);
//     vecA.Allocate(DIM);
//     vecB.Allocate(DIM);
//
//     // build # 1
//
//     for (pgg::MAI i = 0; i != DIM; ++i) {
//          for (pgg::MAI j = 0; j != DIM; ++j) {
//
//               complex<double> tmp_cmplxA = { static_cast<double>(i),
//                                              static_cast<double>(j)
//                                            };
//
//               matA.SetElement(i, j, tmp_cmplxA);
//          }
//     }
//
//     // build # 2
//
//     for (pgg::MAI i = 0; i != DIM; ++i) {
//
//          complex<double> tmp_cmplxA = { sin(static_cast<double>(i)),
//                                         sin(static_cast<double>(i))
//                                       };
//
//          vecA.SetElement(i, tmp_cmplxA);
//     }
//
//
//     // # 1
//
//     vecB.Dot(matA, vecA);
//
//     const complex<double> corr[DIM] = { complex<double>(54.1556827284055,
//                                         -54.1556827284055),
//                                         complex<double>(54.53487735585484,
//                                                   -53.776488100956165),
//                                         complex<double>(54.914071983304176,
//                                                   -53.39729347350683),
//                                         complex<double>(55.29326661075352,
//                                                   -53.018098846057484),
//                                         complex<double>(55.67246123820286,
//                                                   -52.63890421860815),
//                                         complex<double>(56.051655865652194,
//                                                   -52.25970959115881),
//                                         complex<double>(56.43085049310153,
//                                                   -51.88051496370947),
//                                         complex<double>(56.81004512055087,
//                                                   -51.501320336260136),
//                                         complex<double>(57.18923974800021,
//                                                   -51.12212570881079),
//                                         complex<double>(57.56843437544955,
//                                                   -50.742931081361455),
//                                         complex<double>(57.94762900289889,
//                                                   -50.36373645391211),
//                                         complex<double>(58.32682363034824,
//                                                   -49.98454182646277),
//                                         complex<double>(58.70601825779757,
//                                                   -49.60534719901344),
//                                         complex<double>(59.085212885246904,
//                                                   -49.2261525715641),
//                                         complex<double>(59.46440751269624,
//                                                   -48.84695794411476),
//                                         complex<double>(59.843602140145585,
//                                                   -48.46776331666542),
//                                         complex<double>(60.22279676759492,
//                                                   -48.08856868921608),
//                                         complex<double>(60.601991395044266,
//                                                   -47.70937406176674),
//                                         complex<double>(60.9811860224936,
//                                                   -47.3301794343174),
//                                         complex<double>(61.36038064994295,
//                                                   -46.95098480686806),
//                                         complex<double>(61.739575277392284,
//                                                   -46.57179017941872),
//                                         complex<double>(62.11876990484162,
//                                                   -46.19259555196938),
//                                         complex<double>(62.49796453229098,
//                                                   -45.813400924520025),
//                                         complex<double>(62.87715915974027,
//                                                   -45.43420629707073),
//                                         complex<double>(63.256353787189624,
//                                                   -45.05501166962138),
//                                         complex<double>(63.63554841463895,
//                                                   -44.675817042172056),
//                                         complex<double>(64.01474304208831,
//                                                   -44.29662241472269),
//                                         complex<double>(64.39393766953766,
//                                                   -43.91742778727334),
//                                         complex<double>(64.77313229698697,
//                                                   -43.538233159824024),
//                                         complex<double>(65.15232692443632,
//                                                   -43.15903853237469),
//                                         complex<double>(65.53152155188567,
//                                                   -42.77984390492533),
//                                         complex<double>(65.91071617933504,
//                                                   -42.400649277475964),
//                                         complex<double>(66.28991080678433,
//                                                   -42.02145465002667),
//                                         complex<double>(66.66910543423373,
//                                                   -41.64226002257727),
//                                         complex<double>(67.04830006168302,
//                                                   -41.263065395127974),
//                                         complex<double>(67.42749468913239,
//                                                   -40.883870767678616),
//                                         complex<double>(67.8066893165817,
//                                                   -40.50467614022931),
//                                         complex<double>(68.18588394403102,
//                                                   -40.12548151277999),
//                                         complex<double>(68.5650785714804,
//                                                   -39.74628688533061),
//                                         complex<double>(68.94427319892975,
//                                                   -39.36709225788126),
//                                         complex<double>(69.32346782637907,
//                                                   -38.98789763043194),
//                                         complex<double>(69.70266245382842,
//                                                   -38.60870300298258),
//                                         complex<double>(70.08185708127775,
//                                                   -38.229508375533264),
//                                         complex<double>(70.46105170872706,
//                                                   -37.85031374808395),
//                                         complex<double>(70.84024633617645,
//                                                   -37.471119120634555),
//                                         complex<double>(71.2194409636257,
//                                                   -37.0919244931853),
//                                         complex<double>(71.59863559107505,
//                                                   -36.71272986573595),
//                                         complex<double>(71.97783021852436,
//                                                   -36.33353523828664),
//                                         complex<double>(72.35702484597375,
//                                                   -35.95434061083725),
//                                         complex<double>(72.73621947342312,
//                                                   -35.575145983387884),
//                                         complex<double>(73.1154141008724,
//                                                   -35.195951355938604),
//                                         complex<double>(73.49460872832182,
//                                                   -34.816756728489175),
//                                         complex<double>(73.87380335577112,
//                                                   -34.43756210103988),
//                                         complex<double>(74.25299798322052,
//                                                   -34.058367473590486),
//                                         complex<double>(74.63219261066982,
//                                                   -33.67917284614118),
//                                         complex<double>(75.01138723811911,
//                                                   -33.2999782186919),
//                                         complex<double>(75.39058186556846,
//                                                   -32.92078359124255),
//                                         complex<double>(75.76977649301784,
//                                                   -32.54158896379315),
//                                         complex<double>(76.14897112046714,
//                                                   -32.16239433634387),
//                                         complex<double>(76.52816574791643,
//                                                   -31.783199708894564),
//                                         complex<double>(76.90736037536584,
//                                                   -31.404005081445163),
//                                         complex<double>(77.28655500281518,
//                                                   -31.024810453995826),
//                                         complex<double>(77.66574963026457,
//                                                   -30.645615826546432),
//                                         complex<double>(78.04494425771391,
//                                                   -30.266421199097095),
//                                         complex<double>(78.42413888516317,
//                                                   -29.88722657164783),
//                                         complex<double>(78.80333351261245,
//                                                   -29.508031944198557),
//                                         complex<double>(79.18252814006198,
//                                                   -29.128837316749035),
//                                         complex<double>(79.56172276751116,
//                                                   -28.74964268929984),
//                                         complex<double>(79.94091739496056,
//                                                   -28.370448061850446),
//                                         complex<double>(80.32011202240989,
//                                                   -27.991253434401123),
//                                         complex<double>(80.69930664985927,
//                                                   -27.61205880695173),
//                                         complex<double>(81.0785012773085,
//                                                   -27.232864179502506),
//                                         complex<double>(81.45769590475788,
//                                                   -26.853669552053113),
//                                         complex<double>(81.83689053220718,
//                                                   -26.47447492460382),
//                                         complex<double>(82.21608515965653,
//                                                   -26.09528029715448),
//                                         complex<double>(82.59527978710597,
//                                                   -25.71608566970503),
//                                         complex<double>(82.97447441455529,
//                                                   -25.336891042255722),
//                                         complex<double>(83.35366904200458,
//                                                   -24.957696414806414),
//                                         complex<double>(83.73286366945399,
//                                                   -24.57850178735702),
//                                         complex<double>(84.11205829690326,
//                                                   -24.19930715990774),
//                                         complex<double>(84.49125292435264,
//                                                   -23.820112532458374),
//                                         complex<double>(84.87044755180204,
//                                                   -23.440917905008952),
//                                         complex<double>(85.24964217925134,
//                                                   -23.061723277559658),
//                                         complex<double>(85.62883680670063,
//                                                   -22.682528650110363),
//                                         complex<double>(86.00803143414998,
//                                                   -22.303334022661026),
//                                         complex<double>(86.38722606159925,
//                                                   -21.92413939521176),
//                                         complex<double>(86.7664206890486,
//                                                   -21.544944767762395),
//                                         complex<double>(87.14561531649795,
//                                                   -21.165750140313058),
//                                         complex<double>(87.52480994394739,
//                                                   -20.786555512863607),
//                                         complex<double>(87.90400457139668,
//                                                   -20.407360885414327),
//                                         complex<double>(88.28319919884589,
//                                                   -20.028166257965104),
//                                         complex<double>(88.66239382629533,
//                                                   -19.648971630515682),
//                                         complex<double>(89.0415884537446,
//                                                   -19.2697770030664),
//                                         complex<double>(89.42078308119403,
//                                                   -18.89058237561698),
//                                         complex<double>(89.79997770864321,
//                                                   -18.511387748167785),
//                                         complex<double>(90.17917233609279,
//                                                   -18.13219312071822),
//                                         complex<double>(90.558366963542,
//                                                   -17.752998493268997),
//                                         complex<double>(90.93756159099135,
//                                                   -17.37380386581966),
//                                         complex<double>(91.31675621844073,
//                                                   -16.994609238370266),
//                                         complex<double>(91.69595084589,
//                                                   -16.615414610921015)
//                                       };
//
//     // test
//
//     for(int i = 0; i != DIM; ++i) {
//          EXPECT_TRUE(std::real(corr[i]-vecB(i)) < pow(10.0, -10.0));
//     }
//
//     for(int i = 0; i != DIM; ++i) {
//          EXPECT_TRUE(std::imag(corr[i]-vecB(i)) < pow(10.0, -10.0));
//     }
//}
//
////===========//
//// test # 21 //
////===========//
//
//TEST(VectorTest21, DotComplex)
//{
//     VectorDense<complex<double>> vecA;
//     VectorDense<complex<double>> vecB;
//
//     const pgg::MAI DIM = 100;
//
//     vecA.Allocate(DIM);
//     vecB.Allocate(DIM);
//
//     // build # 2
//
//     for (pgg::MAI i = 0; i != DIM; ++i) {
//
//          complex<double> tmp_cmplxA = { cos(static_cast<double>(i)),
//                                         sin(static_cast<double>(i))
//                                       };
//
//          complex<double> tmp_cmplxB = { cos(static_cast<double>(i)),
//                                         cos(static_cast<double>(i))
//                                       };
//
//          vecA.SetElement(i, tmp_cmplxA);
//          vecB.SetElement(i, tmp_cmplxB);
//     }
//
//
//     // # 1
//
//     const complex<double> res = vecB.Dot(vecA);
//     const complex<double> cor = complex<double>(49.687376068621084, 50.28866122084714);
//
//     // test
//
//     for(int i = 0; i != DIM; ++i) {
//          EXPECT_TRUE(std::real(res-cor) < pow(10.0, -10.0));
//     }
//
//     for(int i = 0; i != DIM; ++i) {
//          EXPECT_TRUE(std::imag(res-cor) < pow(10.0, -10.0));
//     }
//}
//
//// END
