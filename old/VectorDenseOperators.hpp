
#ifndef VECTOR_DENSE_OPERATORS_H
#define VECTOR_DENSE_OPERATORS_H

namespace pgg {
    namespace sep {

// operator = # 1

        template<typename T1>
        VectorDense <T1> &VectorDense<T1>::operator=(
                const VectorDense <T1> &vec) {
            this->Set(vec);

            return *this;
        }

// operator = # 2

        template<typename T1>
        VectorDense <T1> &VectorDense<T1>::operator=(
                const T1 &elem) {
            this->Set(elem);

            return *this;
        }

// operator + # 1

        template<typename T1>
        VectorDense <T1> VectorDense<T1>::operator+(
                const VectorDense <T1> &vec) const {
            VectorDense <T1> vec_tmp;

            vec_tmp.Allocate(vec.elems);
            vec_tmp.Plus(*this, vec);

            return vec_tmp;
        }

// operator + # 2

        template<typename T1>
        VectorDense <T1> VectorDense<T1>::operator+(
                const T1 &elem) const {
            VectorDense <T1> vec_tmp;

            vec_tmp.Allocate(this->elems);
            vec_tmp.Plus(*this, elem);

            return vec_tmp;
        }

// operator + # 3

        template<typename T1>
        VectorDense <T1> operator+(
                const T1 &elem,
                const VectorDense <T1> &vec) {
            VectorDense <T1> vec_tmp;

            vec_tmp.Allocate(vec.elems);
            vec_tmp.Plus(vec, elem);

            return vec_tmp;
        }

// operator - # 1

        template<typename T1>
        VectorDense <T1> VectorDense<T1>::operator-(
                const VectorDense <T1> &vec) const {
            VectorDense <T1> vec_tmp;

            vec_tmp.Allocate(vec.elems);
            vec_tmp.Subtract(*this, vec);

            return vec_tmp;
        }

// operator - # 2

        template<typename T1>
        VectorDense <T1> VectorDense<T1>::operator-(
                const T1 &elem) const {
            VectorDense <T1> vec_tmp;

            vec_tmp.Allocate(this->elems);
            vec_tmp.Subtract(*this, elem);

            return vec_tmp;
        }

// operator - # 3

        template<typename T1>
        VectorDense <T1> operator-(
                const T1 &elem,
                const VectorDense <T1> &vec) {
            VectorDense <T1> vec_tmp;

            vec_tmp.Allocate(vec.elems);
            vec_tmp.Subtract(elem, vec);

            return vec_tmp;
        }

// operator - # 4

        template<typename T1>
        VectorDense <T1> VectorDense<T1>::operator-() const {
            VectorDense <T1> vec_tmp;

            vec_tmp.Allocate(this->elems);

            vec_tmp.Times(*this, static_cast<T1>(-ONE_DBL_MAX));

            return vec_tmp;
        }

// operator * # 1

        template<typename T1>
        VectorDense <T1> VectorDense<T1>::operator*(
                const VectorDense <T1> &vec) const {
            VectorDense <T1> vec_tmp;

            vec_tmp.Allocate(vec.elems);
            vec_tmp.Times(*this, vec);

            return vec_tmp;
        }

// operator * # 2

        template<typename T1>
        VectorDense <T1> VectorDense<T1>::operator*(
                const T1 &elem) const {
            VectorDense <T1> vec_tmp;

            vec_tmp.Allocate(this->elems);
            vec_tmp.Times(*this, elem);

            return vec_tmp;
        }

// operator * # 3

        template<typename T1>
        VectorDense <T1> operator*(
                const T1 &elem,
                const VectorDense <T1> &vec) {
            return vec * elem;
        }

// operator / # 1

        template<typename T1>
        VectorDense <T1> VectorDense<T1>::operator/(
                const VectorDense <T1> &vec) const {
            VectorDense <T1> vec_tmp;

            vec_tmp.Allocate(vec.elems);
            vec_tmp.Divide(*this, vec);

            return vec_tmp;
        }

// operator / # 2

        template<typename T1>
        VectorDense <T1> VectorDense<T1>::operator/(
                const T1 &elem) const {
            VectorDense <T1> vec_tmp;

            vec_tmp.Allocate(this->elems);
            vec_tmp.Divide(*this, elem);

            return vec_tmp;
        }

// operator / # 3

        template<typename T1>
        VectorDense <T1> operator/(
                const T1 &elem,
                const VectorDense <T1> &vec) {
            VectorDense <T1> vec_tmp;

            vec_tmp.Allocate(vec.elems);
            vec_tmp.Divide(elem, vec);

            return vec_tmp;
        }

// operator ()

        template<typename T1>
        const T1 VectorDense<T1>::operator()(
                const VEI &index) const {
            const T1 elem = this->vector[index];

            return elem;
        }

// operator += # 1

