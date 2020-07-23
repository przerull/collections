cmake_minimum_required(VERSION 3.9.2 FATAL_ERROR)



include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/cpp-pm/hunter/archive/v0.23.260.tar.gz"
    SHA1 "13775235910a3fa85644568d1c5be8271de72e1c"
)

project(Collections VERSION 0.0.1)

add_library(Collections INTERFACE)
target_include_directories(Collections INTERFACE src/)


hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)


add_executable(run_tests test/test_linked_list.cpp)
target_link_libraries(run_tests GTest::gtest GTest::gtest_main)
target_link_libraries(run_tests Collections)

set(config_install_dir "${PROJECT_NAME}")
set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")
set(version_config "${generated_dir}/${PROJECT_NAME}ConfigVersion.cmake")
set(project_config "${generated_dir}/${PROJECT_NAME}Config.cmake")
set(targets_export_name "${PROJECT_NAME}Targets")

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
	${version_config}
	VERSION 0.0.1
	COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
	"cmake/Config.cmake.in"
	${project_config}
	INSTALL_DESTINATION "${config_install_dir}"
)


install(
	DIRECTORY "src/"
	DESTINATION "${config_install_dir}"
)

install(
	FILES "${project_config}" "${version_config}"
	DESTINATION "${config_install_dir}"
)
