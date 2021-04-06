#include <stdio.h>

int main() {
    float float_div_zero = 1.0f / 0;
    printf("1.0f / 0 = %f\n", float_div_zero);
    int int_div_zero = 1 / 0;
    printf("   1 / 0 = %d\n", int_div_zero);
}
