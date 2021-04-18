int atoi(char *str) {
    char *backup_p = str;
    int num = 0;
    while (*str != '\0') {
        num = num * 10 + *str - '0';
        str++;
    }
    str = backup_p;
    return num;
}
