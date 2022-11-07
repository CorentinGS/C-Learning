
/******************************************************************************
 * Copyright (c) 2022.                                                        *
 *                                                                            *
 *                                                                            *
 * Learning C                             ______   _______      _______.      *
 * matrix_sort.c                         /      | /  _____|    /       |      *
 *                                      |  ,----'|  |  __     |   (----`      *
 * By: CorentinGS                       |  |     |  | |_ |     \   \          *
 * <c.giaufersaubert@outlook.com>       |  `----.|  |__| | .----)   |         *
 *                                       \______| \______| |_______/  (_/ -/  *
 * LICENCE: MIT                                                        /  /   *
 * Created: 2022/11/7 by CorentinGS                                           *
 *                                                                            *
 ******************************************************************************/

#include <malloc.h>
#include "sort.h"

void
MatrixSort(int* matrix, int size_row, int size_col) {
    int* array = malloc(sizeof(int) * size_row * size_col);
    int index = 0;
    for (int i = 0; i < size_row; ++i) {
        for (int j = 0; j < size_col; ++j) {
            array[index++] = matrix[i * size_col + j];
        }
    }
    InsertionSort(array, size_row * size_col);
    index = 0;
    for (int i = 0; i < size_row; ++i) {
        for (int j = 0; j < size_col; ++j) {
            matrix[i * size_col + j] = array[index++];
        }
    }

    if (NULL != array) {
        free(array);
    }
}
