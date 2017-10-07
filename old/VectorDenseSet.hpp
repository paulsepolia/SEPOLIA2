
#ifndef VECTOR_DENSE_SET_H
#define VECTOR_DENSE_SET_H

namespace pgg {
    namespace sep {

// Set # 1

        template<typename T1>
        void VectorDense<T1>::Set(const VectorDense <T1> &vec) {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
            vec.CheckAllocation();
#endif

#ifdef DEBUG_COMPAT
            this->CheckCompatibility(vec);
#endif

            const VEI ELEMS = vec.elems;
            VEI i;

#pragma omp parallel default(none) \
     num_threads(NT_1D) \
     private(i) \
     shared(vec)
            {
#pragma omp for

                for (i = 0; i < ELEMS; ++i) {
                    this->vector[i] = vec.vector[i];
                }
            }
        }

// Set # 2

        template<typename T1>
        void VectorDense<T1>::Set(const T1 &val) {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            const VEI ELEMS = this->elems;
            VEI i;

#pragma omp parallel default(none) \
     num_threads(NT_1D) \
     private(i)  \
     shared(val)
            {
#pragma omp for

                for (i = 0; i < ELEMS; ++i) {
                    this->vector[i] = static_cast<T1>(val);
                }
            }
        }

// SetColumn

        template<typename T1>
        template<typename T2>
        void VectorDense<T1>::SetColumn(const MAI &j_col, T2 &mat) const {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
            mat.CheckAllocation();
#endif

#ifdef DEBUG_COMPAT
            this->CheckCompatibility(mat, LEN_COL);
#endif

            const VEI ELEMS = this->GetNumberOfElements();
            VEI i;

#pragma omp parallel default(none) \
     num_threads(NT_1D) \
     private(i)    \
     shared(j_col) \
     shared(mat)
            {
#pragma omp for

                for (i = 0; i < ELEMS; ++i) {
                    mat.SetElement(static_cast<MAI>(i),
                                   j_col,
                                   this->vector[i]);
                }
            }
        }

// SetElement

        template<typename T1>
        void VectorDense<T1>::SetElement(const VEI &i,
                                         const T1 &elem) {
            // set the element (i)

            this->vector[i] = elem;
        }

// SetRow

        template<typename T1>
        template<typename T2>
        void VectorDense<T1>::SetRow(const MAI &i_row, T2 &mat) const {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
            mat.CheckAllocation();
#endif

#ifdef DEBUG_COMPAT
            this->CheckCompatibility(mat, LEN_ROW);
#endif

            VEI j;
            const VEI ELEMS = this->GetNumberOfElements();

#pragma omp parallel default(none) \
     num_threads(NT_1D) \
     private(j)    \
     shared(i_row) \
     shared(mat)
            {
#pragma omp for

                for (j = 0; j < ELEMS; ++j) {
                    mat.SetElement(i_row, static_cast<MAI>(j), this->vector[j]);
                }
            }
        }

    } // sep
} // pgg

#endif // VECTOR_DENSE_SET_H

