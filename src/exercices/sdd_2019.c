

/******************************************************************************
 * Copyright (c) 2022.                                                        *
 *                                                                            *
 *                                                                            *
 * Learning C                             ______   _______      _______.      *
 * sdd_2019.c                            /      | /  _____|    /       |      *
 *                                      |  ,----'|  |  __     |   (----`      *
 * By: CorentinGS                       |  |     |  | |_ |     \   \          *
 * <c.giaufersaubert@outlook.com>       |  `----.|  |__| | .----)   |         *
 *                                       \______| \______| |_______/  (_/ -/  *
 * LICENCE: MIT                                                        /  /   *
 * Created: 2022/11/7 by CorentinGS                                           *
 *                                                                            *
 ******************************************************************************/

#include <stdio.h>
#include "sdd_2019.h"

void secret(int n);

void
exo_sdd_2019(void) {
    int n = 4;
    secret(n);
}

void
secret(int n) {
    int x = 1;
    int y = 1;
    while (x < n) {
        x = x + 1;
        y = y + 2 * x - 1;
        printf("x = %d, y = %d\n", x, y);
    }
}

void
tri_interstion(void) {
    int n = 7;
    int T[7] = {10, 2, 3, 9, 8, 7, 12};
    int up = 0;
    for (int i = 1; i < n; ++i) {
        int x = T[i];
        ++up;
        int j = i;
        while (j > 0 && T[j - 1] > x) {
            T[j] = T[j - 1];
            ++up;
            --j;
        }
        T[j] = x;
        ++up;
    }
    printf("up = %d", up);
}

void
tri_insertion_swap(void) {

    int n = 7;
    int T[7] = {10, 2, 3, 9, 8, 7, 12};
    int up = 0;
    for (int i = 1; i < n; ++i) {
        int j = i;
        while (j > 0 && T[j] < T[j - 1]) {
            int tmp = T[j];
            T[j] = T[j - 1];
            T[j - 1] = tmp;
            --j;
            up += 3;
        }
    }
    printf("up = %d", up);
}

void
print_array(int* T, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", T[i]);
    }
    printf("\n");
}
