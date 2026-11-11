#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

Node* tree = NULL;
int sz = 0;

int isEmpty() {
    return sz==0;
}

int isFull() {
    return sz==100;
}

Node* getNode(Node* curr, int tidx, int cidx) {
    if(curr==NULL || cidx>tidx)  return NULL;
    if(cidx==tidx)  return curr;
    
    Node* leftSearch = getNode(curr->left, tidx, 2*cidx+1);
    if(leftSearch!=NULL)  return leftSearch;
    
    return getNode(curr->right, tidx, 2*cidx+2);
}

Node* create(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(int idx, int val) {
    if(isFull()) {
        printf("Tree is Full!\n");
        return;
    }
    if(idx<0 || idx>=100) {
        printf("Index %d is out of bounds!\n", idx);
        return;
    }
    if(getNode(tree, idx, 0)!=NULL) {
        printf("Node already exists at index %d!\n", idx);
        return;
    }
    if(idx==0) {
        tree = create(val);
        if(tree!=NULL)  sz++;
        return;
    }

    int parent = (idx-1)/2;
    Node* pNode = getNode(tree, parent, 0);

    if(pNode==NULL) {
        printf("Parent does not exist for %d!\n", val);
        return;
    }

    if(idx==2*parent+1) {
        pNode->left = create(val);
        if(pNode->left!=NULL)  sz++;
    } else {
        pNode->right = create(val);
        if(pNode->right!=NULL)  sz++;
    }
}

void freeSubtree(Node* curr) {
    if(curr==NULL)  return;
    freeSubtree(curr->left);
    freeSubtree(curr->right);
    free(curr);
    sz--;
}

void delete(int idx) {
    if(isEmpty()) {
        printf("Tree is Empty!\n");
        return;
    }
    if(idx<0 || idx>=100) {
        printf("Index %d is out of bounds!\n", idx);
        return;
    }
    if(idx==0) {
        freeSubtree(tree);
        tree = NULL;
        printf("Deleted node at index %d\n", idx);
        return;
    }

    int parent = (idx-1)/2;
    Node* pNode = getNode(tree, parent, 0);

    if(pNode==NULL) {
        printf("Error: No node exists at index %d.\n", idx);
        return;
    }

    if(idx==2*parent+1 && pNode->left!=NULL) {
        freeSubtree(pNode->left);
        pNode->left = NULL;
        printf("Deleted node at index %d\n", idx);
    }
    else if(idx==2*parent+2 && pNode->right!=NULL) {
        freeSubtree(pNode->right);
        pNode->right = NULL;
        printf("Deleted node at index %d\n", idx);
    }
    else    printf("Error: No node exists at index %d.\n", idx);
}

void inorder(Node* curr) {
    if(curr==NULL)  return;
    inorder(curr->left);
    printf("%d ", curr->val);
    inorder(curr->right);
}

void display() {
    if(isEmpty()) {
        printf("Tree is empty.\n");
        return;
    }
    printf("\n--- Linked List Binary Tree (Inorder) ---\n");
    inorder(tree);
    printf("\nTotal Nodes: %d\n", sz);
    printf("-----------------------------------------\n");
}

int main() {
    int tn = 0;
    printf("Enter total number of nodes to insert (max %d): ", 100);
    if(scanf("%d", &tn)!=1 || tn<=0 || tn>100) {
        printf("Invalid number of nodes.\n");
        return -99;
    }
    printf("\n--- Input Node Details ---\n");
    printf("Note: 0-based indexing. Root is at index 0.\n");
    printf("For a node at index i, left child is at (2*i + 1), right child is at (2*i + 2).\n\n");

    for(int i=0; i<tn; ++i) {
        int pos, val;
        printf("Node %d - Enter position(index) and value: ", i+1);
        scanf("%d %d", &pos, &val);
        insert(pos, val);
    }

    display();

    int delIndex;
    printf("\nEnter index of node to delete (or -1 to skip): ");
    scanf("%d", &delIndex);
    if(delIndex>=0) {
        delete(delIndex);
        display();
    }

    return 0;
}