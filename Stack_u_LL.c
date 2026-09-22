#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

int isEmpty(Node* top) {
    return top == NULL;
}

int isFull() {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL)   return 1;
    free(temp);
    return 0; 
}

void push(Node** top, int val) {
    Node* new = (Node*)malloc(sizeof(Node));
    if (new == NULL) {
        printf("Stack Overflow! Heap memory is full.\n");
        return;
    }
    new->val = val;
    new->next = *top;
    *top = new;
    printf("Pushed %d onto the stack.\n", val);
}

void pop(Node** top) {
    if(isEmpty(*top)) {
        printf("Stack Underflow!");
        return;
    }
    Node* tem = *top;
    printf("%d popped from stack." , tem->val);
    (*top) = tem->next;
    free(tem);
}

void peek(Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Top element: %d\n", top->val);
}

int size(Node* top) {
    int count = 0;
    Node* temp = top;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void display(Node* top) {
    if (isEmpty(top)) {
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
    Node* top = NULL;
    int choice, val, chc;

    printf("--- Linked List Stack ---\n");
    do {
        printf("Enter value to push: ");
        scanf("%d", &val);
        push(&top, val);

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
                push(&top, val);
                break;
            case 2:
                pop(&top);
                break;
            case 3:
                peek(top);
                break;
            case 4:
                if (isEmpty(top)) printf("Stack is EMPTY.\n");
                else printf("Stack is NOT empty.\n");
                break;
            case 5:
                if (isFull()) printf("Stack is FULL (Out of memory).\n");
                else printf("Stack is NOT full (Memory available).\n");
                break;
            case 6:
                printf("Current Stack Size: %d\n", size(top));
                break;
            case 7:
                display(top);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}