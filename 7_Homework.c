/******************************************************************************
2025-2026 Data Structures Güz Final Ödevleri Samet Sayın Student No: 2510213383
*******************************************************************************/
#include <stdio.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[10] = {1, 2, 4, 5};
    int size = 4;
    int capacity = 10;

    int insertPos = 2;
    int newValue = 3;

    if (size < capacity) {
        for (int i = size; i > insertPos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[insertPos] = newValue;
        size++;
    }

    printArray(arr, size);

    int deletePos = 1;

    if (deletePos < size) {
        for (int i = deletePos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    printArray(arr, size);

    return 0;
}