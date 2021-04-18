#include "5_1-atoi.c"

#define MAX_BUFFER 100

int pow10(int n) {
    if (n == 0) { return 1; }
    return 10 * pow10(n - 1);
}

float atof(char *str) {
    char buffer[MAX_BUFFER] = "0";
    int meet_dot = 0;
    int dot_position_right = 0;

    for (int i = 0; str[i] != '\0' && i < MAX_BUFFER; ++i) {
        if (meet_dot == 0) {
            if (str[i] != '.') {
                buffer[i] = str[i];
            } else {
                meet_dot = 1;
            }
        } else {
            buffer[i - 1] = str[i];
            dot_position_right++;
        }
    }

    int num = atoi(buffer);
    return (float) num / (float) pow10(dot_position_right);
}
