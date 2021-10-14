set(
        TEST_SOURCES
        src/main.cpp
)

add_executable(test ${TEST_SOURCES})
target_link_libraries(test libgfx)