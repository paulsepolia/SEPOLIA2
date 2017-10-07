
#ifndef VECTOR_DENSE_DECLARATION_H
#define VECTOR_DENSE_DECLARATION_H

#include <complex>

namespace pgg {
namespace sep {

template<typename T1>
class VectorDense {
public:

     //===============//
     // Algebra Basic //
     //===============//

     // Divide

     void Divide(const VectorDense<T1> &,
                 const VectorDense<T1> &);

     void Divide(const VectorDense<T1> &,
                 const T1 &);

     void Divide(const T1 &,
                 const VectorDense<T1> &);

     void Divide(const T1 &);

     void Divide(const VectorDense<T1> &);

     // Minus

     void Minus(const VectorDense<T1> &);

     // Negate

     void Negate();

     // Plus

     void Plus(const VectorDense<T1> &,
               const VectorDense<T1> &);

     void Plus(const VectorDense<T1> &,
               const T1 &);

     void Plus(const T1 &,
               const VectorDense<T1> &);

     void Plus(const T1 &);

     void Plus(const VectorDense<T1> &);

     // Subtract

     void Subtract(const VectorDense<T1> &,
                   const VectorDense<T1> &);

     void Subtract(const VectorDense<T1> &,
                   const T1 &);

     void Subtract(const T1 &,
                   const VectorDense<T1> &);

     void Subtract(const T1 &);

     void Subtract(const VectorDense<T1> &);

     // Times

     void Times(const VectorDense<T1> &,
                const VectorDense<T1> &);

     void Times(const VectorDense<T1> &,
                const T1 &);

     void Times(const T1 &,
                const VectorDense<T1> &);

     void Times(const T1 &);

     void Times(const VectorDense<T1> &);

private:

     // VectorScalarTypeA

     void VectorScalarTypeA(
          const VectorDense<T1> &,
          const T1 &,
          T1 op_fn(const T1 &, const T1 &));

     // VectorVectorTypeA

     void VectorVectorTypeA(
          const VectorDense<T1> &,
          const VectorDense<T1> &,
          T1 op_fn(const T1 &, const T1 &));

public:

     //===========//
     // Auxiliary //
     //===========//

     // CheckAllocation

     bool CheckAllocation() const;

     // CheckCompatibility # 1

     bool CheckCompatibility(const VectorDense<T1> &) const;

     // CheckCompatibility # 2

     template<typename T2>
     bool CheckCompatibility(const T2 &, const std::string &) const;

     // Equal # 1

     bool Equal(const T1 &,
                const T1 & = static_cast<T1>(ZERO_DBL)) const;

     // Equal # 2

     bool Equal(const VectorDense<T1> &,
                const T1 & = static_cast<T1>(ZERO_DBL)) const;

     // Greater # 1

     bool Greater(const T1 &) const;

     // Greater # 2

     bool Greater(const VectorDense<T1> &) const;

     // GreaterEqual # 1

     bool GreaterEqual(const T1 &) const;

     // GreaterEqual # 2

     bool GreaterEqual(const VectorDense<T1> &) const;

     // Less # 1

     bool Less(const T1 &) const;

     // Less # 2

     bool Less(const VectorDense<T1> &) const;

     // LessEqual # 1

     bool LessEqual(const T1 &) const;

     // LessEqual # 2

     bool LessEqual(const VectorDense<T1> &) const;

     // Map # 1

     void Map(T1 function_to_apply(T1));

     // Map # 2

     void Map(const VectorDense<T1> &,
              T1 function_to_apply(T1));

     // Map # 3

     template<typename T2>
     void Map(T2 &);

     // Map # 4

     template<typename T2>
     void Map(const VectorDense<T1> &,
              T2 &);

     // Mean

     T1 Mean() const;

     // Nest # 1

     void Nest(T1 function_to_apply(T1),
               const VEI_MAX &);

     // Nest # 2

     void Nest(const VectorDense<T1> &,
               T1 function_to_apply(T1),
               const VEI_MAX &);

     // Nest # 3

     template<typename T2>
     void Nest(T2 &, const VEI_MAX &);

     // Nest # 4

     template<typename T2>
     void Nest(const VectorDense<T1> &,
               T2 &,
               const VEI_MAX &);

     // NotEqual # 1

     bool NotEqual(const T1 &,
                   const T1 & = static_cast<T1>(ZERO_DBL)) const;

     // NotEqual # 2

     bool NotEqual(const VectorDense<T1> &,
                   const T1 & = static_cast<T1>(ZERO_DBL)) const;

     // Random

     void Random(const T1 &, const T1 &, const unsigned int &);

