//
// Created by yume on 23/09/22.
//

#include <malloc.h>
#include <assert.h>
#include "pyramide_test.h"
#include "../../exercices/pyramide.h"

void
test_fill_pyramide(void) {
    int size = 5;
    int* pyramide = malloc(sizeof(int) * size * (size + 1) / 2);
    int result[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    fill_pyramide(pyramide, size);
    for (int i = 0; i < size * (size + 1) / 2; ++i) {
        assert(pyramide[i] == result[i]);
    }

    if (NULL != pyramide) {
        free(pyramide);
    }

    int size2 = 3;
    int* pyramide2 = malloc(sizeof(int) * size2 * (size2 + 1) / 2);
    int result2[] = {1, 2, 3, 4, 5, 6};
    fill_pyramide(pyramide2, size2);
    for (int i = 0; i < size2 * (size2 + 1) / 2; ++i) {
        assert(pyramide2[i] == result2[i]);
    }

    if (NULL != pyramide2) {
        free(pyramide2);
    }

    int size3 = 1;
    int* pyramide3 = malloc(sizeof(int) * size3 * (size3 + 1) / 2);
    int result3[] = {1};
    fill_pyramide(pyramide3, size3);
    for (int i = 0; i < size3 * (size3 + 1) / 2; ++i) {
        assert(pyramide3[i] == result3[i]);
    }

    if (NULL != pyramide3) {
        free(pyramide3);
    }
}

void
test_find_row_col(void) {
    int size = 5;
    int* pyramide = malloc(sizeof(int) * size * (size + 1) / 2);
    fill_pyramide(pyramide, size);
    assert(find_row_col(pyramide, size, 1, 1) == 1);
    assert(find_row_col(pyramide, size, 2, 1) == 2);
    assert(find_row_col(pyramide, size, 2, 2) == 3);
    assert(find_row_col(pyramide, size, 3, 1) == 4);
    assert(find_row_col(pyramide, size, 3, 2) == 5);
    assert(find_row_col(pyramide, size, 3, 3) == 6);
    assert(find_row_col(pyramide, size, 4, 1) == 7);
    assert(find_row_col(pyramide, size, 4, 2) == 8);
    assert(find_row_col(pyramide, size, 4, 3) == 9);
    assert(find_row_col(pyramide, size, 4, 4) == 10);
    assert(find_row_col(pyramide, size, 5, 1) == 11);
    assert(find_row_col(pyramide, size, 5, 2) == 12);
    assert(find_row_col(pyramide, size, 5, 3) == 13);
    assert(find_row_col(pyramide, size, 5, 4) == 14);
    assert(find_row_col(pyramide, size, 5, 5) == 15);
    assert(find_row_col(pyramide, size, 6, 1) == -1);
    assert(find_row_col(pyramide, size, 1, 6) == -1);
    assert(find_row_col(pyramide, size, 2, 3) == -1);
    assert(find_row_col(pyramide, size, 0, 0) == -1);
    assert(find_row_col(pyramide, size, -1, -1) == -1);

    if (NULL != pyramide) {
        free(pyramide);
    }
}
