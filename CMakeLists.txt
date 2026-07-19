cmake_minimum_required(VERSION 3.10.0)
project(Linux_C++ VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Eigen3 REQUIRED)
find_package(OpenCV REQUIRED)

add_subdirectory(DynamicLib)
add_subdirectory(StaticLib)

add_executable(Linux_C++ main.cpp)

target_include_directories(Linux_C++ PRIVATE
    ${CMAKE_SOURCE_DIR}
    ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(Linux_C++ PRIVATE
    DynamicLib
    StaticLib
    Eigen3::Eigen
    ${OpenCV_LIBS}
)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
