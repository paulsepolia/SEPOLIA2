#pragma once

#include <memory>
#include "../parameters/parameters.h"

namespace sepolia {

    template<typename T>
    class vector_dense {

    public:

        //==============//
        // constructors //
        //==============//

        // constructor with no arguments
        explicit vector_dense<T>();

        // constructor with two arguments
        vector_dense<T>(const uint64_t &, const T & = 0);

        // copy constructor
        vector_dense<T>(const vector_dense<T> &);

        // move constructor
        vector_dense<T>(vector_dense<T> &&);

        //========//
        // memory //
        //========//

        bool allocate(const uint64_t &);

        bool is_allocated() const;

        bool deallocate();

        bool is_deallocated() const;

        //===========//
        // operators //
        //===========//

        // vector copy assignment operator
        vector_dense<T> &operator=(const vector_dense<T> &);

        // element copy assignment operator
        vector_dense<T> &operator=(const T &);

        // vector move assignment operator
        vector_dense<T> &operator=(vector_dense<T> &&);

        // operator +
        vector_dense<T> operator+(const vector_dense<T> &) const;

        vector_dense<T> operator+(const T &) const;

        template<typename T2>
        friend vector_dense<T2> operator+(const T2 &,
                                          const vector_dense<T2> &);

        // operator -
        vector_dense<T> operator-(const vector_dense<T> &) const;

        vector_dense<T> operator-(const T &) const;

        template<typename T2>
        friend vector_dense<T2> operator-(const T2 &,
                                          const vector_dense<T2> &);

        // operator *
        vector_dense<T> operator*(const vector_dense<T> &) const;

        vector_dense<T> operator*(const T &) const;

        template<typename T2>
        friend vector_dense<T2> operator*(const T2 &,
                                          const vector_dense<T2> &);

        // operator /
        vector_dense<T> operator/(const vector_dense<T> &) const;

        vector_dense<T> operator/(const T &) const;

        template<typename T2>
        friend vector_dense<T2> operator/(const T2 &,
                                          const vector_dense<T2> &);

        // operator ()

        T operator()(const uint64_t &) const;

        // operator []

        T &operator[](const uint64_t &) const;


        // operator +=

        vector_dense<T> operator+=(const vector_dense<T> &);

        vector_dense<T> operator+=(const T &);

        // operator -=

        vector_dense<T> operator-=(const vector_dense<T> &);

        vector_dense<T> operator-=(const T &);

        // operator *=

        vector_dense<T> operator*=(const vector_dense<T> &);

        vector_dense<T> operator*=(const T &);

        // operator /=

        vector_dense<T> operator/=(const vector_dense<T> &);

        vector_dense<T> operator/=(const T &);

        // operator ++

        vector_dense<T> operator++();

        vector_dense<T> operator++(int);

        // operator --

        vector_dense<T> operator--();

        vector_dense<T> operator--(int);

        // operator ==

        bool operator==(const vector_dense<T> &) const;

        bool operator==(const T &) const;

        // operator !=

        bool operator!=(const vector_dense<T> &) const;

        bool operator!=(const T &) const;

        //=====//
        // get //
        //=====//

        uint64_t get_dimension() const;

        T get_element(const uint64_t &) const;

        //=====//
        // set //
        //=====//

        void set_element(const uint64_t &, const T &);

        //=========//
        // algebra //
        //=========//

        vector_dense<T> plus(const vector_dense<T> &, const bool & = false) const;

        vector_dense<T> plus(const T &, const bool & = false) const;

        vector_dense<T> times(const vector_dense<T> &, const bool & = false) const;

        vector_dense<T> times(const T &, const bool & = false) const;

        vector_dense<T> subtract(const vector_dense<T> &, const bool & = false) const;

        vector_dense<T> subtract(const T &, const bool & = false) const;

        vector_dense<T> divide(const vector_dense<T> &, const bool & = false) const;

        vector_dense<T> divide(const T &, const bool & = false) const;

    private:

        //==============//
        // data members //
        //==============//

        uint64_t _dimension;
        std::shared_ptr<T> _vdsp;

        //================//
        // help functions //
        //================//

        void vector_dense_transform(vector_dense<T> &vec_in_out,
                                    std::function<T(T, T)> fun,
                                    const bool &) const;

        void vector_dense_transform(const vector_dense<T> &vec_in,
                                    vector_dense<T> &vec_out,
                                    std::function<T(T, T)> fun,
                                    const bool &) const;

        void check_allocation() const;

        void check_if_is_in_range(const uint64_t &) const;

        void set(const T &);

