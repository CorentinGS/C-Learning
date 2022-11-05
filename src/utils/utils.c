//
// Created by yume on 02/09/22.
//

#include <stdio.h>

int
sum(int x, int y) {
    return x + y;
}

int
division(int x, int y) {
    int d = x / y;
    return d;
}

int
min(int x, int y) {
    return y ^ ((x ^ y) & -(x < y));
}

int
max(int x, int y) {
    return x ^ ((x ^ y) & -(x < y));
}
