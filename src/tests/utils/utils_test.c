//
// Created by yume on 02/09/22.
//

#include "utils_test.h"
#include "assert.h"

int
sum_testing(void) {
    assert(sum(1, 2) == 3);
    assert(sum(2, 3) == 5);
    assert(sum(3, 4) == 7);
    assert(sum(4, 5) == 9);
    return 0;
}

int
test_division(void) {
    assert(division(6, 2) == 3);
    assert(division(6, 3) == 2);
    assert(division(6, 4) == 1);
    assert(division(3, 2) == 1);
    return 0;
}

int
test_min(void) {
    assert(min(1, 2) == 1);
    assert(min(0, 0) == 0);
    assert(min(0, 1) == 0);
    assert(min(2, 3) == 2);
    assert(min(3, 4) == 3);
    assert(min(4, 5) == 4);
    return 0;
}

int
test_max(void) {
    assert(max(1, 2) == 2);
    assert(max(2, 3) == 3);
    assert(max(3, 4) == 4);
    assert(max(0, 0) == 0);
    assert(max(0, 1) == 1);
    assert(max(4, 5) == 5);
    return 0;
}
