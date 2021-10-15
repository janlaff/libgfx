#pragma once

#include <memory>

#include "GLFixedIncludes.h"

namespace gfx {
    class Window {
    public:
        Window(const Window&) = delete;
        Window(Window&&) = default;
        ~Window();

        void Update();
        bool IsOpen();

        static Window Create(int width, int height, const std::string &title, bool fullscreen);

    private:
        Window(GLFWwindow* window, GLFWmonitor* monitor);

        // Initialization functions
        static void         InitGlfw(int glMajorVersion, int glMinorVersion);
        static void         InitGlew();
        static GLFWmonitor* GetMonitor(bool fullscreen);
        static GLFWwindow*  OpenWindow(int width, int height, const std::string &title, GLFWmonitor* monitor);

        GLFWwindow* m_windowHandle;
        GLFWmonitor* m_monitorHandle;
    };
}