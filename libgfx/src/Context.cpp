#include <libutil/Exceptions.h>

#include "libgfx/Context.h"

using namespace util;

namespace gfx {
    static void GlfwErrorHook(int errorCode, const char* errorMessage) {
        throw std::runtime_error(errorMessage);
    }

    Context::Context() {
        InitGlfw(4, 4);
    }

    Context::~Context() {
        ExitGlfw();
    }

    Window Context::CreateWindow(int width, int height, const std::string &title, bool fullscreen) {
        Window window(width, height, title, fullscreen);
        InitGlew();
        return window;
    }

    void Context::InitGlew() {
        ThrowIf(glewInit() != GLEW_OK, "Failed to initialize GLEW");
    }

    void Context::InitGlfw(int glMajorVersion, int glMinorVersion) {
        glfwSetErrorCallback(GlfwErrorHook);
        ThrowIf(!glfwInit(), "Failed to initialize GLFW");
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, glMajorVersion);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, glMinorVersion);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }

    void Context::ExitGlfw() {
        glfwTerminate();
    }
}