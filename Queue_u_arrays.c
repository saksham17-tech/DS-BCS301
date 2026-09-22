#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int queue[MAX];
int front  = -1, rear = -1;

int isEmpty() {
    return (front == -1 || front > rear);
}

int isFull() {
    return (rear == MAX-1);
}

void enqueue(int val) {
    if(isFull()) {
        printf("Queue Overflow!\n");
        return;
    }
    if(front==-1)   front = 0;
    rear++;
    queue[rear] = val;
    printf("Enqueued %d\n", val);
}

void dequeue() {
    if(isEmpty()) {
        printf("Queue Underflow!\n");
        return;
    }
    printf("Dequeued %d\n", queue[front++]);
    if(front>rear) {
        front = -1;
        rear = -1;
    }
}

void peek() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Front element: %d\n", queue[front]);
}

int size() {
    if(isEmpty())   return 0;
    return (rear-front+1);
}

void display() {
    if(isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for(int i=front; i<=rear; ++i)  printf("%d<-", queue[i]);
    printf("END\n");
}

int main() {
    int choice, val, chc;

    printf("--- Array Queue Creation ---\n");
    do {
        if (isFull()) break;
        printf("Enter value to enqueue: ");
        scanf("%d", &val);
        enqueue(val);
        printf("Add another? (1 for Yes / 0 for No): ");
        scanf("%d", &chc);
    } while (chc == 1);

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. isEmpty\n5. isFull\n6. Size\n7. Display\n8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);   break;
            case 2: dequeue();  break;
            case 3: peek();     break;
            case 4: printf(isEmpty() ? "Empty\n" : "Not empty\n");  break;
            case 5: printf(isFull() ? "Full\n" : "Not full\n");     break;
            case 6: printf("Size: %d\n", size());   break;
            case 7: display();  break;
            case 8: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}