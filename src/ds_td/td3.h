/******************************************************************************
 * Copyright (c) 2022.                                                        *
 *                                                                            *
 *                                                                            *
 * Learning C                             ______   _______      _______.      *
 * td3.c                                 /      | /  _____|    /       |      *
 *                                      |  ,----'|  |  __     |   (----`      *
 * By: CorentinGS                       |  |     |  | |_ |     \   \          *
 * <c.giaufersaubert@outlook.com>       |  `----.|  |__| | .----)   |         *
 *                                       \______| \______| |_______/  (_/ -/  *
 * LICENCE: MIT                                                        /  /   *
 * Created: 2022/11/7 by CorentinGS                                           *
 *                                                                            *
 ******************************************************************************/

#ifndef C_TD3_H
#define C_TD3_H

extern void td3(void);
void update_sorted_array(int* array, int size, int value, int index);
void selection_sort(int* array, int size);
void merge_array(int* array, int size, int* array2, int size2, int* array3);
void merge_sort(int* array, int size);
#endif //C_TD3_H
