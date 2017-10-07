
#ifndef VECTOR_DENSE_COMPLEX_H
#define VECTOR_DENSE_COMPLEX_H

#include <complex>

namespace pgg {
namespace sep {

// ImaginaryPart

template<typename T1>
template<typename T2>
void VectorDense<T1>::ImaginaryPart(
     const VectorDense<T2> & vecComplex)
{
#ifdef DEBUG_ALLOC
     this->CheckAllocation();
     vecComplex.CheckAllocation();
#endif

     const VEI ELEMS_IM = this->GetNumberOfElements();

#ifdef DEBUG_COMPAT
     const VEI ELEMS_CMPLX = vecComplex.GetNumberOfElements();

     if (ELEMS_CMPLX != ELEMS_IM) {
          functions::Exit(E_VEC_VEC_CONFORM_NOT);
     }
#endif

     VEI_MAX i;

     #pragma omp parallel default(none) \
     num_threads(NT_1D) \
     private(i)    \
     shared(vecComplex)
     {
          #pragma omp for

          for (i = 0; i < ELEMS_IM; ++i) {
               this->SetElement(i, imag(vecComplex(i)));
          }
     }
}

// RealPart

template<typename T1>
template<typename T2>
void VectorDense<T1>::RealPart(
     const VectorDense<T2> & vecComplex)
{
#ifdef DEBUG_ALLOC
     this->CheckAllocation();
     vecComplex.CheckAllocation();
#endif

     const VEI ELEMS_RE = this->GetNumberOfElements();

#ifdef DEBUG_COMPAT
     const VEI ELEMS_CMPLX = vecComplex.GetNumberOfElements();

     if (ELEMS_CMPLX != ELEMS_RE) {
          functions::Exit(E_VEC_VEC_CONFORM_NOT);
     }
#endif

     VEI_MAX i;

     #pragma omp parallel default(none) \
     num_threads(NT_1D) \
     private(i)    \
     shared(vecComplex)
     {
          #pragma omp for

          for (i = 0; i < ELEMS_RE; ++i) {
               this->SetElement(i, real(vecComplex(i)));
          }
     }
}

} // sep
} // pgg

#endif // VECTOR_DENSE_COMPLEX_H

