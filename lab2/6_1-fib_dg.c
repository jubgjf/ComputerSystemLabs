#include <stdio.h>

int dp_int[100];
long dp_long[100];
unsigned dp_unsigned[100];
unsigned long dp_ulong[100];

int fib_dg_int(int n) {
    if (n == 0 || n == 1) {
        dp_int[n] = n;
        return dp_int[n];
    }
    if (dp_int[n] == 0) {
        dp_int[n] = fib_dg_int(n - 1) + fib_dg_int(n - 2);
    }
    return dp_int[n];
}

long fib_dg_long(long n) {
    if (n == 0 || n == 1) {
        dp_long[n] = n;
        return dp_long[n];
    }
    if (dp_long[n] == 0) {
        dp_long[n] = fib_dg_long(n - 1) + fib_dg_long(n - 2);
    }
    return dp_long[n];
}

unsigned fib_dg_unsigned(unsigned n) {
    if (n == 0 || n == 1) {
        dp_unsigned[n] = n;
        return dp_unsigned[n];
    }
    if (dp_unsigned[n] == 0) {
        dp_unsigned[n] = fib_dg_unsigned(n - 1) + fib_dg_unsigned(n - 2);
    }
    return dp_unsigned[n];
}

unsigned long fib_dg_ulong(unsigned long n) {
    if (n == 0 || n == 1) {
        dp_ulong[n] = n;
        return dp_ulong[n];
    }
    if (dp_ulong[n] == 0) {
        dp_ulong[n] = fib_dg_ulong(n - 1) + fib_dg_ulong(n - 2);
    }
    return dp_ulong[n];
}

int main() {
    printf("fib_dg_int(46) = %d\n", fib_dg_int(46));
    printf("fib_dg_int(47) = %d\n", fib_dg_int(47));

    printf("fib_dg_long(92) = %ld\n", fib_dg_long(92));
    printf("fib_dg_long(93) = %ld\n", fib_dg_long(93));

    printf("fib_dg_unsigned(47) = %u\n", fib_dg_unsigned(47));
    printf("fib_dg_unsigned(48) = %u\n", fib_dg_unsigned(48));

    printf("fib_dg_ulong(93) = %lu\n", fib_dg_ulong(93));
    printf("fib_dg_ulong(94) = %lu\n", fib_dg_ulong(94));
}