     // Range # 1

     void Range(const T1 &);

     // Range # 2

     void Range(const T1 &, const T1 &);

     // SetMax # 1

     void SetMax(const T1 &, const T1 &);

     // SetMax # 2

     void SetMax(const T1 &);

     // SetMax # 3

     void SetMax(const VectorDense<T1> &, const T1 &);

     // SetMin # 1

     void SetMin(const T1 &, const T1 &);

     // SetMin # 2

     void SetMin(const T1 &);

     // SetMin # 3

     void SetMin(const VectorDense<T1> &, const T1 &);

     // Swap

     void Swap(VectorDense<T1> &);

private:

     // VectorScalarComparison

     bool VectorScalarComparison(
          const T1 &,
          bool comp_fn(const T1 &, const T1 &)) const;

     // VectorScalarEqual

     bool VectorScalarEqual(
          const T1 &,
          const T1 &,
          bool comp_fn(const T1 &,
                       const T1 &,
                       const T1 &)) const;

     // VectorVectorComparison

     bool VectorVectorComparison(
          const VectorDense<T1> &,
          bool comp_fn(const T1 &, const T1 &)) const;

     // VectorVectorEqual

     bool VectorVectorEqual(
          const VectorDense<T1> &,
          const T1 &,
          bool comp_fn(const T1 &,
                       const T1 &,
                       const T1 &)) const;

public:

     //======//
     // BLAS //
     //======//

     //===============================//
     // Complex Double General Vector //
     //===============================//

     // BLAS Level 1

     // DotBLAS

     std::complex<double> DotBLAS(const VectorDense<std::complex<double>> &) const;

     // BLAS Level 2

     // DotBLAS

     template<typename T2>
     void DotBLAS(const T2 &,
                  const VectorDense<std::complex<double>> &,
                  const std::string & = WITH_ROWS);

     //=======================//
     // Double General Vector //
     //=======================//

     // BLAS Level 1

     // DotBLAS

     double DotBLAS(const VectorDense<double> &) const;

     // BLAS Level 2

     // DotBLAS

     template<typename T2>
     void DotBLAS(const T2 &,
                  const VectorDense<double> &,
                  const std::string & = WITH_ROWS);

public:

     //=========//
     // Complex //
     //=========//

     template<typename T2>
     void ImaginaryPart(const VectorDense<T2> &);

     template<typename T2>
     void RealPart(const VectorDense<T2> &);

public:

     //==============//
     // Constructors //
     //==============//

     explicit VectorDense<T1>();

     VectorDense<T1>(const VectorDense<T1> &);

public:

     //=======//
     // CMATH //
     //=======//

     // Abs # 1

     void Abs(const VectorDense<T1> &);

     // Abs # 2

     void Abs();

     // ArcCos # 1

     void ArcCos(const VectorDense<T1> &);

     // ArcCos # 2

     void ArcCos();

     // ArcSin # 1

     void ArcSin(const VectorDense<T1> &);

     // ArcSin # 2

     void ArcSin();

     // Cos # 1

     void Cos(const VectorDense<T1> &);

     // Cos # 2

     void Cos();

     // FastMA

     void FastMA(const VectorDense<T1> &,
                 const VectorDense<T1> &,
                 const VectorDense<T1> &);

     // Power

     void Power(const VectorDense<T1> &,
                const VectorDense<T1> &);

     // Sin # 1

     void Sin(const VectorDense<T1> &);

     // Sin # 2

     void Sin();

public:

     //============//
     // Destructor //
     //============//

     virtual ~VectorDense<T1>();

public:

     //===================//
     // Generic functions //
     //===================//

     //========================//
     // Complex Double Vectors //
     //========================//

     // Dot # 1

     std::complex<double> Dot(const VectorDense<std::complex<double>> &) const;

     // Dot # 2

     template<typename T2>
     void Dot(const T2 &,
              const VectorDense<std::complex<double>> &,
              const std::string & = "WithRows");

     //=====================//
     // Real Double Vectors //
     //=====================//

     // Dot # 1

     double Dot(const VectorDense<double> &,
                const std::string & = "BLAS") const;

     // Dot # 2

     template<typename T2>
     void Dot(const T2 &,
              const VectorDense<double> &,
              const std::string & = "WithRows",
              const std::string & = "BLAS");

public:

     //=====//
     // GSL //
     //=====//

     // DotGSL # 1

     double DotGSL(const VectorDense<double> &) const;

     // DotGSL # 2

     template<typename T2>
     void DotGSL(const T2 &,
                 const VectorDense<double> &,
                 const std::string & = WITH_ROWS);

public:

