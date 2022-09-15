//
// Created by yume on 15/09/22.
//

#include "merge_sort.h"

void MergeSort(int array[], int l, int r) {
    if (l < r) {
        // Split the array into two parts
        int m = l + (r - l) / 2;

        // Sort the two parts recursively
        MergeSort(array, l, m); // Left part
        MergeSort(array, m+1, r); // Right part

        // Merge the two parts together in sorted order
        Merge(array, l, m, r);
    }
}

void Merge(int arr[], int l, int m, int r) {
    // L = Arr[l...m]
    int nL = m-l+1;
    int L[nL];

    // R = Arr[m...r]
    int nR = r-m;
    int R[nR];

    // Copy the data to the temp arrays
    for (int i = 0; i < nL; i++) {
        L[i] = arr[l+i];
    }

    for (int j = 0;j<nR; j++) {
        R[j] = arr[m+j+1];
    }

    // Merge the temp arrays back into arr[l...r]
    int i, j, k; // i = index of L, j = index of R, k = index of arr
    i = 0; j = 0; k = l; // Initial index of L, R and arr

    // While there are elements in both L and R
    while (i < nL && j < nR) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    // Copy the remaining elements of L, if there are any
    while ( i < nL) {
        arr[k] = L[i];
        ++i; ++k;
    }

    // Copy the remaining elements of R, if there are any
    while (j < nR) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

