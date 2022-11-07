
/******************************************************************************
 * Copyright (c) 2022.                                                        *
 *                                                                            *
 *                                                                            *
 * Learning C                             ______   _______      _______.      *
 * sort.h                                /      | /  _____|    /       |      *
 *                                      |  ,----'|  |  __     |   (----`      *
 * By: CorentinGS                       |  |     |  | |_ |     \   \          *
 * <c.giaufersaubert@outlook.com>       |  `----.|  |__| | .----)   |         *
 *                                       \______| \______| |_______/  (_/ -/  *
 * LICENCE: MIT                                                        /  /   *
 * Created: 2022/11/7 by CorentinGS                                           *
 *                                                                            *
 ******************************************************************************/

#ifndef C_SORT_H
#define C_SORT_H

extern void InsertionSort(int* array, int size);
extern void SelectionSort(int* array, int size);
extern void HeapSort(int* array, int size);
extern void RevertHeapSort(int* array, int size);
extern void MatrixSort(int* matrix, int size_row, int size_col);
extern void BubbleSort(int* array, int size);
extern void CountingSort(int* array, int size);

#endif //C_SORT_H
