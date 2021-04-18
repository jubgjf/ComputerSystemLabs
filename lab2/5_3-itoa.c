#include <stdlib.h>

#define MAX_LENGTH 10

char *itoa(int num) {
    char *reverse_buffer = (char *) malloc(MAX_LENGTH * sizeof(char));
    int len = 0;

    for (int i = 0; num != 0 && i < MAX_LENGTH; ++i) {
        reverse_buffer[i] = (char) (num % 10) + '0';
        num /= 10;
        len++;
    }

    char *buffer = (char *) malloc(len * sizeof(char));
    for (int i = 0; i < len; ++i) {
        buffer[i] = reverse_buffer[len - i - 1];
    }

    return buffer;
}
