#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "utils/enum.h"

int debug_mode = 0;


int main() {
    init();
    return 0;
}



int get_debug_mode() {
    char *debug = getenv("DEBUG_MODE");
    if (debug == NULL || strcmp(debug, "release") == 0) {
        return DEBUG_MODE_NONE;
    }

    if (strcmp(debug, "test") == 0) {
        return DEBUG_MODE_TEST;
    }

    return DEBUG_MODE_ALL;
}

void init() {
    debug_mode = get_debug_mode();
    if (debug_mode == DEBUG_MODE_TEST || debug_mode == DEBUG_MODE_ALL) {
        printf("Debug mode: %d\n", debug_mode);
        printf("--------------------------------\n");
        printf("Running tests...\n");
        tests();
        printf("--------------------------------\n");
        printf("Tests finished with no errors\n");
    } else {
        printf("Release mode\n");
        printf("--------------------------------\n");
        printf("Running main...\n");
    }
}

