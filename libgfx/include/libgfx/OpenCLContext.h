#pragma once

#define CL_HPP_TARGET_OPENCL_VERSION 300
#include <CL/opencl.hpp>

#include "Window.h"

namespace gfx {
    class OpenCLContext {
    public:
        static OpenCLContext Create(const Window& window);

    private:
        explicit OpenCLContext(cl::Context& context);

        static std::vector<cl_context_properties> GetProperties(cl::Platform& platform);
        static cl::Platform                       GetDefaultPlatform();
        static cl::Device                         GetDefaultDevice(cl::Platform& platform);

        mutable cl::Context m_context;
    };
}