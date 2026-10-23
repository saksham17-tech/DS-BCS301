#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* prev;
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

int isEmpty() {
    return front == NULL;
}

int isFull() {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) return 1; // Out of heap memory
    free(temp);
    return 0;
}

void insertFront(int val) {
    if(isFull()) {
        printf("Deque Overflow!\n");
        return;
    }
    Node* new = (Node*)malloc(sizeof(Node));
    new->val = val;
    new->prev = NULL;
    new->next = front;

    if (isEmpty()) {
        front = rear = new;
    } else {
        front->prev = new;
        front = new;
    }
    printf("Inserted %d at front.\n", val);
}

void insertRear(int val) {
    if(isFull()) {
        printf("Deque Overflow!\n");
        return;
    }
    Node* new = (Node*)malloc(sizeof(Node));
    new->val = val;
    new->next = NULL;
    new->prev = rear;

    if (isEmpty()) {
        front = rear = new;
    } else {
        rear->next = new;
        rear = new;
    }
    printf("Inserted %d at rear.\n", val);
}

void deleteFront() {
    if (isEmpty()) {
        printf("Deque Underflow! Deque is empty.\n");
        return;
    }
    Node* temp = front;
    printf("Deleted %d from front.\n", temp->val);
    
    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        front->prev = NULL;
    }
    free(temp);
}

void deleteRear() {
    if (isEmpty()) {
        printf("Deque Underflow! Deque is empty.\n");
        return;
    }
    Node* temp = rear;
    printf("Deleted %d from rear.\n", temp->val);

    if (front == rear) {
        front = rear = NULL;
    } else {
        rear = rear->prev;
        rear->next = NULL;
    }
    free(temp);
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty!\n");
        return;
    }
    Node* temp = front;
    printf("Deque (Front to Rear): ");
    while (temp != NULL) {
        printf("%d <-> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, val, chc;

    printf("--- DLL Deque Initial Population ---\n");
    do {
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
            case 6: printf(isFull() ? "Full (No memory)\n" : "Not full\n"); break;
            case 7: display(); break;
            case 8: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}