cmake_minimum_required(VERSION 3.9.2 FATAL_ERROR)



include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/cpp-pm/hunter/archive/v0.23.260.tar.gz"
    SHA1 "13775235910a3fa85644568d1c5be8271de72e1c"
)

project(Collections)

add_library(Collections INTERFACE)
target_include_directories(Collections INTERFACE src/)


hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)


add_executable(run_tests test/test_linked_list.cpp)
target_link_libraries(run_tests GTest::gtest GTest::gtest_main)
target_link_libraries(run_tests Collections)

