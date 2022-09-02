//
// Created by yume on 02/09/22.
//

#include <stdio.h>
#include <assert.h>
#include "tests.h"

#define LEN(x)  (sizeof(x) / sizeof((x)[0]))


void test_create_linked_list();
void test_linked_list_size();
void test_linked_list_to_array();
void test_insert_at_head();
void test_insert_at_end();

void tests () {
    printf(ANSI_COLOR_YELLOW"➡️ utils functions....."ANSI_COLOR_RESET);
    sum_testing();
    printf(ANSI_COLOR_GREEN "OK \n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW"➡️ linked list........."ANSI_COLOR_RESET);
    test_create_linked_list();
    test_linked_list_to_array();
    test_linked_list_size();
    test_insert_at_head();
    test_insert_at_end();
    printf(ANSI_COLOR_GREEN "OK \n" ANSI_COLOR_RESET);

}

void test_create_linked_list() {
    int initial_array[] = {1, 2, 3, 4, 5};
    size_t n = LEN(initial_array);
    Node *head = create_linked_list( initial_array, n);
    for (int i = 0; i < 5; i++) {
        assert(head->value == initial_array[i]);
        head = head->next;
    }

    free_linked_list(head);
}

void test_linked_list_size() {
    int initial_array[] = {1, 2, 3, 4, 5};
    size_t n = LEN(initial_array);
    Node *head = create_linked_list( initial_array, n);
    assert(get_linked_list_size(head) == 5);

    free_linked_list(head);
}

void test_linked_list_to_array() {
    int initial_array[] = {1, 2, 3, 4, 5};
    size_t n = LEN(initial_array);
    Node *head = create_linked_list( initial_array, n);
    int *array = linked_list_to_array(head);

    for (int i = 0; i < n; i++) {
        assert(array[i] == initial_array[i]);
    }
    free_linked_list(head);
}

void test_insert_at_head() {
    int initial_array[] = {1, 2, 3, 4, 5};
    size_t n = LEN(initial_array);
    Node *head = create_linked_list( initial_array, n);
    int new_value = 0;
    insert_at_head(&head, new_value);
    assert(head->value == new_value);
    assert(head->next->value == 1);
    free_linked_list(head);
}

void test_insert_at_end() {
    int initial_array[] = {1, 2, 3, 4, 5};
    size_t n = LEN(initial_array);
    Node *head = create_linked_list( initial_array, n);
    int new_value = 6;
    insert_at_end(head, new_value);
    while (head->next != NULL) {
        head = head->next;
    }
    assert(head->value == new_value);
    free_linked_list(head);
}
