
#ifndef VECTOR_DENSE_CONSTRUCTORS_H
#define VECTOR_DENSE_CONSTRUCTORS_H

namespace pgg {
    namespace sep {

// constructor

        template<typename T1>
        VectorDense<T1>::VectorDense() :
                vector(0), elems(0), is_alloc(FALSE_ALLOC) {}

// copy constructor

        template<typename T1>
        VectorDense<T1>::VectorDense(const VectorDense <T1> &vec) :
                vector(0), elems(0), is_alloc(FALSE_ALLOC) {
            if (vec.AllocatedQ()) {
                this->Allocate(vec.elems);
                this->Set(vec);
            } else if (vec.DeallocatedQ()) {
                functions::Exit(E_VEC_ALLOC_NOT);
            }
        }

    } // sep
} // pgg

#endif // VECTOR_DENSE_CONSTRUCTORS_H

