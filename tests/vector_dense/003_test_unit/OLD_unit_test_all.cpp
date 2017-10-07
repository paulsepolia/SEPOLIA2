//=============//
// test driver //
//=============//

// sepolia

#include "../../../head/sepolia.hpp"

using pgg::sep::MatrixDense;
using pgg::sep::VectorDense;
using pgg::functions::Sin;
using pgg::functions::Cos;
using pgg::functions::ArcCos;
using pgg::functions::ArcSin;

// C++

#include <complex>
#include <cmath>

using std::complex;
using std::sin;
using std::cos;
using std::abs;

// Google Test

#include "gtest/gtest.h"

//==========//
// test # 1 //
//==========//

TEST(VectorTest1, Memory) {
    // This test is named "Memory",
    // and belongs to the "VectorTest1"

    VectorDense<double> vecA;

    // test
    // AllocatedQ()
    // DeallocatedQ()

    EXPECT_EQ(vecA.AllocatedQ(), false);
    EXPECT_EQ(vecA.DeallocatedQ(), true);
    EXPECT_EQ(vecA.DeallocatedQ(), !vecA.AllocatedQ());

    // test
    // AllocatedQ()
    // DeallocatedQ()

    vecA.Allocate(10);

    EXPECT_EQ(vecA.AllocatedQ(), true);
    EXPECT_EQ(vecA.DeallocatedQ(), false);
    EXPECT_EQ(vecA.DeallocatedQ(), !vecA.AllocatedQ());

    // test
    // AllocatedQ()
    // DeallocatedQ()

    vecA.Deallocate();

    EXPECT_EQ(vecA.AllocatedQ(), false);
    EXPECT_EQ(vecA.DeallocatedQ(), true);
    EXPECT_EQ(vecA.DeallocatedQ(), !vecA.AllocatedQ());

    // end test
}

//==========//
// test # 2 //
//==========//

TEST(VectorTest2, Memory) {
    // This test is named "Memory",
    // and belongs to the "VectorTest2"

    VectorDense<double> vecA;

    vecA.Allocate(10);

    VectorDense<double> vecB(vecA);

    // test
    // AllocatedQ()
    // DeallocatedQ()

    EXPECT_EQ(vecB.AllocatedQ(), true);
    EXPECT_EQ(vecB.DeallocatedQ(), false);
    EXPECT_EQ(vecB.DeallocatedQ(), !vecB.AllocatedQ());

    // test
    // AllocatedQ()
    // DeallocatedQ()

    vecB.Deallocate();
    vecB.Allocate(10);

    EXPECT_EQ(vecB.AllocatedQ(), true);
    EXPECT_EQ(vecB.DeallocatedQ(), false);
    EXPECT_EQ(vecB.DeallocatedQ(), !vecB.AllocatedQ());

    // test
    // AllocatedQ()
    // DeallocatedQ()

    vecB.Deallocate();

    EXPECT_EQ(vecB.AllocatedQ(), false);
    EXPECT_EQ(vecB.DeallocatedQ(), true);
    EXPECT_EQ(vecB.DeallocatedQ(), !vecB.AllocatedQ());

    // test
    // AllocatedQ()
    // DeallocatedQ()

    vecB.Allocate(10);
    vecB.Allocate(11);
    vecB.Allocate(12);

    EXPECT_EQ(vecB.AllocatedQ(), true);
    EXPECT_EQ(vecB.DeallocatedQ(), false);
    EXPECT_EQ(vecB.DeallocatedQ(), !vecB.AllocatedQ());

    // test
    // AllocatedQ()
    // DeallocatedQ()

    vecB.Deallocate();
    vecB.Deallocate();
    vecB.Deallocate();

    EXPECT_EQ(vecB.AllocatedQ(), false);
    EXPECT_EQ(vecB.DeallocatedQ(), true);
    EXPECT_EQ(vecB.DeallocatedQ(), !vecB.AllocatedQ());

    // end test
}

//==========//
// test # 3 //
//==========//

TEST(VectorTest3, Memory) {
    // This test is named "Memory",
    // and belongs to the "VectorTest3"

    VectorDense<double> vecA;

    vecA.Allocate(100);

    VectorDense<double> vecB(vecA);

    // test
    // AllocatedQ()
    // DeallocatedQ()

    EXPECT_TRUE(vecB.AllocatedQ());
    EXPECT_FALSE(vecB.DeallocatedQ());

    // test
    // AllocatedQ()
    // DeallocatedQ()

    vecB.Deallocate();

    EXPECT_FALSE(vecB.AllocatedQ());
    EXPECT_TRUE(vecB.DeallocatedQ());

    // test
    // AllocatedQ()
    // DeallocatedQ()

    vecB.Allocate(1);
    vecB.Allocate(1);
    vecB.Allocate(200);

    EXPECT_TRUE(vecB.AllocatedQ());
    EXPECT_FALSE(vecB.DeallocatedQ());

    // end test
}

//==========//
// test # 4 //
//==========//

TEST(VectorTest4, Memory) {
    // This test is named "Memory",
    // and belongs to the "VectorTest4"

    VectorDense<double> vecA;
    VectorDense<double> vecB;

    // local scope

    {
        VectorDense<double> vecA;

        vecA.Allocate(100);
        vecB.Allocate(8);

        // test
        // AllocatedQ()
        // DeallocatedQ()

        EXPECT_TRUE(vecA.AllocatedQ());
        EXPECT_FALSE(vecA.DeallocatedQ());

        EXPECT_TRUE(vecB.AllocatedQ());
        EXPECT_FALSE(vecB.DeallocatedQ());
    }

    // test
    // AllocatedQ()
    // DeallocatedQ()

    EXPECT_FALSE(vecA.AllocatedQ());
    EXPECT_TRUE(vecA.DeallocatedQ());

    EXPECT_TRUE(vecB.AllocatedQ());
    EXPECT_FALSE(vecB.DeallocatedQ());

    vecB.Deallocate();

    EXPECT_FALSE(vecB.AllocatedQ());
    EXPECT_TRUE(vecB.DeallocatedQ());

    // end test
}

//==========//
// test # 5 //
//==========//

TEST(VectorTest5, Get) {
    // This test is named "Get",
    // and belongs to the "VectorTest1"

    VectorDense<double> vecA;

    // test
    // AllocatedQ()
    // DeallocatedQ()

    EXPECT_EQ(vecA.AllocatedQ(), false);
    EXPECT_EQ(vecA.DeallocatedQ(), true);

    // test
    // AllocatedQ()
    // DeallocatedQ()

    const int NUM_ELEMS = 1000;

    vecA.Allocate(NUM_ELEMS);

    EXPECT_EQ(vecA.AllocatedQ(), true);
    EXPECT_EQ(vecA.DeallocatedQ(), false);

    // test
    // = operator
    // (i,j) operator

    const double ELEM_A = 12.34567;

    vecA = ELEM_A;

    EXPECT_EQ(vecA, ELEM_A);
    EXPECT_EQ(vecA(0), ELEM_A);

    for (int i = 0; i != NUM_ELEMS; ++i) {
        EXPECT_EQ(vecA(i), ELEM_A);
    }

    // test
    // Set
    // GetElement(i)

    const double ELEM_B = 11.2233445566;

    vecA.Set(ELEM_B);

    EXPECT_EQ(vecA, ELEM_B);
    EXPECT_EQ(vecA.GetElement(0), ELEM_B);

    for (int i = 0; i != NUM_ELEMS; ++i) {
        EXPECT_EQ(vecA.GetElement(i), ELEM_B);
    }

    // test
    // GetNumberOfElements()

    EXPECT_EQ(vecA.GetNumberOfElements(), NUM_ELEMS);

    // test
    // GetColumn

    MatrixDense<double> matA;

    EXPECT_FALSE(matA.AllocatedQ());
    EXPECT_TRUE(matA.DeallocatedQ());

    matA.Allocate(NUM_ELEMS);

    EXPECT_TRUE(matA.AllocatedQ());
    EXPECT_FALSE(matA.DeallocatedQ());

    const double ELEM_C = 4.12345;

    matA = ELEM_C;

    vecA.GetColumn(matA, 10);

    EXPECT_EQ(vecA, ELEM_C);

    // test
    // GetRow

    vecA.Deallocate();
    matA.Deallocate();

    EXPECT_FALSE(vecA.AllocatedQ());
    EXPECT_TRUE(vecA.DeallocatedQ());

    EXPECT_FALSE(matA.AllocatedQ());
    EXPECT_TRUE(matA.DeallocatedQ());

    vecA.Allocate(NUM_ELEMS);
    matA.Allocate(NUM_ELEMS);

    const double ELEM_D = 234.123;

    matA = ELEM_D;

    EXPECT_TRUE(vecA.AllocatedQ());
    EXPECT_FALSE(vecA.DeallocatedQ());

    EXPECT_TRUE(matA.AllocatedQ());
    EXPECT_FALSE(matA.DeallocatedQ());

    vecA.GetRow(matA, 3);

    EXPECT_EQ(vecA, ELEM_D);

    for (int i = 0; i != NUM_ELEMS; ++i) {
        EXPECT_EQ(vecA.GetElement(i), ELEM_D);
    }

    // end test
}

//==========//
// test # 6 //
//==========//

TEST(VectorTest6, Get) {
    // This test is named "Get",
    // and belongs to the "VectorTest1"

    VectorDense<double> vecA;

    // test
    // AllocatedQ()
    // DeallocatedQ()

    EXPECT_EQ(vecA.AllocatedQ(), false);
    EXPECT_EQ(vecA.DeallocatedQ(), true);

    // test
    // AllocatedQ()
    // DeallocatedQ()

    const int NUM_ELEMS = 1000;

    vecA.Allocate(NUM_ELEMS);

    EXPECT_EQ(vecA.AllocatedQ(), true);
    EXPECT_EQ(vecA.DeallocatedQ(), false);

    // test
    // Set
    // (i) operator

    const double ELEM_A = 12.34567;

    vecA.Set(ELEM_A);

    EXPECT_EQ(vecA, ELEM_A);
    EXPECT_EQ(vecA(0), ELEM_A);

    for (int i = 0; i != NUM_ELEMS; ++i) {
        EXPECT_EQ(vecA(i), ELEM_A);
    }

    // test
    // SetElement
    // GetElement

    const double ELEM_B = 11.2233445566;

    for (int i = 0; i != NUM_ELEMS; ++i) {
        vecA.SetElement(i, ELEM_B);
    }

    for (int i = 0; i != NUM_ELEMS; ++i) {
        EXPECT_EQ(vecA.GetElement(i), ELEM_B);
    }

    // test
    // SetElement
    // GetElement

    for (int i = 0; i != NUM_ELEMS; ++i) {
        vecA.SetElement(i, cos(i));
    }

    const double THRES_A = pow(10.0, -10.0);

    for (int i = 0; i != NUM_ELEMS; ++i) {
        EXPECT_TRUE((vecA.GetElement(i) - cos(i)) < THRES_A);
    }

    const double THRES_B = pow(10.0, -15.0);

    for (int i = 0; i != NUM_ELEMS; ++i) {
        EXPECT_TRUE((vecA.GetElement(i) - cos(i)) < THRES_B);
    }

    // test
    // SetElement
    // GetElement

    VectorDense<long double> vecB;

    vecB.Allocate(NUM_ELEMS);

    for (int i = 0; i != NUM_ELEMS; ++i) {
        vecB.SetElement(i, Cos(static_cast<long double>(i)));
    }

    for (int i = 0; i != NUM_ELEMS; ++i) {
        EXPECT_TRUE((vecB.GetElement(i) -
                     Cos(static_cast<long double>(i))) < THRES_A);
    }

    const double THRES_C = pow(10.0, -16.0);

    for (int i = 0; i != NUM_ELEMS; ++i) {
        EXPECT_TRUE((vecB.GetElement(i) -
                     Cos(static_cast<long double>(i))) < THRES_C);
    }

    const double THRES_D = pow(10.0, -20.0);

    for (int i = 0; i != NUM_ELEMS; ++i) {
        EXPECT_TRUE((vecB.GetElement(i) -
                     Cos(static_cast<long double>(i))) < THRES_D);
    }

    // end test
}

//==========//
// test # 7 //
//==========//

TEST(VectorTest7, Get) {
    // This test is named "Get",
    // and belongs to the "VectorTest1"

    VectorDense<long double> vecA;

    // test
    // AllocatedQ()
    // DeallocatedQ()

    EXPECT_EQ(vecA.AllocatedQ(), false);
    EXPECT_EQ(vecA.DeallocatedQ(), true);

    // test
    // AllocatedQ()
    // DeallocatedQ()

    const int NUM_ELEMS = 1000;

    vecA.Allocate(NUM_ELEMS);

    EXPECT_EQ(vecA.AllocatedQ(), true);
    EXPECT_EQ(vecA.DeallocatedQ(), false);

    // test
    // Set
    // (i) operator

    const long double ELEM_A = 12.34567L;

    vecA.Set(Cos(ELEM_A));

    EXPECT_EQ(vecA, Cos(ELEM_A));
    EXPECT_EQ(vecA(0), Cos(ELEM_A));

    for (int i = 0; i != NUM_ELEMS; ++i) {
        EXPECT_EQ(vecA(i), Cos(ELEM_A));
    }

    // test
    // SetElement
    // GetElement

    const long double ELEM_B = Sin(11.2233445566L);

    for (int i = 0; i != NUM_ELEMS; ++i) {
        vecA.SetElement(i, Sin(ELEM_B));
    }

    for (int i = 0; i != NUM_ELEMS; ++i) {
        EXPECT_EQ(vecA.GetElement(i), Sin(ELEM_B));
    }

    // test
    // SetElement
    // GetElement

    for (int i = 0; i != NUM_ELEMS; ++i) {
        vecA.SetElement(i, Sin(static_cast<long double>(i)));
    }

    const double THRES_A = pow(10.0, -10.0);

    for (int i = 0; i != NUM_ELEMS; ++i) {
        EXPECT_TRUE((vecA.GetElement(i) - sin(i)) < THRES_A);
    }

    const double THRES_B = pow(10.0, -14.0);

    for (int i = 0; i != NUM_ELEMS; ++i) {
        EXPECT_TRUE((vecA.GetElement(i) - sin(i)) < THRES_B);
    }

    const double THRES_C = pow(10.0, -16.0);

    for (int i = 0; i != NUM_ELEMS; ++i) {
        EXPECT_TRUE((vecA.GetElement(i) -
                     Sin(static_cast<long double>(i))) < THRES_C);
    }

    const double THRES_D = pow(10.0, -20.0);

    for (int i = 0; i != NUM_ELEMS; ++i) {
        EXPECT_TRUE((vecA.GetElement(i) -
                     Sin(static_cast<long double>(i))) < THRES_D);
    }

    const double THRES_E = pow(10.0, -14.0);

    for (int i = 0; i != NUM_ELEMS; ++i) {
        EXPECT_TRUE((vecA.GetElement(i) -
                     sin(static_cast<long double>(i))) < THRES_E);
    }

    // end test
}

//==========//
// test # 8 //
//==========//

TEST(VectorTest8, Get) {
    VectorDense<double> vecA;

    const int ELEMS = 1000;

    vecA.Allocate(ELEMS);

    const double ELEM_A = 12.34;

    vecA = Sin(ELEM_A);

    EXPECT_TRUE(vecA.Equal(Sin(ELEM_A)));

    EXPECT_TRUE(vecA.Equal(sin(ELEM_A)));

    EXPECT_TRUE(vecA == sin(ELEM_A));

    vecA.Map(Cos < double > );

    EXPECT_TRUE(vecA == cos(sin(ELEM_A)));

    vecA.Map(Sin < double > );

    EXPECT_TRUE(vecA == sin(cos(sin(ELEM_A))));
}

//==========//
// test # 9 //
//==========//

TEST(VectorTest9, GetSet) {
    VectorDense<double> vecA;
    VectorDense<double> vecB;

    const int ELEMS = 1000;

    vecA.Allocate(ELEMS);
    vecB.Allocate(ELEMS);

    const double ELEM_A = 12.34;

    // # 1

    vecA = Sin(ELEM_A);
    vecB = vecA;

    EXPECT_TRUE(vecA == vecB);

    // # 2

    vecA.Map(sin);
    vecB.Map(Sin < double > );

    EXPECT_TRUE(vecA == vecB);

    // # 3

    vecA.Map(asin);
    vecB.Map(ArcSin < double > );

    EXPECT_TRUE(vecA == vecB);

    // # 4

    const int NEST_NUM = 50;

    vecA.Nest(asin, NEST_NUM);
    vecB.Nest(ArcSin < double > , NEST_NUM);

    EXPECT_TRUE(vecA == vecB);

    // # 5

    const int NEST_NUM_B = 200;

    vecA.Nest(sin, NEST_NUM_B);
    vecB.Nest(Sin < double > , NEST_NUM_B);

    EXPECT_TRUE(vecA == vecB);

    // # 6

    const int NEST_NUM_C = 1;

    vecA.Nest(acos, NEST_NUM_C);
    vecB.Nest(ArcCos < double > , NEST_NUM_C);

    EXPECT_TRUE(vecA == vecB);

    // # 7

    const int NEST_NUM_D = 1;

    vecA.Nest(cos, NEST_NUM_D);
    vecB.Nest(Cos < double > , NEST_NUM_D);

    EXPECT_TRUE(vecA == vecB);

    // # 8

    const int NEST_NUM_E = 500;

    vecA.Nest(cos, NEST_NUM_E);
    vecB.Nest(Cos < double > , NEST_NUM_E);
    const double THRES_E = pow(10.0, -15.0);

    for (int i = 0; i != ELEMS; ++i) {
        EXPECT_TRUE((vecA(i) - vecB(i)) < THRES_E);
    }

}

