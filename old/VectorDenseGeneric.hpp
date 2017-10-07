
#ifndef VECTOR_DENSE_GENERIC_H
#define VECTOR_DENSE_GENERIC_H

#include <string>
#include <complex>

namespace pgg {
namespace sep {

//========================//
// Complex Double Vectors //
//========================//

// Dot # 1

template<>
std::complex<double> VectorDense<std::complex<double>>::Dot(
               const VectorDense<std::complex<double>> & vec) const
{
#ifdef DEBUG_ALLOC
     this->CheckAllocation();
     vec.CheckAllocation();
#endif

#ifdef DEBUG_COMPAT
     this->CheckCompatibility(vec);
#endif

     std::complex<double> tmp_cmplx = ZERO_CMPLX;

     tmp_cmplx = this->DotBLAS(vec);

     return tmp_cmplx;
}

// Dot # 2

template<>
template<typename T2>
void VectorDense<std::complex<double>>::Dot(
          const T2 & mat,
          const VectorDense<std::complex<double>> & vec,
          const std::string & row_col)
{
#ifdef DEBUG_ALLOC
     this->CheckAllocation();
     mat.CheckAllocation();
     vec.CheckAllocation();
#endif

     this->DotBLAS(mat, vec, row_col);
}

//=====================//
// Real Double Vectors //
//=====================//

// Dot # 1

template<>
double VectorDense<double>::Dot(const VectorDense<double> & vec,
                                const std::string & str_val) const
{
#ifdef DEBUG_ALLOC
     this->CheckAllocation();
     vec.CheckAllocation();
#endif

#ifdef DEBUG_COMPAT
     this->CheckCompatibility(vec);
#endif

     double tmp_double = ZERO_DBL;

     if (str_val == GSL_LIB) {
          tmp_double = this->DotGSL(vec);
     } else if (str_val == BLAS_LIB) {
          tmp_double = this->DotBLAS(vec);
     } else {
          functions::Exit(E_VEC_LIB_TYPE_NOT);
     }

     return tmp_double;
}

// Dot # 2

template<>
template<typename T2>
void VectorDense<double>::Dot(const T2 & mat,
                              const VectorDense<double> & vec,
                              const std::string & row_col,
                              const std::string & str_val)
{
#ifdef DEBUG_ALLOC
     this->CheckAllocation();
     mat.CheckAllocation();
     vec.CheckAllocation();
#endif

     if (str_val == GSL_LIB) {
          this->DotGSL(mat, vec, row_col);
     } else if (str_val == BLAS_LIB) {
          this->DotBLAS(mat, vec, row_col);
     } else {
          functions::Exit(E_VEC_LIB_TYPE_NOT);
     }
}

} // sep
} // pgg

#endif // VECTOR_DENSE_GENERIC_H

