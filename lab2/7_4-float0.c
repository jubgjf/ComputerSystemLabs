#include <stdio.h>

int main() {
    float num = 10;
    float zero = 0;
    float min = 0;
    *((unsigned *) (&min)) = 0x1;

    printf("float / 0   = %f\n", num / zero);
    printf("float / min = %f\n", num / min);
}
