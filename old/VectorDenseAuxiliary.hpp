
#ifndef VECTOR_DENSE_AUXILIARY_H
#define VECTOR_DENSE_AUXILIARY_H

#include <complex>

namespace pgg {
    namespace sep {

// CheckAllocation

        template<typename T1>
        bool VectorDense<T1>::CheckAllocation() const {
            if (this->DeallocatedQ()) {
                functions::Exit(E_VEC_ALLOC_NOT);
            }

            return true;
        }

// CheckCompatibility # 1

        template<typename T1>
        bool VectorDense<T1>::CheckCompatibility(
                const VectorDense <T1> &vec) const {
#ifdef CHECK_ALLOC
            this->CheckAllocation();
            vec.CheckAllocation();
#endif

            // test for elements equality

            if (this->elems != vec.elems) {
                functions::Exit(E_VEC_VEC_CONFORM_NOT);
            }

            return true;
        }

// CheckCompatibility # 2

        template<typename T1>
        template<typename T2>
        bool VectorDense<T1>::CheckCompatibility(const T2 &mat,
                                                 const std::string &row_col) const {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
            mat.CheckAllocation();
#endif

            // test for equality

            // # 1

            if (row_col == LEN_ROW) {
                if (this->elems != mat.GetNumberOfColumns()) {
                    functions::Exit(E_VEC_MAT_CONFORM_NOT);
                }
            }

            // # 2

            if (row_col == LEN_COL) {
                if (this->elems != mat.GetNumberOfRows()) {
                    functions::Exit(E_VEC_MAT_CONFORM_NOT);
                }
            }

            return true;
        }

// Equal # 1

        template<typename T1>
        bool VectorDense<T1>::Equal(const T1 &elem,
                                    const T1 &thres) const {
            return this->VectorScalarEqual(elem, thres, functions::Equal);
        }

// Equal # 2

        template<typename T1>
        bool VectorDense<T1>::Equal(const VectorDense <T1> &vec,
                                    const T1 &thres) const {
            return this->VectorVectorEqual(vec, thres, functions::Equal);
        }

// Equal # 3 --> complex<double>

        template<>
        bool VectorDense<std::complex<double>>::Equal(
                const std::complex<double> &elem,
                const std::complex<double> &thres) const {
            return this->VectorScalarEqual(elem, thres, functions::Equal);
        }

// Equal # 4 --> complex<double>

        template<>
        bool VectorDense<std::complex<double>>::Equal(
                const VectorDense <std::complex<double>> &vec,
                const std::complex<double> &thres) const {
            return this->VectorVectorEqual(vec, thres, functions::Equal);
        }

// Equal # 5 --> complex<long double>

        template<>
        bool VectorDense<std::complex<long double>>::Equal(
                const std::complex<long double> &elem,
                const std::complex<long double> &thres) const {
            return this->VectorScalarEqual(elem, thres, functions::Equal);
        }

// Equal # 6 --> complex<double>

        template<>
        bool VectorDense<std::complex<long double>>::Equal(
                const VectorDense <std::complex<long double>> &vec,
                const std::complex<long double> &thres) const {
            return this->VectorVectorEqual(vec, thres, functions::Equal);
        }

// Greater # 1

        template<typename T1>
        bool VectorDense<T1>::Greater(
                const T1 &elem) const {
            return this->VectorScalarComparison(elem, functions::Greater);
        }

// Greater # 2

        template<typename T1>
        bool VectorDense<T1>::Greater(
                const VectorDense <T1> &vec) const {
            return this->VectorVectorComparison(vec, functions::Greater);
        }

// Greater # 3 --> complex<double>

        template<>
        bool VectorDense<std::complex<double>>::Greater(
                const std::complex<double> &elem) const {
            return this->VectorScalarComparison(elem, functions::Greater);
        }

// Greater # 4 --> complex<double>

        template<>
        bool VectorDense<std::complex<double>>::Greater(
                const VectorDense <std::complex<double>> &vec) const {
            return this->VectorVectorComparison(vec, functions::Greater);
        }

// Greater # 5 --> complex<long double>

        template<>
        bool VectorDense<std::complex<long double>>::Greater(
                const std::complex<long double> &elem) const {
            return this->VectorScalarComparison(elem, functions::Greater);
        }

// Greater # 6 --> complex<long double>

