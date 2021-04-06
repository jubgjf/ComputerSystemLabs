cmake_minimum_required(VERSION 3.16)

project(ComputerSystemLabs C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")

# 实验一
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

# 实验二
add_executable(lab2_hellolinux lab2/2_2-hellolinux.c)
set_target_properties(lab2_hellolinux PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")

add_executable(lab2_arch32 lab2/3_1-arch32.c)
set_target_properties(lab2_arch32 PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")

add_executable(lab2_arch64 lab2/3_1-arch64.c)

add_executable(lab2_xyz lab2/3_2-xyz.c)
set_target_properties(lab2_xyz PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")

add_executable(lab2_arg_main lab2/3_3-arg_main.c)
set_target_properties(lab2_arg_main PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")

add_executable(lab2_str lab2/3_4-str.c)
set_target_properties(lab2_str PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")

add_executable(lab2_utf8len lab2/4_1-utf8len.c)

add_executable(lab2_ftoa lab2/5_4-ftoa.c)

add_executable(lab2_fib_dg lab2/6_1-fib_dg.c)

add_executable(lab2_fib_loop lab2/6_2-fib_loop.c)

add_executable(lab2_zero lab2/6_4-zero.c)

add_executable(lab2_float11 lab2/7_2-float11.c)
