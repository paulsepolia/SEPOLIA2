
#ifndef VECTOR_DENSE_STL_H
#define VECTOR_DENSE_STL_H

#include <algorithm>

namespace pgg {
    namespace sep {

// BinarySearch # 1

        template<typename T1>
        bool VectorDense<T1>::BinarySearch(const T1 &elem) const {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            // local variables and parameters

            bool bool_tmp;
            const VEI ELEMS = this->elems;

            // try to find the element

            bool_tmp = std::binary_search(this->vector,
                                          this->vector + ELEMS,
                                          elem);

            // return

            return bool_tmp;
        }

// BinarySearch # 2

        template<typename T1>
        template<typename T2>
        bool VectorDense<T1>::BinarySearch(const T1 &elem,
                                           T2 &my_comp) const {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            // local variables and parameters

            bool bool_tmp;
            const VEI ELEMS = this->elems;

            // try to find the element

            bool_tmp = std::binary_search(this->vector,
                                          this->vector + ELEMS,
                                          elem,
                                          my_comp);

            // return

            return bool_tmp;
        }

// Count

        template<typename T1>
        unsigned long VectorDense<T1>::Count(const T1 &elem) const {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            // local variables and parameters

            VEI tmp_val;
            const VEI ELEMS = this->elems;

            // try to find the element

            tmp_val = std::count(this->vector,
                                 this->vector + ELEMS,
                                 elem);

            // return

            return tmp_val;
        }

// CountIf

        template<typename T1>
        template<typename T2>
        unsigned long VectorDense<T1>::CountIf(T2 &my_comp) const {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            // local variables and parameters

            VEI tmp_val;
            const VEI ELEMS = this->elems;

            // try to find the element

            tmp_val = std::count_if(this->vector,
                                    this->vector + ELEMS,
                                    my_comp);

            // return

            return tmp_val;
        }

// FindElement

        template<typename T1>
        double VectorDense<T1>::FindElement(const T1 &elem) const {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            // local variables and parameters

            T1 *ptr_tmp;
            double res_tmp;
            const VEI ELEMS = this->elems;

            // try to find the element

            ptr_tmp = std::find(this->vector,
                                this->vector + ELEMS,
                                elem);

            // check if the element has been found

            if (ptr_tmp == this->vector + ELEMS) {
                res_tmp = static_cast<double>(-1);
            } else if (ptr_tmp != this->vector + ELEMS) {
                VEI loc = ptr_tmp - this->vector;
                res_tmp = static_cast<double>(loc);
            }

            // return

            return res_tmp;
        }

// Generate

        template<typename T1>
        template<typename T2>
        void VectorDense<T1>::Generate(T2 &my_generator) {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            // local parameters

            const VEI ELEMS = this->elems;

            // fill array_tmp with specific elements

            std::generate(this->vector,
                          this->vector + ELEMS,
                          my_generator);
        }

// Max # 1

        template<typename T1>
        T1 VectorDense<T1>::Max() const {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            // local variables

            T1 val_tmp;

            // local parameters

            const VEI ELEMS = this->elems;

            // get the maximum element

            val_tmp = *std::max_element(this->vector,
                                        this->vector + ELEMS);

            // return

            return val_tmp;
        }

// Max # 2

        template<typename T1>
        template<typename T2>
        T1 VectorDense<T1>::Max(T2 &my_comp) const {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            // local variables

            T1 val_tmp;

            // local parameters

            const VEI ELEMS = this->elems;

            // get the maximum element

            val_tmp = *std::max_element(this->vector,
                                        this->vector + ELEMS,
                                        my_comp);

            // return

            return val_tmp;
        }

// Min # 1

        template<typename T1>
        T1 VectorDense<T1>::Min() const {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            // local variables

            T1 val_tmp;

            // local parameters

            const VEI ELEMS = this->elems;

            // get the minimum element

            val_tmp = *std::min_element(this->vector,
                                        this->vector + ELEMS);

            // return

            return val_tmp;
        }

// Min # 2

        template<typename T1>
        template<typename T2>
        T1 VectorDense<T1>::Min(T2 &my_comp) const {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            // local variables

            T1 val_tmp;

            // local parameters

            const VEI ELEMS = this->elems;

            // get the minimum element

            val_tmp = *std::min_element(this->vector,
                                        this->vector + ELEMS,
                                        my_comp);

            // return

            return val_tmp;
        }

// NextPermutation # 1

        template<typename T1>
        bool VectorDense<T1>::NextPermutation() {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            // local variables and parameters

            bool bool_tmp;
            const VEI ELEMS = this->elems;

            // main algorithm

            bool_tmp = std::next_permutation(this->vector,
                                             this->vector + ELEMS);

            // return

            return bool_tmp;
        }

// NextPermutation # 2

