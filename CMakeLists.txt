cmake_minimum_required(VERSION 2.8)
project(Collections CXX)

include_directories("src")
add_executable(test test.cpp)

enable_testing()
add_test(NAME fancy_test
	COMMAND test
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