        void set(const vector_dense<T> &);

        bool equal_exact(const vector_dense<T> &) const;

        bool equal_exact(const T &) const;
    };
}

/*


// Minus

void Minus(const vector_dense<T> &);

// Negate

void Negate();

private:

// VectorScalarTypeA

void VectorScalarTypeA(
        const vector_dense<T> &,
        const T &,
        T op_fn(const T &, const T &));

// VectorVectorTypeA

void VectorVectorTypeA(
        const vector_dense<T> &,
        const vector_dense<T> &,
        T op_fn(const T &, const T &));

public:

//===========//
// Auxiliary //
//===========//

// CheckAllocation

bool CheckAllocation() const;

// CheckCompatibility # 1

bool CheckCompatibility(const vector_dense<T> &) const;

// CheckCompatibility # 2

template<typename T2>
bool CheckCompatibility(const T2 &, const std::string &) const;

// Equal # 1

bool Equal(const T &,
           const T & = static_cast<T>(ZERO_DBL)) const;

// Equal # 2

bool Equal(const vector_dense<T> &,
           const T & = static_cast<T>(ZERO_DBL)) const;

// Greater # 1

bool Greater(const T &) const;

// Greater # 2

bool Greater(const vector_dense<T> &) const;

// GreaterEqual # 1

bool GreaterEqual(const T &) const;

// GreaterEqual # 2

bool GreaterEqual(const vector_dense<T> &) const;

// Less # 1

bool Less(const T &) const;

// Less # 2

bool Less(const vector_dense<T> &) const;

// LessEqual # 1

bool LessEqual(const T &) const;

// LessEqual # 2

bool LessEqual(const vector_dense<T> &) const;

// Map # 1

void Map(T function_to_apply(T));

// Map # 2

void Map(const vector_dense<T> &,
         T function_to_apply(T));

// Map # 3

template<typename T2>
void Map(T2 &);

// Map # 4

template<typename T2>
void Map(const vector_dense<T> &,
         T2 &);

// Mean

T Mean() const;

// Nest # 1

void Nest(T function_to_apply(T),
          const VEI_MAX &);

// Nest # 2

void Nest(const vector_dense<T> &,
          T function_to_apply(T),
          const VEI_MAX &);

// Nest # 3

template<typename T2>
void Nest(T2 &, const VEI_MAX &);

// Nest # 4

template<typename T2>
void Nest(const vector_dense<T> &,
          T2 &,
          const VEI_MAX &);

// NotEqual # 1

bool NotEqual(const T &,
              const T & = static_cast<T>(ZERO_DBL)) const;

// NotEqual # 2

bool NotEqual(const vector_dense<T> &,
              const T & = static_cast<T>(ZERO_DBL)) const;

// Random

void Random(const T &, const T &, const unsigned int &);

// Range # 1

void Range(const T &);

// Range # 2

void Range(const T &, const T &);

// SetMax # 1

void SetMax(const T &, const T &);

// SetMax # 2

void SetMax(const T &);

// SetMax # 3

void SetMax(const vector_dense<T> &, const T &);

// SetMin # 1

void SetMin(const T &, const T &);

// SetMin # 2

void SetMin(const T &);

// SetMin # 3

void SetMin(const vector_dense<T> &, const T &);

// Swap

void Swap(vector_dense<T> &);

private:

// VectorScalarComparison

bool VectorScalarComparison(
        const T &,
        bool comp_fn(const T &, const T &)) const;

// VectorScalarEqual

bool VectorScalarEqual(
        const T &,
        const T &,
        bool comp_fn(const T &,
                     const T &,
                     const T &)) const;

// VectorVectorComparison

bool VectorVectorComparison(
        const vector_dense<T> &,
        bool comp_fn(const T &, const T &)) const;

// VectorVectorEqual

bool VectorVectorEqual(
        const vector_dense<T> &,
        const T &,
        bool comp_fn(const T &,
                     const T &,
                     const T &)) const;

public:

//======//
// BLAS //
//======//

//===============================//
// Complex Double General Vector //
//===============================//

// BLAS Level 1

// DotBLAS

std::complex<double> DotBLAS(const vector_dense<std::complex<double>> &) const;

// BLAS Level 2

// DotBLAS

template<typename T2>
void DotBLAS(const T2 &,
             const vector_dense<std::complex<double>> &,
             const std::string & = WITH_ROWS);

//=======================//
// Double General Vector //
//=======================//

// BLAS Level 1

// DotBLAS

double DotBLAS(const vector_dense<double> &) const;

// BLAS Level 2

// DotBLAS

template<typename T2>
void DotBLAS(const T2 &,
             const vector_dense<double> &,
             const std::string & = WITH_ROWS);

public:

//=========//
// Complex //
//=========//

template<typename T2>
void ImaginaryPart(const vector_dense<T2> &);

template<typename T2>
void RealPart(const vector_dense<T2> &);

public:

//==============//
// Constructors //
//==============//

explicit vector_dense<T>();

vector_dense<T>(const vector_dense<T> &);

public:

//=======//
// CMATH //
//=======//

// Abs # 1

void Abs(const vector_dense<T> &);

// Abs # 2

void Abs();

// ArcCos # 1

void ArcCos(const vector_dense<T> &);

// ArcCos # 2

void ArcCos();

// ArcSin # 1

void ArcSin(const vector_dense<T> &);

// ArcSin # 2

void ArcSin();

// Cos # 1

void Cos(const vector_dense<T> &);

// Cos # 2

void Cos();

// FastMA

void FastMA(const vector_dense<T> &,
            const vector_dense<T> &,
            const vector_dense<T> &);

// Power

void Power(const vector_dense<T> &,
           const vector_dense<T> &);

// Sin # 1

void Sin(const vector_dense<T> &);

// Sin # 2

void Sin();

public:

//============//
// Destructor //
//============//

virtual ~vector_dense<T>();

public:

//===================//
// Generic functions //
//===================//

//========================//
// Complex Double Vectors //
//========================//

// Dot # 1

std::complex<double> Dot(const vector_dense<std::complex<double>> &) const;

// Dot # 2

template<typename T2>
void Dot(const T2 &,
         const vector_dense<std::complex<double>> &,
         const std::string & = "WithRows");

//=====================//
// Real Double Vectors //
//=====================//

// Dot # 1

double Dot(const vector_dense<double> &,
           const std::string & = "BLAS") const;

// Dot # 2

template<typename T2>
void Dot(const T2 &,
         const vector_dense<double> &,
         const std::string & = "WithRows",
         const std::string & = "BLAS");

public:

//=====//
// GSL //
//=====//

// DotGSL # 1

double DotGSL(const vector_dense<double> &) const;

// DotGSL # 2

template<typename T2>
void DotGSL(const T2 &,
            const vector_dense<double> &,
            const std::string & = WITH_ROWS);

public:

//=====//
// Get //
//=====//

template<typename T2>
void GetColumn(const T2 &, const MAI &);

VEI GetNumberOfElements() const;

T GetElement(const VEI &) const;

template<typename T2>
void GetRow(const T2 &, const MAI &);

//===========//
// Operators //
//===========//

// ==

bool operator==(const vector_dense<T> &) const;

bool operator==(const T &) const;

// !=

bool operator!=(const vector_dense<T> &) const;

bool operator!=(const T &) const;

public:

//=====//
// Set //
//=====//

template<typename T2>
void SetColumn(const MAI &, T2 &) const;

void SetElement(const VEI &,
                const T &);

template<typename T2>
void SetRow(const MAI &, T2 &) const;

public:

//=====//
// STL //
//=====//

// BinarySearch # 1

bool BinarySearch(const T &) const;

// BinarySearch # 2

template<typename T2>
bool BinarySearch(const T &, T2 &) const;

// Count

VEI Count(const T &) const;

// CountIf

template<typename T2>
VEI CountIf(T2 &) const;

// FindElement

double FindElement(const T &) const;

// Generate

template<typename T2>
void Generate(T2 &);

// Max # 1

T Max() const;

// Max # 2

template<typename T2>
T Max(T2 &) const;

// Min # 1

T Min() const;

// Min # 2

template<typename T2>
T Min(T2 &) const;

// NextPermutation # 1

bool NextPermutation();

// NextPermutation # 2

template<typename T2>
bool NextPermutation(T2 &);

// PreviousPermutation # 1

bool PreviousPermutation();

// PreviousPermutation # 2

template<typename T2>
bool PreviousPermutation(T2 &);

// RandomShuffle # 1

void RandomShuffle();

// RandomShuffle # 2

void RandomShuffle(const unsigned int &);

// Reverse

void Reverse();

// RotateLeft

void RotateLeft(const VEI &);

// RotateRight

void RotateRight(const VEI &);

// Sort # 1

void Sort();

// Sort # 2

template<typename T2>
void Sort(T2 &);

// SortedQ # 1

bool SortedQ() const;

// SortedQ # 2

template<typename T2>
bool SortedQ(T2 &) const;

};

}

*/
