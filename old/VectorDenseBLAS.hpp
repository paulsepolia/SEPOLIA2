
#ifndef VECTOR_DENSE_BLAS_H
#define VECTOR_DENSE_BLAS_H

#include "../head/sepolia_gsl.hpp"

namespace pgg {
    namespace sep {

//=======================//
// Complex Double vector //
//=======================//

// DotBLAS # 1

        template<>
        std::complex<double> VectorDense<std::complex < double>>
        ::DotBLAS(
        const VectorDense<std::complex < double>> & vec) const {
#ifdef DEBUG_ALLOC
        this->CheckAllocation();
        vec.CheckAllocation();
#endif

#ifdef DEBUG_COMPAT
        this->CheckCompatibility(vec);
#endif

        // get the number of elements

        const VEI ELEMS = vec.elems;

        // local parameters and variables

        const auto ONE = static_cast<BLAS_INT>(1);
        std::complex<double> tmp_cmplx;

        cblas_zdotu_sub(ELEMS,
        static_cast<void *>(this->vector),
        ONE,
        vec.vector,
        ONE,
        &tmp_cmplx);

        // return

        return
        tmp_cmplx;
    }

// DotBLAS # 2

    template<>
    template<typename T2>
    void VectorDense<std::complex < double>>
    ::DotBLAS(
    const T2 &mat,
    const VectorDense<std::complex < double>> & vec,
    const std::string &row_col
    ) {
#ifdef DEBUG_ALLOC
    this->CheckAllocation();
    mat.CheckAllocation();
    vec.CheckAllocation();
#endif


    if(row_col == WITH_ROWS) {
#ifdef DEBUG_COMPAT
    vec.CheckCompatibility(mat, LEN_ROW);
    this->CheckCompatibility(mat, LEN_COL);
#endif

    // local parameters and variables

    const MAI ROWS = mat.GetNumberOfRows();
    const MAI COLS = mat.GetNumberOfColumns();

    if(this == &vec) {
    // declare and allocate tmp vector

    VectorDense<std::complex < double>>
    vec_tmp;
    vec_tmp.
    Allocate(ROWS);

    // execution

    cblas_zgemv(CblasRowMajor,               //  1 --> CblasRowMajor, CblasColMajor
            CblasNoTrans,                //  2 --> CblasNoTrans, CblasTrans
    static_cast
    <BLAS_INT>(ROWS), //  3 --> m
    static_cast
    <BLAS_INT>(COLS), //  4 --> n
            &ONE_CMPLX,                  //  5 --> alpha
            mat
    .matrix,                  //  6 --> *a
    static_cast
    <BLAS_INT>(COLS), //  7 --> lda
            vec
    .vector,                  //  8 --> *b
    static_cast<BLAS_INT>(1),    //  9 --> incx
    &ZERO_CMPLX,                 // 10 --> beta
    vec_tmp.vector,              // 11 --> *c
    static_cast<BLAS_INT>(1));   // 12 --> ldc

    this->
    Set(vec_tmp);

    // deallocate tmp vector

    vec_tmp.

    Deallocate();
}
else if(this != &vec) {

// execution

cblas_zgemv(CblasRowMajor,                //  1 --> CblasRowMajor, CblasColMajor
        CblasNoTrans,                 //  2 --> CblasNoTrans, CblasTrans
static_cast
<BLAS_INT>(ROWS),  //  3 --> m
static_cast
<BLAS_INT>(COLS),  //  4 --> n
        &ONE_CMPLX,                   //  5 --> alpha
        mat
.matrix,                   //  6 --> *a
static_cast
<BLAS_INT>(COLS),  //  7 --> lda
        vec
.vector,                   //  8 --> *b
static_cast<BLAS_INT>(1),     //  9 --> incx
&ZERO_CMPLX,                  // 10 --> beta
this->vector,                 // 11 --> *c
static_cast<BLAS_INT>(1));    // 12 --> incy
}
} else if(row_col == WITH_COLS) {
#ifdef DEBUG_COMPAT
vec.CheckCompatibility(mat, LEN_COL);
this->CheckCompatibility(mat, LEN_ROW);
#endif

// local parameters and variables

const MAI ROWS = mat.GetNumberOfRows();
const MAI COLS = mat.GetNumberOfColumns();

if(this == &vec) {
// declare and allocate tmp vector

VectorDense <std::complex<double>> vec_tmp;
vec_tmp.
Allocate(COLS);

// execution

cblas_zgemv(CblasRowMajor,                //  1 --> CblasRowMajor, CblasColMajor
        CblasTrans,                   //  2 --> CblasNoTrans, CblasTrans
static_cast
<BLAS_INT>(ROWS),  //  3 --> m
static_cast
<BLAS_INT>(COLS),  //  4 --> n
        &ONE_CMPLX,                   //  5 --> alpha
        mat
.matrix,                   //  6 --> *a
static_cast
<BLAS_INT>(COLS),  //  7 --> lda
        vec
.vector,                   //  8 --> *b
static_cast<BLAS_INT>(1),     //  9 --> incx
&ZERO_CMPLX,                  // 10 --> beta
vec_tmp.vector,               // 11 --> *c
static_cast<BLAS_INT>(1));    // 12 --> ldc

this->
Set(vec_tmp);

// deallocate tmp vector

vec_tmp.

Deallocate();

} else if(this != &vec) {

// execution

cblas_zgemv(CblasRowMajor,                //  1 --> CblasRowMajor, CblasColMajor
        CblasTrans,                   //  2 --> CblasNoTrans, CblasTrans
static_cast
<BLAS_INT>(ROWS),  //  3 --> m
static_cast
<BLAS_INT>(COLS),  //  4 --> n
        &ONE_CMPLX,                   //  5 --> alpha
        mat
.matrix,                   //  6 --> *a
static_cast
<BLAS_INT>(COLS),  //  7 --> lda
        vec
.vector,                   //  8 --> *b
static_cast<BLAS_INT>(1),     //  9 --> incx
&ZERO_CMPLX,                  // 10 --> beta
this->vector,                 // 11 --> *c
static_cast<BLAS_INT>(1));    // 12 --> incy
}
} else {
functions::Exit(E_MAT_VEC_DOT_TYPE_NOT);
}

// return
}

//===============//
// Double vector //
//===============//

// DotBLAS # 1

template<>
double VectorDense<double>::DotBLAS(const VectorDense<double> &vec) const {
#ifdef DEBUG_ALLOC
    this->CheckAllocation();
    vec.CheckAllocation();
#endif

#ifdef DEBUG_COMPAT
    this->CheckCompatibility(vec);
#endif

    // get the number of elements

    const VEI ELEMS = vec.elems;

    // local parameters and variables

    const auto ONE = static_cast<BLAS_INT>(1);
    double tmp_double;

    tmp_double = cblas_ddot(ELEMS,
                            this->vector,
                            ONE,
                            vec.vector,
                            ONE);

    // return

    return tmp_double;
}

// DotBLAS # 2

template<>
template<typename T2>
void VectorDense<double>::DotBLAS(const T2 &mat,
                                  const VectorDense<double> &vec,
                                  const std::string &row_col) {
#ifdef DEBUG_ALLOC
    this->CheckAllocation();
    mat.CheckAllocation();
    vec.CheckAllocation();
#endif


    if (row_col == WITH_ROWS) {
#ifdef DEBUG_COMPAT
        vec.CheckCompatibility(mat, LEN_ROW);
        this->CheckCompatibility(mat, LEN_COL);
#endif

        // local parameters and variables

        const MAI ROWS = mat.GetNumberOfRows();
        const MAI COLS = mat.GetNumberOfColumns();

        if (this == &vec) {
            // declare and allocate tmp vector

            VectorDense<double> vec_tmp;
            vec_tmp.Allocate(ROWS);

            // execution

            cblas_dgemv(CblasRowMajor,               //  1 --> CblasRowMajor, CblasColMajor
                        CblasNoTrans,                //  2 --> CblasNoTrans, CblasTrans
                        static_cast<BLAS_INT>(ROWS), //  3 --> m
                        static_cast<BLAS_INT>(COLS), //  4 --> n
                        ONE_DBL,                     //  5 --> alpha
                        mat.matrix,                  //  6 --> *a
                        static_cast<BLAS_INT>(COLS), //  7 --> lda
                        vec.vector,                  //  8 --> *b
                        static_cast<BLAS_INT>(1),    //  9 --> incx
                        ZERO_DBL,                    // 10 --> beta
                        vec_tmp.vector,              // 11 --> *c
                        static_cast<BLAS_INT>(1));   // 12 --> ldc

            this->Set(vec_tmp);

            // deallocate tmp vector

            vec_tmp.Deallocate();
        } else if (this != &vec) {

            // execution

            cblas_dgemv(CblasRowMajor,                //  1 --> CblasRowMajor, CblasColMajor
                        CblasNoTrans,                 //  2 --> CblasNoTrans, CblasTrans
                        static_cast<BLAS_INT>(ROWS),  //  3 --> m
                        static_cast<BLAS_INT>(COLS),  //  4 --> n
                        ONE_DBL,                      //  5 --> alpha
                        mat.matrix,                   //  6 --> *a
                        static_cast<BLAS_INT>(COLS),  //  7 --> lda
                        vec.vector,                   //  8 --> *b
                        static_cast<BLAS_INT>(1),     //  9 --> incx
                        ZERO_DBL,                     // 10 --> beta
                        this->vector,                 // 11 --> *c
                        static_cast<BLAS_INT>(1));    // 12 --> incy
        }
    } else if (row_col == WITH_COLS) {
#ifdef DEBUG_COMPAT
        vec.CheckCompatibility(mat, LEN_COL);
        this->CheckCompatibility(mat, LEN_ROW);
#endif

        // local parameters and variables

        const MAI ROWS = mat.GetNumberOfRows();
        const MAI COLS = mat.GetNumberOfColumns();

        if (this == &vec) {
            // declare and allocate tmp vector

            VectorDense<double> vec_tmp;
            vec_tmp.Allocate(COLS);

            // execution

            cblas_dgemv(CblasRowMajor,                //  1 --> CblasRowMajor, CblasColMajor
                        CblasTrans,                   //  2 --> CblasNoTrans, CblasTrans
                        static_cast<BLAS_INT>(ROWS),  //  3 --> m
                        static_cast<BLAS_INT>(COLS),  //  4 --> n
                        ONE_DBL,                      //  5 --> alpha
                        mat.matrix,                   //  6 --> *a
                        static_cast<BLAS_INT>(COLS),  //  7 --> lda
                        vec.vector,                   //  8 --> *b
                        static_cast<BLAS_INT>(1),     //  9 --> incx
                        ZERO_DBL,                     // 10 --> beta
                        vec_tmp.vector,               // 11 --> *c
                        static_cast<BLAS_INT>(1));    // 12 --> ldc

            this->Set(vec_tmp);

            // deallocate tmp vector

            vec_tmp.Deallocate();
        } else if (this != &vec) {

            // execution

            cblas_dgemv(CblasRowMajor,                //  1 --> CblasRowMajor, CblasColMajor
                        CblasTrans,                   //  2 --> CblasNoTrans, CblasTrans
                        static_cast<BLAS_INT>(ROWS),  //  3 --> m
                        static_cast<BLAS_INT>(COLS),  //  4 --> n
                        ONE_DBL,                      //  5 --> alpha
                        mat.matrix,                   //  6 --> *a
                        static_cast<BLAS_INT>(COLS),  //  7 --> lda
                        vec.vector,                   //  8 --> *b
                        static_cast<BLAS_INT>(1),     //  9 --> incx
                        ZERO_DBL,                     // 10 --> beta
                        this->vector,                 // 11 --> *c
                        static_cast<BLAS_INT>(1));    // 12 --> incy
        }
    } else {
        functions::Exit(E_MAT_VEC_DOT_TYPE_NOT);
    }

    // return
}

} // sep
} // pgg

#endif // VECTOR_DENSE_BLAS_H
