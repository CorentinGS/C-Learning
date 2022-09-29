cmake_minimum_required(VERSION 3.23)
project(C C)

set(CMAKE_C_STANDARD 99)

add_executable(C src/main.c src/main.h src/utils/utils.c src/utils/utils.h src/common.h src/tests/utils/utils_test.c src/tests/utils/utils_test.h src/tests/tests.c src/tests/tests.h src/utils/enum.h src/linked_list/linked_list.c src/linked_list/linked_list.h src/utils/colors.h src/tests/linked_list/linked_list_test.c src/tests/linked_list/linked_list_test.h src/ds_td/td1.c src/ds_td/td1.h src/tests/ds_td/td1_test.c src/tests/ds_td/td1_test.h src/sort/merge_sort.c src/sort/merge_sort.h src/tests/sort/merge_sort_test.c src/tests/sort/merge_sort_test.h src/exercices/pyramide.c src/exercices/pyramide.h src/tests/exercices/pyramide_test.c src/tests/exercices/pyramide_test.h src/sort/sort.c src/sort/sort.h src/tests/sort/sort_test.c src/tests/sort/sort_test.h src/sort/heap_sort.c src/sort/matrix_sort.c src/benchmark/sort_benchmark.c src/benchmark/sort_benchmark.h src/sort/counting_sort.c src/exercices/sdd_2019.c src/exercices/sdd_2019.h)
