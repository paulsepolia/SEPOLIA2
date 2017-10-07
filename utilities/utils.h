#pragma once

namespace sepolia {
    template<typename T>
    class array_deleter {
    public:
        void operator()(T const *p) {
            delete[] p;
        }
    };
}