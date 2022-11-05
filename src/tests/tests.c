//
// Created by yume on 02/09/22.
//

#include <stdio.h>
#include "tests.h"
#include "ds_td/td1_test.h"
#include "sort/merge_sort_test.h"
#include "exercices/pyramide_test.h"
#include "sort/sort_test.h"

void test_utils(void);
void test_linked_list(void);
void test_ds_td(void);
void test_sort(void);
void test_exercices(void);

void
tests(void) {
    test_utils();
    test_linked_list();
    test_ds_td();
    test_sort();
    test_exercices();
}

void
test_utils(void) {
    printf(ANSI_COLOR_YELLOW "➡️ utils functions....." ANSI_COLOR_RESET);
    sum_testing();
    test_division();
    test_min();
    test_max();
    printf(ANSI_COLOR_GREEN "OK \n" ANSI_COLOR_RESET);
}

void
test_linked_list(void) {
    printf(ANSI_COLOR_YELLOW "➡️ linked list........." ANSI_COLOR_RESET);
    test_create_linked_list();
    test_linked_list_to_array();
    test_linked_list_size();
    test_insert_at_head();
    test_insert_at_end();
    printf(ANSI_COLOR_GREEN "OK \n" ANSI_COLOR_RESET);
}

void
test_ds_td(void) {
    printf(ANSI_COLOR_YELLOW "➡️ Data Structure TD..." ANSI_COLOR_RESET);
    test_td1();
    printf(ANSI_COLOR_GREEN "OK \n" ANSI_COLOR_RESET);
}

void
test_sort(void) {
    printf(ANSI_COLOR_YELLOW "➡️ Sorting............." ANSI_COLOR_RESET);
    test_merge_sort();
    test_merge_sort_random();
    test_insertion_sort();
    test_selection_sort();
    test_heap_sort();
    test_revert_heap_sort();
    test_matrix_sort();
    test_bubble_sort();
    test_counting_sort();
    // benchmark_merge_sort();
    printf(ANSI_COLOR_GREEN "OK \n" ANSI_COLOR_RESET);
}

void
test_exercices(void) {
    printf(ANSI_COLOR_YELLOW "➡️ Exercices..........." ANSI_COLOR_RESET);
    test_fill_pyramide();
    test_find_row_col();
    printf(ANSI_COLOR_GREEN "OK \n" ANSI_COLOR_RESET);
}
