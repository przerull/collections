#!/usr/bin/env bash

build() {
    cmake . -Bbuild
    cmake --build build
}

install() {
    DESTDIR=./install cmake --install build
}

clean() {
    rm -rf build
    rm -rf install
}

full() {
    clean
    build
    install
}

show_help() {
    echo "usage: ./compile.sh {build|clean}"
}

if [ -z $1 ]; then
    command=build
else
    command=$1
fi

case $command in
    full)
        full
    ;;
    build)
        build
    ;;
    clean)
        clean
    ;;
    install)
        install
    ;;
    *)
        show_help
    ;;
esac
