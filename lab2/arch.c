#include <stdio.h>
#include "arch.h"

void win_x86() {
    printf("sizeof char        = %u\n", sizeof(char));
    printf("sizeof short       = %u\n", sizeof(short));
    printf("sizeof int         = %u\n", sizeof(int));
    printf("sizeof long        = %u\n", sizeof(long));
    printf("sizeof long long   = %u\n", sizeof(long long));
    printf("sizeof float       = %u\n", sizeof(float));
    printf("sizeof double      = %u\n", sizeof(double));
    printf("sizeof long double = %u\n", sizeof(long double));
    printf("sizeof pointer     = %u\n", sizeof(void *));
}

void win_x64() {
    printf("sizeof char        = %lu\n", sizeof(char));
    printf("sizeof short       = %lu\n", sizeof(short));
    printf("sizeof int         = %lu\n", sizeof(int));
    printf("sizeof long        = %lu\n", sizeof(long));
    printf("sizeof long long   = %lu\n", sizeof(long long));
    printf("sizeof float       = %lu\n", sizeof(float));
    printf("sizeof double      = %lu\n", sizeof(double));
    printf("sizeof long double = %lu\n", sizeof(long double));
    printf("sizeof pointer     = %lu\n", sizeof(void *));
}

void linux_32() {
    printf("sizeof char        = %u\n", sizeof(char));
    printf("sizeof short       = %u\n", sizeof(short));
    printf("sizeof int         = %u\n", sizeof(int));
    printf("sizeof long        = %u\n", sizeof(long));
    printf("sizeof long long   = %u\n", sizeof(long long));
    printf("sizeof float       = %u\n", sizeof(float));
    printf("sizeof double      = %u\n", sizeof(double));
    printf("sizeof long double = %u\n", sizeof(long double));
    printf("sizeof pointer     = %u\n", sizeof(void *));
}

void linux_64() {
    printf("sizeof char        = %lu\n", sizeof(char));
    printf("sizeof short       = %lu\n", sizeof(short));
    printf("sizeof int         = %lu\n", sizeof(int));
    printf("sizeof long        = %lu\n", sizeof(long));
    printf("sizeof long long   = %lu\n", sizeof(long long));
    printf("sizeof float       = %lu\n", sizeof(float));
    printf("sizeof double      = %lu\n", sizeof(double));
    printf("sizeof long double = %lu\n", sizeof(long double));
    printf("sizeof pointer     = %lu\n", sizeof(void *));
}

void print_archs() {
    printf("===== win x86 =====\n");
    win_x86();
    printf("\n");

    printf("===== win x64 =====\n");
    win_x64();
    printf("\n");

    printf("===== linux 32 =====\n");
    linux_32();
    printf("\n");

    printf("===== linux 64 =====\n");
    linux_64();
    printf("\n");
}
