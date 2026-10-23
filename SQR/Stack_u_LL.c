#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* top = NULL;

int isEmpty() {
    return top == NULL;
}

int isFull() {
    Node* temp = (Node*)malloc(sizeof(Node));
    if(!temp)   return 1;
    free(temp);
    return 0; 
}

void push(int val) {
    Node* new = (Node*)malloc(sizeof(Node));
    if (new == NULL) {
        printf("Stack Overflow! Heap memory is full.\n");
        return;
    }
    new->val = val;
    new->next = top;
    top = new;
    printf("Pushed %d onto the stack.\n", val);
}

void pop() {
    if(isEmpty()) {
        printf("Stack Underflow!");
        return;
    }
    Node* tem = top;
    printf("%d popped from stack." , tem->val);
    top = tem->next;
    free(tem);
}

void peek() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Top element: %d\n", top->val);
}

int size() {
    int count = 0;
    Node* temp = top;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
        return;
    }
    Node* temp = top;
    printf("Stack (Top to Bottom): ");
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, val, chc;

    printf("--- Linked List Stack ---\n");
    do {
        printf("Enter value to push: ");
        scanf("%d", &val);
        push(val);

        printf("Do you want to push another element? (1 for Yes / 0 for No): ");
        scanf("%d", &chc);
    } while (chc == 1);

    while (1) {
        printf("\n--- LL Stack Operations Menu ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Check isEmpty\n5. Check isFull\n6. Get Size\n7. Display\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                (isEmpty())?printf("Stack is EMPTY.\n"):printf("Stack is NOT empty.\n");
                break;
            case 5:
                (isFull())?printf("Stack is FULL (Out of memory).\n"):printf("Stack is NOT full (Memory available).\n");
                break;
            case 6:
                printf("Current Stack Size: %d\n", size());
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}