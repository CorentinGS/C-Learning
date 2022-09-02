cmake_minimum_required(VERSION 3.23)
project(C C)

set(CMAKE_C_STANDARD 99)

add_executable(C src/main.c src/main.h src/utils/utils.c src/utils/utils.h src/common.h src/tests/utils_test.c src/tests/utils_test.h src/tests/tests.c src/tests/tests.h src/utils/enum.h src/linked_list/linked_list.c src/linked_list/linked_list.h)