     //=====//
     // Get //
     //=====//

     template<typename T2>
     void GetColumn(const T2 &, const MAI &);

     VEI GetNumberOfElements() const;

     T1 GetElement(const VEI &) const;

     template<typename T2>
     void GetRow(const T2 &, const MAI &);

public:

     //========//
     // Memory //
     //========//

     void Allocate(const VEI &);

     bool AllocatedQ() const;

     void Deallocate();

     bool DeallocatedQ() const;

public:

     //===========//
     // Operators //
     //===========//

     // =

     VectorDense<T1> & operator =(const VectorDense<T1> &);

     VectorDense<T1> & operator =(const T1 &);

     // +

     VectorDense<T1> operator +(const VectorDense<T1> &) const;

     VectorDense<T1> operator +(const T1 &) const;

     template <typename T2>
     friend VectorDense<T2> operator +(const T2 &,
                                       const VectorDense<T2> &);

     // -

     VectorDense<T1> operator -(const VectorDense<T1> &) const;

     VectorDense<T1> operator -(const T1 &) const;

     VectorDense<T1> operator -() const;

     template<typename T2>
     friend VectorDense<T2> operator -(const T2 &,
                                       const VectorDense<T2> &);

     // *

     VectorDense<T1> operator *(const VectorDense<T1> &) const;

     VectorDense<T1> operator *(const T1 &) const;

     template<typename T2>
     friend VectorDense<T2> operator *(const T2 &,
                                       const VectorDense<T2> &);

     // /

     VectorDense<T1> operator /(const VectorDense<T1> &) const;

     VectorDense<T1> operator /(const T1 &) const;

     template<typename T2>
     friend VectorDense<T2> operator /(const T2 &,
                                       const VectorDense<T2> &);

     // +=

     VectorDense<T1> operator +=(const VectorDense<T1> &);

     VectorDense<T1> operator +=(const T1 &);

     // -=

     VectorDense<T1> operator -=(const VectorDense<T1> &);

     VectorDense<T1> operator -=(const T1 &);

     // *=

     VectorDense<T1> operator *=(const VectorDense<T1> &);

     VectorDense<T1> operator *=(const T1 &);

     // /=

     VectorDense<T1> operator /=(const VectorDense<T1> &);

     VectorDense<T1> operator /=(const T1 &);

     // ++

     VectorDense<T1> operator ++();
     VectorDense<T1> operator ++(int);

     // --

     VectorDense<T1> operator --();
     VectorDense<T1> operator --(int);

     // ==

     bool operator ==(const VectorDense<T1> &) const;

     bool operator ==(const T1 &) const;

     // !=

     bool operator !=(const VectorDense<T1> &) const;

     bool operator !=(const T1 &) const;

     // >

     bool operator >(const VectorDense<T1> &) const;

     bool operator >(const T1 &) const;

     // >=

     bool operator >=(const VectorDense<T1> &) const;

     bool operator >=(const T1 &) const;

     // <

     bool operator <(const VectorDense<T1> &) const;

     bool operator <(const T1 &) const;

     // <=

     bool operator <=(const VectorDense<T1> &) const;

     bool operator <=(const T1 &) const;

     // ()

     const T1 operator ()(const VEI &) const;

     // []

     const T1 operator [](const VEI &) const;

public:

     //=====//
     // Set //
     //=====//

     void Set(const VectorDense<T1> &);

     void Set(const T1 &);

     template<typename T2>
     void SetColumn(const MAI &, T2 &) const;

     void SetElement(const VEI &,
                     const T1 &);

     template<typename T2>
     void SetRow(const MAI &, T2 &) const;

public:

     //=====//
     // STL //
     //=====//

     // BinarySearch # 1

     bool BinarySearch(const T1 &) const;

     // BinarySearch # 2

     template<typename T2>
     bool BinarySearch(const T1 &, T2 &) const;

     // Count

     VEI Count(const T1 &) const;

     // CountIf

     template<typename T2>
     VEI CountIf(T2 &) const;

     // FindElement

     double FindElement(const T1 &) const;

     // Generate

     template<typename T2>
     void Generate(T2 &);

     // Max # 1

     T1 Max() const;

     // Max # 2

     template<typename T2>
     T1 Max(T2 &) const;

     // Min # 1

     T1 Min() const;

     // Min # 2

     template<typename T2>
     T1 Min(T2 &) const;

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

public:

     T1 * vector;

private:

     VEI elems;
     bool is_alloc;
};

} // sep
} // pgg

#endif // VECTOR_DENSE_DECLARATION_H

