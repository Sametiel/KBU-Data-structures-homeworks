#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

int main() {
    Node *head = NULL;

    int values[] = {30, 20, 10};

    for (int i = 0; i < 3; i++) {
        Node *newNode = (Node *)malloc(sizeof(Node));
        
        newNode->data = values[i];
        
        newNode->next = head;
        
        head = newNode;
    }
    
    Node *current = head;
    
    printf("Liste: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    current = head;
    while (current != NULL) {
        Node *next_node = current->next;
        free(current);
        current = next_node;
    }
    head = NULL;

    return 0;
}