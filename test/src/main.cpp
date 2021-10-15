#include <iostream>

#include <libgfx/Window.h>
#include <libgfx/OpenCLContext.h>
#include <libutil/ArrayStorage.hpp>

using namespace util;

int main(int argc, char* argv[]) {
    auto window = gfx::Window::Create(1024, 768, "Hello World", false);
    auto clContext = gfx::OpenCLContext::Create(window);
    auto storage = ArrayStorage<1024, DynamicArray, int, float>{};

    GetArray<int>(storage).at(1023);

    while (window.IsOpen()) {
        window.Update();
    }
}