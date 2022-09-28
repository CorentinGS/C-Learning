//
// Created by yume on 28/09/22.
//

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "sort_benchmark.h"
#include "../sort/merge_sort.h"
#include "../sort/sort.h"

const int SIZE[5] = {10,100,1000,10000,100000};


void benchmark() {
    for (int i = 0; i < 5; ++i) {
        benchmark_merge_sort(SIZE[i]);
        benchmark_bubble_sort(SIZE[i]);
        benchmark_insertion_sort(SIZE[i]);
        benchmark_selection_sort(SIZE[i]);
        benchmark_heap_sort(SIZE[i]);
        benchmark_counting_sort(SIZE[i]);
        printf("--------------------------------\n");
    }
}

void benchmark_counting_sort(int size) {
    int* array = malloc(sizeof(int) * size);
    srand(time(0));
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % size;
    }
    clock_t start = clock();
    CountingSort(array, size);
    clock_t end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("CountingSort: %f seconds to sort %d numbers....\n", time, size);
}

void benchmark_merge_sort(int size) {

    srand(time(0));
    int array[size];
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % size;
    }

    clock_t start = clock();
    MergeSort(array, 0, size);
    clock_t end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("MergeSort: %f seconds to sort %d numbers....\n", time, size);
}

void benchmark_insertion_sort(int size) {
    srand(time(0));
    int array[size];
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % size;
    }

    clock_t start = clock();
    InsertionSort(array, size);
    clock_t end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("InsertionSort: %f seconds to sort %d numbers....\n", time, size);
}

void benchmark_bubble_sort(int size) {
    srand(time(0));
    int array[size];
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % size;
    }

    clock_t start = clock();
    BubbleSort(array, size);
    clock_t end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("BubbleSort: %f seconds to sort %d numbers....\n", time, size);
}

void benchmark_heap_sort(int size) {
    srand(time(0));
    int array[size];
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % size;
    }

    clock_t start = clock();
    HeapSort(array, size);
    clock_t end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("HeapSort: %f seconds to sort %d numbers....\n", time, size);
}

void benchmark_selection_sort(int size) {
    srand(time(0));
    int array[size];
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % size;
    }

    clock_t start = clock();
    SelectionSort(array, size);
    clock_t end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("SelectionSort: %f seconds to sort %d numbers....\n", time, size);
}