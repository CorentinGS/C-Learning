
/******************************************************************************
 * Copyright (c) 2022.                                                        *
 *                                                                            *
 *                                                                            *
 * Learning C                             ______   _______      _______.      *
 * sort.c                                /      | /  _____|    /       |      *
 *                                      |  ,----'|  |  __     |   (----`      *
 * By: CorentinGS                       |  |     |  | |_ |     \   \          *
 * <c.giaufersaubert@outlook.com>       |  `----.|  |__| | .----)   |         *
 *                                       \______| \______| |_______/  (_/ -/  *
 * LICENCE: MIT                                                        /  /   *
 * Created: 2022/11/7 by CorentinGS                                           *
 *                                                                            *
 ******************************************************************************/

#include "sort.h"

void Swap(int* array, int i, int j);

void
BubbleSort(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                Swap(array, j, j + 1);
            }
        }
    }
}

void
InsertionSort(int* array, int size) {
    for (int i = 1; i < size; ++i) {
        int j = i;
        while (j > 0 && array[j] < array[j - 1]) {
            Swap(array, j, j - 1);
            --j;
        }
    }
}

void
SelectionSort(int* array, int size) {
    for (int i = 0; i < size - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < size; ++j) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        if (min != i) {
            Swap(array, i, min);
        }
    }
}

void
Swap(int* array, int i, int j) {
    // Swap array[i] and array[j] without using a temporary variable
    array[i] = array[i] ^ array[j];
    array[j] = array[i] ^ array[j];
    array[i] = array[i] ^ array[j];
}
