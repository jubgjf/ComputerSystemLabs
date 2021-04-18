#include <stdio.h>

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

int main() {
    printf("===== win x64 =====\n");
    win_x64();
    printf("\n");

    printf("===== linux 64 =====\n");
    linux_64();
    printf("\n");
}
