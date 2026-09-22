#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

int isEmpty() {
    return front == NULL;
}

void enqueue(int val) {
    Node* new = (Node*)malloc(sizeof(Node));
    if (new == NULL) {
        printf("Queue Overflow!\n");
        return;
    }
    new->val = val;

    if (isEmpty()) {
        front = rear = new;
        rear->next = front; // Point to itself to form a circle
    } else {
        rear->next = new;
        rear = new;
        rear->next = front; // Maintain circular link back to front
    }
    printf("Enqueued %d\n", val);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow!\n");
        return;
    }
    Node* temp = front;
    printf("Dequeued %d\n", temp->val);

    if (front == rear) {
        // Only one node in queue
        front = rear = NULL;
        free(temp);
    } else {
        front = front->next;
        rear->next = front; // Maintain circular link
        free(temp);
    }
}

void peek() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Front element: %d\n", front->val);
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    Node* temp = front;
    printf("Circular LL Queue: ");
    do {
        printf("%d -> ", temp->val);
        temp = temp->next;
    } while (temp != front);
    printf("(back to front)\n");
}

int main() {
    int choice, val, chc;

    printf("--- LL Circular Queue Creation ---\n");
    do {
        printf("Enter value to enqueue: ");
        scanf("%d", &val);
        enqueue(val);
        printf("Add another? (1 for Yes / 0 for No): ");
        scanf("%d", &chc);
    } while (chc == 1);

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. isEmpty\n5. Display\n6. Exit\n");
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
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}