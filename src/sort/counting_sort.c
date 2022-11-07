
/******************************************************************************
 * Copyright (c) 2022.                                                        *
 *                                                                            *
 *                                                                            *
 * Learning C                             ______   _______      _______.      *
 * counting_sort.c                       /      | /  _____|    /       |      *
 *                                      |  ,----'|  |  __     |   (----`      *
 * By: CorentinGS                       |  |     |  | |_ |     \   \          *
 * <c.giaufersaubert@outlook.com>       |  `----.|  |__| | .----)   |         *
 *                                       \______| \______| |_______/  (_/ -/  *
 * LICENCE: MIT                                                        /  /   *
 * Created: 2022/11/7 by CorentinGS                                           *
 *                                                                            *
 ******************************************************************************/

#include <malloc.h>
#include <memory.h>
#include "sort.h"

void
CountingSort(int* array, int size) {
    int max = array[0];
    for (int i = 1; i < size; ++i) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    int* count = (int*)malloc(sizeof(int) * (max + 1));

    memset(count, 0, sizeof(int) * (max + 1));

    for (int i = 0; i < size; ++i) {
        count[array[i]]++;
    }

    int index = 0;

    for (int i = 0; i <= max; ++i) {
        for (int j = 0; j < count[i]; ++j) {
            array[index++] = i;
        }
    }

    free(count);
}

void
CountingSortIndex(int* array, int size) {
    int max = array[0];
    for (int i = 1; i < size; ++i) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    int count[max + 1]; // count[i] is the number of elements equal to i

    // Initialize count array to 0
    for (int i = 0; i < max + 1; ++i) {
        count[i] = 0;
    }

    // Count the number of elements equal to i
    for (int i = 0; i < size; ++i) {
        count[array[i]]++;
    }

    // Count the number of elements less than or equal to i
    for (int i = 1; i < max + 1; ++i) {
        count[i] += count[i - 1];
    }

    int output[size];

    // Place the elements in the correct position in the output array
    for (int i = size - 1; i >= 0; --i) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // Copy the output array to the input array, so that the input array now
    // contains the sorted array
    for (int i = 0; i < size; ++i) {
        array[i] = output[i];
    }
}
