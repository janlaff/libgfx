#include <vector>

#include <libutil/Exceptions.h>

#include "libgfx/GLFixedIncludes.h"
#include "libgfx/OpenCLContext.h"

// Must be at the bottom
#include <GL/glxew.h>

using namespace util;

namespace gfx {
    OpenCLContext::OpenCLContext(cl::Context &context)
        : m_context(context) {}

    OpenCLContext OpenCLContext::Create(const Window& window) {
        auto platform = GetDefaultPlatform();
        auto device = GetDefaultDevice(platform);
        auto properties = GetProperties(platform);
        auto context = cl::Context{device, properties.data()};

        return OpenCLContext(context);
    }

    std::vector<cl_context_properties> OpenCLContext::GetProperties(cl::Platform& platform) {
#ifdef __linux__
        return {
                CL_GL_CONTEXT_KHR, (cl_context_properties)glXGetCurrentContext(),
                CL_GLX_DISPLAY_KHR, (cl_context_properties)glXGetCurrentDisplay(),
                CL_CONTEXT_PLATFORM, (cl_context_properties)platform()
        };
#elif _WIN32
        throw std::runtime_error("Windows support currently not added");
#else
        throw std::runtime_error("Current platform is not supported");
#endif
    }

    cl::Platform OpenCLContext::GetDefaultPlatform() {
        std::vector<cl::Platform> platforms;
        cl::Platform::get(&platforms);
        ThrowIf(platforms.empty(), "No OpenCL platforms found");
        return platforms.at(0);
    }

    cl::Device OpenCLContext::GetDefaultDevice(cl::Platform &platform) {
        std::vector<cl::Device> devices;
        platform.getDevices(CL_DEVICE_TYPE_GPU, &devices);
        ThrowIf(devices.empty(), "No GPU device found");
        return devices.at(0);
    }
}