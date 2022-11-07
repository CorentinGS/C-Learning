/******************************************************************************
 * Copyright (c) 2022.                                                        *
 *                                                                            *
 *                                                                            *
 * Learning C                             ______   _______      _______.      *
 * sort_benchmark.h                      /      | /  _____|    /       |      *
 *                                      |  ,----'|  |  __     |   (----`      *
 * By: CorentinGS                       |  |     |  | |_ |     \   \          *
 * <c.giaufersaubert@outlook.com>       |  `----.|  |__| | .----)   |         *
 *                                       \______| \______| |_______/  (_/ -/  *
 * LICENCE: MIT                                                        /  /   *
 * Created: 2022/11/7 by CorentinGS                                           *
 *                                                                            *
 ******************************************************************************/

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