//===========//
// test # 10 //
//===========//

TEST(VectorTest10, Divide) {
    // This test is named "Divide",
    // and belongs to the "VectorTest1"

    VectorDense<double> vecA;
    const int ELEMS = 1000;

    vecA.Allocate(ELEMS);

    // # 1

    const double ELEM_A = 10.0;

    vecA = ELEM_A;

    EXPECT_EQ(vecA, ELEM_A);

    // # 2

    const double ELEM_B = 11.0;

    vecA.Divide(ELEM_B);

    EXPECT_EQ(vecA, ELEM_A / ELEM_B);

    // # 3

    VectorDense<double> vecB;

    vecB.Allocate(ELEMS);

    vecB = vecA;

    EXPECT_EQ(vecA, vecB);

    // # 4

    vecA.Divide(vecB);

    EXPECT_EQ(vecA, 1.0);

    // # 5

    vecB.Divide(vecB);

    EXPECT_EQ(vecB, 1.0);

    // # 6

    const double ELEM_C = 0.123456;
    const double ELEM_D = 1.234567;

    vecA = ELEM_C;
    vecB = ELEM_D;

    EXPECT_EQ(vecA / vecB, ELEM_C / ELEM_D);

    // # 7

    EXPECT_EQ(vecA / vecB + vecB / vecA, ELEM_C / ELEM_D + ELEM_D / ELEM_C);

    // # 8

    vecA = Sin(ELEM_C);
    vecB = Cos(ELEM_D);

    vecA.Divide(vecA, vecB);

    EXPECT_EQ(vecA, sin(ELEM_C) / cos(ELEM_D));

    // # 9

    for (int i = 0; i != ELEMS; ++i) {
        vecA.SetElement(i, Cos(static_cast<double>(i)));
        vecB.SetElement(i, Sin(static_cast<double>(i)) + 0.1);
    }

    vecA = vecA / vecB;

    const double THRES_A = pow(10.0, -11.0);

    for (int i = 0; i != ELEMS; ++i) {
        EXPECT_TRUE((vecA(i) - Cos(static_cast<double>(i)) /
                               (Sin(static_cast<double>(i)) + 0.1)) <
                    THRES_A);
    }

    // # 10

    const double TINY_A = pow(10.0, -10.0);

    for (int i = 0; i != ELEMS; ++i) {
        vecA.SetElement(i, Cos(static_cast<double>(i)));
        vecB.SetElement(i, Sin(static_cast<double>(i)) + TINY_A);
    }

    vecA = vecA / vecB;

    const double THRES_B = pow(10.0, -10.0);

    for (int i = 0; i != ELEMS; ++i) {
        EXPECT_TRUE((vecA(i) - Cos(static_cast<double>(i)) /
                               (Sin(static_cast<double>(i)) + TINY_A)) <
                    THRES_B);
    }
}

//===========//
// test # 11 //
//===========//

TEST(VectorTest11, Plus) {
    // This test is named "Plus",
    // and belongs to the "VectorTest2"

    VectorDense<double> vecA;
    const int ELEMS = 1000;

    vecA.Allocate(ELEMS);

    // # 1

    const double ELEM_A = 10.0;

    vecA = ELEM_A;

    EXPECT_EQ(vecA, ELEM_A);

    // # 2

    const double ELEM_B = 11.0;

    vecA.Plus(ELEM_B);

    EXPECT_EQ(vecA, ELEM_A + ELEM_B);

    // # 3

    VectorDense<double> vecB;

    vecB.Allocate(ELEMS);

    vecB = vecA;

    EXPECT_EQ(vecA, vecB);

    // # 4

    vecA.Plus(vecB);

    EXPECT_EQ(vecA, 2 * (ELEM_A + ELEM_B));

    // # 5

    vecB.Plus(vecB);

    EXPECT_EQ(vecB, vecA);

    // # 6

    const double ELEM_C = 0.123456;
    const double ELEM_D = 1.234567;

    vecA = ELEM_C;
    vecB = ELEM_D;

    EXPECT_EQ(vecA + vecB, ELEM_C + ELEM_D);

    // # 7

    EXPECT_EQ(vecA + vecB + vecB + vecA, ELEM_C + ELEM_D + ELEM_D + ELEM_C);

    // # 8

    vecA = Sin(ELEM_C);
    vecB = Cos(ELEM_D);

    vecA.Plus(vecA, vecB);

    EXPECT_EQ(vecA, sin(ELEM_C) + cos(ELEM_D));

    // # 9

    for (int i = 0; i != ELEMS; ++i) {
        vecA.SetElement(i, Cos(static_cast<double>(i)));
        vecB.SetElement(i, Sin(static_cast<double>(i)));
    }

    vecA = vecA + vecB;

    const double THRES_A = pow(10.0, -11.0);

    for (int i = 0; i != ELEMS; ++i) {
        EXPECT_TRUE(vecA(i) - (Cos(static_cast<double>(i)) +
                               Sin(static_cast<double>(i))) <
                    THRES_A);
    }

    // # 10

    vecA = 20.1234;
    vecB = 12.3456;
    VectorDense<double> vecC;
    vecC.Allocate(ELEMS);

    vecC.Plus(vecA, vecB);

    for (int i = 0; i != ELEMS; ++i) {
        EXPECT_EQ(vecC(i), vecA(i) + vecB(i));
    }

    EXPECT_EQ(vecC, vecA + vecB);

}

//===========//
// test # 12 //
//===========//

TEST(VectorTest12, Subtract) {
    // This test is named "Subtract",
    // and belongs to the "VectorTest3"

    VectorDense<double> vecA;
    const int ELEMS = 1000;

    vecA.Allocate(ELEMS);

    // # 1

    const double ELEM_A = 10.0;

    vecA = ELEM_A;

    EXPECT_EQ(vecA, ELEM_A);

    // # 2

    const double ELEM_B = 11.0;

    vecA.Subtract(ELEM_B);

    EXPECT_EQ(vecA, ELEM_A - ELEM_B);

    // # 3

    VectorDense<double> vecB;

    vecB.Allocate(ELEMS);

    vecB = vecA;

    EXPECT_EQ(vecA, vecB);

    // # 4

    vecA = ELEM_A;
    vecB = ELEM_B;

    vecA.Subtract(vecB);

    EXPECT_EQ(vecA, ELEM_A - ELEM_B);

    // # 5

    vecB.Subtract(vecB);

    EXPECT_EQ(vecB, 0.0);

    // # 6

    const double ELEM_C = 0.123456;
    const double ELEM_D = 1.234567;

    vecA = ELEM_C;
    vecB = ELEM_D;

    EXPECT_EQ(vecA - vecB, ELEM_C - ELEM_D);

    // # 7

    EXPECT_EQ(vecA - vecB + vecB - vecA, ELEM_C - ELEM_D + ELEM_D - ELEM_C);

    // # 8

    vecA = Sin(ELEM_C);
    vecB = Cos(ELEM_D);

    vecA.Subtract(vecA, vecB);

    EXPECT_EQ(vecA, sin(ELEM_C) - cos(ELEM_D));

    // # 9

    for (int i = 0; i != ELEMS; ++i) {
        vecA.SetElement(i, Cos(static_cast<double>(i)));
        vecB.SetElement(i, Sin(static_cast<double>(i)));
    }

    vecA = vecA - vecB;

    const double THRES_A = pow(10.0, -11.0);

    for (int i = 0; i != ELEMS; ++i) {
        EXPECT_TRUE(vecA(i) - (Cos(static_cast<double>(i)) -
                               Sin(static_cast<double>(i))) <
                    THRES_A);
    }

    // # 10

    vecA = 20.1234;
    vecB = 12.3456;
    VectorDense<double> vecC;
    vecC.Allocate(ELEMS);

    vecC.Subtract(vecA, vecB);

    for (int i = 0; i != ELEMS; ++i) {
        EXPECT_EQ(vecC(i), vecA(i) - vecB(i));
    }

    EXPECT_EQ(vecC, vecA - vecB);

}

//===========//
// test # 13 //
//===========//

TEST(VectorTest13, Times) {
    // This test is named "Times",
    // and belongs to the "VectorTest4"

    VectorDense<double> vecA;
    const int ELEMS = 1000;

    vecA.Allocate(ELEMS);

    // # 1

    const double ELEM_A = 10.0;

    vecA = ELEM_A;

    EXPECT_EQ(vecA, ELEM_A);

    // # 2

    const double ELEM_B = 11.0;

    vecA.Times(ELEM_B);

    EXPECT_EQ(vecA, ELEM_A * ELEM_B);

    // # 3

    VectorDense<double> vecB;

    vecB.Allocate(ELEMS);

    vecB = vecA;

    EXPECT_EQ(vecA, vecB);

    // # 4

    vecA = ELEM_A;
    vecB = ELEM_B;

    vecA.Times(vecB);

    EXPECT_EQ(vecA, ELEM_A * ELEM_B);

    // # 5

    vecB.Times(vecB);

    EXPECT_EQ(vecB, ELEM_B * ELEM_B);

    // # 6

    const double ELEM_C = 0.123456;
    const double ELEM_D = 1.234567;

    vecA = ELEM_C;
    vecB = ELEM_D;

    EXPECT_EQ(vecA * vecB, ELEM_C * ELEM_D);

    // # 7

    EXPECT_EQ(vecA * vecB + vecB * vecA, ELEM_C * ELEM_D + ELEM_D * ELEM_C);

    // # 8

    vecA = Sin(ELEM_C);
    vecB = Cos(ELEM_D);

    vecA.Times(vecA, vecB);

    EXPECT_EQ(vecA, sin(ELEM_C) * cos(ELEM_D));

    // # 9

    for (int i = 0; i != ELEMS; ++i) {
        vecA.SetElement(i, Cos(static_cast<double>(i)));
        vecB.SetElement(i, Sin(static_cast<double>(i)));
    }

    vecA = vecA * vecB;

    const double THRES_A = pow(10.0, -11.0);

    for (int i = 0; i != ELEMS; ++i) {
        EXPECT_TRUE(vecA(i) - (Cos(static_cast<double>(i)) *
                               Sin(static_cast<double>(i))) <
                    THRES_A);
    }

    // # 10

    vecA = 20.1234;
    vecB = 12.3456;
    VectorDense<double> vecC;
    vecC.Allocate(ELEMS);

    vecC.Times(vecA, vecB);

    for (int i = 0; i != ELEMS; ++i) {
        EXPECT_EQ(vecC(i), vecA(i) * vecB(i));
    }

    EXPECT_EQ(vecC, vecA * vecB);

}

//===========//
// test # 14 //
//===========//

TEST(VectorTest14, Negate) {
    // This test is named "Negate",
    // and belongs to the "VectorTest5"

    VectorDense<double> vecA;
    const int ELEMS = 1000;

    vecA.Allocate(ELEMS);

    // # 1

    const double ELEM_A = 10.0;

    vecA = ELEM_A;

    EXPECT_EQ(vecA, ELEM_A);

    // # 2

    vecA.Negate();

    EXPECT_EQ(vecA, -ELEM_A);

    // # 3

    vecA.Negate();

    EXPECT_EQ(vecA, ELEM_A);

    // # 4

    VectorDense<double> vecB;

    vecB.Allocate(ELEMS);

    (vecA + vecA).Negate(); // DOES NOT AFFECT vecA

    vecB = ELEM_A;

    EXPECT_EQ(vecB, vecA);

    // # 5

    vecA = ELEM_A;
    vecB = ELEM_A;

    (2.0 * vecA).Negate(); // DOES NOT AFFECT vecA
    (2.0 * vecB).Negate(); // DOES NOT AFFECT vecB

    EXPECT_EQ(vecB, vecA);

    EXPECT_EQ(0.0 * vecB, 0.0 * vecA);

    EXPECT_EQ(-12345.678 * vecB, -12345.678 * vecA);

    EXPECT_EQ(-0.001 * vecB, -0.001 * vecA);

    EXPECT_EQ(0.000002 * vecB, 0.000002 * vecA);

    EXPECT_EQ(0.1 * vecB * vecA, vecA * vecB * 0.1);
}

//===========//
// test # 15 //
//===========//

TEST(VectorTest15, Minus) {
    // This test is named "Minus",
    // and belongs to the "VectorTest6"

    VectorDense<double> vecA;
    const int ELEMS = 1000;

    vecA.Allocate(ELEMS);

    const double ELEM_A = 10.0;

    vecA = ELEM_A;

    VectorDense<double> vecB(vecA);

    // # 1

    EXPECT_EQ(vecA, ELEM_A);

    // # 2

    EXPECT_EQ(vecA, vecB);

    // # 3

    vecA.Minus(vecB);

    EXPECT_EQ(vecA, -vecB);

    EXPECT_EQ(vecA, -(-(-vecB)));

    EXPECT_EQ(-vecA, -(-vecB));

    EXPECT_EQ(-vecA, -(-(-vecA)));

    // # 4

    vecA = 10.0;
    vecB = 11.1;

    vecA.Minus(vecA);
    vecB.Minus(vecB);

    EXPECT_EQ(vecA, -10.0);
    EXPECT_EQ(vecB, -11.1);

    // # 5

    vecA = 10.0;
    vecB = 11.1;

    vecA.Minus(vecA + vecB);
    vecB.Minus(vecB + vecA);

    EXPECT_EQ(vecA, -21.1);

    const double THRES_A = pow(10.0, -15.0);
    const double THRES_B = pow(10.0, -16.0);
    const double THRES_C = pow(10.0, -17.0);

    for (int i = 0; i != ELEMS; ++i) {
        EXPECT_TRUE((vecB(i) - (+21.1 - 11.1)) < THRES_A);
        EXPECT_TRUE((vecB(i) - (+21.1 - 11.1)) < THRES_B);
        EXPECT_TRUE((vecB(i) - (+21.1 - 11.1)) < THRES_C);
    }
}

//===========//
// test # 16 //
//===========//

TEST(VectorTest16, ComplexDouble) {
    const unsigned long int ELEMS = 8 * static_cast<unsigned long int>(pow(10.0, 3.0));

    VectorDense <std::complex<double>> vecA;
    VectorDense <std::complex<double>> vecB;

    vecA.Allocate(ELEMS);
    vecB.Allocate(ELEMS);

    vecA = {1.1, 4.0};
    vecB = {1.1, 4.0};

    EXPECT_TRUE(vecA == vecB);
    EXPECT_EQ(vecA, vecB);

    const std::complex<double> coA = {1.1, 2.2};
    const std::complex<double> coB = {1.2, 2.3};

    vecA = coA;
    EXPECT_EQ(vecA, coA);

    vecB = coB;
    EXPECT_EQ(vecB, coB);

    vecA.Deallocate();
    vecB.Deallocate();
}

//===========//
// test # 17 //
//===========//

TEST(VectorTest17, ComplexLongDouble) {
    const unsigned long int ELEMS = 4 * static_cast<unsigned long int>(pow(10.0, 3.0));

    VectorDense <std::complex<long double>> vecA;
    VectorDense <std::complex<long double>> vecB;

    vecA.Allocate(ELEMS);
    vecB.Allocate(ELEMS);

    vecA = {1.1L, 4.0L};
    vecB = {1.1L, 4.0L};

    EXPECT_TRUE(vecA == vecB);
    EXPECT_EQ(vecA, vecB);

    const std::complex<long double> coA = {1.1L, 2.2L};
    const std::complex<long double> coB = {1.2L, 2.3L};

    vecA = coA;
    EXPECT_EQ(vecA, coA);

    vecB = coB;
    EXPECT_EQ(vecB, coB);

    vecA.Deallocate();
    vecB.Deallocate();
}

//===========//
// test # 18 //
//===========//

