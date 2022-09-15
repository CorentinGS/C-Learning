//
// Created by yume on 02/09/22.
//

#include <stdio.h>
#include "tests.h"
#include "ds_td/td1_test.h"


void test_utils();
void test_linked_list();
void test_ds_td();

void tests () {
    test_utils();
    test_linked_list();
    test_ds_td();
}

void test_utils(){
    printf(ANSI_COLOR_YELLOW"➡️ utils functions....."ANSI_COLOR_RESET);
    sum_testing();
    test_division();
    test_min();
    test_max();
    printf(ANSI_COLOR_GREEN "OK \n" ANSI_COLOR_RESET);
}

void test_linked_list(){
    printf(ANSI_COLOR_YELLOW"➡️ linked list........."ANSI_COLOR_RESET);
    test_create_linked_list();
    test_linked_list_to_array();
    test_linked_list_size();
    test_insert_at_head();
    test_insert_at_end();
    printf(ANSI_COLOR_GREEN "OK \n" ANSI_COLOR_RESET);
}

void test_ds_td() {
    printf(ANSI_COLOR_YELLOW"➡️ Data Structure TD..."ANSI_COLOR_RESET);
    test_td1();
    printf(ANSI_COLOR_GREEN "OK \n" ANSI_COLOR_RESET);

}


