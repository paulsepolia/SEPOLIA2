
#ifndef VECTOR_DENSE_ALGEBRA_BASIC_H
#define VECTOR_DENSE_ALGEBRA_BASIC_H

namespace pgg {
    namespace sep {

// Divide # 1

        template<typename T1>
        void VectorDense<T1>::Divide(const VectorDense <T1> &vecA,
                                     const VectorDense <T1> &vecB) {
            this->VectorVectorTypeA(vecA, vecB, functions::Divide);
        }

// Divide # 2

        template<typename T1>
        void VectorDense<T1>::Divide(const VectorDense <T1> &vec,
                                     const T1 &elem) {
            this->VectorScalarTypeA(vec, elem, functions::Divide);
        }

// Divide # 3

        template<typename T1>
        void VectorDense<T1>::Divide(const T1 &elem,
                                     const VectorDense <T1> &vec) {
            this->VectorScalarTypeA(vec, elem, functions::DivideInverse);
        }

// Divide # 4

        template<typename T1>
        void VectorDense<T1>::Divide(const T1 &elem) {
            this->VectorScalarTypeA(*this, elem, functions::Divide);
        }

// Divide # 5

        template<typename T1>
        void VectorDense<T1>::Divide(const VectorDense <T1> &vec) {
            this->VectorVectorTypeA(*this, vec, functions::Divide);
        }

// Minus

        template<typename T1>
        void VectorDense<T1>::Minus(const VectorDense <T1> &vec) {
            this->Map(vec, functions::Minus < T1 > );
        }

// Negate

        template<typename T1>
        void VectorDense<T1>::Negate() {
            this->Map(*this, functions::Minus < T1 > );
        }

// Plus # 1

        template<typename T1>
        void VectorDense<T1>::Plus(const VectorDense <T1> &vecA,
                                   const VectorDense <T1> &vecB) {
            this->VectorVectorTypeA(vecA, vecB, functions::Plus);
        }

// Plus # 2

        template<typename T1>
        void VectorDense<T1>::Plus(const VectorDense <T1> &vec,
                                   const T1 &elem) {
            this->VectorScalarTypeA(vec, elem, functions::Plus);
        }

// Plus # 3

        template<typename T1>
        void VectorDense<T1>::Plus(const T1 &elem,
                                   const VectorDense <T1> &vec) {
            this->VectorScalarTypeA(vec, elem, functions::Plus);
        }

// Plus # 4

        template<typename T1>
        void VectorDense<T1>::Plus(const T1 &elem) {
            this->VectorScalarTypeA(*this, elem, functions::Plus);
        }

// Plus # 5

        template<typename T1>
        void VectorDense<T1>::Plus(const VectorDense <T1> &vec) {
            this->VectorVectorTypeA(*this, vec, functions::Plus);
        }

// Subtract # 1

        template<typename T1>
        void VectorDense<T1>::Subtract(const VectorDense <T1> &vecA,
                                       const VectorDense <T1> &vecB) {
            this->VectorVectorTypeA(vecA, vecB, functions::Subtract);
        }

// Subtract # 2

        template<typename T1>
        void VectorDense<T1>::Subtract(const VectorDense <T1> &vec,
                                       const T1 &elem) {
            this->VectorScalarTypeA(vec, elem, functions::Subtract);
        }

// Subtract # 3

        template<typename T1>
        void VectorDense<T1>::Subtract(const T1 &elem,
                                       const VectorDense <T1> &vec) {
            this->VectorScalarTypeA(vec, elem, functions::SubtractNegate);
        }

// Subtract # 4

        template<typename T1>
        void VectorDense<T1>::Subtract(const T1 &elem) {
            this->VectorScalarTypeA(*this, elem, functions::Subtract);
        }

// Subtract # 5

        template<typename T1>
        void VectorDense<T1>::Subtract(const VectorDense <T1> &vec) {
            this->VectorVectorTypeA(*this, vec, functions::Subtract);
        }

// Times # 1

        template<typename T1>
        void VectorDense<T1>::Times(const VectorDense <T1> &vecA,
                                    const VectorDense <T1> &vecB) {
            this->VectorVectorTypeA(vecA, vecB, functions::Times);
        }

// Times # 2

        template<typename T1>
        void VectorDense<T1>::Times(const VectorDense <T1> &vec,
                                    const T1 &elem) {
            this->VectorScalarTypeA(vec, elem, functions::Times);
        }

// Times # 3

        template<typename T1>
        void VectorDense<T1>::Times(const T1 &elem,
                                    const VectorDense <T1> &vec) {
            this->VectorScalarTypeA(vec, elem, functions::Times);
        }

// Times # 4

        template<typename T1>
        void VectorDense<T1>::Times(const T1 &elem) {
            this->VectorScalarTypeA(*this, elem, functions::Times);
        }

// Times # 5

        template<typename T1>
        void VectorDense<T1>::Times(const VectorDense <T1> &vec) {
            this->VectorVectorTypeA(*this, vec, functions::Times);
        }

// VectorScalarTypeA

        template<typename T1>
        void VectorDense<T1>::VectorScalarTypeA(
                const VectorDense <T1> &vecA,
                const T1 &elem,
                T1 op_fn(const T1 &, const T1 &)) {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
            vecA.CheckAllocation();
#endif

#ifdef DEBUG_COMPAT
            this->CheckCompatibility(vecA);
#endif

            VEI i;
            T1 tmp_val;
            const VEI ELEMS = vecA.elems;

#pragma omp parallel default(none) \
     num_threads(NT_1D) \
     private(i)       \
     private(tmp_val) \
     shared(vecA)     \
     shared(elem)     \
     shared(op_fn)
            {
#pragma omp for

                for (i = 0; i < ELEMS; ++i) {
                    tmp_val = op_fn(vecA.vector[i], elem);
                    this->vector[i] = tmp_val;
                }
            }
        }

// VectorVectorTypeA

        template<typename T1>
        void VectorDense<T1>::VectorVectorTypeA(
                const VectorDense <T1> &vecA,
                const VectorDense <T1> &vecB,
                T1 op_fn(const T1 &, const T1 &)) {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
            vecA.CheckAllocation();
            vecB.CheckAllocation();
#endif

#ifdef DEBUG_COMPAT
            this->CheckCompatibility(vecA);
            this->CheckCompatibility(vecB);
#endif

            VEI i;
            T1 tmp_val;
            const VEI ELEMS = vecA.elems;

#pragma omp parallel default(none) \
     num_threads(NT_1D) \
     private(i)       \
     private(tmp_val) \
     shared(vecA)     \
     shared(vecB)     \
     shared(op_fn)
            {
#pragma omp for

                for (i = 0; i < ELEMS; ++i) {
                    tmp_val = op_fn(vecA.vector[i], vecB.vector[i]);
                    this->vector[i] = tmp_val;
                }
            }
        }

    } // sep
} // pgg

#endif // VECTOR_DENSE_ALGEBRA_BASIC_H

