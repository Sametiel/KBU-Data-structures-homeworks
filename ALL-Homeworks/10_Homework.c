/******************************************************************************
2025-2026 Data Structures Güz Final Ödevleri Samet Sayın Student No: 2510213383
*******************************************************************************/
#include <stdio.h>

void printTree(int arr[], int n, int i) {
    if (i < n) {
        printTree(arr, n, 2 * i + 1);
        printf("%d ", arr[i]);
        printTree(arr, n, 2 * i + 2);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    printf("Inorder: ");
    printTree(arr, n, 0);
    
    return 0;
}