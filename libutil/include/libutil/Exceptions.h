#pragma once

#include <type_traits>
#include <stdexcept>
#include <string>

namespace util {
    void ThrowIf(bool condition, const std::string &errorMessage);

    template<typename T>
    void ThrowIfNull(T *object, const std::string &errorMessage) {
        ThrowIf(object == nullptr, errorMessage);
    }
}