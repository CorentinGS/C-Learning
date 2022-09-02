//
// Created by yume on 02/09/22.
//

#include <stddef.h>
#include <malloc.h>
#include "linked_list.h"

struct Node *create_node(int value) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->value = value;
    node->next = NULL;
    return node;
}

struct Node *create_linked_list(int *values, size_t size) {
    struct Node *head = NULL;
    struct Node *tail = NULL;
    for (int i = 0; i < size; i++) {
        struct Node *node = create_node(values[i]);
        if (head == NULL) {
            head = node;
            head->next = tail;
        } else {
            tail->next = node;
        }
        tail = node;
    }
    return head;
}

void print_linked_list(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

int get_linked_list_size(struct Node *head) {
    int size = 0;
    while (head != NULL) {
        size++;
        head = head->next;
    }
    return size;
}

int* linked_list_to_array(struct Node *head) {
    int size = get_linked_list_size(head);
    int *array = (int *) malloc(sizeof(int) * size);
    int i = 0;
    while (head != NULL) {
        array[i] = head->value;
        head = head->next;
        i++;
    }
    return array;
}

void insert_at_head(struct Node **head, int value) {
    struct Node *node = create_node(value);
    node->next = *head;
    *head = node;
}

void insert_at_end(struct Node *head, int value) {
   struct Node *node = create_node(value);
   while (head->next != NULL) {
       head = head->next;
   }
    head->next = node;
}

void free_linked_list(struct Node *head) {
    struct Node *next;
    while (head != NULL) {
        next = head->next;
        free(head);
        head = next;
    }
}