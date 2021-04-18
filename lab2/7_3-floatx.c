#include <stdio.h>

void show_byte(unsigned char *start, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        printf("%.2x", start[i]);
    }
}

int main() {
    float positive_zero = 0;
    float negative_zero = 0;
    float positive_min = 0;
    float positive_max = 0;
    float positive_format_min = 0;
    float positive_inf = 0;
    float nan = 0;

    *((unsigned *) (&positive_zero)) = 0x0;
    *((unsigned *) (&negative_zero)) = 0x80000000;
    *((unsigned *) (&positive_min)) = 0x1;
    *((unsigned *) (&positive_max)) = 0x7F7FFFFF;
    *((unsigned *) (&positive_format_min)) = 0x800000;
    *((unsigned *) (&positive_inf)) = 0x7F800000;
    *((unsigned *) (&nan)) = 0x7F800001;

    printf("   +0 = %.7f\n", positive_zero);
    printf("   +0 < ");
    show_byte((unsigned char *) &positive_zero, sizeof(float));
    printf("\n");

    printf("   -0 = %.7f\n", negative_zero);
    printf("   -0 < ");
    show_byte((unsigned char *) &negative_zero, sizeof(float));
    printf("\n");

    printf(" +min = %.7f\n", positive_min);
    printf(" +min < ");
    show_byte((unsigned char *) &positive_min, sizeof(float));
    printf("\n");

    printf(" +max = %.7f\n", positive_max);
    printf(" +max < ");
    show_byte((unsigned char *) &positive_max, sizeof(float));
    printf("\n");

    printf("+fmin = %.7f\n", positive_format_min);
    printf("+fmin < ");
    show_byte((unsigned char *) &positive_format_min, sizeof(float));
    printf("\n");

    printf(" +inf = %.7f\n", positive_inf);
    printf(" +inf < ");
    show_byte((unsigned char *) &positive_inf, sizeof(float));
    printf("\n");

    printf("  nan = %.7f\n", nan);
    printf("  nan < ");
    show_byte((unsigned char *) &nan, sizeof(float));
    printf("\n");
}
