/******************************************************************************
2025-2026 Data Structures Güz Final Ödevleri Samet Sayın Student No: 2510213383
*******************************************************************************/
#include <stdio.h>

int main() {
    int graph[3][3] = {
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 0}
    };
    int visited[3] = {0};

    for (int i = 0; i < 3; i++) {
        if (!visited[i]) {
            printf("Group: %d ", i);
            visited[i] = 1;
            for (int j = 0; j < 3; j++) {
                if (graph[i][j] == 1 && !visited[j]) {
                    printf("%d ", j);
                    visited[j] = 1;
                }
            }
            printf("\n");
        }
    }
    return 0;
}