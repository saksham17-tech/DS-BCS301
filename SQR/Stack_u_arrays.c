#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stack[MAX];
int top = -1;

int isFull() {
    return top == MAX - 1;
}

int isEmpty() {
    return top == -1;
}

int size() {
    return top + 1;
}

void push(int val) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d\n", val);
        return;
    }
    stack[++top] = val;
    printf("Pushed %d onto the stack.\n", val);
}

void pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }
    printf("Popped element: %d\n", stack[top--]);
}

void peek() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Top element: %d\n", stack[top]);
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack (Top to Bottom): ");
    for(int i=top; i>=0; --i)  printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    int choice, val, chc;
    printf("--- Stack using Arrays ---\n");

    do {
        if (isFull()) {
            printf("Stack is full! Cannot add more elements initially.\n");
            break;
        }
        printf("Enter value to push: ");
        scanf("%d", &val);
        push(val);

        if (!isFull()) {
            printf("Do you want to push another element? (1 for Yes / 0 for No): ");
            scanf("%d", &chc);
        }
        else        chc = 0;
    } while (chc == 1);

    while (1) {
        printf("\n--- Array Stack Operations Menu ---\n");
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
                if (isEmpty()) printf("Stack is EMPTY.\n");
                else printf("Stack is NOT empty.\n");
                break;
            case 5:
                if (isFull()) printf("Stack is FULL.\n");
                else printf("Stack is NOT full.\n");
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
                printf("Invalid choice!\n");
        }
    }
    return 0;
}