#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int DQ[MAX];
int front = -1;
int rear = -1;

int isEmpty() {
    return (front == -1);
}

int isFull() {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));   //(rear+1)%MAX==front
}

void insertFront(int val) {
    if (isFull()) {
        printf("DQ Overflow!\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1; // Wrap around backwards
    } else {
        front--;
    }
    DQ[front] = val;
    printf("Inserted %d at front.\n", val);
}

void insertRear(int val) {
    if (isFull()) {
        printf("DQ Overflow!\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0; // Wrap around forwards
    } else {
        rear++;
    }
    DQ[rear] = val;
    printf("Inserted %d at rear.\n", val);
}

void deleteFront() {
    if (isEmpty()) {
        printf("DQ Underflow!\n");
        return;
    }
    printf("Deleted %d from front.\n", DQ[front]);

    if (front == rear) {
        front = rear = -1; // Queue becomes empty
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

void deleteRear() {
    if (isEmpty()) {
        printf("DQ Underflow!\n");
        return;
    }
    printf("Deleted %d from rear.\n", DQ[rear]);

    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

void display() {
    if (isEmpty()) {
        printf("DQ is empty!\n");
        return;
    }
    printf("Circular Array DQ: ");
    int i = front;
    while (1) {
        printf("%d ", DQ[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, val, chc;

    printf("--- Circular Array DQ Creation ---\n");
    do {
        if (isFull()) break;
        printf("Enter value to insert at rear: ");
        scanf("%d", &val);
        insertRear(val);
        printf("Add another? (1 for Yes / 0 for No): ");
        scanf("%d", &chc);
    } while (chc == 1);

    while (1) {
        printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. isEmpty\n6. isFull\n7. Display\n8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertFront(val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertRear(val);
                break;
            case 3: deleteFront(); break;
            case 4: deleteRear(); break;
            case 5: printf(isEmpty() ? "Empty\n" : "Not empty\n"); break;
            case 6: printf(isFull() ? "Full\n" : "Not full\n"); break;
            case 7: display(); break;
            case 8: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}