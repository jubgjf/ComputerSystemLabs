# cmake_minimum_required(VERSION <specify CMake version here>)
project(ComputerSystemLabs C)

set(CMAKE_C_STANDARD 99)

add_executable(
        lab1
        lab1/header.h
        lab1/main.c
        lab1/hellolinux.c
        lab1/hellowin.c
        lab1/showbyte.c
        lab1/datatype.c
        lab1/basicinfo.c
        lab1/floattest.c
        lab1/sumtest.c
)