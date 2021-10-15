#include <libutil/Exceptions.h>

#include "libgfx/Window.h"

using namespace util;

namespace gfx {
    static void GlfwErrorHook(int errorCode, const char* errorMessage) {
        throw std::runtime_error(errorMessage);
    }

    Window::Window(GLFWwindow *window, GLFWmonitor *monitor)
        : m_windowHandle(window)
        , m_monitorHandle(monitor)
        {}

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

    Window Window::Create(int width, int height, const std::string &title, bool fullscreen) {
        InitGlfw(4, 4);
        auto monitor = GetMonitor(fullscreen);
        auto window = OpenWindow(width, height, title, monitor);
        InitGlew();

        return {window, monitor};
    }

    void Window::InitGlfw(int glMajorVersion, int glMinorVersion) {
        ThrowIf(!glfwInit(), "Failed to initialize GLFW");
        glfwSetErrorCallback(GlfwErrorHook);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, glMajorVersion);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, glMinorVersion);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }

    void Window::InitGlew() {
        ThrowIf(glewInit() != GLEW_OK, "Failed to initialize GLEW");
    }

    GLFWmonitor* Window::GetMonitor(bool fullscreen) {
        return fullscreen ? glfwGetPrimaryMonitor() : nullptr;
    }

    GLFWwindow* Window::OpenWindow(int width, int height, const std::string &title, GLFWmonitor* monitor) {
        GLFWwindow* window = glfwCreateWindow(width, height, title.c_str(), monitor, nullptr);
        ThrowIfNull(window, "Failed to create GLFW window");

        glfwSetInputMode(window, GLFW_STICKY_KEYS, true);
        glfwMakeContextCurrent(window);

        return window;
    }
}