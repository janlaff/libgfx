set(
        LIBGFX_SOURCES
        src/Context.cpp
        src/Window.cpp
        src/InputBindings.cpp
)

add_library(libgfx ${LIBGFX_SOURCES})
target_include_directories(libgfx PUBLIC include)
target_link_libraries(libgfx libutil libglew_static glfw glm)