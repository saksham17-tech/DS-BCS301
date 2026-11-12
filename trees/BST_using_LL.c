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
    if(!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* curr, int val) {
    if(curr==NULL)  return create(val);

    if(val<curr->val)
        curr->left = insert(curr->left, val);
    else if(val>curr->val)
        curr->right = insert(curr->right, val);
    else
        printf("Duplicate value %d ignored.\n", val);

    return curr;
}

Node* search(Node* curr, int val) {
    if(!curr || curr->val==val) return curr;
    return (val<curr->val)?search(curr->left,val):search(curr->right,val);
}

Node* findMin(Node* curr) {
    while(curr && curr->left!=NULL)
        curr = curr->left;
    return curr;
}

Node* delete(Node* curr, int val) {
    if(curr==NULL) {
        printf("Value %d not found in BST.\n", val);
        return NULL;
    }

    if(val<curr->val)       curr->left = delete(curr->left, val);
    else if(val>curr->val)  curr->right = delete(curr->right, val);
    else {
        if(!curr->left && !curr->right) {
            free(curr);
            return NULL;
        }
        else if(curr->left==NULL) {
            Node* temp = curr->right;
            free(curr);
            return temp;
        } else if(curr->right==NULL) {
            Node* temp = curr->left;
            free(curr);
            return temp;
        }
        else {
            Node* temp = findMin(curr->right);
            curr->val = temp->val;
            curr->right = delete(curr->right, temp->val);
        }
    }
    return curr;
}

void inorder(Node* curr) {
    if(curr==NULL)  return;
    inorder(curr->left);
    printf("%d ", curr->val);
    inorder(curr->right);
}

void display() {
    if(tree==NULL) {
        printf("BST is empty.\n");
        return;
    }
    printf("BST (Inorder / Sorted): ");
    inorder(tree);
    printf("\n");
}

int main() {
    int choice, val, n;

    while(1) {
        printf("\n--- BST Operations ---\n");
        printf("1. Insert multiple values\n");
        printf("2. Insert single value\n");
        printf("3. Search value\n");
        printf("4. Delete value\n");
        printf("5. Display BST\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        if(scanf("%d", &choice)!=1)  break;

        switch(choice) {
            case 1:
                printf("How many values do you want to insert? ");
                scanf("%d", &n);
                printf("Enter %d values: ", n);
                for(int i=0; i<n; ++i) {
                    scanf("%d", &val);
                    tree = insert(tree, val);
                }
                break;

            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                tree = insert(tree, val);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &val);
                if(search(tree, val)!=NULL)
                    printf("Found %d in BST!\n", val);
                else
                    printf("%d not found in BST.\n", val);
                break;

            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                tree = delete(tree, val);
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}