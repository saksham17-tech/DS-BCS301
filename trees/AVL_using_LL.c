#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

Node* tree = NULL;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(Node* curr) {
    if(curr==NULL)  return 0;
    return curr->height;
}

int getBalance(Node* curr) {
    if(curr==NULL)  return 0;
    return getHeight(curr->left) - getHeight(curr->right);
}

Node* create(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode==NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

Node* rightRotate(Node* z) {
    Node* y = z->left;
    Node* T3 = y->right;

    y->right = z;
    z->left = T3;

    z->height = 1 + max(getHeight(z->left), getHeight(z->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

Node* leftRotate(Node* z) {
    Node* y = z->right;
    Node* T2 = y->left;

    y->left = z;
    z->right = T2;

    z->height = 1 + max(getHeight(z->left), getHeight(z->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

Node* insert(Node* curr, int val) {
    if(curr==NULL)  return create(val);

    if(val < curr->val)
        curr->left = insert(curr->left, val);
    else if(val > curr->val)
        curr->right = insert(curr->right, val);
    else
        return curr;

    curr->height = 1 + max(getHeight(curr->left), getHeight(curr->right));

    int bf = getBalance(curr);

    // LL Case
    if(bf > 1 && val < curr->left->val)
        return rightRotate(curr);

    // RR Case
    if(bf < -1 && val > curr->right->val)
        return leftRotate(curr);

    // LR Case
    if(bf > 1 && val > curr->left->val) {
        curr->left = leftRotate(curr->left);
        return rightRotate(curr);
    }

    // RL Case
    if(bf < -1 && val < curr->right->val) {
        curr->right = rightRotate(curr->right);
        return leftRotate(curr);
    }

    return curr;
}

Node* findMin(Node* curr) {
    while(curr && curr->left!=NULL)
        curr = curr->left;
    return curr;
}

Node* delete(Node* curr, int val) {
    if(curr==NULL) {
        printf("Value %d not found in AVL tree.\n", val);
        return NULL;
    }

    if(val < curr->val) {
        curr->left = delete(curr->left, val);
    } else if(val > curr->val) {
        curr->right = delete(curr->right, val);
    } else {
        if(curr->left==NULL || curr->right==NULL) {
            Node* temp = curr->left ? curr->left : curr->right;
            if(temp==NULL) {
                free(curr);
                return NULL;
            } else {
                *curr = *temp;
                free(temp);
            }
        } else {
            Node* temp = findMin(curr->right);
            curr->val = temp->val;
            curr->right = delete(curr->right, temp->val);
        }
    }

    curr->height = 1 + max(getHeight(curr->left), getHeight(curr->right));

    int bf = getBalance(curr);

    // LL Case
    if(bf > 1 && getBalance(curr->left) >= 0)
        return rightRotate(curr);

    // LR Case
    if(bf > 1 && getBalance(curr->left) < 0) {
        curr->left = leftRotate(curr->left);
        return rightRotate(curr);
    }

    // RR Case
    if(bf < -1 && getBalance(curr->right) <= 0)
        return leftRotate(curr);

    // RL Case
    if(bf < -1 && getBalance(curr->right) > 0) {
        curr->right = rightRotate(curr->right);
        return leftRotate(curr);
    }

    return curr;
}

Node* search(Node* curr, int val) {
    if(curr==NULL || curr->val==val)
        return curr;

    if(val < curr->val)
        return search(curr->left, val);
    else
        return search(curr->right, val);
}

void inorder(Node* curr) {
    if(curr==NULL)  return;
    inorder(curr->left);
    printf("%d ", curr->val);
    inorder(curr->right);
}

void preorder(Node* curr) {
    if(curr==NULL)  return;
    printf("%d(BF:%d) ", curr->val, getBalance(curr));
    preorder(curr->left);
    preorder(curr->right);
}

void display() {
    if(tree==NULL) {
        printf("AVL Tree is empty.\n");
        return;
    }
    printf("Inorder (Sorted):    ");
    inorder(tree);
    printf("\nPreorder (Structure): ");
    preorder(tree);
    printf("\nRoot: %d | Tree Height: %d\n", tree->val, getHeight(tree));
}

int main() {
    printf("--- Inserting 1 to 10 into AVL Tree ---\n");
    for(int i=1; i<=10; ++i) {
        tree = insert(tree, i);
    }
    display();

    printf("\n--- Searching Elements ---\n");
    int s1 = 7, s2 = 15;
    printf("Search %d: %s\n", s1, search(tree, s1)!=NULL ? "Found" : "Not Found");
    printf("Search %d: %s\n", s2, search(tree, s2)!=NULL ? "Found" : "Not Found");

    printf("\n--- Deleting 4, 8, and 1 ---\n");
    tree = delete(tree, 4);
    tree = delete(tree, 8);
    tree = delete(tree, 1);
    display();

    return 0;
}