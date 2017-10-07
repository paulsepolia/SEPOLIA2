
#ifndef VECTOR_DENSE_CMATH_H
#define VECTOR_DENSE_CMATH_H

namespace pgg {
namespace sep {

// Abs # 1

template<typename T1>
inline void VectorDense<T1>::Abs(
     const VectorDense<T1> & vec)
{
#ifdef DEBUG_ALLOC
     this->CheckAllocation();
     vec.CheckAllocation();
#endif

#ifdef DEBUG_COMPAT
     this->CheckCompatibility(vec);
#endif

     this->Map(vec, std::abs);
}

// Abs # 2

template<typename T1>
inline void VectorDense<T1>::Abs()
{
#ifdef DEBUG_ALLOC
     this->CheckAllocation();
#endif

     this->Map(std::abs);
}

// ArcCos # 1

template<typename T1>
inline void VectorDense<T1>::ArcCos(const VectorDense<T1> & vec)
{
#ifdef DEBUG_ALLOC
     this->CheckAllocation();
     vec.CheckAllocation();
#endif

#ifdef DEBUG_COMPAT
     this->CheckCompatibility(vec);
#endif

     this->Map(vec, std::acos);
}

// ArcCos # 2

template<typename T1>
inline void VectorDense<T1>::ArcCos()
{
#ifdef DEBUG_ALLOC
     this->CheckAllocation();
#endif

     this->Map(std::acos);
}

// ArcSin # 1

template<typename T1>
inline void VectorDense<T1>::ArcSin(const VectorDense<T1> & vec)
{
#ifdef DEBUG_ALLOC
     this->CheckAllocation();
     vec.CheckAllocation();
#endif

#ifdef DEBUG_COMPAT
     this->CheckCompatibility(vec);
#endif

     this->Map(vec, std::asin);
}

// ArcSin # 2

template<typename T1>
inline void VectorDense<T1>::ArcSin()
{
#ifdef DEBUG_ALLOC
     this->CheckAllocation();
#endif

     this->Map(std::asin);
}

// Cos # 1

template<typename T1>
inline void VectorDense<T1>::Cos(const VectorDense<T1> & vec)
{
#ifdef DEBUG_ALLOC
     this->CheckAllocation();
     vec.CheckAllocation();
#endif

#ifdef DEBUG_COMPAT
     this->CheckCompatibility(vec);
#endif

     this->Map(vec, std::cos);
}

// Cos # 2

template<typename T1>
inline void VectorDense<T1>::Cos()
{
#ifdef DEBUG_ALLOC
     this->CheckAllocation();
#endif

     this->Map(std::cos);
}

// FastMA # 1

template<>
inline void VectorDense<double>::FastMA(
     const VectorDense<double> & vecA,
     const VectorDense<double> & vecB,
     const VectorDense<double> & vecC)
{
#ifdef DEBUG_ALLOC
     this->CheckAllocation();
     vecA.CheckAllocation();
     vecB.CheckAllocation();
     vecC.CheckAllocation();
#endif

#ifdef DEBUG_COMPAT
     this->CheckCompatibility(vecA);
     this->CheckCompatibility(vecB);
     this->CheckCompatibility(vecC);
#endif

     VEI i;

     const VEI ELEMS = vecA.elems;

     #pragma omp parallel default(none) \
     num_threads(NT_1D) \
     private(i)    \
     shared(vecA)  \
     shared(vecB)  \
     shared(vecC)
     {
          #pragma omp for

          for (i = 0; i < ELEMS; ++i) {

               this->vector[i] = std::fma(
                                      vecA.vector[i],
                                      vecB.vector[i],
                                      vecC.vector[i]);
          }
     }
}

// FastMA # 2

template<>
inline void VectorDense<long double>::FastMA(
     const VectorDense<long double> & vecA,
     const VectorDense<long double> & vecB,
     const VectorDense<long double> & vecC)
{
#ifdef DEBUG_ALLOC
     this->CheckAllocation();
     vecA.CheckAllocation();
     vecB.CheckAllocation();
     vecC.CheckAllocation();
#endif

#ifdef DEBUG_COMPAT
     this->CheckCompatibility(vecA);
     this->CheckCompatibility(vecB);
     this->CheckCompatibility(vecC);
#endif

     VEI i;
     const VEI ELEMS = vecA.elems;

     #pragma omp parallel default(none) \
     num_threads(NT_1D) \
     private(i)   \
     shared(vecA) \
     shared(vecB) \
     shared(vecC)
     {
          #pragma omp for

          for (i = 0; i < ELEMS; ++i) {

               this->vector[i] = std::fma(
                                      vecA.vector[i],
                                      vecB.vector[i],
                                      vecC.vector[i]);
          }
     }
}

// Power # 1

template<>
inline void VectorDense<double>::Power(
     const VectorDense<double> & vec_base,
     const VectorDense<double> & vec_exponent)
{
#ifdef DEBUG_ALLOC
     this->CheckAllocation();
     vec_base.CheckAllocation();
     vec_exponent.CheckAllocation();
#endif

#ifdef DEBUG_COMPAT
     this->CheckCompatibility(vec_base);
     this->CheckCompatibility(vec_exponent);
#endif

     const VEI ELEMS = this->elems;
     VEI i;

     #pragma omp parallel default(none) \
     num_threads(NT_1D) \
     private(i)       \
     shared(vec_base) \
     shared(vec_exponent)
     {
          #pragma omp for

          for (i = 0; i < ELEMS; ++i) {

               this->vector[i] = std::pow(
                                      vec_base.vector[i],
                                      vec_exponent.vector[i]);
          }
     }
}

// Power # 2

template<>
inline void VectorDense<long double>::Power(
     const VectorDense<long double> & vec_base,
     const VectorDense<long double> & vec_exponent)
{
#ifdef DEBUG_ALLOC
     this->CheckAllocation();
     vec_base.CheckAllocation();
     vec_exponent.CheckAllocation();
#endif

#ifdef DEBUG_COMPAT
     this->CheckCompatibility(vec_base);
     this->CheckCompatibility(vec_exponent);
#endif

     VEI i;
     const VEI ELEMS = this->elems;

     #pragma omp parallel default(none) \
     num_threads(NT_1D) \
     private(i)       \
     shared(vec_base) \
     shared(vec_exponent)
     {
          #pragma omp for

          for (i = 0; i < ELEMS; ++i) {

               this->vector[i] = std::pow(
                                      vec_base.vector[i],
                                      vec_exponent.vector[i]);
          }
     }
}

// Sin # 1

template<typename T1>
inline void VectorDense<T1>::Sin(const VectorDense<T1> & vec)
{
#ifdef DEBUG_ALLOC
     this->CheckAllocation();
     vec.CheckAllocation();
#endif

#ifdef DEBUG_COMPAT
     this->CheckCompatibility(vec);
#endif

     this->Map(vec, std::sin);
}

// Sin # 2

template<typename T1>
inline void VectorDense<T1>::Sin()
{
#ifdef DEBUG_ALLOC
     this->CheckAllocation();
#endif

     this->Map(std::sin);
}

} // sep
} // pgg

#endif // VECTOR_DENSE_CMATH_H

