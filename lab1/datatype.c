#include "header.h"

char var_char = 'G';
short var_short = 1190;
int var_int = 1190200703;
long var_long = 11902007031903008;
float var_float = 19030.08f;
double var_double = 1190200703.1903008;
void *var_pointer = &var_char;
struct {
    int num;
    char ch;
} var_struct = {.num=0x11902007, .ch='G'};
union {
    int num;
    char ch;
} var_union = {.num=0x11902047};

void show_datatype_char() {
    printf("char   value = %-18d address = %p memory = ", var_char, &var_char);
    show_byte((byte_pointer) &var_char, sizeof(char));
    printf("\n");
}

void show_datatype_short() {
    printf("short  value = %-18d address = %p memory = ", var_short, &var_short);
    show_byte((byte_pointer) &var_short, sizeof(short));
    printf("\n");
}

void show_datatype_int() {
    printf("int    value = %-18d address = %p memory = ", var_int, &var_int);
    show_byte((byte_pointer) &var_int, sizeof(int));
    printf("\n");
}

void show_datatype_long() {
    printf("long   value = %-18ld address = %p memory = ", var_long, &var_long);
    show_byte((byte_pointer) &var_long, sizeof(long));
    printf("\n");
}

void show_datatype_float() {
    printf("float  value = %-18.2f address = %p memory = ", var_float, &var_float);
    show_byte((byte_pointer) &var_float, sizeof(float));
    printf("\n");
}

void show_datatype_double() {
    printf("double value = %-18.7f address = %p memory = ", var_double, &var_double);
    show_byte((byte_pointer) &var_double, sizeof(double));
    printf("\n");
}

void show_datatype_pointer() {
    printf("void*  value = %-18p address = %p memory = ", var_pointer, &var_pointer);
    show_byte((byte_pointer) &var_pointer, sizeof(double));
    printf("\n");
}

void show_datatype_struct() {
    printf("struct %-26s address = %p memory = ", "", &var_struct);
    show_byte((byte_pointer) &var_struct, sizeof(var_struct));
    printf("\n");

    printf("struct valu0 = %-18d address = %p memory = ", var_struct.num, &var_struct.num);
    show_byte((byte_pointer) &var_struct.num, sizeof(var_struct.num));
    printf("\n");

    printf("struct valu1 = %-18c address = %p memory = ", var_struct.ch, &var_struct.ch);
    show_byte((byte_pointer) &var_struct.ch, sizeof(var_struct.ch));
    printf("\n");
}

void show_datatype_union() {
    printf("union  %-26s address = %p memory = ", "", &var_union);
    show_byte((byte_pointer) &var_union, sizeof(var_union));
    printf("\n");

    printf("union  value = %-18d address = %p memory = ", var_union.num, &var_union.num);
    show_byte((byte_pointer) &var_union.num, sizeof(var_union.num));
    printf("\n");

    printf("union  value = %-18c address = %p memory = ", var_union.ch, &var_union.ch);
    show_byte((byte_pointer) &var_union.ch, sizeof(var_union.ch));
    printf("\n");
}

void show_main_addr() {
    printf("main   %26s address = %p\n", "", main);
}

void show_printf_addr() {
    printf("printf %26s address = %p\n", "", printf);
}