TEST(VectorTest18, FastWayA) {
    // local parameters

    const auto DIM = 8 * static_cast<pgg::VEI_MAX>(pow(10.0, 2.0));
    const auto K_MAX_LOC = 2;
    const auto ONE_DOUBLE = 1.0;
    const auto TWO_DOUBLE = 2.0;
    const auto THREE_DOUBLE = 3.0;

    VectorDense<double> vecA;
    VectorDense<double> vecB;
    VectorDense<double> vecC;

    vecA.Allocate(DIM);
    vecB.Allocate(DIM);
    vecC.Allocate(DIM);

    vecA.Set(ONE_DOUBLE);
    vecB.Set(TWO_DOUBLE);
    vecC.Set(THREE_DOUBLE);

    EXPECT_TRUE(vecA.Equal(ONE_DOUBLE));
    EXPECT_TRUE(vecB.Equal(TWO_DOUBLE));
    EXPECT_TRUE(vecC.Equal(THREE_DOUBLE));

    // add matrices

    for (int i = 0; i != K_MAX_LOC; ++i) {
        vecC.Plus(vecA, vecB);
    }

    EXPECT_TRUE(vecA.Equal(ONE_DOUBLE));
    EXPECT_TRUE(vecB.Equal(TWO_DOUBLE));
    EXPECT_TRUE(vecC.Equal(THREE_DOUBLE));

    // subtract matrices

    for (int i = 0; i != K_MAX_LOC; ++i) {
        vecC.Subtract(vecA, vecB);
    }

    EXPECT_TRUE(vecA.Equal(ONE_DOUBLE));
    EXPECT_TRUE(vecB.Equal(TWO_DOUBLE));
    EXPECT_TRUE(vecC.Equal(-ONE_DOUBLE));

    // multiply matrices


    for (int i = 0; i != K_MAX_LOC; ++i) {
        vecC.Times(vecA, vecB);
    }

    EXPECT_TRUE(vecA.Equal(ONE_DOUBLE));
    EXPECT_TRUE(vecB.Equal(TWO_DOUBLE));
    EXPECT_TRUE(vecC.Equal(TWO_DOUBLE));

    // divide matrices

    for (int i = 0; i != K_MAX_LOC; ++i) {
        vecC.Divide(vecA, vecB);
    }

    EXPECT_TRUE(vecA.Equal(ONE_DOUBLE));
    EXPECT_TRUE(vecB.Equal(TWO_DOUBLE));
    EXPECT_TRUE(vecC.Equal(ONE_DOUBLE / TWO_DOUBLE));

    // swap matrices

    for (int i = 0; i != K_MAX_LOC; ++i) {

        vecA.Set(ONE_DOUBLE);
        vecB.Set(TWO_DOUBLE);
        vecC.Set(THREE_DOUBLE);

        vecA.Set(vecB);
        vecB.Set(vecC);
        vecC.Set(ONE_DOUBLE);
    }

    EXPECT_TRUE(vecA.Equal(TWO_DOUBLE));
    EXPECT_TRUE(vecB.Equal(THREE_DOUBLE));
    EXPECT_TRUE(vecC.Equal(ONE_DOUBLE));

    // advance matrices

    vecA.Set(ONE_DOUBLE);
    vecB.Set(TWO_DOUBLE);
    vecC.Set(THREE_DOUBLE);

    for (int i = 0; i != K_MAX_LOC; ++i) {
        vecA.Plus(vecA, ONE_DOUBLE);
        vecB.Plus(vecB, ONE_DOUBLE);
        vecC.Plus(vecC, ONE_DOUBLE);
    }

    EXPECT_TRUE(vecA.Equal(ONE_DOUBLE + ONE_DOUBLE * K_MAX_LOC));
    EXPECT_TRUE(vecB.Equal(TWO_DOUBLE + ONE_DOUBLE * K_MAX_LOC));
    EXPECT_TRUE(vecC.Equal(THREE_DOUBLE + ONE_DOUBLE * K_MAX_LOC));

    // advance matrices

    vecA.Set(ONE_DOUBLE);
    vecB.Set(TWO_DOUBLE);
    vecC.Set(THREE_DOUBLE);

    for (int i = 0; i != K_MAX_LOC; ++i) {
        vecA.Subtract(vecA, ONE_DOUBLE);
        vecB.Subtract(vecB, ONE_DOUBLE);
        vecC.Subtract(vecC, ONE_DOUBLE);
    }

    EXPECT_TRUE(vecA.Equal(ONE_DOUBLE - ONE_DOUBLE * K_MAX_LOC));
    EXPECT_TRUE(vecB.Equal(TWO_DOUBLE - ONE_DOUBLE * K_MAX_LOC));
    EXPECT_TRUE(vecC.Equal(THREE_DOUBLE - ONE_DOUBLE * K_MAX_LOC));

    // advance matrices

    vecA.Set(ONE_DOUBLE);
    vecB.Set(TWO_DOUBLE);
    vecC.Set(THREE_DOUBLE);

    for (int i = 0; i != K_MAX_LOC; ++i) {
        vecA.Times(vecA, ONE_DOUBLE);
        vecB.Times(vecB, ONE_DOUBLE);
        vecC.Times(vecC, ONE_DOUBLE);
    }

    EXPECT_TRUE(vecA.Equal(ONE_DOUBLE));
    EXPECT_TRUE(vecB.Equal(TWO_DOUBLE));
    EXPECT_TRUE(vecC.Equal(THREE_DOUBLE));

    // advance matrices

    vecA.Set(ONE_DOUBLE);
    vecB.Set(TWO_DOUBLE);
    vecC.Set(THREE_DOUBLE);

    for (int i = 0; i != K_MAX_LOC; ++i) {
        vecA.Divide(vecA, ONE_DOUBLE);
        vecB.Divide(vecB, ONE_DOUBLE);
        vecC.Divide(vecC, ONE_DOUBLE);
    }

    EXPECT_TRUE(vecA.Equal(ONE_DOUBLE));
    EXPECT_TRUE(vecB.Equal(TWO_DOUBLE));
    EXPECT_TRUE(vecC.Equal(THREE_DOUBLE));

    // advance matrices

    vecA.Set(ONE_DOUBLE);
    vecB.Set(TWO_DOUBLE);
    vecC.Set(THREE_DOUBLE);

    for (int i = 0; i != K_MAX_LOC; ++i) {
        vecA.Plus(vecA);
        vecB.Plus(vecB);
        vecC.Plus(vecC);
    }

    EXPECT_TRUE(vecA.Equal(1.0 * pow(TWO_DOUBLE, K_MAX_LOC)));
    EXPECT_TRUE(vecB.Equal(2.0 * pow(TWO_DOUBLE, K_MAX_LOC)));
    EXPECT_TRUE(vecC.Equal(3.0 * pow(TWO_DOUBLE, K_MAX_LOC)));

    // advance matrices

    vecA.Set(ONE_DOUBLE);
    vecB.Set(TWO_DOUBLE);
    vecC.Set(THREE_DOUBLE);

    for (int i = 0; i != K_MAX_LOC; ++i) {
        vecA.Subtract(vecA);
        vecB.Subtract(vecB);
        vecC.Subtract(vecC);
    }

    EXPECT_TRUE(vecA.Equal(pgg::ZERO_DBL));
    EXPECT_TRUE(vecB.Equal(pgg::ZERO_DBL));
    EXPECT_TRUE(vecC.Equal(pgg::ZERO_DBL));

    // advance matrices

    vecA.Set(ONE_DOUBLE);
    vecB.Set(TWO_DOUBLE);
    vecC.Set(THREE_DOUBLE);

    for (int i = 0; i != K_MAX_LOC; ++i) {
        vecA.Divide(vecA);
        vecB.Divide(vecB);
        vecC.Divide(vecC);
    }

    EXPECT_TRUE(vecA.Equal(pgg::ONE_DBL));
    EXPECT_TRUE(vecB.Equal(pgg::ONE_DBL));
    EXPECT_TRUE(vecC.Equal(pgg::ONE_DBL));

    // advance matrices

    vecA.Set(ONE_DOUBLE);
    vecB.Set(TWO_DOUBLE);
    vecC.Set(THREE_DOUBLE);

    for (int i = 0; i != K_MAX_LOC; ++i) {
        vecA.Times(vecA);
        vecB.Times(vecB);
        vecB.Divide(TWO_DOUBLE);
        vecC.Times(vecC);
        vecC.Divide(THREE_DOUBLE);
    }

    EXPECT_TRUE(vecA.Equal(ONE_DOUBLE));
    EXPECT_TRUE(vecB.Equal(TWO_DOUBLE));
    EXPECT_TRUE(vecC.Equal(THREE_DOUBLE));

    // deallocate heap space

    vecA.Deallocate();
    vecB.Deallocate();
    vecC.Deallocate();

}

//===========//
// test # 19 //
//===========//

TEST(VectorTest19, Swap) {
    // This test is named "Swap",
    // and belongs to the "VectorTest1"

    VectorDense<double> vecA;
    VectorDense<double> vecB;
    const int ELEMS = 1000;

    vecA.Allocate(ELEMS);
    vecB.Allocate(ELEMS);

    // # 1

    const double ELEM_A = 10.0;
    const double ELEM_B = 20.1;

    vecA = ELEM_A;
    vecB = ELEM_B;

    EXPECT_EQ(vecA, ELEM_A);
    EXPECT_EQ(vecB, ELEM_B);

    // # 2

    vecA.Swap(vecB);

    EXPECT_EQ(vecA, ELEM_B);
    EXPECT_EQ(vecB, ELEM_A);

    // # 3

    vecA.Swap(vecB);

    EXPECT_EQ(vecA, ELEM_A);
    EXPECT_EQ(vecB, ELEM_B);
}

//===========//
// test # 20 //
//===========//

TEST(VectorTest20, Swap) {
    // This test is named "Swap",
    // and belongs to the "VectorTest2"

    VectorDense<double> vecA;
    VectorDense<double> vecB;
    const int ELEMS = static_cast<int>(pow(10.0, 3.0));

    vecA.Allocate(ELEMS);
    vecB.Allocate(ELEMS);

    // # 1

    const double ELEM_A = 10.0;
    const double ELEM_B = 20.1;

    vecA = ELEM_A;
    vecB = ELEM_B;

    EXPECT_EQ(vecA, ELEM_A);
    EXPECT_EQ(vecB, ELEM_B);

    // # 2

    for (int i = 0; i != 5; ++i) {
        vecA.Swap(vecB);
    }

    EXPECT_EQ(vecA, ELEM_B);
    EXPECT_EQ(vecB, ELEM_A);

    // # 3

    for (int i = 0; i != 5; ++i) {
        vecA.Swap(vecB);
    }

    EXPECT_EQ(vecA, ELEM_A);
    EXPECT_EQ(vecB, ELEM_B);
}

//===========//
// test # 21 //
//===========//

TEST(VectorTest21, CheckCompatibility) {
    VectorDense<double> vecA;
    VectorDense<double> vecB;

    const int ELEM = 100;

    // # 1

    vecA.Allocate(ELEM);
    vecB.Allocate(ELEM);

    EXPECT_TRUE(vecA.AllocatedQ());
    EXPECT_TRUE(vecB.AllocatedQ());

    EXPECT_TRUE(vecA.CheckCompatibility(vecB));
    EXPECT_TRUE(vecB.CheckCompatibility(vecA));

    // # 2

    vecA.Deallocate();
    vecB.Deallocate();

    // # 3

    EXPECT_TRUE(vecA.DeallocatedQ());
    EXPECT_TRUE(vecB.DeallocatedQ());
}

//===========//
// test # 22 //
//===========//

TEST(VectorTest22, Equal) {
    VectorDense<double> vecA;
    VectorDense<double> vecB;

    const int ELEM = 100;

    // # 1

    vecA.Allocate(ELEM);
    vecB.Allocate(ELEM);

    vecA = 11.1111;
    vecB = 12.3456;

    EXPECT_TRUE(vecA.Equal(11.1111));
    EXPECT_TRUE(vecB.Equal(12.3456));

    EXPECT_FALSE(vecA.Equal(11.11111));
    EXPECT_FALSE(vecB.Equal(12.34567));

    EXPECT_TRUE(vecA.Equal(11.11111, 0.01));
    EXPECT_TRUE(vecB.Equal(12.34567, 0.01));

    EXPECT_FALSE(vecA.Equal(11.11111, 0.000000001));
    EXPECT_FALSE(vecB.Equal(12.34567, 0.000000001));

    EXPECT_TRUE(vecA.Equal(vecA));
    EXPECT_TRUE(vecB.Equal(vecB));

    EXPECT_TRUE(vecA.Equal(vecA, 10.0));
    EXPECT_TRUE(vecB.Equal(vecB, 20.0));

    EXPECT_FALSE(vecA.Equal(vecA, -10.0));
    EXPECT_FALSE(vecB.Equal(vecB, -20.0));

    EXPECT_TRUE(vecA.Equal(vecB, 100.0));
    EXPECT_TRUE(vecB.Equal(vecA, 200.0));

    vecA = 10.00000000000000000;
    vecB = 10.00000000000000001;

    EXPECT_TRUE(vecA.Equal(vecB));
    EXPECT_TRUE(vecB.Equal(vecA));

    vecA = 10.0000000000000000;
    vecB = 10.0000000000000001;

    EXPECT_TRUE(vecA.Equal(vecB));
    EXPECT_TRUE(vecB.Equal(vecA));

    vecA = 10.000000000000000; // 15 digits accuracy for double
    vecB = 10.000000000000001;

    EXPECT_FALSE(vecA.Equal(vecB));
    EXPECT_FALSE(vecB.Equal(vecA));

    // # 2

    VectorDense<long double> vecC;
    VectorDense<long double> vecD;

    vecC.Allocate(1000);
    vecD.Allocate(1000);

    vecC = 10.00000000000000000L;
    vecD = 10.00000000000000001L;

    EXPECT_FALSE(vecC.Equal(vecD));
    EXPECT_FALSE(vecD.Equal(vecC));

    vecC = 10.0000000000000000000L;
    vecD = 10.0000000000000000001L; // 19 digits accuracy for long double

    EXPECT_TRUE(vecC.Equal(vecD));
    EXPECT_TRUE(vecD.Equal(vecC));
}

//===========//
// test # 23 //
//===========//

TEST(VectorTest23, Map) {
    VectorDense<double> vecA;
    VectorDense<double> vecB;

    vecA.Allocate(100);
    vecB.Allocate(100);

    vecA = 10.0;
    vecB = 20.0;

    // # 1

    vecA.Map(cos);
    vecB.Map(sin);

    EXPECT_EQ(vecA, cos(10.0));
    EXPECT_EQ(vecB, sin(20.0));

    // # 2

    vecA.Map(cos);
    vecB.Map(sin);

    EXPECT_EQ(vecA, cos(cos(10.0)));
    EXPECT_EQ(vecB, sin(sin(20.0)));

    // # 3

    vecA.Map(cos);
    vecB.Map(sin);

    EXPECT_EQ(vecA, cos(cos(cos(10.0))));
    EXPECT_EQ(vecB, sin(sin(sin(20.0))));

    // # 4

    vecA.Map(sin);
    vecB.Map(cos);

    vecA.Map(sin);
    vecB.Map(cos);

    EXPECT_EQ(vecA, sin(sin(cos(cos(cos(10.0))))));
    EXPECT_EQ(vecB, cos(cos(sin(sin(sin(20.0))))));
}

//===========//
// test # 24 //
//===========//

TEST(VectorTest24, Nest) {
    VectorDense<double> vecA;
    VectorDense<double> vecB;

    vecA.Allocate(100);
    vecB.Allocate(100);

    vecA = 10.0;
    vecB = 20.0;

    // # 1

    vecA.Map(cos);
    vecB.Map(sin);

    EXPECT_EQ(vecA, Cos<double>(10.0));
    EXPECT_EQ(vecB, Sin<double>(20.0));

    // # 2

    vecA.Nest(Cos < double > , 4);
    vecB.Nest(Sin < double > , 4);

    EXPECT_EQ(vecA, cos(cos(cos(cos(cos(10.0))))));
    EXPECT_EQ(vecB, sin(sin(sin(sin(sin(20.0))))));
}

//===========//
// test # 25 //
//===========//

TEST(VectorTest25, Mean) {
    MatrixDense<double> vecA;
    MatrixDense<double> vecB;

    const int ELEM_A = 100;
    const int ELEM_B = 200;

    vecA.Allocate(ELEM_A);
    vecB.Allocate(ELEM_B);

    vecA.Random(0.0, 1.0, 20);
    vecB.Random(0.0, 1.0, 20);

    double tmpA = vecA.Mean();
    double tmpB = vecB.Mean();

    // # 1

    pgg::functions::SeedRandomGenerator(20);

    double tmp_val = 0.0;
    for (int i = 0; i != ELEM_A; ++i) {
        tmp_val = tmp_val + pgg::functions::RandomNumber(0.0, 1.0);
    }

    tmp_val = tmp_val / ELEM_A;

    EXPECT_TRUE((tmp_val - tmpA) < pow(10.0, -14.0));

    // # 2

    pgg::functions::SeedRandomGenerator(20);

    tmp_val = 0.0;
    for (int i = 0; i != ELEM_B; ++i) {
        tmp_val = tmp_val + pgg::functions::RandomNumber(0.0, 1.0);
    }

    tmp_val = tmp_val / ELEM_B;

    EXPECT_TRUE((tmp_val - tmpB) < pow(10.0, -14.0));
}

//===========//
// test # 26 //
//===========//

TEST(VectorTest26, Range) {
    VectorDense<double> vecA;
    VectorDense<double> vecB;

    const int ELEM_A = 100;
    const int ELEM_B = 200;

    vecA.Allocate(ELEM_A);
    vecB.Allocate(ELEM_B);

    vecA.Range(1.0);
    vecB.Range(2.0);

    for (int i = 0; i != ELEM_A; ++i) {
        EXPECT_EQ(vecA(i), 1.0 + i);
    }

    for (int i = 0; i != ELEM_B; ++i) {
        EXPECT_EQ(vecB(i), 2.0 + i);
    }
}

//===========//
// test # 27 //
//===========//

TEST(VectorTest27, Range) {
    VectorDense<double> vecA;
    VectorDense<double> vecB;

    const int ELEM_A = 100;
    const int ELEM_B = 200;

    vecA.Allocate(ELEM_A);
    vecB.Allocate(ELEM_B);

    vecA.Range(1.0, 2.0);
    vecB.Range(2.0, 4.0);

    const double STEP_A = (2.0 - 1.0) / ELEM_A;
    const double STEP_B = (4.0 - 2.0) / ELEM_B;

    for (int i = 0; i != ELEM_A; ++i) {
        EXPECT_EQ(vecA(i), STEP_A * i + 1.0);
    }

    for (int i = 0; i != ELEM_B; ++i) {
        EXPECT_EQ(vecB(i), STEP_B * i + 2.0);
    }
}

//===========//
// test # 28 //
//===========//

TEST(VectorTest28, GreaterAll) {
    VectorDense<double> vecA;
    VectorDense<double> vecB;

    const int ELEM = 100;

    vecA.Allocate(ELEM);
    vecB.Allocate(ELEM);

    vecA.Range(1.0, 2.0);
    vecB.Range(3.0, 4.0);

    EXPECT_TRUE(vecB.Greater(vecA));
    EXPECT_TRUE(vecB > vecA);
    EXPECT_TRUE(vecB.GreaterEqual(vecA));
    EXPECT_TRUE(vecB >= vecA);
}

//===========//
// test # 29 //
//===========//

