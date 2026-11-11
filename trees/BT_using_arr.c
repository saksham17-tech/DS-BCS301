#include <stdio.h>
#include <stdlib.h>

int tree[100];
int sz = 0;

int isEmpty() {
    return sz==0;
}

int isFull() {
    return sz==100;
}

void create(int idx, int val) {
    if(idx<0 || idx>=100) {
        printf("Index %d is out of bounds!\n",idx);
        return;
    }
    if(tree[idx]==-1)    sz++;
    tree[idx] = val;
}

void insert(int idx, int val) {
    if(isFull()) {
        printf("Tree is Full!\n");
        return;
    }
    if(idx<0 || idx>100) {
        printf("Index %d is out of bounds!\n",idx);
        return;
    }
    if(idx>0) {
        int parent = (idx-1)/2;
        if(tree[parent]==-1) {
            printf("Parent does not exist for %d!\n",val);
            return;
        }
    }
    create(idx,val);
}

void delete(int idx) {
    if(isEmpty()) {
        printf("Tree is Empty!\n");
        return;
    }
    if(idx<0 || idx>=100 || tree[idx]==-1) {
        printf("Error: No node exists at index %d.\n", idx);
        return;
    }
    int left = 2*idx+1, right = 2*idx+2;
    if(left<100 && tree[left]!=-1)   delete(left);
    if(right<100 && tree[right]!=-1) delete(right);
    
    tree[idx] = -1;
    sz--;
    printf("Deleted node at index %d\n", idx);
}

void display() {
    if(isEmpty()) {
        printf("Tree is empty.\n");
        return;
    }
    int hidx = -1;
    for(int i=0; i<100; ++i)
        if(tree[i]!=-1)  hidx = i;

    printf("\n--- Binary Tree Array Representation ---\n");
    printf("Index:\t");
    for(int i=0; i<=hidx; ++i)  printf("%d\t", i);
    printf("\nValue:\t");
    for(int i=0; i<=hidx; ++i) {
        if(tree[i]==-1)  printf("-\t");
        else                printf("%d\t", tree[i]);
    }
    printf("\n-----------------------------------------\n");
}

int main() {
    int tn=0;
    for(int i=0; i<100; ++i)    tree[i] = -1;
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