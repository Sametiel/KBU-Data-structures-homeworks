#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node *left, *right;
};

struct Node* create(char val) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

void preOrder(struct Node* root) {
    if (root == NULL) return;
    printf("%c ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    struct Node* root = create('=');
    root->left = create('s');
    root->right = create('+');
    root->right->left = create('m');
    root->right->right = create('*');
    root->right->right->left = create('t');
    root->right->right->right = create('2');
    printf("--- AST AGAC YAPISI ---\n\n");
    printf("    %c\n", root->data);
    printf("   / \\\n");
    printf("  %c   %c\n", root->left->data, root->right->data);
    printf("     / \\\n");
    printf("    %c   %c\n", root->right->left->data, root->right->right->data);
    printf("       / \\\n");
    printf("      %c   %c\n", root->right->right->left->data, root->right->right->right->data);

    printf("\n--- PRE-ORDER CIKTI ---\n");
    preOrder(root);
    printf("\n");

    return 0;
}