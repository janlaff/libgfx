cmake_minimum_required(VERSION 3.18)
project(gfx)

set(CMAKE_CXX_STANDARD 20)

include(cmake/CPM.cmake)
CPMAddPackage("gh:Perlmint/glew-cmake#glew-cmake-2.2.0")
CPMAddPackage("gh:glfw/glfw#3.3.4")
CPMAddPackage("gh:g-truc/glm#0.9.9.8")

add_subdirectory(libgfx)
add_subdirectory(libutil)
add_subdirectory(test)