import os
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
    generators = 'compiler_args'
    exports_sources = "src/*", "test.cpp"

    def build(self):
        self.run("mkdir -p bin")
        print(os.getcwd())
        self.run('g++ test.cpp -fprofile-arcs -ftest-coverage @conanbuildinfo.args -o bin/test')
        self.run('''
            valgrind \
            --leak-check=full \
            --error-exitcode=1 \
            ./bin/test
            '''.strip())
        self.run('gcov -r test.cpp')
        self.run('gcovr -k -f src/* . --html --html-details -o coverage.html')
        self.run('xdg-open coverage.html')

    def build_requirements(self):
        self.build_requires('gtest/1.10.0')


    def package(self):
        self.copy("*.h")

    def package_id(self):
        self.info.header_only()