TEST(VectorTest29, LessAll) {
    VectorDense<double> vecA;
    VectorDense<double> vecB;

    const int ELEM = 100;

    vecA.Allocate(ELEM);
    vecB.Allocate(ELEM);

    vecB.Range(1.0, 2.0);
    vecA.Range(3.0, 4.0);

    EXPECT_TRUE(vecB.Less(vecA));
    EXPECT_TRUE(vecB < vecA);
    EXPECT_TRUE(vecB.LessEqual(vecA));
    EXPECT_TRUE(vecB <= vecA);
}

//===========//
// test # 30 //
//===========//

TEST(VectorTest30, GreaterAll) {
    VectorDense<double> vecA;

    const int ELEM = 100;

    vecA.Allocate(ELEM);

    vecA.Range(1.0, 2.0);

    EXPECT_TRUE(vecA.Greater(0.0));
    EXPECT_TRUE(vecA > -1.0);
    EXPECT_TRUE(vecA.GreaterEqual(1.0));
    EXPECT_TRUE(vecA >= 1.0);
}

//===========//
// test # 31 //
//===========//

TEST(VectorTest31, LessAll) {
    VectorDense<double> vecA;

    const int ELEM = 100;

    vecA.Allocate(ELEM);

    vecA.Range(3.0, 4.0);

    EXPECT_TRUE(vecA.Less(10.0));
    EXPECT_TRUE(vecA < 4.001);
    EXPECT_TRUE(vecA.LessEqual(4.0));
    EXPECT_TRUE(vecA <= 4.0);
}

//===========//
// test # 32 //
//===========//

TEST(VectorTest32, CompareAllComplexA) {
    VectorDense <std::complex<double>> vecA;
    VectorDense <std::complex<double>> vecB;

    const int ELEM = 100;

    vecA.Allocate(ELEM);
    vecB.Allocate(ELEM);

    vecA.Set({1.0, 0.0});
    vecB.Set(1.0);

    EXPECT_TRUE(vecA.Equal(vecB));
    EXPECT_TRUE(vecA == vecB);
    EXPECT_TRUE(vecA.Less({2.0, 1.0}));
    EXPECT_TRUE(vecA.LessEqual({4.0, 0.0}));

    vecA.Set({2.0, 3.0});
    vecB.Set({3.0, 2.0});

    EXPECT_FALSE(vecA.Equal(vecB));
    EXPECT_FALSE(vecA == vecB);
    EXPECT_TRUE(vecA.Less({5.0, 4.0}));
    EXPECT_TRUE(vecA.LessEqual({5.0, 3.0}));
    EXPECT_TRUE(vecB.Less({5.0, 15.0}));
    EXPECT_TRUE(vecB.LessEqual({3.0, 2.0}));
}

//===========//
// test # 33 //
//===========//

TEST(VectorTest33, CompareAllComplexB) {
    VectorDense <std::complex<long double>> vecA;
    VectorDense <std::complex<long double>> vecB;

    const int ELEM = 100;

    vecA.Allocate(ELEM);
    vecB.Allocate(ELEM);

    vecA.Set({1.0L, 0.0L});
    vecB.Set(1.0L);

    EXPECT_TRUE(vecA.Equal(vecB));
    EXPECT_TRUE(vecA == vecB);
    EXPECT_TRUE(vecA.Less({2.0L, 2.0L}));
    EXPECT_TRUE(vecA.LessEqual(4.0L));

    vecA.Set({2.0L, 3.0L});
    vecB.Set({3.0L, 2.0L});

    EXPECT_FALSE(vecA.Equal(vecB));
    EXPECT_FALSE(vecA == vecB);
    EXPECT_TRUE(vecA.Less({5.0L, 5.0L}));
    EXPECT_TRUE(vecA.LessEqual({5.0L, 3.0L}));
    EXPECT_TRUE(vecB.Less({5.0L, 4.0L}));
    EXPECT_TRUE(vecB.LessEqual({5.0L, 2.0L}));

}

//===========//
// test # 34 //
//===========//

TEST(VectorTest34, Dot) {
    VectorDense<double> vecA;
    VectorDense<double> vecB;

    const int ELEMS = 100;

    vecA.Allocate(ELEMS);
    vecB.Allocate(ELEMS);

    vecA = 1.234;
    vecB = 2.345;

    double tmp_double = vecA.Dot(vecB);

    EXPECT_TRUE((1.234 * 2.345 * 100.0 - tmp_double) < pow(10.0, -14.0));
}

//===========//
// test # 35 //
//===========//

TEST(VectorTest35, Dot) {
    VectorDense<double> vecA;
    VectorDense<double> vecB;

    EXPECT_TRUE(vecA.DeallocatedQ());
    EXPECT_TRUE(vecB.DeallocatedQ());

    const int ELEMS = 10000;

    vecA.Allocate(ELEMS);
    vecB.Allocate(ELEMS);

    EXPECT_TRUE(vecA.AllocatedQ());
    EXPECT_TRUE(vecB.AllocatedQ());

    vecA.Random(1.0, 2.0, 20);
    vecB.Random(1.0, 2.0, 20);

    double tmp_doubleA = vecA.Dot(vecB);
    double tmp_doubleB;

    pgg::functions::SeedRandomGenerator(20);

    tmp_doubleB = 0.0;

    for (int i = 0; i != ELEMS; ++i) {
        double tmp = pgg::functions::RandomNumber(1.0, 2.0);

        tmp_doubleB = tmp_doubleB + tmp * tmp;
    }

    EXPECT_TRUE((tmp_doubleA - tmp_doubleB) < pow(10.0, -10.0));
}

//===========//
// test # 36 //
//===========//

TEST(VectorTest36, Dot) {
    VectorDense<double> vecA;
    VectorDense<double> vecB;

    EXPECT_TRUE(vecA.DeallocatedQ());
    EXPECT_TRUE(vecB.DeallocatedQ());

    const int ELEMS = 10000;

    vecA.Allocate(ELEMS);
    vecB.Allocate(ELEMS);

    EXPECT_TRUE(vecA.AllocatedQ());
    EXPECT_TRUE(vecB.AllocatedQ());

    for (int i = 0; i != ELEMS; ++i) {
        vecA.SetElement(i, sin(static_cast<double>(i)));
        vecB.SetElement(i, cos(static_cast<double>(i)));
    }

    double tmp_doubleA = vecA.Dot(vecB);
    const double tmp_doubleB = -0.11551041567000858692;

    EXPECT_TRUE((tmp_doubleA - tmp_doubleB) < pow(10.0, -14.0));
}

//===========//
// test # 37 //
//===========//

TEST(VectorTest37, Dot) {
    VectorDense<double> vecA;
    VectorDense<double> vecB;
    MatrixDense<double> matA;

    EXPECT_TRUE(vecA.DeallocatedQ());
    EXPECT_TRUE(vecB.DeallocatedQ());
    EXPECT_TRUE(matA.DeallocatedQ());

    const int ELEMS_A = 10;
    const int ELEMS_B = 1000;

    vecA.Allocate(ELEMS_A);
    vecB.Allocate(ELEMS_B);
    matA.Allocate(ELEMS_A, ELEMS_B);

    EXPECT_TRUE(vecA.AllocatedQ());
    EXPECT_TRUE(vecB.AllocatedQ());
    EXPECT_TRUE(matA.AllocatedQ());

    for (int i = 0; i != ELEMS_B; ++i) {
        vecB.SetElement(i, sin(static_cast<double>(i)));
    }

    for (int i = 0; i != ELEMS_B * ELEMS_A; ++i) {
        matA.SetElement(i, cos(static_cast<double>(i)));
    }

    vecA.DotGSL(matA, vecB);

    const double corr[ELEMS_A] = {
            -0.013000956337400969716, -413.04095342736712548,
            -464.55817876109059451, -109.47464548253968530,
            341.42567875364489603, 493.49596116134191391,
            213.63792682857131289, -253.20496126031645456,
            -498.43227128017131844, -307.41079937172321604
    };

    for (int i = 0; i != ELEMS_A; ++i) {
        EXPECT_TRUE((corr[i] - vecA[i]) < pow(10.0, -10.0));
    }
}

//===========//
// test # 38 //
//===========//

TEST(VectorTest38, Dot) {
    VectorDense<double> vecA;
    VectorDense<double> vecB;
    MatrixDense<double> matA;

    EXPECT_TRUE(vecA.DeallocatedQ());
    EXPECT_TRUE(vecB.DeallocatedQ());
    EXPECT_TRUE(matA.DeallocatedQ());

    const int ELEMS_A = 10;
    const int ELEMS_B = 1000;

    vecA.Allocate(ELEMS_A);
    vecB.Allocate(ELEMS_B);
    matA.Allocate(ELEMS_A, ELEMS_B);

    EXPECT_TRUE(vecA.AllocatedQ());
    EXPECT_TRUE(vecB.AllocatedQ());
    EXPECT_TRUE(matA.AllocatedQ());

    for (int i = 0; i != ELEMS_B; ++i) {
        vecB.SetElement(i, sin(static_cast<double>(i)));
    }

    for (int i = 0; i != ELEMS_B * ELEMS_A; ++i) {
        matA.SetElement(i, cos(static_cast<double>(i)));
    }

    vecA.DotBLAS(matA, vecB);

    const double corr[ELEMS_A] = {
            -0.013000956337400969716, -413.04095342736712548,
            -464.55817876109059451, -109.47464548253968530,
            341.42567875364489603, 493.49596116134191391,
            213.63792682857131289, -253.20496126031645456,
            -498.43227128017131844, -307.41079937172321604
    };

    for (int i = 0; i != ELEMS_A; ++i) {
        EXPECT_TRUE((corr[i] - vecA[i]) < pow(10.0, -10.0));
    }
}

//===========//
// test # 39 //
//===========//

TEST(VectorTest39, Dot) {
    VectorDense<double> vecA;
    VectorDense<double> vecB;
    MatrixDense<double> matA;

    EXPECT_TRUE(vecA.DeallocatedQ());
    EXPECT_TRUE(vecB.DeallocatedQ());
    EXPECT_TRUE(matA.DeallocatedQ());

    const int ELEMS_A = 10;
    const int ELEMS_B = 1000;

    vecA.Allocate(ELEMS_A);
    vecB.Allocate(ELEMS_B);
    matA.Allocate(ELEMS_A, ELEMS_B);

    EXPECT_TRUE(vecA.AllocatedQ());
    EXPECT_TRUE(vecB.AllocatedQ());
    EXPECT_TRUE(matA.AllocatedQ());

    for (int i = 0; i != ELEMS_B; ++i) {
        vecB.SetElement(i, sin(static_cast<double>(i)));
    }

    for (int i = 0; i != ELEMS_B * ELEMS_A; ++i) {
        matA.SetElement(i, cos(static_cast<double>(i)));
    }

    vecA.Dot(matA, vecB, "WithRows");

    const double corr[ELEMS_A] = {
            -0.013000956337400969716, -413.04095342736712548,
            -464.55817876109059451, -109.47464548253968530,
            341.42567875364489603, 493.49596116134191391,
            213.63792682857131289, -253.20496126031645456,
            -498.43227128017131844, -307.41079937172321604
    };

    for (int i = 0; i != ELEMS_A; ++i) {
        EXPECT_TRUE((corr[i] - vecA[i]) < pow(10.0, -10.0));
    }
}

//===========//
// test # 40 //
//===========//

TEST(VectorTest40, Dot) {
    VectorDense<double> vecA;
    VectorDense<double> vecB;
    MatrixDense<double> matA;

    EXPECT_TRUE(vecA.DeallocatedQ());
    EXPECT_TRUE(vecB.DeallocatedQ());
    EXPECT_TRUE(matA.DeallocatedQ());

    const int ELEMS_A = 10;
    const int ELEMS_B = 10;

    vecA.Allocate(ELEMS_A);
    vecB.Allocate(ELEMS_B);
    matA.Allocate(ELEMS_A, ELEMS_B);

    EXPECT_TRUE(vecA.AllocatedQ());
    EXPECT_TRUE(vecB.AllocatedQ());
    EXPECT_TRUE(matA.AllocatedQ());

    for (int i = 0; i != ELEMS_B; ++i) {
        vecB.SetElement(i, sin(static_cast<double>(i)));
    }

    for (int i = 0; i != ELEMS_B * ELEMS_A; ++i) {
        matA.SetElement(i, cos(static_cast<double>(i)));
    }

    // # 1

    vecA.Dot(matA, vecB, "WithColumns");

    const double corr[ELEMS_A] = {
            -0.3454781443936671, -0.1019678318253387, 0.2352912350744567,
            0.3562246255479217, 0.1496467381066567, -0.1945156702185772,
            -0.3598412683998245, -0.1943304639073055, 0.1498468729007396,
            0.3562556858181048
    };

    for (int i = 0; i != ELEMS_A; ++i) {
        EXPECT_TRUE((corr[i] - vecA[i]) < pow(10.0, -10.0));
    }

    // # 2

    vecA.Dot(matA, vecB, "WithRows", "GSL");

    const double corr2[ELEMS_A] = {
            -0.1332197783447333, 2.671656845240047, -4.350202610261541,
            4.628605466729006, -3.417259522658326, 1.106044879126973,
            1.561157986745827, -3.725891317264447, 4.691420662753688,
            -4.146983700810754
    };

    for (int i = 0; i != ELEMS_A; ++i) {
        EXPECT_TRUE((corr2[i] - vecA[i]) < pow(10.0, -10.0));
    }

    // # 3

    vecA.Dot(matA, vecB, "WithRows", "BLAS");

    for (int i = 0; i != ELEMS_A; ++i) {
        EXPECT_TRUE((corr2[i] - vecA[i]) < pow(10.0, -10.0));
    }
}

//===========//
// test # 41 //
//===========//

TEST(VectorTest41, Dot) {
    VectorDense<double> vecA;
    VectorDense<double> vecB;
    MatrixDense<double> matA;

    EXPECT_TRUE(vecA.DeallocatedQ());
    EXPECT_TRUE(vecB.DeallocatedQ());
    EXPECT_TRUE(matA.DeallocatedQ());

    const int ELEMS_A = 10;
    const int ELEMS_B = 20;

    vecA.Allocate(ELEMS_A);
    vecB.Allocate(ELEMS_B);
    matA.Allocate(ELEMS_B, ELEMS_A);

    EXPECT_TRUE(vecA.AllocatedQ());
    EXPECT_TRUE(vecB.AllocatedQ());
    EXPECT_TRUE(matA.AllocatedQ());

    for (int i = 0; i != ELEMS_B; ++i) {
        vecB.SetElement(i, sin(static_cast<double>(i)));
    }

    for (int i = 0; i != ELEMS_B * ELEMS_A; ++i) {
        matA.SetElement(i, cos(static_cast<double>(i)));
    }

    // # 1

    vecA.Dot(matA, vecB, "WithColumns", "GSL");

    const double corr[ELEMS_A] = {-0.30954436029720900162, -0.48502368596743207457,
                                  -0.21457447156052705936, 0.25315352243825139799,
                                  0.48813333538458521522, 0.27432561092054338018,
                                  -0.19169581510647377821, -0.48147299277514408727,
                                  -0.32858612131281527168, 0.12640131473197932762
    };

    for (int i = 0; i != ELEMS_A; ++i) {
        EXPECT_TRUE((corr[i] - vecA[i]) < pow(10.0, -10.0));
    }

    // # 2

    vecA.Dot(matA, vecB, "WithColumns", "BLAS");

    for (int i = 0; i != ELEMS_A; ++i) {
        EXPECT_TRUE((corr[i] - vecA[i]) < pow(10.0, -10.0));
    }

    // # 3

    vecA.Dot(matA, vecB, "WithColumns");

    for (int i = 0; i != ELEMS_A; ++i) {
        EXPECT_TRUE((corr[i] - vecA[i]) < pow(10.0, -10.0));
    }
}

//===========//
// test # 42 //
//===========//

TEST(VectorTest42, Dot) {
    VectorDense<double> vecA;
    VectorDense<double> vecB;
    MatrixDense<double> matA;

    EXPECT_TRUE(vecA.DeallocatedQ());
    EXPECT_TRUE(vecB.DeallocatedQ());
    EXPECT_TRUE(matA.DeallocatedQ());

    const int ELEMS_A = 10;
    const int ELEMS_B = 10;

    vecA.Allocate(ELEMS_A);
    vecB.Allocate(ELEMS_B);
    matA.Allocate(ELEMS_A, ELEMS_B);

    EXPECT_TRUE(vecA.AllocatedQ());
    EXPECT_TRUE(vecB.AllocatedQ());
    EXPECT_TRUE(matA.AllocatedQ());

    for (int i = 0; i != ELEMS_B; ++i) {
        vecB.SetElement(i, sin(static_cast<double>(i)));
    }

    for (int i = 0; i != ELEMS_B * ELEMS_A; ++i) {
        matA.SetElement(i, cos(static_cast<double>(i)));
    }

    // # 1

    vecA.Dot(matA, vecB, "WithColumns");

    const double corr[ELEMS_A] = {
            -0.3454781443936671, -0.1019678318253387, 0.2352912350744567,
            0.3562246255479217, 0.1496467381066567, -0.1945156702185772,
            -0.3598412683998245, -0.1943304639073055, 0.1498468729007396,
            0.3562556858181048
    };

    for (int i = 0; i != ELEMS_A; ++i) {
        EXPECT_TRUE((corr[i] - vecA[i]) < pow(10.0, -10.0));
    }

    // # 2

    for (int i = 0; i != ELEMS_B; ++i) {
        vecB.SetElement(i, sin(static_cast<double>(i)));
    }

    vecB.Dot(matA, vecB, "WithRows", "GSL");

    const double corr2[ELEMS_A] = {
            -0.1332197783447333, 2.671656845240047, -4.350202610261541,
            4.628605466729006, -3.417259522658326, 1.106044879126973,
            1.561157986745827, -3.725891317264447, 4.691420662753688,
            -4.146983700810754
    };

    for (int i = 0; i != ELEMS_A; ++i) {
        EXPECT_TRUE((corr2[i] - vecB[i]) < pow(10.0, -10.0));
    }

    // # 3

    for (int i = 0; i != ELEMS_B; ++i) {
        vecB.SetElement(i, sin(static_cast<double>(i)));
    }

    vecB.Dot(matA, vecB, "WithRows", "BLAS");

    for (int i = 0; i != ELEMS_A; ++i) {
        EXPECT_TRUE((corr2[i] - vecB[i]) < pow(10.0, -10.0));
    }

    // # 4

    for (int i = 0; i != ELEMS_B; ++i) {
        vecB.SetElement(i, sin(static_cast<double>(i)));
    }

    vecB.Dot(matA, vecB);

    for (int i = 0; i != ELEMS_A; ++i) {
        EXPECT_TRUE((corr2[i] - vecB[i]) < pow(10.0, -10.0));
    }
}

