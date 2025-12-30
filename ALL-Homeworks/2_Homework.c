/******************************************************************************
2025-2026 Data Structures Güz Final Ödevleri Samet Sayın Student No: 2510213383
*******************************************************************************/
#include <stdio.h>

void hanoi(int n, char source, char auxiliary, char target) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, target);
        return;
    }
    
    hanoi(n - 1, source, target, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, target);
    hanoi(n - 1, auxiliary, source, target);
}

int main() {
    int n = 3;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}