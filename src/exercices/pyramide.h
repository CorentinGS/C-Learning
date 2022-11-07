/******************************************************************************
 * Copyright (c) 2022.                                                        *
 *                                                                            *
 *                                                                            *
 * Learning C                             ______   _______      _______.      *
 * pyramide.h                            /      | /  _____|    /       |      *
 *                                      |  ,----'|  |  __     |   (----`      *
 * By: CorentinGS                       |  |     |  | |_ |     \   \          *
 * <c.giaufersaubert@outlook.com>       |  `----.|  |__| | .----)   |         *
 *                                       \______| \______| |_______/  (_/ -/  *
 * LICENCE: MIT                                                        /  /   *
 * Created: 2022/11/7 by CorentinGS                                           *
 *                                                                            *
 ******************************************************************************/

#ifndef C_PYRAMIDE_H
#define C_PYRAMIDE_H

void display_pyramide(int* pyramide, int size);
extern int pyramide(void);
void fill_pyramide(int* pyramide, int size);
int find_row_col(int* pyramide, int size, int row, int col);

#endif //C_PYRAMIDE_H
