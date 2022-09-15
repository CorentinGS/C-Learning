#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "utils/enum.h"
#include "ds_td/td1.h"

int debug_mode = 0;

int main() {
    init();

    char string[] = "Hello World!";
    PrintStringWhile(string, LEN(string));

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
        printf(ANSI_COLOR_MAGENTA "Debug mode: %d\n" ANSI_COLOR_RESET, debug_mode);
        printf("--------------------------------\n");
        printf(ANSI_COLOR_RED "Running tests ⤵️\n" ANSI_COLOR_RESET);
        tests();
        printf("--------------------------------\n");
        printf(ANSI_COLOR_GREEN "Tests finished with no errors ✅\n" ANSI_COLOR_RESET);
    } else {
        printf(ANSI_COLOR_BLUE "Release mode\n" ANSI_COLOR_RESET);
        printf("--------------------------------\n");
        printf("Running main...\n");
    }
}

