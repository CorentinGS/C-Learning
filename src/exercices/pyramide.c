//
// Created by yume on 23/09/22.
//

//      1
//     2 3
//    4 5 6
//   7 8 9 10
//11 12 13 14 15
#include <malloc.h>
#include "pyramide.h"

int
pyramide(void) {
    int size = 5;
    int* pyramide = malloc(sizeof(int) * size * (size + 1) / 2);

    fill_pyramide(pyramide, size);

    display_pyramide(pyramide, size);

    find_row_col(pyramide, size, 3, 1);

    return 0;
}

void
fill_pyramide(int* pyramide, int size) {
    for (int i = 0; i < size * (size + 1) / 2; ++i) {
        pyramide[i] = i + 1;
    }
}

int
find_row_col(int* pyramide, int size, int row, int col) {
    if (row <= 0 || col <= 0 || row > size || col > size || row < col) {
        return -1;
    }
    int index = 0;
    for (int i = 0; i < row; ++i) {
        index += i;
    }
    index += col - 1;

    return pyramide[index];
}

void
display_pyramide(int* pyramide, int size) {

    int index = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - i; ++j) {
            printf(" ");
        }
        for (int j = 0; j < i + 1; ++j) {
            printf("%d ", pyramide[index++]);
        }
        printf("\n");
    }
}
