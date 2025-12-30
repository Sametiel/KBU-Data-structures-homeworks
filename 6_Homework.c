/******************************************************************************
2025-2026 Data Structures Güz Final Ödevleri Samet Sayın Student No: 2510213383
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void traverse(struct Node* head) {
    if (head == NULL) return;
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) return;
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void deleteNode(struct Node** head_ref, int key) {
    if (*head_ref == NULL) return;
    struct Node *curr = *head_ref, *prev;
    if (curr->data == key && curr->next == *head_ref) {
        free(curr);
        *head_ref = NULL;
        return;
    }
    if (curr->data == key) {
        while (curr->next != *head_ref) curr = curr->next;
        curr->next = (*head_ref)->next;
        free(*head_ref);
        *head_ref = curr->next;
        return;
    }
    curr = *head_ref;
    while (curr->next != *head_ref && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }
    if (curr->data == key) {
        prev->next = curr->next;
        free(curr);
    }
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 81;
    head->next = head;
    insertAfter(head, 54);
    insertAfter(head, 78);
    traverse(head);
    deleteNode(&head, 78);
    traverse(head);
    return 0;
}