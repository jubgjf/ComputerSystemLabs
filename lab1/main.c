#include "header.h"

int main() {
    printf("===== Hello Linux =====\n");
    hello_linux();
    printf("\n");

    printf("===== Hello Windows =====\n");
    hello_win();
    printf("\n");

    printf("===== hellolinux.c =====\n");
    show_file_byte("../lab1/hellolinux.c");
    printf("\n");

    printf("===== hellowin.c =====\n");
    show_file_byte("../lab1/hellowin.c");
    printf("\n");

    printf("===== datatype =====\n");
    show_datatype_char();
    show_datatype_short();
    show_datatype_int();
    show_datatype_long();
    show_datatype_float();
    show_datatype_double();
    show_datatype_pointer();
    show_datatype_struct();
    show_datatype_union();
    show_main_addr();
    show_printf_addr();
    printf("\n");

    printf("===== endian =====\n");
    if (is_little_endian() == 1) {
        printf("This is little endian\n");
    } else {
        printf("This is not little endian\n");
    }
    printf("\n");

    printf("===== cpu word size =====\n");
    printf("This is %zu architecture\n", cpu_word_size());
    printf("\n");

    printf("===== sumtest =====\n");
    int a[5] = {1, 2, 3, 4, 5};
//    sum_test(a, 0u);
    printf("\n");

    printf("===== floattest =====\n");
    float_test();
    printf("\n");

    return 0;
}