        template<>
        bool VectorDense<std::complex<long double>>::Greater(
                const VectorDense <std::complex<long double>> &vec) const {
            return this->VectorVectorComparison(vec, functions::Greater);
        }

// GreaterEqual # 1

        template<typename T1>
        bool VectorDense<T1>::GreaterEqual(
                const T1 &elem) const {
            return this->VectorScalarComparison(elem, functions::GreaterEqual);
        }

// GreaterEqual # 2

        template<typename T1>
        bool VectorDense<T1>::GreaterEqual(
                const VectorDense <T1> &vec) const {
            return this->VectorVectorComparison(vec, functions::GreaterEqual);
        }

// GreaterEqual # 3 --> complex<double>

        template<>
        bool VectorDense<std::complex<double>>::GreaterEqual(
                const std::complex<double> &elem) const {
            return this->VectorScalarComparison(elem, functions::GreaterEqual);
        }

// GreaterEqual # 4 --> complex<double>

        template<>
        bool VectorDense<std::complex<double>>::GreaterEqual(
                const VectorDense <std::complex<double>> &vec) const {
            return this->VectorVectorComparison(vec, functions::GreaterEqual);
        }

// GreaterEqual # 5 --> complex<long double>

        template<>
        bool VectorDense<std::complex<long double>>::GreaterEqual(
                const std::complex<long double> &elem) const {
            return this->VectorScalarComparison(elem, functions::GreaterEqual);
        }

// GreaterEqual # 6 --> complex<long double>

        template<>
        bool VectorDense<std::complex<long double>>::GreaterEqual(
                const VectorDense <std::complex<long double>> &vec) const {
            return this->VectorVectorComparison(vec, functions::GreaterEqual);
        }

// Less # 1

        template<typename T1>
        bool VectorDense<T1>::Less(
                const T1 &elem) const {
            return this->VectorScalarComparison(elem, functions::Less);
        }

// Less # 2

        template<typename T1>
        bool VectorDense<T1>::Less(
                const VectorDense <T1> &vec) const {
            return this->VectorVectorComparison(vec, functions::Less);
        }

// Less # 3 --> complex<double>

        template<>
        bool VectorDense<std::complex<double>>::Less(
                const std::complex<double> &elem) const {
            return this->VectorScalarComparison(elem, functions::Less);
        }

// Less # 4 --> complex<double>

        template<>
        bool VectorDense<std::complex<double>>::Less(
                const VectorDense <std::complex<double>> &vec) const {
            return this->VectorVectorComparison(vec, functions::Less);
        }

// Less # 5 --> complex<long double>

        template<>
        bool VectorDense<std::complex<long double>>::Less(
                const std::complex<long double> &elem) const {
            return this->VectorScalarComparison(elem, functions::Less);
        }

// Less # 6 --> complex<long double>

        template<>
        bool VectorDense<std::complex<long double>>::Less(
                const VectorDense <std::complex<long double>> &vec) const {
            return this->VectorVectorComparison(vec, functions::Less);
        }

// LessEqual # 1

        template<typename T1>
        bool VectorDense<T1>::LessEqual(
                const T1 &elem) const {
            return this->VectorScalarComparison(elem, functions::LessEqual);
        }

// LessEqual # 2

        template<typename T1>
        bool VectorDense<T1>::LessEqual(
                const VectorDense <T1> &vec) const {
            return this->VectorVectorComparison(vec, functions::LessEqual);
        }

// LessEqual # 3 --> complex<double>

        template<>
        bool VectorDense<std::complex<double>>::LessEqual(
                const std::complex<double> &elem) const {
            return this->VectorScalarComparison(elem, functions::LessEqual);
        }

// LessEqual # 4 --> complex<double>

        template<>
        bool VectorDense<std::complex<double>>::LessEqual(
                const VectorDense <std::complex<double>> &vec) const {
            return this->VectorVectorComparison(vec, functions::LessEqual);
        }

// LessEqual # 5 --> complex<long double>

        template<>
        bool VectorDense<std::complex<long double>>::LessEqual(
                const std::complex<long double> &elem) const {
            return this->VectorScalarComparison(elem, functions::LessEqual);
        }

// LessEqual # 6 --> complex<long double>

