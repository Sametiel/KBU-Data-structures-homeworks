#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *head = NULL;
Node *tail = NULL;

void add_to_end_dll(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) return;
    
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}


void delete_all_recursive(Node *current) {
    if (current == NULL) {
        return;
    }
    
    delete_all_recursive(current->next);
    
    free(current);
}

void delete_linked_list_recursive() {
    delete_all_recursive(head);
    head = NULL;
    tail = NULL;
}

void add_between_dll(Node *prevNode, int value) {
    if (prevNode == NULL) return;

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) return;
    
    newNode->data = value;
    
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    
    if (prevNode->next != NULL) {
        prevNode->next->prev = newNode;
    } else {
        tail = newNode;
    }
    
    prevNode->next = newNode;
}


void traverse() {
    Node *current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    
    add_to_end_dll(10);
    add_to_end_dll(20);
    add_to_end_dll(40);
    
    printf("Initial List: ");
    traverse();

    Node *target = head->next; 

    add_between_dll(target, 30);
    
    printf("After Insertion (30): ");
    traverse();
    
    delete_linked_list_recursive();
    
    printf("After Recursive Deletion: ");
    traverse();

    return 0;
}