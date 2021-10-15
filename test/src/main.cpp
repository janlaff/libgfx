#include <iostream>

#include <libgfx/Window.h>
#include <libgfx/OpenCLContext.h>
#include <libutil/ArrayStorage.hpp>

using namespace util;

int main(int argc, char* argv[]) {
    auto window = gfx::Window::Create(1024, 768, "Hello World", false);
    auto clContext = gfx::OpenCLContext::Create(window);

    while (window.IsOpen()) {
        window.Update();
    }
}