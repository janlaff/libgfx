#pragma once

#include <array>

namespace util {
    template<size_t ArraySize, template<size_t, typename> class ArrayType, typename ... ComponentTypes>
    struct ArrayStorage;

    template<size_t Size, typename ComponentType>
    struct StaticArray : std::array<ComponentType, Size> {};

    template<size_t Size, typename ComponentType>
    struct DynamicArray : std::vector<ComponentType> {
        DynamicArray() : std::vector<ComponentType>(Size) {}
    };

    template<size_t ArraySize, template<size_t, typename> class ArrayType, typename FirstComponentType, typename ... ComponentTypes>
    struct ArrayStorage<ArraySize, ArrayType, FirstComponentType, ComponentTypes...>
            : ArrayStorage<ArraySize, ArrayType, ComponentTypes...> {
        ArrayType<ArraySize, FirstComponentType> array{};
    };

    template<size_t ArraySize, template<size_t, typename> class ArrayType>
    struct ArrayStorage<ArraySize, ArrayType> {};

    template<typename ComponentType, typename ArrayStorageType>
    struct ArrayStorageElement;

    template<size_t ArraySize, template<size_t, typename> class ArrayType, typename ComponentType, typename FirstComponentType, typename ... ComponentTypes>
    struct ArrayStorageElement<ComponentType, ArrayStorage<ArraySize, ArrayType, FirstComponentType, ComponentTypes...>>
            : ArrayStorageElement<ComponentType, ArrayStorage<ArraySize, ArrayType, ComponentTypes...>>
            {};

    template<size_t ArraySize, template<size_t, typename> class ArrayType, typename ComponentType, typename ... ComponentTypes>
    struct ArrayStorageElement<ComponentType, ArrayStorage<ArraySize, ArrayType, ComponentType, ComponentTypes...>> {
        using array_storage_type = ArrayStorage<ArraySize, ArrayType, ComponentType, ComponentTypes...>;
    };

    template<typename ComponentType, typename ArrayStorageType>
    constexpr auto& GetArray(ArrayStorageType& arrayStorage) {
        using array_storage_type = typename ArrayStorageElement<ComponentType, ArrayStorageType>::array_storage_type;
        return static_cast<array_storage_type&>(arrayStorage).array;
    }
}