        template<typename T1>
        template<typename T2>
        bool VectorDense<T1>::NextPermutation(T2 &my_comp) {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            // local variables and parameters

            bool bool_tmp;
            const VEI ELEMS = this->elems;

            // main algorithm

            bool_tmp = std::next_permutation(this->vector,
                                             this->vector + ELEMS,
                                             my_comp);

            // return

            return bool_tmp;
        }

// PreviousPermutation # 1

        template<typename T1>
        bool VectorDense<T1>::PreviousPermutation() {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            // local variables and parameters

            bool bool_tmp;
            const VEI ELEMS = this->elems;

            // main algorithm

            bool_tmp = std::prev_permutation(this->vector,
                                             this->vector + ELEMS);

            // return

            return bool_tmp;
        }

// PreviousPermutation # 2

        template<typename T1>
        template<typename T2>
        bool VectorDense<T1>::PreviousPermutation(T2 &my_comp) {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            // local variables and parameters

            bool bool_tmp;
            const VEI ELEMS = this->elems;

            // main algorithm

            bool_tmp = std::prev_permutation(this->vector,
                                             this->vector + ELEMS,
                                             my_comp);

            // return

            return bool_tmp;
        }

// RandomShuffle # 1

        template<typename T1>
        void VectorDense<T1>::RandomShuffle() {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            // local variables and parameters

            const VEI ELEMS = this->elems;

            // reverse the array the elements

            std::random_shuffle(this->vector, this->vector + ELEMS);
        }

// RandomShuffle # 2

        template<typename T1>
        void VectorDense<T1>::RandomShuffle(const unsigned int &n) {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            // local variables and parameters

            const VEI ELEMS = this->elems;

            // seed the generator

            functions::SeedRandomGenerator(n);

            // reverse the array the elements

            std::random_shuffle(this->vector, this->vector + ELEMS);
        }

// Reverse

        template<typename T1>
        void VectorDense<T1>::Reverse() {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            // local parameters and variables

            const VEI ELEMS = this->elems;

            // reverse the array the elements

            std::reverse(this->vector, this->vector + ELEMS);
        }

// RotateLeft

        template<typename T1>
        void VectorDense<T1>::RotateLeft(const VEI &pos) {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            // local variables and parameters

            const VEI ELEMS = this->elems;

            // check if position "pos" is valid

            // test --> a

            if (pos <= 0) {
                functions::Exit(E_ARG_POS);
            }

            // test --> b

            if (pos > ELEMS) {
                functions::Exit(E_ARG_LESS_TOT_ELEMS);
            }

            // main algorithm

            std::rotate(this->vector,
                        this->vector + pos,
                        this->vector + ELEMS);
        }

// RotateRight

        template<typename T1>
        void VectorDense<T1>::RotateRight(const VEI &pos) {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            // local parameters

            const VEI ELEMS = this->elems;

            // check if position "pos" is valid

            // test --> a

            if (pos <= 0) {
                functions::Exit(E_ARG_POS);
            }

            // test --> b

            if (pos > ELEMS) {
                functions::Exit(E_ARG_LESS_TOT_ELEMS);
            }

            // main algorithm

            std::reverse(this->vector, this->vector + ELEMS);
            std::reverse(this->vector + pos, this->vector + ELEMS);
            std::reverse(this->vector, this->vector + pos);
        }

// Sort # 1

        template<typename T1>
        void VectorDense<T1>::Sort() {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            // local parameters

            const VEI ELEMS = this->elems;

            // sort the array

            std::sort(this->vector, this->vector + ELEMS);
        }

// Sort # 2

        template<typename T1>
        template<typename T2>
        void VectorDense<T1>::Sort(T2 &my_comp) {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            // local parameters

            const VEI ELEMS = this->elems;

            // sort the array

            std::sort(this->vector,
                      this->vector + ELEMS,
                      my_comp);
        }

// SortedQ # 1

        template<typename T1>
        bool VectorDense<T1>::SortedQ() const {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            bool val_tmp;

            // local parameters

            const VEI ELEMS = this->elems;

            // check if the array is sorted

            val_tmp = std::is_sorted(this->vector,
                                     this->vector + ELEMS);

            // return

            return val_tmp;
        }

// SortedQ # 2

        template<typename T1>
        template<typename T2>
        bool VectorDense<T1>::SortedQ(T2 &my_comp) const {
#ifdef DEBUG_ALLOC
            this->CheckAllocation();
#endif

            bool val_tmp;

            // local parameters

            const VEI ELEMS = this->elems;

            // check if the array is sorted

            val_tmp = std::is_sorted(this->vector,
                                     this->vector + ELEMS,
                                     my_comp);

            // return

            return val_tmp;
        }

    } // sep
} // pgg

#endif // VECTOR_DENSE_STL_H