        template<>
        bool VectorDense<std::complex<long double>>::LessEqual(
                const VectorDense <std::complex<long double>> &vec) const {
            return this->VectorVectorComparison(vec, functions::LessEqual);
        }

// Map # 1

        template<typename T1>
        void VectorDense<T1>::Map(T1 function_to_apply(T1)) {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            const VEI ELEMS = this->elems;
            VEI i;

#pragma omp parallel default(none) \
     num_threads(NT_1D) \
     private(i)    \
     shared(function_to_apply)
            {
#pragma omp for

                for (i = 0; i < ELEMS; ++i) {

                    this->vector[i] =
                            function_to_apply(this->vector[i]);
                }
            }
        }

// Map # 2

        template<typename T1>
        void VectorDense<T1>::Map(
                const VectorDense <T1> &vec,
                T1 function_to_apply(T1)) {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
            vec.CheckAllocation();
#endif

#ifdef DEBUG_COMPAT
            this->CheckCompatibility(vec);
#endif

            const VEI ELEMS = this->elems;
            VEI i;

#pragma omp parallel default(none) \
     num_threads(NT_1D) \
     private(i)   \
     shared(vec)  \
     shared(function_to_apply)
            {
#pragma omp for

                for (i = 0; i < ELEMS; ++i) {

                    this->vector[i] = function_to_apply(vec.vector[i]);
                }
            }
        }

// Map # 3

        template<typename T1>
        template<typename T2>
        void VectorDense<T1>::Map(T2 &fun_obj) {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            const VEI ELEMS = this->elems;
            VEI i;

#pragma omp parallel default(none) \
     num_threads(NT_1D) \
     private(i) \
     shared(fun_obj)
            {
#pragma omp for

                for (i = 0; i < ELEMS; ++i) {

                    this->vector[i] = fun_obj(this->vector[i]);
                }
            }
        }

// Map # 4

        template<typename T1>
        template<typename T2>
        void VectorDense<T1>::Map(const VectorDense <T1> &vec,
                                  T2 &fun_obj) {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
            vec.CheckAllocation();
#endif

#ifdef DEBUG_COMPAT
            this->CheckCompatibility(vec);
#endif

            const VEI ELEMS = this->elems;
            VEI i;

#pragma omp parallel default(none) \
     num_threads(NT_1D) \
     private(i)   \
     shared(vec)  \
     shared(fun_obj)
            {
#pragma omp for

                for (i = 0; i < ELEMS; ++i) {

                    this->vector[i] = fun_obj(vec.vector[i]);
                }
            }
        }

// Mean

        template<typename T1>
        T1 VectorDense<T1>::Mean() const {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            T1 mean_val = static_cast<T1>(ZERO_DBL_MAX);

            const VEI ELEMS = this->elems;
            VEI i;

#pragma omp parallel default(none) \
     num_threads(NT_1D) \
     private(i)    \
reduction(+:mean_val)
            {
#pragma omp for

                for (i = 0; i < ELEMS; ++i) {
                    mean_val = mean_val + this->vector[i];
                }
            }

            // take the mean

            mean_val = mean_val / static_cast<T1>(ELEMS);

            // return

            return mean_val;
        }

// Nest # 1

        template<typename T1>
        void VectorDense<T1>::Nest(T1 function_to_apply(T1),
                                   const VEI &n) {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            VEI i;

            for (i = 0; i != n; ++i) {
                this->Map(function_to_apply);
            }
        }

// Nest # 2

        template<typename T1>
        void VectorDense<T1>::Nest(const VectorDense <T1> &vec,
                                   T1 function_to_apply(T1),
                                   const VEI &n) {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
            vec.CheckAllocation();
#endif

#ifdef DEBUG_COMPAT
            this->CheckCompatibility(vec);
#endif

            this->Set(vec);

            VEI i;

            for (i = 0; i != n; ++i) {
                this->Map(*this, function_to_apply);
            }
        }

// Nest # 3

        template<typename T1>
        template<typename T2>
        void VectorDense<T1>::Nest(T2 &fun_obj,
                                   const VEI &n) {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            VEI i;

            for (i = 0; i != n; ++i) {
                this->Map(*this, fun_obj);
            }
        }

// Nest # 4