//===========//
// test # 43 //
//===========//

TEST(VectorTest43, op_equal) {
    VectorDense<double> vecA;
    VectorDense<double> vecB;
    VectorDense<double> vecC;

    const int ELEMS = 100;

    vecA.Allocate(ELEMS);
    vecB.Allocate(ELEMS);
    vecC.Allocate(ELEMS);

    vecA = 10.0;
    vecB = vecA;
    vecC = vecB;

    // # 1

    EXPECT_TRUE(vecA == vecB);
    EXPECT_TRUE(vecB == vecC);
}

//===========//
// test # 44 //
//===========//

TEST(VectorTest44, op_equal) {
    VectorDense<double> vecA;
    VectorDense<double> vecB;
    VectorDense<double> vecC;

    const int ELEMS = 100;

    vecA.Allocate(ELEMS);
    vecB.Allocate(ELEMS);
    vecC.Allocate(ELEMS);

    vecA = 11.0;
    vecB = 12.0;
    vecC = 13.0;

    // # 1

    EXPECT_TRUE(vecA == 11.0);
    EXPECT_TRUE(vecB == 12.0);
    EXPECT_TRUE(vecC == 13.0);
}

//===========//
// test # 45 //
//===========//

TEST(VectorTest45, op_plus) {
    VectorDense<double> vecA;
    VectorDense<double> vecB;
    VectorDense<double> vecC;

    const int ELEMS = 100;

    vecA.Allocate(ELEMS);
    vecB.Allocate(ELEMS);
    vecC.Allocate(ELEMS);

    vecA = 11.0;
    vecB = 12.0;
    vecC = 13.0;

    // # 1

    EXPECT_TRUE(vecA + vecB == 11.0 + 12.0);
    EXPECT_TRUE(vecB + vecA == 12.0 + 11.0);
    EXPECT_TRUE(vecC + vecA + vecB == 13.0 + 12.0 + 11.0);
}

//===========//
// test # 46 //
//===========//

TEST(VectorTest46, op_times) {
    VectorDense<double> vecA;
    VectorDense<double> vecB;
    VectorDense<double> vecC;

    const int ELEMS = 100;

    vecA.Allocate(ELEMS);
    vecB.Allocate(ELEMS);
    vecC.Allocate(ELEMS);

    vecA = 11.0;
    vecB = 12.0;
    vecC = 13.0;

    // # 1

    EXPECT_TRUE(vecA * vecB == 11.0 * 12.0);
    EXPECT_TRUE(vecB * vecA == 12.0 * 11.0);
    EXPECT_TRUE(vecC * vecA * vecB == 13.0 * 12.0 * 11.0);
}

//===========//
// test # 47 //
//===========//

TEST(VectorTest47, op_divide) {
    VectorDense<double> vecA;
    VectorDense<double> vecB;
    VectorDense<double> vecC;

    const int ELEMS = 100;

    vecA.Allocate(ELEMS);
    vecB.Allocate(ELEMS);
    vecC.Allocate(ELEMS);

    vecA = 11.0;
    vecB = 12.0;
    vecC = 13.0;

    // # 1

    EXPECT_TRUE(vecA / vecB == 11.0 / 12.0);
    EXPECT_TRUE(vecB / vecA == 12.0 / 11.0);
    EXPECT_TRUE(vecC / vecA / vecB == 13.0 / 11.0 / 12.0);
}

//===========//
// test # 48 //
//===========//

TEST(VectorTest48, op_subtract) {
    VectorDense<double> vecA;
    VectorDense<double> vecB;
    VectorDense<double> vecC;

    const int ELEMS = 100;

    vecA.Allocate(ELEMS);
    vecB.Allocate(ELEMS);
    vecC.Allocate(ELEMS);

    vecA = 11.0;
    vecB = 12.0;
    vecC = 13.0;

    // # 1

    EXPECT_TRUE(vecA - vecB == 11.0 - 12.0);
    EXPECT_TRUE(vecB - vecA == 12.0 - 11.0);
    EXPECT_TRUE(vecC - vecA - vecB == 13.0 - 11.0 - 12.0);
}

//===========//
// test # 49 //
//===========//

TEST(VectorTest49, op_all) {
    VectorDense<double> vecA;
    VectorDense<double> vecB;
    VectorDense<double> vecC;

    const int ELEMS = 100;

    vecA.Allocate(ELEMS);
    vecB.Allocate(ELEMS);
    vecC.Allocate(ELEMS);

    vecA = 11.0;
    vecB = 12.0;
    vecC = 13.0;

    // # 1

    EXPECT_TRUE(vecA - vecB + vecA / vecC * vecB == 11.0 - 12.0 + 11.0 / 13.0 * 12.0);
}

//===========//
// test # 50 //
//===========//

TEST(VectorTest50, op_all) {
    VectorDense<double> vecA;
    VectorDense<double> vecB;
    VectorDense<double> vecC;

    const int ELEMS = 100;

    vecA.Allocate(ELEMS);
    vecB.Allocate(ELEMS);
    vecC.Allocate(ELEMS);

    vecA = 11.0;
    vecB = 12.0;
    vecC = 13.0;

    vecA = vecA / vecA / vecA / vecA / vecA;
    vecB = vecB / vecB / vecB / vecB / vecB;
    vecC = vecC / vecC / vecC / vecC / vecC;

    // # 1

    EXPECT_TRUE(vecA == 11.0 / 11.0 / 11.0 / 11.0 / 11.0);
    EXPECT_TRUE(vecB == 12.0 / 12.0 / 12.0 / 12.0 / 12.0);
    EXPECT_TRUE(vecC == 13.0 / 13.0 / 13.0 / 13.0 / 13.0);
}

//===========//
// test # 51 //
//===========//

TEST(VectorTest51, op_various) {
    VectorDense<double> vecA;
    VectorDense<double> vecB;
    VectorDense<double> vecC;

    const int ELEMS = 100;

    vecA.Allocate(ELEMS);
    vecB.Allocate(ELEMS);
    vecC.Allocate(ELEMS);

    vecA = 11.0;
    vecB = 12.0;
    vecC = 13.0;

    vecA = vecA / vecA / vecA / vecA / vecA;
    vecB = vecB / vecB / vecB / vecB / vecB;
    vecC = vecC / vecC / vecC / vecC / vecC;

    // # 1

    EXPECT_FALSE(vecA != 11.0 / 11.0 / 11.0 / 11.0 / 11.0);
    EXPECT_FALSE(vecB != 12.0 / 12.0 / 12.0 / 12.0 / 12.0);
    EXPECT_FALSE(vecC != 13.0 / 13.0 / 13.0 / 13.0 / 13.0);
}

//===========//
// test # 52 //
//===========//

TEST(VectorTest52, op_various) {
    VectorDense<double> vecA;
    VectorDense<double> vecB;
    VectorDense<double> vecC;

    const int ELEMS = 100;

    vecA.Allocate(ELEMS);
    vecB.Allocate(ELEMS);
    vecC.Allocate(ELEMS);

    vecA = 11.0;
    vecB = 12.0;
    vecC = 13.0;

    vecA += vecA;
    vecB += vecB;
    vecC += vecC;

    // # 1

    EXPECT_TRUE(vecA == 11.0 + 11.0);
    EXPECT_TRUE(vecB == 12.0 + 12.0);
    EXPECT_TRUE(vecC == 13.0 + 13.0);

    EXPECT_FALSE(vecA != 11.0 + 11.0);
    EXPECT_FALSE(vecB != 12.0 + 12.0);
    EXPECT_FALSE(vecC != 13.0 + 13.0);
}

//===========//
// test # 53 //
//===========//

TEST(VectorTest53, op_various) {
    VectorDense<double> vecA;
    VectorDense<double> vecB;
    VectorDense<double> vecC;

    const int ELEMS = 100;

    vecA.Allocate(ELEMS);
    vecB.Allocate(ELEMS);
    vecC.Allocate(ELEMS);

    vecA = 11.0;
    vecB = 12.0;
    vecC = 13.0;

    vecA /= vecA;
    vecB /= vecB;
    vecC /= vecC;

    // # 1

    EXPECT_TRUE(vecA == 11.0 / 11.0);
    EXPECT_TRUE(vecB == 12.0 / 12.0);
    EXPECT_TRUE(vecC == 13.0 / 13.0);

    EXPECT_FALSE(vecA != 11.0 / 11.0);
    EXPECT_FALSE(vecB != 12.0 / 12.0);
    EXPECT_FALSE(vecC != 13.0 / 13.0);
}

//===========//
// test # 54 //
//===========//

TEST(VectorTest54, op_various) {
    VectorDense<double> vecA;
    VectorDense<double> vecB;
    VectorDense<double> vecC;

    const int ELEMS = 100;

    vecA.Allocate(ELEMS);
    vecB.Allocate(ELEMS);
    vecC.Allocate(ELEMS);

    vecA = 11.0;
    vecB = 12.0;
    vecC = 13.0;

    vecA *= vecA;
    vecB *= vecB;
    vecC *= vecC;

    // # 1

    EXPECT_TRUE(vecA == 11.0 * 11.0);
    EXPECT_TRUE(vecB == 12.0 * 12.0);
    EXPECT_TRUE(vecC == 13.0 * 13.0);

    EXPECT_FALSE(vecA != 11.0 * 11.0);
    EXPECT_FALSE(vecB != 12.0 * 12.0);
    EXPECT_FALSE(vecC != 13.0 * 13.0);
}

//===========//
// test # 55 //
//===========//

TEST(VectorTest55, op_various) {
    VectorDense<double> vecA;
    VectorDense<double> vecB;
    VectorDense<double> vecC;

    const int ELEMS = 100;

    vecA.Allocate(ELEMS);
    vecB.Allocate(ELEMS);
    vecC.Allocate(ELEMS);

    vecA = 11.0;
    vecB = 12.0;
    vecC = 13.0;

    vecA -= vecA;
    vecB -= vecB;
    vecC -= vecC;

    // # 1

    EXPECT_TRUE(vecA == 11.0 - 11.0);
    EXPECT_TRUE(vecB == 12.0 - 12.0);
    EXPECT_TRUE(vecC == 13.0 - 13.0);

    EXPECT_FALSE(vecA != 11.0 - 11.0);
    EXPECT_FALSE(vecB != 12.0 - 12.0);
    EXPECT_FALSE(vecC != 13.0 - 13.0);
}

//===========//
// test # 56 //
//===========//

TEST(VectorTest56, SlowWayA) {
    // local parameters

    const auto DIM = 1 * static_cast<pgg::MAI_MAX>(pow(10.0, 2.0));
    const auto K_MAX_LOC = 10;
    const auto ONE_DOUBLE = 1.0;
    const auto TWO_DOUBLE = 2.0;
    const auto THREE_DOUBLE = 3.0;

    VectorDense<double> vecA;
    VectorDense<double> vecB;
    VectorDense<double> vecC;

    // allocate heap space

    vecA.Allocate(DIM);
    vecB.Allocate(DIM);
    vecC.Allocate(DIM);

    // build vectors

    vecA = ONE_DOUBLE;
    vecB = TWO_DOUBLE;
    vecC = THREE_DOUBLE;

    // test equality

    EXPECT_TRUE(vecA == ONE_DOUBLE);
    EXPECT_TRUE(vecB == TWO_DOUBLE);
    EXPECT_TRUE(vecC == THREE_DOUBLE);

    // add vectors

    for (int i = 0; i != K_MAX_LOC; ++i) {
        vecC = vecA + vecB;
    }

    EXPECT_TRUE(vecA == ONE_DOUBLE);
    EXPECT_TRUE(vecB == TWO_DOUBLE);
    EXPECT_TRUE(vecC == THREE_DOUBLE);

    // subtract vectors

    for (int i = 0; i != K_MAX_LOC; ++i) {
        vecC = vecA - vecB;
    }

    EXPECT_TRUE(vecA == ONE_DOUBLE);
    EXPECT_TRUE(vecB == TWO_DOUBLE);
    EXPECT_TRUE(vecC == -ONE_DOUBLE);

    // multiply vectors

    for (int i = 0; i != K_MAX_LOC; ++i) {
        vecC = vecA * vecB;
    }

    EXPECT_TRUE(vecA == ONE_DOUBLE);
    EXPECT_TRUE(vecB == TWO_DOUBLE);
    EXPECT_TRUE(vecC == TWO_DOUBLE);

    // divide vectors

    for (int i = 0; i != K_MAX_LOC; ++i) {
        vecC = vecA / vecB;
    }

    EXPECT_TRUE(vecA == ONE_DOUBLE);
    EXPECT_TRUE(vecB == TWO_DOUBLE);
    EXPECT_TRUE(vecC == (ONE_DOUBLE / TWO_DOUBLE));

    // swap vectors

    for (int i = 0; i != K_MAX_LOC; ++i) {

        vecA = ONE_DOUBLE;
        vecB = TWO_DOUBLE;
        vecC = THREE_DOUBLE;

        vecA = vecB;
        vecB = vecC;
        vecC = ONE_DOUBLE;
    }

    EXPECT_TRUE(vecA == TWO_DOUBLE);
    EXPECT_TRUE(vecB == THREE_DOUBLE);
    EXPECT_TRUE(vecC == ONE_DOUBLE);

    // advance vectors

    vecA = ONE_DOUBLE;
    vecB = TWO_DOUBLE;
    vecC = THREE_DOUBLE;

    for (int i = 0; i != K_MAX_LOC; ++i) {
        vecA = vecA + ONE_DOUBLE;
        vecB = vecB + ONE_DOUBLE;
        vecC = vecC + ONE_DOUBLE;
    }

    EXPECT_TRUE(vecA == (ONE_DOUBLE + ONE_DOUBLE * K_MAX_LOC));
    EXPECT_TRUE(vecB == (TWO_DOUBLE + ONE_DOUBLE * K_MAX_LOC));
    EXPECT_TRUE(vecC == (THREE_DOUBLE + ONE_DOUBLE * K_MAX_LOC));

    // advance vectors

    vecA = ONE_DOUBLE;
    vecB = TWO_DOUBLE;
    vecC = THREE_DOUBLE;

    for (int i = 0; i != K_MAX_LOC; ++i) {
        vecA = vecA - ONE_DOUBLE;
        vecB = vecB - ONE_DOUBLE;
        vecC = vecC - ONE_DOUBLE;
    }

    EXPECT_TRUE(vecA == (ONE_DOUBLE - ONE_DOUBLE * K_MAX_LOC));
    EXPECT_TRUE(vecB == (TWO_DOUBLE - ONE_DOUBLE * K_MAX_LOC));
    EXPECT_TRUE(vecC == (THREE_DOUBLE - ONE_DOUBLE * K_MAX_LOC));

    // advance vectors

    vecA = ONE_DOUBLE;
    vecB = TWO_DOUBLE;
    vecC = THREE_DOUBLE;

    for (int i = 0; i != K_MAX_LOC; ++i) {
        vecA = vecA * ONE_DOUBLE;
        vecB = vecB * ONE_DOUBLE;
        vecC = vecC * ONE_DOUBLE;
    }

    EXPECT_TRUE(vecA == ONE_DOUBLE);
    EXPECT_TRUE(vecB == TWO_DOUBLE);
    EXPECT_TRUE(vecC == THREE_DOUBLE);

    // advance vectors

    vecA = ONE_DOUBLE;
    vecB = TWO_DOUBLE;
    vecC = THREE_DOUBLE;

    for (int i = 0; i != K_MAX_LOC; ++i) {
        vecA = vecA / ONE_DOUBLE;
        vecB = vecB / ONE_DOUBLE;
        vecC = vecC / ONE_DOUBLE;
    }

    EXPECT_TRUE(vecA == ONE_DOUBLE);
    EXPECT_TRUE(vecB == TWO_DOUBLE);
    EXPECT_TRUE(vecC == THREE_DOUBLE);

    // advance vectors

    vecA = ONE_DOUBLE;
    vecB = TWO_DOUBLE;
    vecC = THREE_DOUBLE;

    for (int i = 0; i != K_MAX_LOC; ++i) {
        vecA = vecA + vecA;
        vecB = vecB + vecB;
        vecC = vecC + vecC;
    }

    EXPECT_TRUE(vecA == 1.0 * pow(TWO_DOUBLE, K_MAX_LOC));
    EXPECT_TRUE(vecB == 2.0 * pow(TWO_DOUBLE, K_MAX_LOC));
    EXPECT_TRUE(vecC == 3.0 * pow(TWO_DOUBLE, K_MAX_LOC));

    // advance vectors

    vecA = ONE_DOUBLE;
    vecB = TWO_DOUBLE;
    vecC = THREE_DOUBLE;

    for (int i = 0; i != K_MAX_LOC; ++i) {
        vecA = vecA - vecA;
        vecB = vecB - vecB;
        vecC = vecC - vecC;
    }

    EXPECT_TRUE(vecA == pgg::ZERO_DBL);
    EXPECT_TRUE(vecB == pgg::ZERO_DBL);
    EXPECT_TRUE(vecC == pgg::ZERO_DBL);

    // advance vectors

    vecA = ONE_DOUBLE;
    vecB = TWO_DOUBLE;
    vecC = THREE_DOUBLE;

    for (int i = 0; i != K_MAX_LOC; ++i) {
        vecA = vecA / vecA;
        vecB = vecB / vecB;
        vecC = vecC / vecC;
    }

    EXPECT_TRUE(vecA == pgg::ONE_DBL);
    EXPECT_TRUE(vecB == pgg::ONE_DBL);
    EXPECT_TRUE(vecC == pgg::ONE_DBL);

    // advance vectors

    vecA = ONE_DOUBLE;
    vecB = TWO_DOUBLE;
    vecC = THREE_DOUBLE;

    for (int i = 0; i != K_MAX_LOC; ++i) {
        vecA = vecA * vecA;
        vecB = vecB * vecB;
        vecB = vecB / TWO_DOUBLE;
        vecC = vecC * vecC;
        vecC = vecC / THREE_DOUBLE;
    }

    EXPECT_TRUE(vecA == ONE_DOUBLE);
    EXPECT_TRUE(vecB == TWO_DOUBLE);
    EXPECT_TRUE(vecC == THREE_DOUBLE);

    // deallocate heap space

    vecA.Deallocate();
    vecB.Deallocate();
    vecC.Deallocate();
}

