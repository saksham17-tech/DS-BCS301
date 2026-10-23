#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int CQ[MAX];
int front = -1;
int rear = -1;

int isEmpty() {
    return (front == -1);
}

int isFull() {
    return ((rear + 1) % MAX == front);
}

void enqueue(int val) {
    if (isFull()) {
        printf("Queue Overflow! Circular Queue is full.\n");
        return;
    }
    if(isEmpty())   front = rear = 0;       // First element
    else            rear = (rear+1)%MAX;    // Wrap around
    CQ[rear] = val;
    printf("Enqueued %d\n", val);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Circular Queue is empty.\n");
        return;
    }
    printf("Dequeued %d\n", CQ[front]);    
    if(front==rear)     front = rear = -1;
    else                front = (front+1)%MAX; // Wrap around
}

void peek() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Front element: %d\n", CQ[front]);
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Circular Queue: ");
    int i = front;
    while (1) {                                             //IMPP
        printf("%d ", CQ[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, val, chc;

    printf("--- Array Circular Queue Creation ---\n");
    do {
        if (isFull()) {
            printf("Queue is full! Cannot add more.\n");
            break;
        }
        printf("Enter value to enqueue: ");
        scanf("%d", &val);
        enqueue(val);
        printf("Add another? (1 for Yes / 0 for No): ");
        scanf("%d", &chc);
    } while (chc == 1);

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. isEmpty\n5. isFull\n6. Display\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: printf(isEmpty() ? "Empty\n" : "Not empty\n"); break;
            case 5: printf(isFull() ? "Full\n" : "Not full\n"); break;
            case 6: display(); break;
            case 7: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}