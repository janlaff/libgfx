#include <iostream>

#include <libgfx/Context.h>
#include <libgfx/Window.h>
#include <libgfx/InputBindings.h>

int main(int argc, char* argv[]) {
    gfx::Context context;
    gfx::Window window = context.CreateWindow(1024, 768, "Hello World");
    gfx::InputBindings input = window.GetInputBindings();

    while (window.IsOpen()) {
        window.Update();

        if (input.GetKeyState(GLFW_KEY_Q)) {
            break;
        }
    }

    return 0;
}