        template<typename T1>
        VectorDense <T1> VectorDense<T1>::operator+=(
                const VectorDense <T1> &vec) {
            this->Plus(*this, vec);

            return *this;
        }

// operator += # 2

        template<typename T1>
        VectorDense <T1> VectorDense<T1>::operator+=(
                const T1 &elem) {
            this->Plus(*this, elem);

            return *this;
        }

// operator -= # 1

        template<typename T1>
        VectorDense <T1> VectorDense<T1>::operator-=(
                const VectorDense <T1> &vec) {
            this->Subtract(*this, vec);

            return *this;
        }

// operator -= # 2

        template<typename T1>
        VectorDense <T1> VectorDense<T1>::operator-=(
                const T1 &elem) {
            this->Subtract(*this, elem);

            return *this;
        }

// operator *= # 1

        template<typename T1>
        VectorDense <T1> VectorDense<T1>::operator*=(
                const VectorDense <T1> &vec) {
            this->Times(*this, vec);

            return *this;
        }

// operator *= # 2

        template<typename T1>
        VectorDense <T1> VectorDense<T1>::operator*=(
                const T1 &elem) {
            this->Times(*this, elem);

            return *this;
        }

// operator /= # 1

        template<typename T1>
        VectorDense <T1> VectorDense<T1>::operator/=(
                const VectorDense <T1> &vec) {
            this->Divide(*this, vec);

            return *this;
        }

// operator /= # 2

        template<typename T1>
        VectorDense <T1> VectorDense<T1>::operator/=(
                const T1 &elem) {
            this->Divide(*this, elem);

            return *this;
        }

// operator ++ # 1

        template<typename T1>
        VectorDense <T1> VectorDense<T1>::operator++() {
            this->Plus(*this, static_cast<T1>(ONE_DBL_MAX));

            return *this;
        }

// operator ++ # 2

        template<typename T1>
        VectorDense <T1> VectorDense<T1>::operator++(int) {
            this->Plus(*this, static_cast<T1>(ONE_DBL_MAX));

            return *this;
        }

// operator -- # 1

        template<typename T1>
        VectorDense <T1> VectorDense<T1>::operator--() {
            this->Subtract(*this, static_cast<T1>(ONE_DBL_MAX));

            return *this;
        }

// operator -- # 2

        template<typename T1>
        VectorDense <T1> VectorDense<T1>::operator--(int) {
            this->Subtract(*this, static_cast<T1>(ONE_DBL_MAX));

            return *this;
        }

// operator == # 1

        template<typename T1>
        bool VectorDense<T1>::operator==(
                const VectorDense <T1> &vec) const {
            return this->Equal(vec);
        }

// operator == # 2

        template<typename T1>
        bool VectorDense<T1>::operator==(
                const T1 &elem) const {
            return this->Equal(elem);
        }

// operator != # 1

        template<typename T1>
        bool VectorDense<T1>::operator!=(
                const VectorDense <T1> &vec) const {
            return !this->Equal(vec);
        }

// operator != # 2

        template<typename T1>
        bool VectorDense<T1>::operator!=(
                const T1 &elem) const {
            return !this->Equal(elem);
        }

// operator > # 1

        template<typename T1>
        bool VectorDense<T1>::operator>(
                const VectorDense <T1> &vec) const {
            return this->Greater(vec);
        }

// operator > # 2

        template<typename T1>
        bool VectorDense<T1>::operator>(
                const T1 &elem) const {
            return this->Greater(elem);
        }

// operator >= # 1

        template<typename T1>
        bool VectorDense<T1>::operator>=(
                const VectorDense <T1> &vec) const {
            return this->GreaterEqual(vec);
        }

// operator >= # 2

        template<typename T1>
        bool VectorDense<T1>::operator>=(
                const T1 &elem) const {
            return this->GreaterEqual(elem);
        }

// operator < # 1

        template<typename T1>
        bool VectorDense<T1>::operator<(
                const VectorDense <T1> &vec) const {
            return this->Less(vec);
        }

// operator < # 2

        template<typename T1>
        bool VectorDense<T1>::operator<(
                const T1 &elem) const {
            return this->Less(elem);
        }

// operator <= # 1

        template<typename T1>
        bool VectorDense<T1>::operator<=(
                const VectorDense <T1> &vec) const {
            return this->LessEqual(vec);
        }

// operator <= # 2

        template<typename T1>
        bool VectorDense<T1>::operator<=(
                const T1 &elem) const {
            return this->LessEqual(elem);
        }

// operator []

        template<typename T1>
        const T1 VectorDense<T1>::operator[](
                const VEI &index) const {
            const T1 elem = (*this)(index);

            return elem;
        }

    } // sep
} // pgg

#endif // VECTOR_DENSE_OPERATORS_H
