cmake_minimum_required(VERSION 2.8)
project(Collections CXX)

INCLUDE(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
CONAN_BASIC_SETUP()

add_compile_options(-fprofile-arcs -ftest-coverage)
include_directories("src")

add_executable(${PROJECT_NAME}_test test.cpp)

TARGET_LINK_LIBRARIES(${PROJECT_NAME}_test --coverage ${CONAN_LIBS})