//===========//
// test # 57 //
//===========//

TEST(VectorTest57, GreaterAll) {
    VectorDense<double> vecA;
    VectorDense<double> vecB;

    const int ELEM = 100;

    vecA.Allocate(ELEM);
    vecB.Allocate(ELEM);

    vecA.Range(1.0, 2.0);
    vecB.Range(2.0, 4.0);

    EXPECT_TRUE(vecB > vecA);
    EXPECT_TRUE(vecB >= vecA);
}

//===========//
// test # 58 //
//===========//

TEST(VectorTest58, LessAll) {
    VectorDense<double> vecA;
    VectorDense<double> vecB;

    const int ELEM = 100;

    vecA.Allocate(ELEM);
    vecB.Allocate(ELEM);

    vecB.Range(1.0, 2.0);
    vecA.Range(2.0, 4.0);

    EXPECT_TRUE(vecB < vecA);
    EXPECT_TRUE(vecB <= vecA);
}

//===========//
// test # 59 //
//===========//

TEST(VectorTest59, GreaterAll) {
    VectorDense<double> vecA;

    const int ELEM = 100;

    vecA.Allocate(ELEM);

    vecA.Range(1.0, 2.0);

    EXPECT_TRUE(vecA >= -1.0);
    EXPECT_TRUE(vecA >= 1.0);
}

//===========//
// test # 60 //
//===========//

TEST(VectorTest60, LessAll) {
    VectorDense<double> vecA;

    const int ELEM = 100;

    vecA.Allocate(ELEM);

    vecA.Range(3.0, 4.0);

    EXPECT_TRUE(vecA < 4.001);
    EXPECT_TRUE(vecA <= 4.0);

    vecA.Set(10.0);

    EXPECT_TRUE(vecA <= 10.0);
    EXPECT_TRUE(vecA >= 10.0);
    EXPECT_TRUE(vecA == 10.0);
}

//===========//
// test # 61 //
//===========//

TEST(VectorTest61, LessAll) {
    VectorDense<double> vecA;
    VectorDense<double> vecB;

    const int ELEM = 100;

    vecA.Allocate(ELEM);
    vecB.Allocate(ELEM);

    vecA.Range(3.0, 4.0);
    vecB.Range(3.0, 5.0);

    EXPECT_TRUE(vecA <= vecB);
    EXPECT_FALSE(vecA < vecB);

    EXPECT_TRUE(vecA >= 3.0);
    EXPECT_FALSE(vecA > 3.0);
    EXPECT_FALSE(vecA < 3.0);
    EXPECT_FALSE(vecA <= 3.0);

    EXPECT_TRUE(vecA != vecB);
    EXPECT_FALSE(vecA == vecB);
}

//===========//
// test # 62 //
//===========//

TEST(VectorTest62, sinSin) {
    VectorDense<long double> vecA;
    VectorDense<long double> vecB;

    const int ELEM = 100;
    const auto VAL_A = 11.11111L;
    const auto VAL_B = 12.345678901234567890123456789L;

    vecA.Allocate(ELEM);
    vecB.Allocate(ELEM);

    vecA.Set(VAL_A);
    vecB.Set(VAL_B);

    EXPECT_EQ(vecA, VAL_A);
    EXPECT_EQ(vecB, VAL_B);

    vecA.Set(sin(VAL_A));
    vecB.Set(Sin < long
    double > (VAL_A));

    EXPECT_TRUE(vecA.Equal(vecA, std::pow(10.0, -14.0)));
    EXPECT_TRUE(abs(sin(VAL_A) - Sin < long
                        double > (VAL_A)) < std::pow(10.0, -14.0));
    EXPECT_EQ(vecB, Sin < long
            double > (VAL_A));
    EXPECT_EQ(vecA, sin(VAL_A));

    EXPECT_TRUE(vecA.Equal(vecB));
    EXPECT_TRUE(abs(sin(VAL_A) - Sin < long
                        double > (VAL_A)) < std::pow(10.0, -20.0));
    EXPECT_EQ(vecA, Sin < long
            double > (VAL_A));
    EXPECT_EQ(vecB, sin(VAL_A));
}

//===========//
// test # 63 //
//===========//

TEST(VectorTest63, cosCos) {
    VectorDense<long double> vecA;
    VectorDense<long double> vecB;

    const int ELEM = 100;
    const auto VAL_A = 11.0L;
    const auto VAL_B = 12.0L;

    vecA.Allocate(ELEM);
    vecB.Allocate(ELEM);

    vecA.Set(VAL_A);
    vecB.Set(VAL_B);

    EXPECT_EQ(vecA, VAL_A);
    EXPECT_EQ(vecB, VAL_B);

    vecA.Set(cos(VAL_A));
    vecB.Set(Cos < long
    double > (VAL_A));

    EXPECT_TRUE(vecA.Equal(vecB, std::pow(10.0, -14.0)));
    EXPECT_TRUE(abs(cos(VAL_A) - Cos(VAL_A)) <= std::pow(10.0, -14.0));
    EXPECT_EQ(vecB, Cos < long
            double > (VAL_A));
    EXPECT_EQ(vecA, cos(VAL_A));

    EXPECT_TRUE(abs(cos(VAL_A) - Cos(VAL_A)) <= std::pow(10.0, -16.0));
}

//===========//
// test # 64 //
//===========//

TEST(VectorTest64, RealImaginaryPart1) {
    VectorDense <complex<double>> vecA;
    VectorDense<double> vecB;
    VectorDense<double> vecC;
    const int K_MAX = 10;

    // allocations

    const pgg::VEI ELEMS = 5 * static_cast<pgg::VEI>(pow(10.0, 6.0));

    vecA.Allocate(ELEMS);
    vecB.Allocate(ELEMS);
    vecC.Allocate(ELEMS);

    vecA = {-1.23456, +3.45678};

    for (int k = 0; k != K_MAX; ++k) {
        vecB.RealPart(vecA);
        vecC.ImaginaryPart(vecA);
    }

    EXPECT_TRUE(vecB == -1.23456);
    EXPECT_TRUE(vecC == +3.45678);
}

//===========//
// test # 65 //
//===========//

TEST(VectorTest65, RealImaginaryPart2) {
    VectorDense <complex<double>> vecA;
    VectorDense<double> vecB;
    VectorDense<double> vecC;
    const int K_MAX = 10;

    // allocations

    const pgg::VEI ELEMS = 5 * static_cast<pgg::VEI>(pow(10.0, 6.0));

    vecA.Allocate(ELEMS);
    vecB.Allocate(ELEMS);
    vecC.Allocate(ELEMS);

    // build vector

    for (pgg::VEI_MAX i = 0; i != ELEMS; ++i) {
        const complex<double> tmp_elem = {static_cast<double>(i),
                                          static_cast<double>(i)
        };

        vecA.SetElement(i, tmp_elem);
    }

    // get real and imaginary parts

    for (int k = 0; k != K_MAX; ++k) {
        vecB.RealPart(vecA);
        vecC.ImaginaryPart(vecA);
    }

    // test

    for (pgg::VEI_MAX i = 0; i != ELEMS; ++i) {
        EXPECT_TRUE(vecB(i) == static_cast<double>(i));
        EXPECT_TRUE(vecC(i) == static_cast<double>(i));
    }
}

//===========//
// test # 66 //
//===========//

TEST(VectorTest66, DotComplex) {
    VectorDense <complex<double>> vecA;
    VectorDense <complex<double>> vecB;

    const int ELEMS = 100;

    vecA.Allocate(ELEMS);
    vecB.Allocate(ELEMS);

    vecA = 1.234;
    vecB = 2.345;

    complex<double> tmp_double = vecA.Dot(vecB);

    EXPECT_TRUE((1.234 * 2.345 * 100.0 - std::real(tmp_double)) < pow(10.0, -14.0));
}

//===========//
// test # 67 //
//===========//

TEST(VectorTest67, DotComplex) {
    VectorDense <complex<double>> vecA;
    VectorDense <complex<double>> vecB;

    EXPECT_TRUE(vecA.DeallocatedQ());
    EXPECT_TRUE(vecB.DeallocatedQ());

    const int ELEMS = 10000;

    vecA.Allocate(ELEMS);
    vecB.Allocate(ELEMS);

    EXPECT_TRUE(vecA.AllocatedQ());
    EXPECT_TRUE(vecB.AllocatedQ());

    vecA = {1.0, 2.0};
    vecB = {2.0, 3.0};

    complex<double> tmp_cmplxA = vecA.Dot(vecB);
    complex<double> tmp_cmplxB;

    complex<double> tmpA = {1.0, 2.0};
    complex<double> tmpB = {2.0, 3.0};

    tmp_cmplxB = {0.0, 0.0};

    for (int i = 0; i != ELEMS; ++i) {
        tmp_cmplxB = tmp_cmplxB + tmpA * tmpB;
    }

    EXPECT_TRUE(std::real((tmp_cmplxA - tmp_cmplxB)) < pow(10.0, -10.0));
    EXPECT_TRUE(std::imag((tmp_cmplxA - tmp_cmplxB)) < pow(10.0, -10.0));
}

//===========//
// test # 68 //
//===========//

TEST(VectorTest68, DotComplex) {
    VectorDense <complex<double>> vecA;
    VectorDense <complex<double>> vecB;

    EXPECT_TRUE(vecA.DeallocatedQ());
    EXPECT_TRUE(vecB.DeallocatedQ());

    const int ELEMS = 10000;

    vecA.Allocate(ELEMS);
    vecB.Allocate(ELEMS);

    EXPECT_TRUE(vecA.AllocatedQ());
    EXPECT_TRUE(vecB.AllocatedQ());

    for (int i = 0; i != ELEMS; ++i) {
        vecA.SetElement(i, sin(static_cast<complex<double>>(i)));
        vecB.SetElement(i, cos(static_cast<complex<double>>(i)));
    }

    complex<double> tmp_cmplxA = vecA.Dot(vecB);
    const complex<double> tmp_cmplxB = -0.11551041567000858692;

    EXPECT_TRUE(std::real(tmp_cmplxA - tmp_cmplxB) < pow(10.0, -14.0));
}

//===========//
// test # 69 //
//===========//

TEST(VectorTest69, DotComplex) {
    VectorDense <complex<double>> vecA;
    VectorDense <complex<double>> vecB;
    MatrixDense <complex<double>> matA;

    EXPECT_TRUE(vecA.DeallocatedQ());
    EXPECT_TRUE(vecB.DeallocatedQ());
    EXPECT_TRUE(matA.DeallocatedQ());

    const int ELEMS_A = 10;
    const int ELEMS_B = 1000;

    vecA.Allocate(ELEMS_A);
    vecB.Allocate(ELEMS_B);
    matA.Allocate(ELEMS_A, ELEMS_B);

    EXPECT_TRUE(vecA.AllocatedQ());
    EXPECT_TRUE(vecB.AllocatedQ());
    EXPECT_TRUE(matA.AllocatedQ());

    for (int i = 0; i != ELEMS_B; ++i) {
        vecB.SetElement(i, sin(static_cast<complex<double>>(i)));
    }

    for (int i = 0; i != ELEMS_B * ELEMS_A; ++i) {
        matA.SetElement(i, cos(static_cast<complex<double>>(i)));
    }

    vecA.Dot(matA, vecB);

    const double corr[ELEMS_A] = {
            -0.013000956337400969716, -413.04095342736712548,
            -464.55817876109059451, -109.47464548253968530,
            341.42567875364489603, 493.49596116134191391,
            213.63792682857131289, -253.20496126031645456,
            -498.43227128017131844, -307.41079937172321604
    };

    for (int i = 0; i != ELEMS_A; ++i) {
        EXPECT_TRUE((corr[i] - std::real(vecA[i])) < pow(10.0, -10.0));
    }
}

//===========//
// test # 70 //
//===========//

TEST(VectorTest70, DotComplex) {
    VectorDense <complex<double>> vecA;
    VectorDense <complex<double>> vecB;
    MatrixDense <complex<double>> matA;

    EXPECT_TRUE(vecA.DeallocatedQ());
    EXPECT_TRUE(vecB.DeallocatedQ());
    EXPECT_TRUE(matA.DeallocatedQ());

    const int ELEMS_A = 10;
    const int ELEMS_B = 1000;

    vecA.Allocate(ELEMS_A);
    vecB.Allocate(ELEMS_B);
    matA.Allocate(ELEMS_A, ELEMS_B);

    EXPECT_TRUE(vecA.AllocatedQ());
    EXPECT_TRUE(vecB.AllocatedQ());
    EXPECT_TRUE(matA.AllocatedQ());

    for (int i = 0; i != ELEMS_B; ++i) {
        vecB.SetElement(i, sin(static_cast<complex<double>>(i)));
    }

    for (int i = 0; i != ELEMS_B * ELEMS_A; ++i) {
        matA.SetElement(i, cos(static_cast<complex<double>>(i)));
    }

    vecA.Dot(matA, vecB, "WithRows");

    const double corr[ELEMS_A] = {
            -0.013000956337400969716, -413.04095342736712548,
            -464.55817876109059451, -109.47464548253968530,
            341.42567875364489603, 493.49596116134191391,
            213.63792682857131289, -253.20496126031645456,
            -498.43227128017131844, -307.41079937172321604
    };

    for (int i = 0; i != ELEMS_A; ++i) {
        EXPECT_TRUE((corr[i] - std::real(vecA[i])) < pow(10.0, -10.0));
    }
}

//===========//
// test # 71 //
//===========//

TEST(VectorTest71, DotComplex) {
    VectorDense <complex<double>> vecA;
    VectorDense <complex<double>> vecB;
    MatrixDense <complex<double>> matA;

    EXPECT_TRUE(vecA.DeallocatedQ());
    EXPECT_TRUE(vecB.DeallocatedQ());
    EXPECT_TRUE(matA.DeallocatedQ());

    const int ELEMS_A = 10;
    const int ELEMS_B = 10;

    vecA.Allocate(ELEMS_A);
    vecB.Allocate(ELEMS_B);
    matA.Allocate(ELEMS_A, ELEMS_B);

    EXPECT_TRUE(vecA.AllocatedQ());
    EXPECT_TRUE(vecB.AllocatedQ());
    EXPECT_TRUE(matA.AllocatedQ());

    for (int i = 0; i != ELEMS_B; ++i) {
        vecB.SetElement(i, sin(static_cast<complex<double>>(i)));
    }

    for (int i = 0; i != ELEMS_B * ELEMS_A; ++i) {
        matA.SetElement(i, cos(static_cast<complex<double>>(i)));
    }

    // # 1

    vecA.Dot(matA, vecB, "WithColumns");

    const double corr[ELEMS_A] = {
            -0.3454781443936671, -0.1019678318253387, 0.2352912350744567,
            0.3562246255479217, 0.1496467381066567, -0.1945156702185772,
            -0.3598412683998245, -0.1943304639073055, 0.1498468729007396,
            0.3562556858181048
    };

    for (int i = 0; i != ELEMS_A; ++i) {
        EXPECT_TRUE((corr[i] - std::real(vecA[i])) < pow(10.0, -10.0));
    }
}

//===========//
// test # 72 //
//===========//

