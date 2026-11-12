//CONSTRUCTION OF BINRAY TREE WHEN IN-ORDER AND PRE-ORDER TRAVERSALS ARE GIVEN
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* left;
    struct Node* right;
    int val;
} Node;

Node* tree = NULL;
int pidx = 0;

Node* create(int val) {
    Node* nn = (Node*)malloc(sizeof(Node));
    nn->val = val;
    nn->right = NULL;
    nn->left = NULL;
    return nn;
}

int search(int in[], int start, int end, int val) {
    for(int i=start; i<=end; ++i)
        if(in[i]==val)  return i;
    return -1;
}

Node* construct(int pre[], int in[], int start, int end) {
    if(start>end)   return NULL;
    int rootval = pre[pidx--];
    Node* curr = create(rootval);
    if(start==end)  return curr;
    int inidx = search(in, start, end, rootval);
    curr->right = construct(pre, in, inidx+1, end);
    curr->left = construct(pre, in, start, inidx-1);
    return curr;
}

void preorder(Node* curr) {
    if(!curr)   return;
    printf("%d  ",curr->val);
    preorder(curr->left);
    preorder(curr->right);
}

int main() {
    int in[] = {4, 2, 5, 1, 6, 3, 7};
    int post[] = {4, 5, 2, 6, 7, 3, 1};
    int n = sizeof(in)/sizeof(in[0]);

    pidx = n-1;
    tree = construct(post, in, 0, n-1);

    printf("Constructed Tree Verification (Preorder Traversal):\n");
    preorder(tree);
    printf("\n");
    
    return 0;
}