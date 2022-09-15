//
// Created by yume on 15/09/22.
//

#include <assert.h>
#include "merge_sort_test.h"
#include "../../sort/merge_sort.h"

void test_merge_sort() {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int array2[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int array3[15] = {4, 6, 1, 2, 3, 48, 5, 4, 6, 5, 8, 2, 14, 69, 4};

    MergeSort(array, 0, 9);
    MergeSort(array2, 0, 9);
    MergeSort(array3, 0, 14);

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