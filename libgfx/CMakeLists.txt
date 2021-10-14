set(
        LIBGFX_SOURCES
        src/Window.cpp
        src/OpenCLContext.cpp
)

add_library(libgfx ${LIBGFX_SOURCES})
target_include_directories(libgfx PUBLIC include)
target_link_libraries(libgfx libutil libglew_static glfw glm OpenCL OpenCL-CLHPP)