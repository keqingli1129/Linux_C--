add_library(StaticLib STATIC
    src/StaticLib.cpp
)

target_include_directories(StaticLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
