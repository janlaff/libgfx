#pragma once

namespace util {
    template<typename Component, unsigned int S>
    struct ComponentArray : std::array<Component, S> {};

    template<unsigned int S, typename ... Ts>
    struct ComponentArrayStorage;

    template<unsigned int S, typename T, typename ... Ts>
    struct ComponentArrayStorage<S, T, Ts...> : ComponentArrayStorage<S, Ts...> {
        ComponentArray<T, S> value{};
    };

    template<unsigned int S>
    struct ComponentArrayStorage<S> {};

    template<typename Component, typename StorageType>
    struct ComponentArrayStorageElement;

    template<unsigned int S, typename Component, typename T, typename ... Ts>
    struct ComponentArrayStorageElement<Component, Storage<S, T, Ts...>>
            : ComponentArrayStorageElement<Component, Storage<S, Ts...>>
    {};

    template<unsigned int S, typename Component, typename ... Ts>
    struct ComponentArrayStorageElement<Component, ComponentArrayStorage<S, Component, Ts...>> {
        using storage_type = ComponentArrayStorage<S, Component, Ts...>;
    };

    template<typename Component, typename ComponentArrayStorageType>
    constexpr auto& get(ComponentArrayStorageType& storage) {
        using storage_type = typename ComponentArrayStorageElement<Component, ComponentArrayStorageType>::storage_type;
        return static_cast<storage_type&>(storage).value;
    }

    template<typename Component, typename ComponentArrayStorageType>
    constexpr auto& get_component(ComponentArrayStorageType& storage, unsigned int n) {
        return get<Component>(storage).at(n);
    }
}