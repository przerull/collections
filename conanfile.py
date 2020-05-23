from conans import ConanFile, CMake, tools


class CollectionsConan(ConanFile):
    name = "Collections"
    version = "0.1"
    license = "<Put the package license here>"
    author = "Philip Zerull <przerull@gmail.com>"
    url = "<Package recipe repository url here, for issues about the package>"
    description = "<Description of Collections here>"
    topics = ("<Put some tag here>", "<here>", "<and here>")
    settings = "os", "compiler", "build_type", "arch"
    generators = 'cmake'
    no_copy_source=True
    exports_sources = "src/*", "CMakeLists.txt", "test.cpp"

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        if tools.get_env("CONAN_RUN_TESTS", True):
            self.run('''
                valgrind ./bin/Collections_test \
                --leak-check=full \
                --error-exitcode=1
                '''.strip())
            print('running coverage')
            self.run('gcov -r -b test.cpp collections/linked_list.h')
            print('coverage complete')

    def build_requirements(self):
        self.build_requires('gtest/1.10.0')


    def package(self):
        self.copy("*.h")

    def package_id(self):
        self.info.header_only()
