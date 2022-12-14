
/******************************************************************************
 * Copyright (c) 2022.                                                        *
 *                                                                            *
 *                                                                            *
 * Learning C                             ______   _______      _______.      *
 * linked_list.h                         /      | /  _____|    /       |      *
 *                                      |  ,----'|  |  __     |   (----`      *
 * By: CorentinGS                       |  |     |  | |_ |     \   \          *
 * <c.giaufersaubert@outlook.com>       |  `----.|  |__| | .----)   |         *
 *                                       \______| \______| |_______/  (_/ -/  *
 * LICENCE: MIT                                                        /  /   *
 * Created: 2022/11/7 by CorentinGS                                           *
 *                                                                            *
 ******************************************************************************/

#ifndef C_LINKED_LIST_H
#define C_LINKED_LIST_H

struct Node {
    int value;
    struct Node* next;
};

typedef struct Node Node;

extern struct Node* create_linked_list(int* values, size_t size);
extern void print_linked_list(struct Node* head);
extern struct Node* create_node(int value);
extern int* linked_list_to_array(struct Node* head);
extern int get_linked_list_size(struct Node* head);
void insert_at_head(struct Node** head, int value);
void free_linked_list(struct Node* head);
void insert_at_end(struct Node* head, int value);
#endif //C_LINKED_LIST_H
