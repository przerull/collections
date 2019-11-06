clean() {
    git clean -fd
}

build() {
    g++ -o main.exe -fprofile-arcs -ftest-coverage -g -Wall -Wextra main.cpp
    valgrind -q --leak-check=full ./main.exe
    gcov -r -b main.cpp collections/linked_list.h
    echo
}

case $1 in
    clean)
        clean
        ;;
    *)
        build
        ;;
esac
