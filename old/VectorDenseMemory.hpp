
#ifndef VECTOR_DENSE_MEMORY_H
#define VECTOR_DENSE_MEMORY_H

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <utility>
#include <string>

namespace pgg {
    namespace sep {

// Allocate

        template<typename T1>
        void VectorDense<T1>::Allocate(const VEI &dim) {
            if (!this->is_alloc) {
                // set flags

                this->is_alloc = TRUE_ALLOC;

                // set the dimensions

                this->elems = dim;

                // allocate heap space

                const VEI ELEMS = this->elems;

                this->vector = new T1[ELEMS];
            }
        }

// AllocatedQ

        template<typename T1>
        bool VectorDense<T1>::AllocatedQ() const {
            return this->is_alloc;
        }

// Deallocate

        template<typename T1>
        void VectorDense<T1>::Deallocate() {
            if (this->is_alloc) {

                // delete heap space

                delete[] this->vector;

                // set to null pointer

                this->vector = 0;

                // set allocation flag

                this->is_alloc = FALSE_ALLOC;
            }
        }

// DeallocatedQ

        template<typename T1>
        bool VectorDense<T1>::DeallocatedQ() const {
            return !this->is_alloc;
        }

    } // sep
} // pgg

#endif // VECTOR_DENSE_MEMORY_H

