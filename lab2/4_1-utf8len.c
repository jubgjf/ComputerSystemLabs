#include <stdio.h>

int utf8len(char *str) {
    int len = 0;
    char *p = str;
    while (*p != '\0') {
        if ((*p & 0x80) == 0x00) {
            len++;
            p++;
        } else if ((*p & 0xE0) == 0xC0 &&
                   (*(p + 1) & 0xC0) == 0x80) {
            len++;
            p += 2;
        } else if ((*p & 0xF0) == 0xE0 &&
                   (*(p + 1) & 0xC0) == 0x80 &&
                   (*(p + 2) & 0xC0) == 0x80) {
            len++;
            p += 3;
        } else if ((*p & 0xF8) == 0xF0 &&
                   (*(p + 1) & 0xC0) == 0x80 &&
                   (*(p + 2) & 0xC0) == 0x80 &&
                   (*(p + 3) & 0xC0) == 0x80) {
            len++;
            p += 4;
        }
    }
    return len;
}

int main() {
    char *str = "1190200703 - 管健男";

    printf("string = %s\n", str);
    printf("length = %d\n", utf8len(str));
}
