//
// Created by yume on 28/09/22.
//

#include <stdio.h>
#include "sort.h"

void Heapify(int* array, int size, int i);
void HeapifyMin(int* array, int size, int i);
void Swap(int* array, int i, int j);

void
Swap_temp(int* array, int i, int j) {
    // Swap array[i] and array[j] using a temporary variable
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void
Heapify(int* array, int size, int i) {

    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // left node = 2*i + 1
    int right = 2 * i + 2; // right node = 2*i + 2

    // If left child is larger than root (largest)
    if (left < size && array[left] > array[largest]) {
        largest = left; // largest = left
    }

    // If right child is larger than largest so far
    if (right < size && array[right] > array[largest]) {
        largest = right; // largest = right
    }

    // If largest is not root
    if (largest != i) {
        Swap_temp(array, i, largest);  // Swap array[i] and array[largest]
        Heapify(array, size, largest); // Recursively heapify the affected sub-tree until the heap property is satisfied
    }
}

void
HeapSort(int* array, int size) {

    // Build max heap (rearrange array)
    for (int i = size / 2 - 1; i >= 0; --i) {
        Heapify(array, size, i); // Heapify each node
    }

    // One by one extract an element from heap
    for (int i = size - 1; i >= 0; --i) {
        // Move current root to end
        Swap_temp(array, 0, i);
        // Call max heapify on the reduced heap
        Heapify(array, i, 0);
    }
}

void
RevertHeapSort(int* array, int size) {

    for (int i = size / 2 - 1; i >= 0; --i) {
        HeapifyMin(array, size, i);
    }

    for (int i = size - 1; i >= 0; --i) {
        Swap_temp(array, 0, i);
        HeapifyMin(array, i, 0);
    }
}

// Create a Min Heap from the array
void
HeapifyMin(int* array, int size, int i) {

    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && array[left] < array[smallest]) {
        smallest = left;
    }

    if (right < size && array[right] < array[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        Swap_temp(array, i, smallest);
        HeapifyMin(array, size, smallest);
    }
}
