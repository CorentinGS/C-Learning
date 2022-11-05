//
// Created by yume on 03/09/22.
//

#ifndef C_LINKED_LIST_TEST_H
#define C_LINKED_LIST_TEST_H

void test_create_linked_list(void);
void test_linked_list_size(void);
void test_linked_list_to_array(void);
void test_insert_at_head(void);
void test_insert_at_end(void);

#define LEN(x) (sizeof(x) / sizeof((x)[0]))

#include "../../linked_list/linked_list.h"

#endif //C_LINKED_LIST_TEST_H