        template<typename T1>
        template<typename T2>
        void VectorDense<T1>::Nest(const VectorDense <T1> &vec,
                                   T2 &fun_obj,
                                   const VEI &n) {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
            vec.CheckAllocation();
#endif

#ifdef DEBUG_COMPAT
            this->CheckCompatibility(vec);
#endif

            this->Set(vec);

            VEI i;

            for (i = 0; i != n; ++i) {
                this->Map(*this, fun_obj);
            }
        }

// NotEqual # 1

        template<typename T1>
        bool VectorDense<T1>::NotEqual(const VectorDense <T1> &vec,
                                       const T1 &thres) const {
            return !this->Equal(vec, thres);
        }

// NotEqual # 2

        template<typename T1>
        bool VectorDense<T1>::NotEqual(const T1 &elem,
                                       const T1 &thres) const {
            return !this->Equal(elem, thres);
        }

// Random

        template<typename T1>
        void VectorDense<T1>::Random(const T1 &my_start,
                                     const T1 &my_end,
                                     const unsigned int &my_seed) {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            // local parameters

            T1 tmp_val;

            const VEI ELEMS = this->elems;
            const auto DIFF = my_end - my_start;
            const auto START = my_start;
            VEI i;

            // seed the random generator

            srand(my_seed);

            // build the random vector

            for (i = 0; i < ELEMS; ++i) {

                tmp_val = START + (static_cast<T1>(rand()) / RAND_MAX) * DIFF;
                this->vector[i] = tmp_val;
            }
        }

// Range # 1

        template<typename T1>
        void VectorDense<T1>::Range(const T1 &my_start) {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            T1 tmp_val;

            const VEI ELEMS = this->elems;
            VEI i;

            // build the vector

#pragma omp parallel default(none)   \
     num_threads(NT_1D) \
     private(i)       \
     private(tmp_val) \
     shared(my_start)
            {
#pragma omp for

                for (i = 0; i < ELEMS; ++i) {

                    tmp_val = static_cast<T1>(i + my_start);
                    this->vector[i] = tmp_val;
                }
            }
        }

// Range # 2

        template<typename T1>
        void VectorDense<T1>::Range(const T1 &my_start, const T1 &my_end) {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            VEI i;
            T1 tmp_val;

            const VEI ELEMS = this->elems;
            const T1 STEP = (my_end - my_start) / static_cast<T1>(ELEMS);

            // build the vector

#pragma omp parallel default(none) \
     num_threads(NT_1D) \
     private(i)       \
     private(tmp_val) \
     shared(my_start)
            {
#pragma omp for

                for (i = 0; i < ELEMS; ++i) {

                    tmp_val = i * STEP + my_start;
                    this->vector[i] = tmp_val;
                }
            }
        }

// SetMax # 1

        template<typename T1>
        void VectorDense<T1>::SetMax(const T1 &max_val, const T1 &set_max) {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            const VEI ELEMS = this->elems;
            VEI i;

            // build the vector

#pragma omp parallel default(none)   \
     num_threads(NT_1D) \
     private(i)      \
     shared(max_val) \
     shared(set_max)
            {
#pragma omp for

                for (i = 0; i < ELEMS; ++i) {

                    if (this->vector[i] > max_val) {
                        this->vector[i] = static_cast<T1>(set_max);
                    }
                }
            }
        }

// SetMax # 2

        template<typename T1>
        void VectorDense<T1>::SetMax(const T1 &comp_val) {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            const VEI ELEMS = this->elems;
            VEI i;

            // build the vector

#pragma omp parallel default(none) \
     num_threads(NT_1D) \
     private(i)       \
     shared(comp_val)
            {
#pragma omp for

                for (i = 0; i < ELEMS; ++i) {

                    this->vector[i] = std::max(this->vector[i], comp_val);
                }
            }
        }

// SetMax # 3

        template<typename T1>
        void VectorDense<T1>::SetMax(const VectorDense <T1> &vec,
                                     const T1 &comp_val) {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
            vec.CheckAllocation();
#endif

#ifdef DEBUG_COMPAT
            this->CheckCompatibility(vec);
#endif

            const VEI ELEMS = this->elems;
            VEI i;

            // build the vector

#pragma omp parallel default(none)   \
     num_threads(NT_1D) \
     private(i)       \
     shared(comp_val) \
     shared(vec)
            {
#pragma omp for

                for (i = 0; i < ELEMS; ++i) {
                    this->vector[i] = std::max(vec.vector[i], comp_val);
                }
            }
        }

// SetMin # 1

