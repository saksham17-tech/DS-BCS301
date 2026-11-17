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
    nn->left = nn->right = NULL;
    return nn;
}

int search(int in[], int start, int end, int val) {
    for(int i=start; i<=end; ++i)
        if(in[i]==val) return i;
    return -1;
}

Node* construct(int pre[], int in[], int start, int end) {
    if(start>end) return NULL;
    int rootval = pre[pidx++];
    Node* curr = create(rootval);
    if(start==end) return curr;
    int inidx = search(in, start, end, rootval);
    curr->left = construct(pre, in, start, inidx-1);
    curr->right = construct(pre, in, inidx+1, end);
    return curr;
}

void postorder(Node* curr) {
    if(!curr) return;
    postorder(curr->left);
    postorder(curr->right);
    printf("%d ", curr->val);
}

int main() {
    int in[] = {4, 2, 5, 1, 6, 3, 7};
    int pre[] = {1, 2, 4, 5, 3, 6, 7};
    int n = sizeof(in)/sizeof(in[0]);

    pidx = 0;
    tree = construct(pre, in, 0, n-1);

    printf("Constructed Tree Verification (Postorder Traversal):\n");
    postorder(tree);
    printf("\n");
    
    return 0;
}