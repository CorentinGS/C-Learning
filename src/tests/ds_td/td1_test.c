//
// Created by yume on 15/09/22.
//

#include <assert.h>
#include <malloc.h>
#include <string.h>
#include "td1_test.h"
#include "../linked_list/linked_list_test.h"


int test_smallest_element();
int test_get_min_index();
int test_get_min_index_between();
int test_sum_array();
int test_average_array();
int test_sum_array_between();
int test_average_array_between();
int test_extract_firstname();

int test_td1() {
    test_smallest_element();
    test_get_min_index();
    test_get_min_index_between();
    test_sum_array();
    test_average_array();
    test_sum_array_between();
    test_average_array_between();
    return 0;
}




int test_sum_array_between() {
    int array[] = {0,1,2,3,4,5,6};
    assert(SumArrayBetween(array, 7, 0) == 21);
    assert(SumArrayBetween(array, 7, 1) == 21);
    assert(SumArrayBetween(array, 7, 2) == 20);
    int array2[] = {0,1,2,3,4,-1,5,6};
    assert(SumArrayBetween(array2, 8, 0) == 10);
    assert(SumArrayBetween(array2, 8, 3) == 7);
    return 0;
}

int test_average_array_between() {
    int array[] = {0,1,2,3,4,5,6};
    assert(AverageArrayBetween(array, 7, 0) == 3);
    assert(AverageArrayBetween(array, 7, 1) == 3);
    assert(AverageArrayBetween(array, 7, 2) == 4);
    int array2[] = {0,1,2,3,4,-1,5,6};
    assert(AverageArrayBetween(array2, 8, 0) == 2);
    assert(AverageArrayBetween(array2, 8, 3) == 3);
    return 0;
}

int test_sum_array() {
    int array[] = {1, 2, 3, 4, 5};
    assert(SumArray(array, 5) == 15);
    int array2[] = {1, 2, 3, 4, 5, 6};
    assert(SumArray(array2, 6) == 21);
    int array3[] = {1, 2, 3, 4, 5, 6, 7};
    assert(SumArray(array3, 7) == 28);
    int array4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9 ,10, 11,12};
    assert(SumArray(array4, 12) == 78);
    int *array5 = malloc(sizeof(int) * 100);
    for (int i = 0; i < 100; ++i) {
        array5[i] = i;
    }
    assert(SumArray(array5, 100) == 4950);
    free(array5);
    int array6[] = {0, 3, 5,2 ,4,6,7,8,1564,1567,21,84,6,74};
    assert(SumArray(array6, 14) == 3351);

    return 0;
}

int test_average_array() {
    int array[] = {1, 2, 3, 4, 5};
    assert(AverageArray(array, 5) == 3);
    int array2[] = {1, 2, 3, 4, 5, 6};
    assert(AverageArray(array2, 6) == 3);
    int array3[] = {1, 2, 3, 4, 5, 6, 7};
    assert(AverageArray(array3, 7) == 4);
    int array4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9 ,10, 11,12};
    assert(AverageArray(array4, 12) == 6);
    int *array5 = malloc(sizeof(int) * 100);
    for (int i = 0; i < 100; ++i) {
        array5[i] = i;
    }
    assert(AverageArray(array5, 100) == 49);
    free(array5);
    int array6[] = {0, 3, 5,2 ,4,6,7,8,1564,1567,21,84,6,74};
    assert(AverageArray(array6, 14) == 239);

    return 0;
}

int test_get_min_index_between() {
    int array[] = {1, 2, 3, 4, 5};
    assert(getMinIndexBetween(array, 5, 0, 4) == 0);
    assert(getMinIndexBetween(array, 5, 0, 5) == 0);
    int array2[] = {4, 5 ,6,7,45,1,56,48,96};
    assert(getMinIndexBetween(array2, 9, 0, 4) == 0);
    assert(getMinIndexBetween(array2, 9, 0, 5) == 5);
    assert(getMinIndexBetween(array2, 9, 6, 8) == 7);

    return 0;
}

int test_get_min_index(){
    int array[] = {1, 2, 3, 4, 5};
    assert(getMinIndex(array, 5) == 0);
    int array2[] = {5, 4, 3, 2, 1};
    assert(getMinIndex(array2, 5) == 4);
    int array3[] = {1, 2, 3, 4, 1};
    assert(getMinIndex(array3, 5) == 0);
    return 0;
}

int test_smallest_element() {
    int array[] = {1, 2, 3, 4, 5};
    assert(smallestElement(array, 5) == 1);
    int array2[] = {5, 4, 3, 2, 1};
    assert(smallestElement(array2, 5) == 1);
    int array3[] = {1, 1, 1, 1, 1};
    assert(smallestElement(array3, 5) == 1);
    int array4[] = {4,5,9,10,69,6,2,48,21};
    assert(smallestElement(array4, 9) == 2);
    return 0;
}

