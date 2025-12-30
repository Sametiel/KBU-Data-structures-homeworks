/******************************************************************************
2025-2026 Data Structures Güz Final Ödevleri Samet Sayın Student No: 2510213383
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) return;

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;

    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

void deleteNode(struct Node** head_ref, struct Node* del) {
    if (*head_ref == NULL || del == NULL) return;

    if (*head_ref == del)
        *head_ref = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
}

void traverse(struct Node* node) {
    struct Node* last;
    printf("Forward: ");
    while (node != NULL) {
        printf("%d ", node->data);
        last = node;
        node = node->next;
    }
    printf("\nBackward: ");
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->prev;
    }
    printf("\n");
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 54;
    head->prev = NULL;
    head->next = NULL;

    insertAfter(head, 81);
    insertAfter(head, 78); 

    traverse(head);

    deleteNode(&head, head->next);

    traverse(head);

    return 0;
}