/******************************************************************************
 * Copyright (c) 2022.                                                        *
 *                                                                            *
 *                                                                            *
 * Learning C                             ______   _______      _______.      *
 * td1.h                                 /      | /  _____|    /       |      *
 *                                      |  ,----'|  |  __     |   (----`      *
 * By: CorentinGS                       |  |     |  | |_ |     \   \          *
 * <c.giaufersaubert@outlook.com>       |  `----.|  |__| | .----)   |         *
 *                                       \______| \______| |_______/  (_/ -/  *
 * LICENCE: MIT                                                        /  /   *
 * Created: 2022/11/7 by CorentinGS                                           *
 *                                                                            *
 ******************************************************************************/

#ifndef C_TD1_H
#define C_TD1_H

extern int smallestElement(const int* array, int size);
extern int getMinIndex(const int* array, int size);
extern int getMinIndexBetween(const int array[], int size, int lo, int hi);
extern int SumArray(const int array[], int size);
extern int AverageArray(const int array[], int size);
extern int SumArrayBetween(const int array[], int size, int lo);
extern int AverageArrayBetween(const int array[], int size, int lo);
extern void PrintString(const char array[], int size);
extern void PrintStringWhile(const char array[], int size);

#endif //C_TD1_H
