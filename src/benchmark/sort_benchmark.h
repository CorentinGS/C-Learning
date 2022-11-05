//
// Created by yume on 28/09/22.
//

#ifndef C_SORT_BENCHMARK_H
#define C_SORT_BENCHMARK_H

void benchmark_insertion_sort(int size);
void benchmark_selection_sort(int size);
void benchmark_heap_sort(int size);
void benchmark_merge_sort(int size);
void benchmark_bubble_sort(int size);
void benchmark_counting_sort(int size);

extern void benchmark(void);

#endif //C_SORT_BENCHMARK_H
