#include <stdio.h>

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

int main() {
    printf("===== win x86 =====\n");
    win_x86();
    printf("\n");

    printf("===== linux 32 =====\n");
    linux_32();
    printf("\n");
}
