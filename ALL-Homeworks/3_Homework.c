/******************************************************************************
2025-2026 Data Structures Güz Final Ödevleri Samet Sayın Student No: 2510213383
*******************************************************************************/
#include <stdio.h>
#include <ctype.h>

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void shunting_yard(char* infix) {
    char stack[100];
    int top = -1;

    for (int i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];

        if (isalnum(token)) {
            printf("%c", token);
        } else if (token == '(') {
            stack[++top] = token;
        } else if (token == ')') {
            while (top != -1 && stack[top] != '(') {
                printf("%c", stack[top--]);
            }
            top--; 
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(token)) {
                printf("%c", stack[top--]);
            }
            stack[++top] = token;
        }
    }

    while (top != -1) {
        printf("%c", stack[top--]);
    }
    printf("\n");
}

int main() {
    char expression[] = "S+M*(T-X)";
    shunting_yard(expression);
    return 0;
}