TEST(VectorTest72, DotComplex) {
    MatrixDense <complex<double>> matA;
    MatrixDense <complex<double>> matB;
    MatrixDense <complex<double>> matC;

    const pgg::MAI DIM = 100;

    matA.Allocate(DIM);
    matB.Allocate(DIM);
    matC.Allocate(DIM);

    // build

    matC = {0.0, 0.0};

    for (pgg::MAI i = 0; i != DIM; ++i) {
        for (pgg::MAI j = 0; j != DIM; ++j) {
            complex<double> tmp_cmplxA = {static_cast<double>(i),
                                          static_cast<double>(j)
            };

            complex<double> tmp_cmplxB = {sin(static_cast<double>(i)),
                                          cos(static_cast<double>(j))
            };

            matA.SetElement(i, j, tmp_cmplxA);
            matB.SetElement(i, j, tmp_cmplxB);
        }
    }

    // # 1

    matC.Dot(matA, matB);

    const complex<double> corr[DIM] = {complex<double>(-4950., -54.1556827284055),
                                       complex<double>(-2674.4964140472916,
                                                       -54.1556827284055),
                                       complex<double>(2059.9268409083543,
                                                       -54.1556827284055),
                                       complex<double>(4900.4628581722045,
                                                       -54.1556827284055),
                                       complex<double>(3235.5359232748788,
                                                       -54.1556827284055),
                                       complex<double>(-1404.1278180429697,
                                                       -54.1556827284055),
                                       complex<double>(-4752.842918919313,
                                                       -54.1556827284055),
                                       complex<double>(-3731.816158999358,
                                                       -54.1556827284055),
                                       complex<double>(720.2251673526373,
                                                       -54.1556827284055),
                                       complex<double>(4510.094796329151,
                                                       -54.1556827284055),
                                       complex<double>(4153.404068928439,
                                                       -54.1556827284055),
                                       complex<double>(-21.90720504085138,
                                                       -54.1556827284055),
                                       complex<double>(-4177.0770957258355,
                                                       -54.1556827284055),
                                       complex<double>(-4491.861568178471,
                                                       -54.1556827284055),
                                       complex<double>(-676.8492301287763,
                                                       -54.1556827284055),
                                       complex<double>(3760.4551686511654,
                                                       -54.1556827284055),
                                       complex<double>(4740.414427600754,
                                                       -54.1556827284055),
                                       complex<double>(1362.0585233554048,
                                                       -54.1556827284055),
                                       complex<double>(-3268.5677058081965,
                                                       -54.1556827284055),
                                       complex<double>(-4894.087860024013,
                                                       -54.1556827284055),
                                       complex<double>(-2020.0062059762902,
                                                       -54.1556827284055),
                                       complex<double>(2711.2598381101284,
                                                       -54.1556827284055),
                                       complex<double>(4949.806090653454,
                                                       -54.1556827284055),
                                       complex<double>(2637.523450650318,
                                                       -54.1556827284055),
                                       complex<double>(-2099.6860863181355,
                                                       -54.1556827284055),
                                       complex<double>(-4906.4539187241935,
                                                       -54.1556827284055),
                                       complex<double>(-3202.25064552677,
                                                       -54.1556827284055),
                                       complex<double>(1446.087103232489,
                                                       -54.1556827284055),
                                       complex<double>(4764.899038252153,
                                                       -54.1556827284055),
                                       complex<double>(3702.8847719605515,
                                                       -54.1556827284055),
                                       complex<double>(-763.544676943541,
                                                       -54.1556827284055),
                                       complex<double>(-4527.97467113243,
                                                       -54.1556827284055),
                                       complex<double>(-4129.405634507225,
                                                       -54.1556827284055),
                                       complex<double>(65.71989875414442,
                                                       -54.1556827284055),
                                       complex<double>(4200.422860183797,
                                                       -54.1556827284055),
                                       complex<double>(4473.276415202959,
                                                       -54.1556827284055),
                                       complex<double>(633.4202636556531,
                                                       -54.1556827284055),
                                       complex<double>(-3788.7995571294496,
                                                       -54.1556827284055),
                                       complex<double>(-4727.6145380341095,
                                                       -54.1556827284055),
                                       complex<double>(-1319.8825151816895,
                                                       -54.1556827284055),
                                       complex<double>(3301.3434051786967,
                                                       -54.1556827284055),
                                       complex<double>(4887.329423742941,
                                                       -54.1556827284055),
                                       complex<double>(1979.9273091923387,
                                                       -54.1556827284055),
                                       complex<double>(-2747.8108425270966,
                                                       -54.1556827284055),
                                       complex<double>(-4949.224377806071,
                                                       -54.1556827284055),
                                       complex<double>(-2600.34384464776,
                                                       -54.1556827284055),
                                       complex<double>(2139.280827179652,
                                                       -54.1556827284055),
                                       complex<double>(4912.060572297103,
                                                       -54.1556827284055),
                                       complex<double>(3168.7144803725387,
                                                       -54.1556827284055),
                                       complex<double>(-1487.9330915310034,
                                                       -54.1556827284055),
                                       complex<double>(-4776.581841035962,
                                                       -54.1556827284055),
                                       complex<double>(-3673.663274228223,
                                                       -54.1556827284055),
                                       complex<double>(806.8043649387419,
                                                       -54.1556827284055),
                                       complex<double>(4545.499791749989,
                                                       -54.1556827284055),
                                       complex<double>(4105.083672672596,
                                                       -54.1556827284055),
                                       complex<double>(-109.52744349668089,
                                                       -54.1556827284055),
                                       complex<double>(-4223.439533226792,
                                                       -54.1556827284055),
                                       complex<double>(-4454.340793497509,
                                                       -54.1556827284055),
                                       complex<double>(-589.9416704716555,
                                                       -54.1556827284055),
                                       complex<double>(3816.8471037304334,
                                                       -54.1556827284055),
                                       complex<double>(4714.444253055023,
                                                       -54.1556827284055),
                                       complex<double>(1277.6030978944239,
                                                       -54.1556827284055),
                                       complex<double>(-3333.860453501752,
                                                       -54.1556827284055),
                                       complex<double>(-4880.18807883362,
                                                       -54.1556827284055),
                                       complex<double>(-1939.6932906262723,
                                                       -54.1556827284055),
                                       complex<double>(2784.146563628951,
                                                       -54.1556827284055),
                                       complex<double>(4948.254907033432,
                                                       -54.1556827284055),
                                       complex<double>(2562.960508958049,
                                                       -54.1556827284055),
                                       complex<double>(-2178.707961355402,
                                                       -54.1556827284055),
                                       complex<double>(-4917.282379625245,
                                                       -54.1556827284055),
                                       complex<double>(-3134.9300552771842,
                                                       -54.1556827284055),
                                       complex<double>(1529.6625044220498,
                                                       -54.1556827284055),
                                       complex<double>(4787.890411955718,
                                                       -54.1556827284055),
                                       complex<double>(3644.1539552252143,
                                                       -54.1556827284055),
                                       complex<double>(-850.0008420623489,
                                                       -54.1556827284055),
                                       complex<double>(-4562.668785137508,
                                                       -54.1556827284055),
                                       complex<double>(-4080.4400889824105,
                                                       -54.1556827284055),
                                       complex<double>(153.3264070695216,
                                                       -54.1556827284055),
                                       complex<double>(4246.12531156269,
                                                       -54.1556827284055),
                                       complex<double>(4435.0561866152675,
                                                       -54.1556827284055),
                                       complex<double>(546.4168570032856,
                                                       -54.1556827284055),
                                       complex<double>(-3844.5956110070747,
                                                       -54.1556827284055),
                                       complex<double>(-4700.9046045185905,
                                                       -54.1556827284055),
                                       complex<double>(-1235.2235839680238,
                                                       -54.1556827284055),
                                       complex<double>(3366.116303157327,
                                                       -54.1556827284055),
                                       complex<double>(4872.664384800508,
                                                       -54.1556827284055),
                                       complex<double>(1899.3073025012227,
                                                       -54.1556827284055),
                                       complex<double>(-2820.2641546132936,
                                                       -54.1556827284055),
                                       complex<double>(-4946.897754290866,
                                                       -54.1556827284055),
                                       complex<double>(-2525.3763724612622,
                                                       -54.1556827284055),
                                       complex<double>(2217.964399839392,
                                                       -54.1556827284055),
                                       complex<double>(4922.118931594598,
                                                       -54.1556827284055),
                                       complex<double>(3100.9000171561775,
                                                       -54.1556827284055),
                                       complex<double>(-1571.2720725225251,
                                                       -54.1556827284055),
                                       complex<double>(-4798.823865016438,
                                                       -54.1556827284055),
                                       complex<double>(-3614.359126924357,
                                                       -54.1556827284055),
                                       complex<double>(893.1307239908655,
                                                       -54.1556827284055),
                                       complex<double>(4579.48030615225,
                                                       -54.1556827284055),
                                       complex<double>(4055.476814192723,
                                                       -54.1556827284055),
                                       complex<double>(-197.11335794603752,
                                                       -54.1556827284055)
    };

    for (int i = 0; i != DIM; ++i) {
        EXPECT_TRUE(std::real(corr[i] - matC(0, i)) < pow(10.0, -10.0));
    }

    for (int i = 0; i != DIM; ++i) {
        EXPECT_TRUE(std::imag(corr[i] - matC(0, i)) < pow(10.0, -6.0));
    }
}

//===========//
// test # 73 //
//===========//

TEST(VectorTest73, DotComplex) {
    MatrixDense <complex<double>> matA;

    const pgg::MAI DIM = 100;

    matA.Allocate(DIM);

    // build

    for (pgg::MAI i = 0; i != DIM; ++i) {
        for (pgg::MAI j = 0; j != DIM; ++j) {

            complex<double> tmp_cmplxA = {static_cast<double>(i),
                                          static_cast<double>(j)
            };

            matA.SetElement(i, j, tmp_cmplxA);
        }
    }

    // # 1

    matA.Dot(matA, matA);

    const complex<double> corr[DIM] = {complex<double>(0., 328350.),
                                       complex<double>(-4950., 328350.),
                                       complex<double>(-9900., 328350.),
                                       complex<double>(-14850., 328350.),
                                       complex<double>(-19800., 328350.),
                                       complex<double>(-24750., 328350.),
                                       complex<double>(-29700., 328350.),
                                       complex<double>(-34650., 328350.),
                                       complex<double>(-39600., 328350.),
                                       complex<double>(-44550., 328350.),
                                       complex<double>(-49500., 328350.),
                                       complex<double>(-54450., 328350.),
                                       complex<double>(-59400., 328350.),
                                       complex<double>(-64350., 328350.),
                                       complex<double>(-69300., 328350.),
                                       complex<double>(-74250., 328350.),
                                       complex<double>(-79200., 328350.),
                                       complex<double>(-84150., 328350.),
                                       complex<double>(-89100., 328350.),
                                       complex<double>(-94050., 328350.),
                                       complex<double>(-99000., 328350.),
                                       complex<double>(-103950., 328350.),
                                       complex<double>(-108900., 328350.),
                                       complex<double>(-113850., 328350.),
                                       complex<double>(-118800., 328350.),
                                       complex<double>(-123750., 328350.),
                                       complex<double>(-128700., 328350.),
                                       complex<double>(-133650., 328350.),
                                       complex<double>(-138600., 328350.),
                                       complex<double>(-143550., 328350.),
                                       complex<double>(-148500., 328350.),
                                       complex<double>(-153450., 328350.),
                                       complex<double>(-158400., 328350.),
                                       complex<double>(-163350., 328350.),
                                       complex<double>(-168300., 328350.),
                                       complex<double>(-173250., 328350.),
                                       complex<double>(-178200., 328350.),
                                       complex<double>(-183150., 328350.),
                                       complex<double>(-188100., 328350.),
                                       complex<double>(-193050., 328350.),
                                       complex<double>(-198000., 328350.),
                                       complex<double>(-202950., 328350.),
                                       complex<double>(-207900., 328350.),
                                       complex<double>(-212850., 328350.),
                                       complex<double>(-217800., 328350.),
                                       complex<double>(-222750., 328350.),
                                       complex<double>(-227700., 328350.),
                                       complex<double>(-232650., 328350.),
                                       complex<double>(-237600., 328350.),
                                       complex<double>(-242550., 328350.),
                                       complex<double>(-247500., 328350.),
                                       complex<double>(-252450., 328350.),
                                       complex<double>(-257400., 328350.),
                                       complex<double>(-262350., 328350.),
                                       complex<double>(-267300., 328350.),
                                       complex<double>(-272250., 328350.),
                                       complex<double>(-277200., 328350.),
                                       complex<double>(-282150., 328350.),
                                       complex<double>(-287100., 328350.),
                                       complex<double>(-292050., 328350.),
                                       complex<double>(-297000., 328350.),
                                       complex<double>(-301950., 328350.),
                                       complex<double>(-306900., 328350.),
                                       complex<double>(-311850., 328350.),
                                       complex<double>(-316800., 328350.),
                                       complex<double>(-321750., 328350.),
                                       complex<double>(-326700., 328350.),
                                       complex<double>(-331650., 328350.),
                                       complex<double>(-336600., 328350.),
                                       complex<double>(-341550., 328350.),
                                       complex<double>(-346500., 328350.),
                                       complex<double>(-351450., 328350.),
                                       complex<double>(-356400., 328350.),
                                       complex<double>(-361350., 328350.),
                                       complex<double>(-366300., 328350.),
                                       complex<double>(-371250., 328350.),
                                       complex<double>(-376200., 328350.),
                                       complex<double>(-381150., 328350.),
                                       complex<double>(-386100., 328350.),
                                       complex<double>(-391050., 328350.),
                                       complex<double>(-396000., 328350.),
                                       complex<double>(-400950., 328350.),
                                       complex<double>(-405900., 328350.),
                                       complex<double>(-410850., 328350.),
                                       complex<double>(-415800., 328350.),
                                       complex<double>(-420750., 328350.),
                                       complex<double>(-425700., 328350.),
                                       complex<double>(-430650., 328350.),
                                       complex<double>(-435600., 328350.),
                                       complex<double>(-440550., 328350.),
                                       complex<double>(-445500., 328350.),
                                       complex<double>(-450450., 328350.),
                                       complex<double>(-455400., 328350.),
                                       complex<double>(-460350., 328350.),
                                       complex<double>(-465300., 328350.),
                                       complex<double>(-470250., 328350.),
                                       complex<double>(-475200., 328350.),
                                       complex<double>(-480150., 328350.),
                                       complex<double>(-485100., 328350.),
                                       complex<double>(-490050., 328350.)
    };

    // test

    for (int i = 0; i != DIM; ++i) {
        EXPECT_TRUE(std::real(corr[i] - matA(0, i)) < pow(10.0, -10.0));
    }

    for (int i = 0; i != DIM; ++i) {
        EXPECT_TRUE(std::imag(corr[i] - matA(0, i)) < pow(10.0, -10.0));
    }

}

//===========//
// test # 74 //
//===========//

TEST(VectorTest74, DotComplex) {
    MatrixDense <complex<double>> matA;

    const pgg::MAI DIM = 100;

    matA.Allocate(DIM);

    // build

    for (pgg::MAI i = 0; i != DIM; ++i) {
        for (pgg::MAI j = 0; j != DIM; ++j) {

            complex<double> tmp_cmplxA = {static_cast<double>(i),
                                          static_cast<double>(j)
            };

            matA.SetElement(i, j, tmp_cmplxA);
        }
    }

    // # 1

    matA.Dot(matA);

    const complex<double> corr[DIM] = {complex<double>(0., 328350.),
                                       complex<double>(-4950., 328350.),
                                       complex<double>(-9900., 328350.),
                                       complex<double>(-14850., 328350.),
                                       complex<double>(-19800., 328350.),
                                       complex<double>(-24750., 328350.),
                                       complex<double>(-29700., 328350.),
                                       complex<double>(-34650., 328350.),
                                       complex<double>(-39600., 328350.),
                                       complex<double>(-44550., 328350.),
                                       complex<double>(-49500., 328350.),
                                       complex<double>(-54450., 328350.),
                                       complex<double>(-59400., 328350.),
                                       complex<double>(-64350., 328350.),
                                       complex<double>(-69300., 328350.),
                                       complex<double>(-74250., 328350.),
                                       complex<double>(-79200., 328350.),
                                       complex<double>(-84150., 328350.),
                                       complex<double>(-89100., 328350.),
                                       complex<double>(-94050., 328350.),
                                       complex<double>(-99000., 328350.),
                                       complex<double>(-103950., 328350.),
                                       complex<double>(-108900., 328350.),
                                       complex<double>(-113850., 328350.),
                                       complex<double>(-118800., 328350.),
                                       complex<double>(-123750., 328350.),
                                       complex<double>(-128700., 328350.),
                                       complex<double>(-133650., 328350.),
                                       complex<double>(-138600., 328350.),
                                       complex<double>(-143550., 328350.),
                                       complex<double>(-148500., 328350.),
                                       complex<double>(-153450., 328350.),
                                       complex<double>(-158400., 328350.),
                                       complex<double>(-163350., 328350.),
                                       complex<double>(-168300., 328350.),
                                       complex<double>(-173250., 328350.),
                                       complex<double>(-178200., 328350.),
                                       complex<double>(-183150., 328350.),
                                       complex<double>(-188100., 328350.),
                                       complex<double>(-193050., 328350.),
                                       complex<double>(-198000., 328350.),
                                       complex<double>(-202950., 328350.),
                                       complex<double>(-207900., 328350.),
                                       complex<double>(-212850., 328350.),
                                       complex<double>(-217800., 328350.),
                                       complex<double>(-222750., 328350.),
                                       complex<double>(-227700., 328350.),
                                       complex<double>(-232650., 328350.),
                                       complex<double>(-237600., 328350.),
                                       complex<double>(-242550., 328350.),
                                       complex<double>(-247500., 328350.),
                                       complex<double>(-252450., 328350.),
                                       complex<double>(-257400., 328350.),
                                       complex<double>(-262350., 328350.),
                                       complex<double>(-267300., 328350.),
                                       complex<double>(-272250., 328350.),
                                       complex<double>(-277200., 328350.),
                                       complex<double>(-282150., 328350.),
                                       complex<double>(-287100., 328350.),
                                       complex<double>(-292050., 328350.),
                                       complex<double>(-297000., 328350.),
                                       complex<double>(-301950., 328350.),
                                       complex<double>(-306900., 328350.),
                                       complex<double>(-311850., 328350.),
                                       complex<double>(-316800., 328350.),
                                       complex<double>(-321750., 328350.),
                                       complex<double>(-326700., 328350.),
                                       complex<double>(-331650., 328350.),
                                       complex<double>(-336600., 328350.),
                                       complex<double>(-341550., 328350.),
                                       complex<double>(-346500., 328350.),
                                       complex<double>(-351450., 328350.),
                                       complex<double>(-356400., 328350.),
                                       complex<double>(-361350., 328350.),
                                       complex<double>(-366300., 328350.),
                                       complex<double>(-371250., 328350.),
                                       complex<double>(-376200., 328350.),
                                       complex<double>(-381150., 328350.),
                                       complex<double>(-386100., 328350.),
                                       complex<double>(-391050., 328350.),
                                       complex<double>(-396000., 328350.),
                                       complex<double>(-400950., 328350.),
                                       complex<double>(-405900., 328350.),
                                       complex<double>(-410850., 328350.),
                                       complex<double>(-415800., 328350.),
                                       complex<double>(-420750., 328350.),
                                       complex<double>(-425700., 328350.),
                                       complex<double>(-430650., 328350.),
                                       complex<double>(-435600., 328350.),
                                       complex<double>(-440550., 328350.),
                                       complex<double>(-445500., 328350.),
                                       complex<double>(-450450., 328350.),
                                       complex<double>(-455400., 328350.),
                                       complex<double>(-460350., 328350.),
                                       complex<double>(-465300., 328350.),
                                       complex<double>(-470250., 328350.),
                                       complex<double>(-475200., 328350.),
                                       complex<double>(-480150., 328350.),
                                       complex<double>(-485100., 328350.),
                                       complex<double>(-490050., 328350.)
    };

    // test

    for (int i = 0; i != DIM; ++i) {
        EXPECT_TRUE(std::real(corr[i] - matA(0, i)) < pow(10.0, -10.0));
    }

    for (int i = 0; i != DIM; ++i) {
        EXPECT_TRUE(std::imag(corr[i] - matA(0, i)) < pow(10.0, -10.0));
    }
}

