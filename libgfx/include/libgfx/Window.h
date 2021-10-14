#pragma once

#include <memory>

#include "GLInclude.h"

namespace gfx {
    class Context;
    class InputBindings;

    class Window {
    public:
        Window(const Window&) = delete;
        Window(Window&&) = default;
        ~Window();

        void Update();
        bool IsOpen();
        InputBindings GetInputBindings();

    private:
        friend class Context;
        friend class InputBindings;

        Window(int width, int height, const std::string &title, bool fullscreen);

        void SetMonitor(bool fullscreen);
        void SetSettings();
        void Open(int width, int height, const std::string& title);
        void ClaimContext();
        GLFWwindow* GetHandle();

        GLFWwindow* m_windowHandle;
        GLFWmonitor* m_monitorHandle;
    };
}