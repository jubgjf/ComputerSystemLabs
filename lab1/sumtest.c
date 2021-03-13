#include "header.h"

int sum_test(int *a, unsigned len) {
    int sum = 0;
    for (int i = 0; i <= len - 1; ++i) {
        sum += a[i];
    }
    return sum;
}