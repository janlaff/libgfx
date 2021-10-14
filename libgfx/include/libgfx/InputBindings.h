#pragma once

#include <unordered_map>
#include <functional>
#include <memory>
#include <glm/vec2.hpp>

namespace gfx {
    class Window;

    class InputBindings {
    public:
        int GetKeyState(int key);
        glm::dvec2 GetMousePosition();

    private:
        friend class Window;
        InputBindings(Window& window);

        Window& m_window;
    };
}