        template<typename T1>
        void VectorDense<T1>::SetMin(const T1 &min_val,
                                     const T1 &set_min) {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            const VEI ELEMS = this->elems;
            VEI i;

            // build the vector

#pragma omp parallel default(none)   \
     num_threads(NT_1D) \
     private(i)       \
     shared(min_val)  \
     shared(set_min)
            {
#pragma omp for

                for (i = 0; i < ELEMS; ++i) {

                    if (this->vector[i] < min_val) {
                        this->vector[i] = static_cast<T1>(set_min);
                    }
                }
            }
        }

// SetMin # 2

        template<typename T1>
        void VectorDense<T1>::SetMin(const T1 &comp_val) {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            const VEI ELEMS = this->elems;
            VEI i;

            // build the vector

#pragma omp parallel default(none)  \
     num_threads(NT_1D) \
     private(i)       \
     shared(comp_val)
            {
#pragma omp for

                for (i = 0; i < ELEMS; ++i) {

                    this->vector[i] = min(this->vector[i], comp_val);
                }
            }
        }

// SetMin # 3

        template<typename T1>
        void VectorDense<T1>::SetMin(const VectorDense <T1> &vec,
                                     const T1 &comp_val) {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
            vec.CheckAllocation();
#endif

#ifdef DEBUG_COMPAT
            this->CheckCompatibility(vec);
#endif

            const VEI ELEMS = this->elems;
            VEI i;

            // build the vector

#pragma omp parallel default(none)   \
     num_threads(NT_1D) \
     private(i)       \
     shared(comp_val) \
     shared(vec)
            {
#pragma omp for

                for (i = 0; i < ELEMS; ++i) {
                    this->vector[i] = std::min(vec.vector[i], comp_val);
                }
            }
        }

// Swap

        template<typename T1>
        void VectorDense<T1>::Swap(VectorDense <T1> &vec) {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
            vec.CheckAllocation();
#endif

#ifdef DEBUG_COMPAT
            this->CheckCompatibility(vec);
#endif

            // local variables

            const VEI ELEMS = this->elems;
            const VEI BUFFER_SIZE = static_cast<VEI>(pow(10.0, 6.0));

            if (ELEMS >= BUFFER_SIZE) {
                VectorDense <T1> bufferA;
                VectorDense <T1> bufferB;

                const VEI NUM_BUFS = ELEMS / BUFFER_SIZE;
                const VEI LAST_BUF_SIZE = ELEMS % BUFFER_SIZE;

                VEI i;
                VEI j;
                VEI k;

                // all but the last buffer

#pragma omp parallel default(none) \
          num_threads(NT_2D) \
          private(i)         \
          private(k)         \
          private(j)         \
          private(bufferA)   \
          private(bufferB)   \
          shared(vec)
                {
#pragma omp for

                    for (k = 0; k < NUM_BUFS; ++k) {
                        bufferA.Allocate(BUFFER_SIZE);
                        bufferB.Allocate(BUFFER_SIZE);

                        for (i = 0; i < BUFFER_SIZE; ++i) {
                            j = i + BUFFER_SIZE * (k);

                            bufferA.SetElement(i, vec(j));
                            bufferB.SetElement(i, (*this)(j));
                            vec.SetElement(j, bufferB(i));
                            this->SetElement(j, bufferA(i));
                        }

                        bufferA.Deallocate();
                        bufferB.Deallocate();
                    }
                }

                // last buffer case

                for (i = 0; i != LAST_BUF_SIZE; ++i) {
                    bufferA.Allocate(LAST_BUF_SIZE);
                    bufferB.Allocate(LAST_BUF_SIZE);

                    j = i + BUFFER_SIZE * NUM_BUFS;

                    bufferA.SetElement(i, vec(j));
                    bufferB.SetElement(i, (*this)(j));
                    vec.SetElement(j, bufferB(i));
                    this->SetElement(j, bufferA(i));

                    bufferA.Deallocate();
                    bufferB.Deallocate();
                }

                // deallocate local buffers

                bufferA.Deallocate();
                bufferB.Deallocate();
            } else if (ELEMS < BUFFER_SIZE) {
                VectorDense <T1> vec_tmp;

                vec_tmp.Allocate(ELEMS);

                vec_tmp = vec;
                vec = *this;
                *this = vec_tmp;

                vec_tmp.Deallocate();
            }
        }

// VectorScalarComparison

