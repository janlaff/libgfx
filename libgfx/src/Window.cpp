#include <libutil/Exceptions.h>

#include "libgfx/InputBindings.h"
#include "libgfx/Window.h"

using namespace util;

namespace gfx {
    Window::Window(int width, int height, const std::string &title, bool fullscreen) {
        SetMonitor(fullscreen);
        Open(width, height, title);
        ClaimContext();
        SetSettings();
    }

    Window::~Window() {
        glfwDestroyWindow(m_windowHandle);
    }

    void Window::Update() {
        glfwSwapBuffers(m_windowHandle);
        glfwPollEvents();
    }

    bool Window::IsOpen() {
        return !glfwWindowShouldClose(m_windowHandle);
    }

    InputBindings Window::GetInputBindings() {
        return InputBindings(*this);
    }

    void Window::SetMonitor(bool fullscreen) {
        m_monitorHandle = fullscreen ? glfwGetPrimaryMonitor() : nullptr;
    }

    void Window::SetSettings() {
        glfwSetInputMode(m_windowHandle, GLFW_STICKY_KEYS, true);
    }

    void Window::Open(int width, int height, const std::string &title) {
        m_windowHandle = glfwCreateWindow(width, height, title.c_str(), m_monitorHandle, nullptr);
        ThrowIfNull(m_windowHandle, "Failed to create GLFW window");
    }

    void Window::ClaimContext() {
        glfwMakeContextCurrent(m_windowHandle);
    }

    GLFWwindow *Window::GetHandle() {
        return m_windowHandle;
    }
}