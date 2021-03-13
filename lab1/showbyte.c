#include "header.h"

void show_byte(byte_pointer start, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        printf("%.2x", start[i]);
    }
}

void show_file_byte(const char *file_name) {
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error! No such file.\n");
        return;
    }
    char ch;
    int meet_eof = 0;
    int backward_bytes = 16;
    while (!meet_eof) {
        for (int i = 0; i < 16; ++i) {
            if ((ch = (char) fgetc(fp)) != EOF) {
                if (ch == '\r' || ch == '\n') {
                    ch = ' ';
                }
                putchar(' ');
                putchar(ch);
                putchar(' ');
            } else {
                meet_eof = 1;
                backward_bytes = i;
                break;
            }
        }
        putchar('\n');
        fseek(fp, -backward_bytes, SEEK_CUR);
        for (int i = 0; i < 16; ++i) {
            if ((ch = (char) fgetc(fp)) != EOF) {
                show_byte((byte_pointer) &ch, sizeof(char));
                putchar(' ');
            } else {
                meet_eof = 1;
                break;
            }
        }
        putchar('\n');
    }
}
