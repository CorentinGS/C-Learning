//
// Created by yume on 29/09/22.
//

#include <stdio.h>
#include "sdd_2019.h"

void secret(int n );

void exo_sdd_2019() {
    int n = 4;
    secret(n);
}

void secret(int n) {
    int x = 1;
    int y = 1;
    while(x < n) {
        x = x + 1;
        y = y + 2 *x - 1;
        printf("x = %d, y = %d\n", x, y);

    }
}

void tri_interstion() {
    int n = 7;
    int T[7] = {10,2,3,9,8,7,12};
    int up = 0;
    for (int i=1; i < n; ++i) {
        int x = T[i];
        int j = i;
        while (j > 0 && T[j-1] > x) {
            T[j] = T[j-1];
            --j;
            ++up;
            print_array(T, n);
        }
        T[j] = x;
        print_array(T, n);
        ++up;
    }
    printf("up = %d", up);
}

void print_array(int *T, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", T[i]);
    }
    printf("\n");
}