cmake_minimum_required(VERSION 3.16)

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

add_executable(
        lab2_32
        lab2/main.c
        lab2/hellolinux.c lab2/hellolinux.h
        lab2/arch.c lab2/arch.h
        lab2/memroy.c lab2/memroy.h
        lab2/xtoy.c lab2/xtoy.h)
set_target_properties(lab2_32 PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")

add_executable(
        lab2_64
        lab2/main.c
        lab2/hellolinux.c lab2/hellolinux.h
        lab2/arch.c lab2/arch.h
        lab2/memroy.c lab2/memroy.h
        lab2/xtoy.c lab2/xtoy.h)
