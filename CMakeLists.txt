cmake_minimum_required(VERSION 3.10.0)
project(Linux_C++ VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(DynamicLib)
add_subdirectory(StaticLib)

add_executable(Linux_C++ main.cpp)
target_link_libraries(Linux_C++ PRIVATE DynamicLib StaticLib)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
