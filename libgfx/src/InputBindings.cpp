#include "libgfx/GLInclude.h"
#include "libgfx/Window.h"
#include "libgfx/InputBindings.h"

using namespace glm;

namespace gfx {
    InputBindings::InputBindings(Window& window) : m_window(window) {}

    int InputBindings::GetKeyState(int key) {
        glfwGetKey(m_window.GetHandle(), key);
    }

    dvec2 InputBindings::GetMousePosition() {
        dvec2 pos;
        glfwGetCursorPos(m_window.GetHandle(), &pos.x, &pos.y);
        return pos;
    }
}