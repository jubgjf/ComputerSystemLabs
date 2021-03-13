#include "header.h"

void float_test() {
    float f;
    while (1) {
        printf("Please input a float number:\n");
        scanf("%f", &f);
        printf("your input number is %f\n", f);
        if (f == 0) {
            break;
        }
    }
}
