
#ifndef VECTOR_DENSE_DESTRUCTOR_H
#define VECTOR_DENSE_DESTRUCTOR_H

namespace pgg {
namespace sep {

// destructor

template<typename T1>
VectorDense<T1>::~VectorDense()
{
     if(this->is_alloc) {
          this->Deallocate();
     }
}

} // sep
} // pgg

#endif // VECTOR_DENSE_DESTRUCTOR_H

