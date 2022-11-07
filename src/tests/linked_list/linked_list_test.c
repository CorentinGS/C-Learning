//
// Created by yume on 03/09/22.
//

#include <stddef.h>
#include <assert.h>
#include <malloc.h>
#include "linked_list_test.h"

void
test_create_linked_list(void) {
    int initial_array[] = {1, 2, 3, 4, 5};
    size_t n = LEN(initial_array);
    Node* head = create_linked_list(initial_array, n);
    for (int i = 0; i < 5; i++) {
        assert(head->value == initial_array[i]);
        head = head->next;
    }

    free_linked_list(head);
}

void
test_linked_list_size(void) {
    int initial_array[] = {1, 2, 3, 4, 5};
    size_t n = LEN(initial_array);
    Node* head = create_linked_list(initial_array, n);
    assert(get_linked_list_size(head) == 5);

    free_linked_list(head);
}

void
test_linked_list_to_array(void) {
    int initial_array[] = {1, 2, 3, 4, 5};
    size_t n = LEN(initial_array);
    Node* head = create_linked_list(initial_array, n);
    int* array = linked_list_to_array(head);

    for (size_t i = 0; i < n; i++) {
        assert(array[i] == initial_array[i]);
    }
    free_linked_list(head);
    if (array != NULL) {
        free(array);
    }
}

void
test_insert_at_head(void) {
    int initial_array[] = {1, 2, 3, 4, 5};
    size_t n = LEN(initial_array);
    Node* head = create_linked_list(initial_array, n);
    int new_value = 0;
    insert_at_head(&head, new_value);
    assert(head->value == new_value);
    assert(head->next->value == 1);
    free_linked_list(head);
}

void
test_insert_at_end(void) {
    int initial_array[] = {1, 2, 3, 4, 5};
    size_t n = LEN(initial_array);
    Node* head = create_linked_list(initial_array, n);
    int new_value = 6;
    insert_at_end(head, new_value);
    while (head->next != NULL) {
        head = head->next;
    }
    assert(head->value == new_value);
    free_linked_list(head);
}
