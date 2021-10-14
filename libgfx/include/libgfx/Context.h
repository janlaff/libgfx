#pragma once

#include "libgfx/Window.h"

namespace gfx {
    class Context {
    public:
        Context();
        ~Context();

        Window CreateWindow(int width, int height, const std::string& title, bool fullscreen = false);

    private:
        void InitGlew();
        void InitGlfw(int glMajorVersion, int glMinorVersion);
        void ExitGlfw();
    };
}