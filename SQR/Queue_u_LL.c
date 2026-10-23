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

int isFull() {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) return 1;
    free(temp);
    return 0;
}

void enqueue(int val) {
    if(isFull()) return;
    Node* new = (Node*)malloc(sizeof(Node));
    new->val = val;
    new->next = NULL;

    if (rear == NULL) {
        front = rear = new;
    } else {
        rear->next = new;
        rear = new;
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
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
}

void peek() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Front element: %d\n", front->val);
}

int size() {
    int count = 0;
    Node* temp = front;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    Node* temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, val, chc;

    printf("--- LL Queue Creation ---\n");
    do {
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
                enqueue(val);
                break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: printf(isEmpty() ? "Empty\n" : "Not empty\n"); break;
            case 5: printf(isFull() ? "Full\n" : "Not full\n"); break;
            case 6: printf("Size: %d\n", size()); break;
            case 7: display(); break;
            case 8: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}