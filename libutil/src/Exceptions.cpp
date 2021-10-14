#include "libutil/Exceptions.h"

namespace util {
    void ThrowIf(bool condition, const std::string& errorMessage) {
        if (condition) {
            throw std::runtime_error(errorMessage);
        }
    }
}