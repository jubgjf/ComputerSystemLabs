#include <stdlib.h>
#include "5_3-itoa.c"

char *ftoa(float num) {
    char *buffer = (char *) malloc(100 * sizeof(char));

    char *before_dot = itoa((int) num);
    int i;
    for (i = 0; before_dot[i] != '\0'; ++i) {
        buffer[i] = before_dot[i];
    }
    buffer[i] = '.';
    i++;

    float after_dot = num - (int) num;
    for (int j = 0; j < 6; ++j, ++i) {
        after_dot *= 10;
        buffer[i] = ((int) after_dot) % 10 + '0';
    }

    return buffer;
}

int main() {
    char *str = ftoa(123.456f);
}
