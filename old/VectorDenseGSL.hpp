
#ifndef VECTOR_DENSE_GSL_H
#define VECTOR_DENSE_GSL_H

#include "../head/sepolia_gsl.hpp"

namespace pgg {
    namespace sep {

// DotGSL # 1

        template<>
        double VectorDense<double>::DotGSL(const VectorDense<double> &vec) const {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
            vec.CheckAllocation();
#endif

#ifdef DEBUG_COMPAT
            this->CheckCompatibility(vec);
#endif

            // get the dimensions

            const VEI ELEMS = vec.elems;

            // local parameters and variables

            double tmp_double;

            // set gsl vector view

            gsl_vector_const_view A = gsl_vector_const_view_array(vec.vector, ELEMS);
            gsl_vector_const_view B = gsl_vector_const_view_array(this->vector, ELEMS);

            // compute double = dot(A,B) via gsl+blas simplified interface

            gsl_blas_ddot(&A.vector,
                          &B.vector,
                          &tmp_double);

            // return

            return tmp_double;
        }

// DotGSL # 2

        template<>
        template<typename T2>
        void VectorDense<double>::DotGSL(const T2 &mat,
                                         const VectorDense<double> &vec,
                                         const std::string &row_col) {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
            vec.CheckAllocation();
            mat.CheckAllocation();
#endif

            if (row_col == WITH_ROWS) {
#ifdef DEBUG_COMPAT
                vec.CheckCompatibility(mat, LEN_ROW);
                this->CheckCompatibility(mat, LEN_COL);
#endif

                // local parameters and variables

                const MAI ROWS = mat.GetNumberOfRows();
                const MAI COLS = mat.GetNumberOfColumns();

                // main code

                if (this == &vec) {
                    // declare and allocate tmp vector

                    VectorDense<double> vec_tmp;
                    vec_tmp.Allocate(ROWS);

                    // execution

                    gsl_matrix_const_view mA =
                            gsl_matrix_const_view_array(mat.matrix, ROWS, COLS);

                    gsl_vector_const_view vA =
                            gsl_vector_const_view_array(vec.vector, COLS);

                    gsl_vector_view vB =
                            gsl_vector_view_array(vec_tmp.vector, ROWS);

                    gsl_blas_dgemv(CblasNoTrans,  //  1 --> CblasNoTrans, CblasTrans
                                   ONE_DBL,       //  2 --> alpha
                                   &mA.matrix,    //  3 --> *a
                                   &vA.vector,    //  4 --> *b
                                   ZERO_DBL,      //  5 --> beta
                                   &vB.vector);   //  6 --> *c

                    this->Set(vec_tmp);

                    // deallocate tmp vector

                    vec_tmp.Deallocate();
                } else if (this != &vec) {

                    // execution

                    gsl_matrix_const_view mA =
                            gsl_matrix_const_view_array(mat.matrix, ROWS, COLS);

                    gsl_vector_const_view vA =
                            gsl_vector_const_view_array(vec.vector, COLS);

                    gsl_vector_view vB =
                            gsl_vector_view_array(this->vector, ROWS);

                    gsl_blas_dgemv(CblasNoTrans,   //  1 --> CblasNoTrans, CblasTrans
                                   ONE_DBL,        //  2 --> alpha
                                   &mA.matrix,     //  3 --> *a
                                   &vA.vector,     //  4 --> *b
                                   ZERO_DBL,       //  5 --> beta
                                   &vB.vector);    //  6 --> *c
                }
            } else if (row_col == WITH_COLS) {
#ifdef DEBUG_COMPAT
                vec.CheckCompatibility(mat, LEN_COL);
                this->CheckCompatibility(mat, LEN_ROW);
#endif

                // local parameters and variables

                const MAI ROWS = mat.GetNumberOfRows();
                const MAI COLS = mat.GetNumberOfColumns();

                // main code

                if (this == &vec) {
                    // declare and allocate tmp vector

                    VectorDense<double> vec_tmp;
                    vec_tmp.Allocate(COLS);

                    // execution

                    gsl_matrix_const_view mA =
                            gsl_matrix_const_view_array(mat.matrix, ROWS, COLS);

                    gsl_vector_const_view vA =
                            gsl_vector_const_view_array(vec.vector, COLS);

                    gsl_vector_view vB =
                            gsl_vector_view_array(vec_tmp.vector, ROWS);

                    gsl_blas_dgemv(CblasNoTrans,  //  1 --> CblasNoTrans, CblasTrans
                                   ONE_DBL,       //  2 --> alpha
                                   &mA.matrix,    //  3 --> *a
                                   &vA.vector,    //  4 --> *b
                                   ZERO_DBL,      //  5 --> beta
                                   &vB.vector);   //  6 --> *c

                    this->Set(vec_tmp);

                    // deallocate tmp vector

                    vec_tmp.Deallocate();
                } else if (this != &vec) {

                    // execution

                    gsl_matrix_const_view mA =
                            gsl_matrix_const_view_array(mat.matrix, ROWS, COLS);

                    gsl_vector_const_view vA =
                            gsl_vector_const_view_array(vec.vector, ROWS);

                    gsl_vector_view vB =
                            gsl_vector_view_array(this->vector, COLS);

                    gsl_blas_dgemv(CblasTrans,    //  1 --> CblasNoTrans, CblasTrans
                                   ONE_DBL,       //  2 --> alpha
                                   &mA.matrix,    //  3 --> *a
                                   &vA.vector,    //  4 --> *b
                                   ZERO_DBL,      //  5 --> beta
                                   &vB.vector);   //  6 --> *c

                }
            } else {
                functions::Exit(E_MAT_VEC_DOT_TYPE_NOT);
            }

            // return
        }

    } // sep
} // pgg

#endif // VECTOR_DENSE_GSL_H
