/******************************************************************************
2025-2026 Data Structures Güz Final Ödevleri Samet Sayın Student No: 2510213383
*******************************************************************************/

#include <stdio.h>

int main() {
    int matrix[3][3] = {
        {0, 0, 5},
        {1, 0, 0},
        {0, 2, 0}
    };

    int rows = 3, cols = 3;
    int size = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                size++;
            }
        }
    }

    int sparse[size][3];
    int k = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    printf("Row    Column  Value\n");
    for (int i = 0; i < size; i++) {
        printf("%d      %d        %d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }

    return 0;
}