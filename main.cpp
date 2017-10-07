#include <iostream>
#include <iomanip>
#include <cmath>
#include "vector_dense/vector_dense.h"

using std::cout;
using std::endl;

using sepolia::vector_dense;

int main() {
    cout << std::boolalpha;
    cout << std::fixed;
    pgg::culi DIM(static_cast<pgg::uli>(std::pow(10.0, 6.0)));

    cout << "---------------------------------------------------------------------------->>  1" << endl;
    {
        vector_dense<double> vd1;
        bool flg(vd1.allocate(DIM));
        cout << " flg(vd1.allocate(DIM) = " << flg << std::endl;
        cout << " vd1.is_allocated()    = " << vd1.is_allocated() << std::endl;
        cout << " vd1.is_deallocated()  = " << vd1.is_deallocated() << std::endl;
        cout << " vd1.deallocate()      = " << vd1.deallocate() << std::endl;
        cout << " vd1.is_allocated()    = " << vd1.is_allocated() << std::endl;
        cout << " vd1.is_deallocated()  = " << vd1.is_deallocated() << std::endl;
    }

    cout << "---------------------------------------------------------------------------->>  2" << endl;
    {
        vector_dense<double> vd1(100*DIM, 1);
        cout << " vd1.is_allocated()    = " << vd1.is_allocated() << std::endl;
        cout << " vd1.is_deallocated()  = " << vd1.is_deallocated() << std::endl;
        cout << " vd1.deallocate()      = " << vd1.deallocate() << std::endl;
        cout << " vd1.is_allocated()    = " << vd1.is_allocated() << std::endl;
        cout << " vd1.is_deallocated()  = " << vd1.is_deallocated() << std::endl;
    }

    return 0;
}