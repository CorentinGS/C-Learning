//
// Created by yume on 02/09/22.
//

#include "utils_test.h"
#include "assert.h"

int sum_testing() {
    assert(sum(1, 2) == 3);
    assert(sum(2, 3) == 5);
    assert(sum(3, 4) == 7);
    assert(sum(4, 5) == 9);
    return 0;
}