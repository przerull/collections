cmake_minimum_required(VERSION 2.8)
project(Collections CXX)

INCLUDE(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
CONAN_BASIC_SETUP()

include_directories("src")

add_executable(${PROJECT_NAME}_test test.cpp)

TARGET_LINK_LIBRARIES(${PROJECT_NAME}_test ${CONAN_LIBS})

enable_testing()
add_test(NAME ${PROJECT_NAME}_test
	COMMAND ${PROJECT_NAME}_test
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
