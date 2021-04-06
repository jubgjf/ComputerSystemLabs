#include <stdio.h>

void show_byte(unsigned char *start, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        printf("%.2x", start[i]);
    }
}

int main() {
    float f = -1.1f;
    printf("value  = %f\n", f);
    printf("memory = ");
    show_byte((unsigned char *) &f, sizeof(float));
}