//===========//
// test # 75 //
//===========//

TEST(VectorTest75, DotComplex) {
    MatrixDense <complex<double>> matA;

    const pgg::MAI DIM = 100;

    matA.Allocate(DIM);

    // build

    for (pgg::MAI i = 0; i != DIM; ++i) {
        for (pgg::MAI j = 0; j != DIM; ++j) {

            complex<double> tmp_cmplxA = {static_cast<double>(i),
                                          static_cast<double>(j)
            };

            matA.SetElement(i, j, tmp_cmplxA);
        }
    }

    // # 1

    matA.Dot();

    const complex<double> corr[DIM] = {complex<double>(0., 328350.),
                                       complex<double>(-4950., 328350.),
                                       complex<double>(-9900., 328350.),
                                       complex<double>(-14850., 328350.),
                                       complex<double>(-19800., 328350.),
                                       complex<double>(-24750., 328350.),
                                       complex<double>(-29700., 328350.),
                                       complex<double>(-34650., 328350.),
                                       complex<double>(-39600., 328350.),
                                       complex<double>(-44550., 328350.),
                                       complex<double>(-49500., 328350.),
                                       complex<double>(-54450., 328350.),
                                       complex<double>(-59400., 328350.),
                                       complex<double>(-64350., 328350.),
                                       complex<double>(-69300., 328350.),
                                       complex<double>(-74250., 328350.),
                                       complex<double>(-79200., 328350.),
                                       complex<double>(-84150., 328350.),
                                       complex<double>(-89100., 328350.),
                                       complex<double>(-94050., 328350.),
                                       complex<double>(-99000., 328350.),
                                       complex<double>(-103950., 328350.),
                                       complex<double>(-108900., 328350.),
                                       complex<double>(-113850., 328350.),
                                       complex<double>(-118800., 328350.),
                                       complex<double>(-123750., 328350.),
                                       complex<double>(-128700., 328350.),
                                       complex<double>(-133650., 328350.),
                                       complex<double>(-138600., 328350.),
                                       complex<double>(-143550., 328350.),
                                       complex<double>(-148500., 328350.),
                                       complex<double>(-153450., 328350.),
                                       complex<double>(-158400., 328350.),
                                       complex<double>(-163350., 328350.),
                                       complex<double>(-168300., 328350.),
                                       complex<double>(-173250., 328350.),
                                       complex<double>(-178200., 328350.),
                                       complex<double>(-183150., 328350.),
                                       complex<double>(-188100., 328350.),
                                       complex<double>(-193050., 328350.),
                                       complex<double>(-198000., 328350.),
                                       complex<double>(-202950., 328350.),
                                       complex<double>(-207900., 328350.),
                                       complex<double>(-212850., 328350.),
                                       complex<double>(-217800., 328350.),
                                       complex<double>(-222750., 328350.),
                                       complex<double>(-227700., 328350.),
                                       complex<double>(-232650., 328350.),
                                       complex<double>(-237600., 328350.),
                                       complex<double>(-242550., 328350.),
                                       complex<double>(-247500., 328350.),
                                       complex<double>(-252450., 328350.),
                                       complex<double>(-257400., 328350.),
                                       complex<double>(-262350., 328350.),
                                       complex<double>(-267300., 328350.),
                                       complex<double>(-272250., 328350.),
                                       complex<double>(-277200., 328350.),
                                       complex<double>(-282150., 328350.),
                                       complex<double>(-287100., 328350.),
                                       complex<double>(-292050., 328350.),
                                       complex<double>(-297000., 328350.),
                                       complex<double>(-301950., 328350.),
                                       complex<double>(-306900., 328350.),
                                       complex<double>(-311850., 328350.),
                                       complex<double>(-316800., 328350.),
                                       complex<double>(-321750., 328350.),
                                       complex<double>(-326700., 328350.),
                                       complex<double>(-331650., 328350.),
                                       complex<double>(-336600., 328350.),
                                       complex<double>(-341550., 328350.),
                                       complex<double>(-346500., 328350.),
                                       complex<double>(-351450., 328350.),
                                       complex<double>(-356400., 328350.),
                                       complex<double>(-361350., 328350.),
                                       complex<double>(-366300., 328350.),
                                       complex<double>(-371250., 328350.),
                                       complex<double>(-376200., 328350.),
                                       complex<double>(-381150., 328350.),
                                       complex<double>(-386100., 328350.),
                                       complex<double>(-391050., 328350.),
                                       complex<double>(-396000., 328350.),
                                       complex<double>(-400950., 328350.),
                                       complex<double>(-405900., 328350.),
                                       complex<double>(-410850., 328350.),
                                       complex<double>(-415800., 328350.),
                                       complex<double>(-420750., 328350.),
                                       complex<double>(-425700., 328350.),
                                       complex<double>(-430650., 328350.),
                                       complex<double>(-435600., 328350.),
                                       complex<double>(-440550., 328350.),
                                       complex<double>(-445500., 328350.),
                                       complex<double>(-450450., 328350.),
                                       complex<double>(-455400., 328350.),
                                       complex<double>(-460350., 328350.),
                                       complex<double>(-465300., 328350.),
                                       complex<double>(-470250., 328350.),
                                       complex<double>(-475200., 328350.),
                                       complex<double>(-480150., 328350.),
                                       complex<double>(-485100., 328350.),
                                       complex<double>(-490050., 328350.)
    };

    // test

    for (int i = 0; i != DIM; ++i) {
        EXPECT_TRUE(std::real(corr[i] - matA(0, i)) < pow(10.0, -10.0));
    }

    for (int i = 0; i != DIM; ++i) {
        EXPECT_TRUE(std::imag(corr[i] - matA(0, i)) < pow(10.0, -10.0));
    }
}

//===========//
// test # 76 //
//===========//

TEST(VectorTest76, DotComplex) {
    MatrixDense <complex<double>> matA;
    VectorDense <complex<double>> vecA;
    VectorDense <complex<double>> vecB;

    const pgg::MAI DIM = 100;

    matA.Allocate(DIM);
    vecA.Allocate(DIM);
    vecB.Allocate(DIM);

    // build # 1

    for (pgg::MAI i = 0; i != DIM; ++i) {
        for (pgg::MAI j = 0; j != DIM; ++j) {

            complex<double> tmp_cmplxA = {static_cast<double>(i),
                                          static_cast<double>(j)
            };

            matA.SetElement(i, j, tmp_cmplxA);
        }
    }

    // build # 2

    for (pgg::MAI i = 0; i != DIM; ++i) {

        complex<double> tmp_cmplxA = {sin(static_cast<double>(i)),
                                      sin(static_cast<double>(i))
        };

        vecA.SetElement(i, tmp_cmplxA);
    }


    // # 1

    vecB.Dot(matA, vecA);

    const complex<double> corr[DIM] = {complex<double>(54.1556827284055,
                                                       -54.1556827284055),
                                       complex<double>(54.53487735585484,
                                                       -53.776488100956165),
                                       complex<double>(54.914071983304176,
                                                       -53.39729347350683),
                                       complex<double>(55.29326661075352,
                                                       -53.018098846057484),
                                       complex<double>(55.67246123820286,
                                                       -52.63890421860815),
                                       complex<double>(56.051655865652194,
                                                       -52.25970959115881),
                                       complex<double>(56.43085049310153,
                                                       -51.88051496370947),
                                       complex<double>(56.81004512055087,
                                                       -51.501320336260136),
                                       complex<double>(57.18923974800021,
                                                       -51.12212570881079),
                                       complex<double>(57.56843437544955,
                                                       -50.742931081361455),
                                       complex<double>(57.94762900289889,
                                                       -50.36373645391211),
                                       complex<double>(58.32682363034824,
                                                       -49.98454182646277),
                                       complex<double>(58.70601825779757,
                                                       -49.60534719901344),
                                       complex<double>(59.085212885246904,
                                                       -49.2261525715641),
                                       complex<double>(59.46440751269624,
                                                       -48.84695794411476),
                                       complex<double>(59.843602140145585,
                                                       -48.46776331666542),
                                       complex<double>(60.22279676759492,
                                                       -48.08856868921608),
                                       complex<double>(60.601991395044266,
                                                       -47.70937406176674),
                                       complex<double>(60.9811860224936,
                                                       -47.3301794343174),
                                       complex<double>(61.36038064994295,
                                                       -46.95098480686806),
                                       complex<double>(61.739575277392284,
                                                       -46.57179017941872),
                                       complex<double>(62.11876990484162,
                                                       -46.19259555196938),
                                       complex<double>(62.49796453229098,
                                                       -45.813400924520025),
                                       complex<double>(62.87715915974027,
                                                       -45.43420629707073),
                                       complex<double>(63.256353787189624,
                                                       -45.05501166962138),
                                       complex<double>(63.63554841463895,
                                                       -44.675817042172056),
                                       complex<double>(64.01474304208831,
                                                       -44.29662241472269),
                                       complex<double>(64.39393766953766,
                                                       -43.91742778727334),
                                       complex<double>(64.77313229698697,
                                                       -43.538233159824024),
                                       complex<double>(65.15232692443632,
                                                       -43.15903853237469),
                                       complex<double>(65.53152155188567,
                                                       -42.77984390492533),
                                       complex<double>(65.91071617933504,
                                                       -42.400649277475964),
                                       complex<double>(66.28991080678433,
                                                       -42.02145465002667),
                                       complex<double>(66.66910543423373,
                                                       -41.64226002257727),
                                       complex<double>(67.04830006168302,
                                                       -41.263065395127974),
                                       complex<double>(67.42749468913239,
                                                       -40.883870767678616),
                                       complex<double>(67.8066893165817,
                                                       -40.50467614022931),
                                       complex<double>(68.18588394403102,
                                                       -40.12548151277999),
                                       complex<double>(68.5650785714804,
                                                       -39.74628688533061),
                                       complex<double>(68.94427319892975,
                                                       -39.36709225788126),
                                       complex<double>(69.32346782637907,
                                                       -38.98789763043194),
                                       complex<double>(69.70266245382842,
                                                       -38.60870300298258),
                                       complex<double>(70.08185708127775,
                                                       -38.229508375533264),
                                       complex<double>(70.46105170872706,
                                                       -37.85031374808395),
                                       complex<double>(70.84024633617645,
                                                       -37.471119120634555),
                                       complex<double>(71.2194409636257,
                                                       -37.0919244931853),
                                       complex<double>(71.59863559107505,
                                                       -36.71272986573595),
                                       complex<double>(71.97783021852436,
                                                       -36.33353523828664),
                                       complex<double>(72.35702484597375,
                                                       -35.95434061083725),
                                       complex<double>(72.73621947342312,
                                                       -35.575145983387884),
                                       complex<double>(73.1154141008724,
                                                       -35.195951355938604),
                                       complex<double>(73.49460872832182,
                                                       -34.816756728489175),
                                       complex<double>(73.87380335577112,
                                                       -34.43756210103988),
                                       complex<double>(74.25299798322052,
                                                       -34.058367473590486),
                                       complex<double>(74.63219261066982,
                                                       -33.67917284614118),
                                       complex<double>(75.01138723811911,
                                                       -33.2999782186919),
                                       complex<double>(75.39058186556846,
                                                       -32.92078359124255),
                                       complex<double>(75.76977649301784,
                                                       -32.54158896379315),
                                       complex<double>(76.14897112046714,
                                                       -32.16239433634387),
                                       complex<double>(76.52816574791643,
                                                       -31.783199708894564),
                                       complex<double>(76.90736037536584,
                                                       -31.404005081445163),
                                       complex<double>(77.28655500281518,
                                                       -31.024810453995826),
                                       complex<double>(77.66574963026457,
                                                       -30.645615826546432),
                                       complex<double>(78.04494425771391,
                                                       -30.266421199097095),
                                       complex<double>(78.42413888516317,
                                                       -29.88722657164783),
                                       complex<double>(78.80333351261245,
                                                       -29.508031944198557),
                                       complex<double>(79.18252814006198,
                                                       -29.128837316749035),
                                       complex<double>(79.56172276751116,
                                                       -28.74964268929984),
                                       complex<double>(79.94091739496056,
                                                       -28.370448061850446),
                                       complex<double>(80.32011202240989,
                                                       -27.991253434401123),
                                       complex<double>(80.69930664985927,
                                                       -27.61205880695173),
                                       complex<double>(81.0785012773085,
                                                       -27.232864179502506),
                                       complex<double>(81.45769590475788,
                                                       -26.853669552053113),
                                       complex<double>(81.83689053220718,
                                                       -26.47447492460382),
                                       complex<double>(82.21608515965653,
                                                       -26.09528029715448),
                                       complex<double>(82.59527978710597,
                                                       -25.71608566970503),
                                       complex<double>(82.97447441455529,
                                                       -25.336891042255722),
                                       complex<double>(83.35366904200458,
                                                       -24.957696414806414),
                                       complex<double>(83.73286366945399,
                                                       -24.57850178735702),
                                       complex<double>(84.11205829690326,
                                                       -24.19930715990774),
                                       complex<double>(84.49125292435264,
                                                       -23.820112532458374),
                                       complex<double>(84.87044755180204,
                                                       -23.440917905008952),
                                       complex<double>(85.24964217925134,
                                                       -23.061723277559658),
                                       complex<double>(85.62883680670063,
                                                       -22.682528650110363),
                                       complex<double>(86.00803143414998,
                                                       -22.303334022661026),
                                       complex<double>(86.38722606159925,
                                                       -21.92413939521176),
                                       complex<double>(86.7664206890486,
                                                       -21.544944767762395),
                                       complex<double>(87.14561531649795,
                                                       -21.165750140313058),
                                       complex<double>(87.52480994394739,
                                                       -20.786555512863607),
                                       complex<double>(87.90400457139668,
                                                       -20.407360885414327),
                                       complex<double>(88.28319919884589,
                                                       -20.028166257965104),
                                       complex<double>(88.66239382629533,
                                                       -19.648971630515682),
                                       complex<double>(89.0415884537446,
                                                       -19.2697770030664),
                                       complex<double>(89.42078308119403,
                                                       -18.89058237561698),
                                       complex<double>(89.79997770864321,
                                                       -18.511387748167785),
                                       complex<double>(90.17917233609279,
                                                       -18.13219312071822),
                                       complex<double>(90.558366963542,
                                                       -17.752998493268997),
                                       complex<double>(90.93756159099135,
                                                       -17.37380386581966),
                                       complex<double>(91.31675621844073,
                                                       -16.994609238370266),
                                       complex<double>(91.69595084589,
                                                       -16.615414610921015)
    };

    // test

    for (int i = 0; i != DIM; ++i) {
        EXPECT_TRUE(std::real(corr[i] - vecB(i)) < pow(10.0, -10.0));
    }

    for (int i = 0; i != DIM; ++i) {
        EXPECT_TRUE(std::imag(corr[i] - vecB(i)) < pow(10.0, -10.0));
    }
}

//===========//
// test # 77 //
//===========//

TEST(VectorTest77, DotComplex) {
    VectorDense <complex<double>> vecA;
    VectorDense <complex<double>> vecB;

    const pgg::MAI DIM = 100;

    vecA.Allocate(DIM);
    vecB.Allocate(DIM);

    // build # 2

    for (pgg::MAI i = 0; i != DIM; ++i) {

        complex<double> tmp_cmplxA = {cos(static_cast<double>(i)),
                                      sin(static_cast<double>(i))
        };

        complex<double> tmp_cmplxB = {cos(static_cast<double>(i)),
                                      cos(static_cast<double>(i))
        };

        vecA.SetElement(i, tmp_cmplxA);
        vecB.SetElement(i, tmp_cmplxB);
    }


    // # 1

    const complex<double> res = vecB.Dot(vecA);
    const complex<double> cor = complex<double>(49.687376068621084, 50.28866122084714);

    // test

    for (int i = 0; i != DIM; ++i) {
        EXPECT_TRUE(std::real(res - cor) < pow(10.0, -10.0));
    }

    for (int i = 0; i != DIM; ++i) {
        EXPECT_TRUE(std::imag(res - cor) < pow(10.0, -10.0));
    }
}

// END
