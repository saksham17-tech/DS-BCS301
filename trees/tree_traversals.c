#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

Node* tree = NULL;

Node* create(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode==NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorder(Node* curr) {
    if(curr==NULL)  return;
    inorder(curr->left);
    printf("%d ", curr->val);
    inorder(curr->right);
}

void preorder(Node* curr) {
    if(curr==NULL)  return;
    printf("%d ", curr->val);
    preorder(curr->left);
    preorder(curr->right);
}

void postorder(Node* curr) {
    if(curr==NULL)  return;
    postorder(curr->left);
    postorder(curr->right);
    printf("%d ", curr->val);
}

int main() {
    tree = create(1);
    tree->left = create(2);
    tree->right = create(3);
    tree->left->left = create(4);
    tree->left->right = create(5);
    tree->right->left = create(6);
    tree->right->right = create(7);

    printf("Preorder Traversal:   ");
    preorder(tree);
    printf("\n");

    printf("Inorder Traversal:    ");
    inorder(tree);
    printf("\n");

    printf("Postorder Traversal:  ");
    postorder(tree);
    printf("\n");

    return 0;
}