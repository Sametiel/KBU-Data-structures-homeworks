#include <stdio.h>
#include <stdlib.h>
//Pre-order şekilde yazdırma örneği hocam.
struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* create(int val) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

void preOrder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data); 
    preOrder(root->left);      
    preOrder(root->right);     
}

int main() {
    
    struct Node* root = create(1);
    root->left = create(2);
    root->right = create(3);
    
    root->left->left = create(4);
    root->left->right = create(5);
    
    root->right->left = create(6);
    root->right->right = create(7);

   
    printf("AGAC YAPISI\n\n");
    printf("      %d\n", root->data);
    printf("     / \\\n");
    printf("    %d   %d\n", root->left->data, root->right->data);
    printf("   / \\ / \\\n");
    printf("  %d  %d %d  %d\n", 
            root->left->left->data, root->left->right->data, 
            root->right->left->data, root->right->right->data);

    
    printf("Pre-Order:");
    preOrder(root);

    return 0;
}