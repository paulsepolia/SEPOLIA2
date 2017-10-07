#pragma once

#include <stdexcept>
#include "../parameters/errors.h"

// exceptions

namespace sep {

    class is_not_allocated {
    public:

        std::string what() const throw() {
            return std::string(skz::E0001);
        }
    };

    class index_out_of_range {
    public:

        std::string what() const throw() {
            return std::string(skz::E0002);
        }
    };

    class vectors_are_not_of_equal_size {
    public:

        std::string what() const throw() {
            return std::string(skz::E0003);
        }
    };

}