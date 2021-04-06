#include <stdio.h>

int fib_loop_int(int n) {
    if (n == 0 || n == 1) { return n; }
    int first = 0;
    int second = 1;
    int result = 0;
    for (int i = 1; i < n; i++) {
        result = first + second;
        first = second;
        second = result;
    }
    return result;
}

long fib_loop_long(long n) {
    if (n == 0 || n == 1) { return n; }
    long first = 0;
    long second = 1;
    long result = 0;
    for (long i = 1; i < n; i++) {
        result = first + second;
        first = second;
        second = result;
    }
    return result;
}

unsigned fib_loop_unsigned(unsigned n) {
    if (n == 0 || n == 1) { return n; }
    unsigned first = 0;
    unsigned second = 1;
    unsigned result = 0;
    for (unsigned i = 1; i < n; i++) {
        result = first + second;
        first = second;
        second = result;
    }
    return result;
}

unsigned long fib_loop_ulong(unsigned long n) {
    if (n == 0 || n == 1) { return n; }
    unsigned long first = 0;
    unsigned long second = 1;
    unsigned long result = 0;
    for (unsigned long i = 1; i < n; i++) {
        result = first + second;
        first = second;
        second = result;
    }
    return result;
}

int main() {
    printf("fib_loop_int(46) = %d\n", fib_loop_int(46));
    printf("fib_loop_int(47) = %d\n", fib_loop_int(47));

    printf("fib_loop_long(92) = %ld\n", fib_loop_long(92));
    printf("fib_loop_long(93) = %ld\n", fib_loop_long(93));

    printf("fib_loop_unsigned(47) = %u\n", fib_loop_unsigned(47));
    printf("fib_loop_unsigned(48) = %u\n", fib_loop_unsigned(48));

    printf("fib_loop_ulong(93) = %lu\n", fib_loop_ulong(93));
    printf("fib_loop_ulong(94) = %lu\n", fib_loop_ulong(94));
}
