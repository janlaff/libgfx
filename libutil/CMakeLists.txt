set(
        LIBUTIL_SOURCES
        src/Exceptions.cpp
)


add_library(libutil ${LIBUTIL_SOURCES})
target_include_directories(libutil PUBLIC include)