add_library(DynamicLib SHARED
    src/DynamicLib.cpp
)

target_include_directories(DynamicLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
