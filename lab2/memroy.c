#include <stdio.h>

int x = -1190200703;

void show_memory() {
    double y = 230903200104250000.0;
    static char *z = "1190200703 - 管健男";

    printf("===== show memory =====\n");
    printf("x = %d\n", x);
    printf("y = %f\n", y);
    printf("z = %s", z);
    printf("\n");
}
