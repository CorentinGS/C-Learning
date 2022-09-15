//
// Created by yume on 15/09/22.
//

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "td1.h"

int smallestElement(const int *array, int size) {
    int min = array[0];
    for (int i = 1; i < size; ++i) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

int getMinIndex(const int *array, int size) {
    int minIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (array[i] < array[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

int getMinIndexBetween(const int array[], int size, int lo, int hi) {
    int minIndex = lo;
    if (hi > size) {
        hi = size-1;
    };
    for (int i = lo+1; i <= hi; ++i) {
        if (array[i] < array[minIndex]) {
            minIndex = i;
        }
    }
    return  minIndex;
}

int SumArray(const int array[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }
    return sum;
}

int AverageArray(const int array[], int size) {
    return SumArray(array, size) / size;
}

int SumArrayBetween(const int array[], int size, int lo) {
   int sum = 0;
    // hi is the first index higher than lo where array[hi+1] == -1 or hi == size-1
    int hi = lo;
    do {
        sum += array[hi];
        ++hi;
    } while (hi < size && array[hi] != -1);
    return sum;
}

int AverageArrayBetween(const int array[], int size, int lo) {
    int sum = 0;
    int hi = lo;
    do {
        sum += array[hi];
        ++hi;
    } while (hi < size && array[hi] != -1);
    return sum / (hi - lo);
}


void PrintString(const char array[], int size) {
    for (int i = 0; i < size; ++i) {
        if (i == size-1) {
            printf("%c", array[i]);
        } else {
            printf("%c, ", array[i]);
        }
    }
}

void PrintStringWhile(const char array[], int size) {
    int i = 0;
    while (i < size) {
        if (i == size-1) {
            printf("%c", array[i]);
        } else {
            printf("%c, ", array[i]);
        }
        ++i;
    }
}

