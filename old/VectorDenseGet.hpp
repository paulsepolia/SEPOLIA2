
#ifndef VECTOR_DENSE_GET_H
#define VECTOR_DENSE_GET_H

namespace pgg {
    namespace sep {

// GetColumn

        template<typename T1>
        template<typename T2>
        void VectorDense<T1>::GetColumn(const T2 &mat,
                                        const MAI &j_col) {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
            mat.CheckAllocation();
#endif

#ifdef DEBUG_COMPAT
            this->CheckCompatibility(mat, LEN_COL);
#endif

            const MAI ROWS = mat.GetNumberOfRows();
            MAI i;

#pragma omp parallel default(none) \
     num_threads(NT_1D) \
     private(i)    \
     shared(j_col) \
     shared(mat)
            {
#pragma omp for

                for (i = 0; i < ROWS; ++i) {
                    this->vector[static_cast<VEI>(i)] = mat(i, j_col);
                }
            }
        }

// GetElement

        template<typename T1>
        T1 VectorDense<T1>::GetElement(const VEI &index) const {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            return this->vector[index];
        }

// GetNumberOfElements

        template<typename T1>
        unsigned long int VectorDense<T1>::GetNumberOfElements() const {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            return this->elems;
        }

// GetRow

        template<typename T1>
        template<typename T2>
        void VectorDense<T1>::GetRow(const T2 &mat,
                                     const MAI &i_row) {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
            mat.CheckAllocation();
#endif

#ifdef DEBUG_COMPAT
            this->CheckCompatibility(mat, LEN_ROW);
#endif

            const MAI COLS = mat.GetNumberOfColumns();
            MAI j;

#pragma omp parallel default(none) \
     num_threads(NT_1D) \
     private(j)    \
     shared(i_row) \
     shared(mat)
            {
#pragma omp for

                for (j = 0; j < COLS; ++j) {
                    this->vector[static_cast<VEI>(j)] = mat(i_row, j);
                }
            }
        }

    } // sep
} // pgg

#endif // VECTOR_DENSE_GET_H

