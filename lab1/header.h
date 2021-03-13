#ifndef COMPUTERSYSTEMLABS_HEADER_H
#define COMPUTERSYSTEMLABS_HEADER_H

#include <stdio.h>

/* main.c */

int main();

/* hellolinux.c */

/**
 * 在Linux下编写的hello world
 */
void hello_linux();

/* hellowin.c */

/**
 * 在Windows下编写的hello world
 */
void hello_win();

/* showbyte.c */

typedef unsigned char *byte_pointer;

/**
 * 显示变量在内存中的实际存储方式
 * @param start 变量地址
 * @param len 变量类型的大小
 */
void show_byte(byte_pointer start, size_t len);

/**
 * 以二进制方式显示文件内容
 * @param file_name 文件路径
 */
void show_file_byte(const char *file_name);

/* datatype.c */

/**
 * 输出char类型变量的值、变量的地址、变量在内存中实际储存的形式
 */
void show_datatype_char();

/**
 * 输出short类型变量的值、变量的地址、变量在内存中实际储存的形式
 */
void show_datatype_short();

/**
 * 输出int类型变量的值、变量的地址、变量在内存中实际储存的形式
 */
void show_datatype_int();

/**
 * 输出long类型变量的值、变量的地址、变量在内存中实际储存的形式
 */
void show_datatype_long();

/**
 * 输出float类型变量的值、变量的地址、变量在内存中实际储存的形式
 */
void show_datatype_float();

/**
 * 输出double类型变量的值、变量的地址、变量在内存中实际储存的形式
 */
void show_datatype_double();

/**
 * 输出void*类型变量的值、变量的地址、变量在内存中实际储存的形式
 */
void show_datatype_pointer();

/**
 * 输出struct类型变量的值、变量的地址、变量在内存中实际储存的形式
 */
void show_datatype_struct();

/**
 * 输出union类型变量的值、变量的地址、变量在内存中实际储存的形式
 */
void show_datatype_union();

/**
 * 输出main函数的地址
 */
void show_main_addr();

/**
 * 输出printf函数的地址
 */
void show_printf_addr();

/* basicinfo.c */

/**
 * 判断机器的字节序列是否为小端
 * @return 小端则返回1，否则返回0
 */
int is_little_endian();

/**
 * 获取机器的CPU架构
 * @return 则返回void *类型变量的位数作为CPU位数
 */
size_t cpu_word_size();

/* floattest.c */

/**
 * 浮点数分析
 */
void float_test();

/* sumtest.c */

/**
 * 求和分析
 * @param a 数组
 * @param len 数组长度
 * @return 返回数组各项的和
 */
int sum_test(int *a, unsigned len);

#endif //COMPUTERSYSTEMLABS_HEADER_H
