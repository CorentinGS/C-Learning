//
// Created by yume on 28/09/22.
//

#include <assert.h>
#include <malloc.h>
#include "sort_test.h"
#include "../../sort/sort.h"

void test_insertion_sort() {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int array2[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int array3[15] = {4, 6, 1, 2, 3, 48, 5, 4, 6, 5, 8, 2, 14, 69, 4};

    InsertionSort(array, 10);
    InsertionSort(array2, 10);
    InsertionSort(array3, 15);

    int sorted_array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sorted_array2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sorted_array3[15] = {1, 2, 2, 3, 4, 4, 4, 5, 5, 6, 6, 8, 14, 48, 69};

    for (int i = 0; i < 10; ++i) {
        assert(array[i] == sorted_array[i]);
        assert(array2[i] == sorted_array2[i]);
    }

    for (int i = 0; i < 15; ++i) {
        assert(array3[i] == sorted_array3[i]);
    }
}

void test_selection_sort() {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int array2[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int array3[15] = {4, 6, 1, 2, 3, 48, 5, 4, 6, 5, 8, 2, 14, 69, 4};

    SelectionSort(array, 10);
    SelectionSort(array2, 10);
    SelectionSort(array3, 15);

    int sorted_array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sorted_array2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sorted_array3[15] = {1, 2, 2, 3, 4, 4, 4, 5, 5, 6, 6, 8, 14, 48, 69};

    for (int i = 0; i < 10; ++i) {
        assert(array[i] == sorted_array[i]);
        assert(array2[i] == sorted_array2[i]);
    }

    for (int i = 0; i < 15; ++i) {
        assert(array3[i] == sorted_array3[i]);
    }
}

void test_heap_sort() {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int array2[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int array3[15] = {4, 6, 1, 2, 3, 48, 5, 4, 6, 5, 8, 2, 14, 69, 4};

    HeapSort(array, 10);
    HeapSort(array2, 10);
    HeapSort(array3, 15);

    int sorted_array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sorted_array2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sorted_array3[15] = {1, 2, 2, 3, 4, 4, 4, 5, 5, 6, 6, 8, 14, 48, 69};

    for (int i = 0; i < 10; ++i) {
        assert(array[i] == sorted_array[i]);
        assert(array2[i] == sorted_array2[i]);
    }

    for (int i = 0; i < 15; ++i) {
        assert(array3[i] == sorted_array3[i]);
    }
}

void test_revert_heap_sort() {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int array2[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int array3[15] = {4, 6, 1, 2, 3, 48, 5, 4, 6, 5, 8, 2, 14, 69, 4};

    RevertHeapSort(array, 10);
    RevertHeapSort(array2, 10);
    RevertHeapSort(array3, 15);

    int sorted_array[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int sorted_array2[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int sorted_array3[15] = {69, 48, 14, 8, 6, 6, 5, 5, 4, 4, 4, 3, 2, 2, 1};

    for (int i = 0; i < 10; ++i) {
        assert(array[i] == sorted_array[i]);
        assert(array2[i] == sorted_array2[i]);
    }

    for (int i = 0; i < 15; ++i) {
        assert(array3[i] == sorted_array3[i]);
    }
}

void test_matrix_sort() {

    int matrix[3][3] = {{7, 8, 9}, {4, 5, 6}, {1, 2, 3}};
    int matrix2[5][5] = {
            {25, 24, 23, 22, 21},
            {20, 19, 18, 17, 16},
            {15, 14, 13, 12, 11},
            {10, 9, 8, 7, 6},
            {5, 4, 3, 2, 1}
    };
    int matrix3[5][10] = {
            {50, 49, 48, 47, 46, 45, 44, 43, 42, 41},
            {40, 39, 38, 37, 36, 35, 34, 33, 32, 31},
            {30, 29, 28, 27, 26, 25, 24, 23, 22, 21},
            {20, 19, 18, 17, 16, 15, 14, 13, 12, 11},
            {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
    };

    MatrixSort((int *) matrix, 3, 3);
    MatrixSort((int *) matrix2, 5, 5);
    MatrixSort((int *) matrix3, 5, 10);

    int sorted_matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            assert(matrix[i][j] == sorted_matrix[i][j]);
        }
    }

    int sorted_matrix2[5][5] = {
            {1, 2, 3, 4, 5},
            {6, 7, 8, 9, 10},
            {11, 12, 13, 14, 15},
            {16, 17, 18, 19, 20},
            {21, 22, 23, 24, 25}
    };
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            assert(matrix2[i][j] == sorted_matrix2[i][j]);
        }
    }

    int sorted_matrix3[5][10] = {
            {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
            {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
            {21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
            {31, 32, 33, 34, 35, 36, 37, 38, 39, 40},
            {41, 42, 43, 44, 45, 46, 47, 48, 49, 50}
    };
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) {
            assert(matrix3[i][j] == sorted_matrix3[i][j]);
        }
    }
}

void test_bubble_sort() {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int array2[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int array3[15] = {4, 6, 1, 2, 3, 48, 5, 4, 6, 5, 8, 2, 14, 69, 4};

    BubbleSort(array, 10);
    BubbleSort(array2, 10);
    BubbleSort(array3, 15);

    int sorted_array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sorted_array2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sorted_array3[15] = {1, 2, 2, 3, 4, 4, 4, 5, 5, 6, 6, 8, 14, 48, 69};

    for (int i = 0; i < 10; ++i) {
        assert(array[i] == sorted_array[i]);
        assert(array2[i] == sorted_array2[i]);
    }

    for (int i = 0; i < 15; ++i) {
        assert(array3[i] == sorted_array3[i]);
    }
}

void test_counting_sort() {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int array2[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int array3[15] = {4, 6, 1, 2, 3, 48, 5, 4, 6, 5, 8, 2, 14, 69, 4};

    CountingSort(array, 10);
    CountingSort(array2, 10);
    CountingSort(array3, 15);

    int sorted_array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sorted_array2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sorted_array3[15] = {1, 2, 2, 3, 4, 4, 4, 5, 5, 6, 6, 8, 14, 48, 69};

    for (int i = 0; i < 10; ++i) {
        assert(array[i] == sorted_array[i]);
        assert(array2[i] == sorted_array2[i]);
    }

    for (int i = 0; i < 15; ++i) {
        assert(array3[i] == sorted_array3[i]);
    }
}