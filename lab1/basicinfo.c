#include "header.h"
#include <string.h>

int is_little_endian() {
//    const char *cmd = "lscpu | grep \"Byte Order\"";
//    char buffer[80];
//    FILE *fp = popen(cmd, "r");
//    fgets(buffer, sizeof(buffer), fp);
//    pclose(fp);
//    if (strstr(buffer, "Little") != NULL) {
//        return 1;
//    } else {
//        return 0;
//    }
    int num = 0x12345678;
    unsigned char c = *(unsigned char *) &num;
    return c == 0x78;
}

size_t cpu_word_size() {
//    const char *cmd = "lscpu | grep \"Architecture\"";
//    char buffer[80];
//    FILE *fp = popen(cmd, "r");
//    fgets(buffer, sizeof(buffer), fp);
//    pclose(fp);
//    if (strstr(buffer, "x86_64") != NULL) {
//        return 64;
//    } else {
//        return 0;
//    }
    return 8 * sizeof(void *);
}