        template<typename T1>
        bool VectorDense<T1>::VectorScalarComparison(
                const T1 &elem,
                bool comp_fn(const T1 &, const T1 &)) const {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            VEI i; // index for main vector container
            VEI counter = 0UL; // reset counter
            const VEI ELEMS = this->GetNumberOfElements();

#pragma omp parallel default(none) \
     num_threads(NT_1D) \
     private(i)    \
     shared(elem)  \
     shared(comp_fn) \
reduction(+:counter)
            {
#pragma omp for

                for (i = 0; i < ELEMS; ++i) {

                    if (comp_fn(this->vector[i], elem)) {
                        counter = counter + 1UL;
                    }
                }
            }

            if (counter == ELEMS) {
                return true;
            } else if (counter < ELEMS) {
                return false;
            }

            // default case

            return false;
        }

// VectorScalarEqual

        template<typename T1>
        bool VectorDense<T1>::VectorScalarEqual(
                const T1 &elem,
                const T1 &thres,
                bool comp_fn(const T1 &,
                             const T1 &,
                             const T1 &)) const {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            VEI i; // index
            VEI counter = 0UL; // reset the counter
            const VEI ELEMS = this->elems; // total elements

#pragma omp parallel default(none) \
     num_threads(NT_1D) \
     private(i)      \
     shared(elem)    \
     shared(thres)   \
     shared(comp_fn) \
reduction(+:counter)
            {
#pragma omp for

                for (i = 0; i < ELEMS; ++i) {

                    if (comp_fn(this->vector[i], elem, thres)) {
                        counter = counter + 1UL;
                    }
                }
            }

            if (counter == ELEMS) {
                return true;
            } else if (counter < ELEMS) {
                return false;
            }

            // default case

            return false;
        }

// VectorVectorComparison

        template<typename T1>
        bool VectorDense<T1>::VectorVectorComparison(
                const VectorDense <T1> &vecB,
                bool comp_fn(const T1 &, const T1 &)) const {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
            vecB.CheckAllocation();
#endif

#ifdef DEBUG_COMPAT
            this->CheckCompatibility(vecB);
#endif

            VEI counter = 0UL;
            const VEI ELEMS = this->elems;
            VEI i;

#pragma omp parallel default(none) \
     num_threads(NT_1D) \
     private(i)      \
     shared(vecB)    \
     shared(comp_fn) \
reduction(+:counter)
            {
#pragma omp for

                for (i = 0; i < ELEMS; ++i) {

                    if (comp_fn(this->vector[i], vecB.vector[i])) {
                        counter = counter + 1UL;
                    }
                }
            }

            if (counter == ELEMS) {
                return true;
            } else if (counter < ELEMS) {
                return false;
            }

            // default case

            return false;
        }

// VectorVectorEqual

        template<typename T1>
        bool VectorDense<T1>::VectorVectorEqual(
                const VectorDense <T1> &vecB,
                const T1 &thres,
                bool comp_fn(const T1 &,
                             const T1 &,
                             const T1 &)) const {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
            vecB.CheckAllocation();
#endif

#ifdef DEBUG_COMPAT
            this->CheckCompatibility(vecB);
#endif

            VEI i; // index
            VEI counter = 0UL; // reset the counter
            const VEI ELEMS = this->elems; // total elements

#pragma omp parallel default(none) \
     num_threads(NT_1D) \
     private(i)      \
     shared(thres)   \
     shared(comp_fn) \
     shared(vecB)    \
reduction(+:counter)
            {
#pragma omp for

                for (i = 0; i < ELEMS; ++i) {

                    if (comp_fn(this->vector[i], vecB.vector[i], thres)) {
                        counter = counter + 1UL;
                    }
                }
            }

            if (counter == ELEMS) {
                return true;
            } else if (counter < ELEMS) {
                return false;
            }

            // default case

            return false;
        }

    } // sep
} // pgg

#endif // VECTOR_DENSE_AUXILIARY_H

