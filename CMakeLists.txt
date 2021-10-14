cmake_minimum_required(VERSION 3.18)
project(gfx)

set(CMAKE_CXX_STANDARD 20)

include(cmake/CPM.cmake)
CPMAddPackage("gh:Perlmint/glew-cmake#glew-cmake-2.2.0")
CPMAddPackage("gh:glfw/glfw#3.3.4")
CPMAddPackage("gh:g-truc/glm#0.9.9.8")
CPMAddPackage("gh:KhronosGroup/OpenCL-SDK#v2021.07.01")

# Only use CL.hpp header
CPMAddPackage(
        NAME OpenCL-CLHPP
        GIT_REPOSITORY https://github.com/KhronosGroup/OpenCL-CLHPP.git
        TAG v2.0.15
        DOWNLOAD_ONLY YES
)
if (OpenCL-CLHPP_ADDED)
    add_library(OpenCL-CLHPP INTERFACE)
    target_include_directories(OpenCL-CLHPP INTERFACE ${OpenCL-CLHPP_SOURCE_DIR}/include)
endif()

add_subdirectory(libgfx)
add_subdirectory(libutil)
add_subdirectory(test)