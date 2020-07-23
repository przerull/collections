#!/usr/bin/env bash

build() {
    cmake . -Bbuild
    cmake --build build
}

clean() {
    rm -rf build
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
    build)
        build
    ;;
    clean)
        clean
    ;;
    *)
        show_help
    ;;
esac
