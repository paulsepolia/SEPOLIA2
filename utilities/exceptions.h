#pragma once

#include <stdexcept>

#include "../parameters/errors.h"

using pgg::E0001;
using pgg::E0002;

// exceptions

namespace sepolia {

    class is_not_allocated {
    public:

        std::string what() const throw() {
            return std::string(E0001);
        }
    };

    class index_out_of_range {
    public:

        std::string what() const throw() {
            return std::string(E0002);
        }
    };
}