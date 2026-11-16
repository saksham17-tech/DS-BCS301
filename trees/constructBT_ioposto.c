//CONSTRUCTION OF BINARY TREE WHEN IN-ORDER AND POST-ORDER TRAVERSALS ARE GIVEN
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* left;
    struct Node* right;
    int val;
} Node;

Node* tree = NULL;
int pidx = 0; // Will be initialized to n - 1 (end of post-order array)

Node* create(int val) {
    Node* nn = (Node*)malloc(sizeof(Node));
    nn->val = val;
    nn->right = NULL;
    nn->left = NULL;
    return nn;
}

int search(int in[], int start, int end, int val) {
    for(int i = start; i <= end; ++i)
        if(in[i] == val)  return i;
    return -1;
}

Node* construct(int post[], int in[], int start, int end) {
    if(start > end)   return NULL;
    
    // In Post-order, the root is at the current index 'pidx' (starting from the end)
    int rootval = post[pidx--];
    Node* curr = create(rootval);
    
    if(start == end)  return curr;
    
    int inidx = search(in, start, end, rootval);
    
    // IMPORTANT: Because we are moving backwards through post-order, 
    // we MUST build the RIGHT subtree before the LEFT subtree.
    curr->right = construct(post, in, inidx + 1, end);
    curr->left = construct(post, in, start, inidx - 1);
    
    return curr;
}

void preorder(Node* curr) {
    if(!curr)   return;
    printf("%d  ", curr->val);
    preorder(curr->left);
    preorder(curr->right);
}

int main() {
    int in[] = {4, 2, 5, 1, 6, 3, 7};
    int post[] = {4, 5, 2, 6, 7, 3, 1};
    int n = sizeof(in) / sizeof(in[0]);

    // Start pidx from the last element of the post-order array
    pidx = n - 1;
    tree = construct(post, in, 0, n - 1);

    printf("Constructed Tree Verification (Preorder Traversal):\n");
    preorder(tree);
    printf("\n");
    
    return 0;
}