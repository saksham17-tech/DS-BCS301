#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* head = NULL;

Node* create(int val) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->val = val;
    new->next = new;
    return new;
}

void display() {
    if(head == NULL) {
        printf("Empty Circular LL\n");
        return;
    }
    Node* tem = head;
    printf("Circular LL: ");
    do {
        printf("%d -> ", tem->val);
        tem = tem->next;
    } while(tem != head); // Stops when we loop back to the head
    printf("(head)\n");
}

void insertAtBeginning(int val) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->val = val;

    if(head == NULL) {
        head = new;
        new->next = head;
        return;
    }

    // Find the last node so we can update its next pointer to the new head
    Node* tem = head;
    while(tem->next != head) {
        tem = tem->next;
    }

    new->next = head;
    head = new;
    tem->next = head; // Last node now points to the new head
}

void insertAtEnd(int val) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->val = val;

    if(head == NULL) {
        head = new;
        new->next = head;
        return;
    }

    Node* tem = head;
    while(tem->next != head) {
        tem = tem->next;
    }

    tem->next = new;
    new->next = head; // New node points back to head
}

void deleteAtBeginning() {
    if(head == NULL) return;

    // If there is only one node
    if(head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    // Find the last node to update its pointer after head changes
    Node* tem = head;
    while(tem->next != head) {
        tem = tem->next;
    }

    Node* toDelete = head;
    head = head->next;
    tem->next = head; // Last node points to the new head
    free(toDelete);
}

void deleteAtEnd() {
    if(head == NULL) return;

    // If there is only one node
    if(head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    Node* tem = head;
    // Traverse until the second to last node
    while(tem->next->next != head) {
        tem = tem->next;
    }

    Node* toDelete = tem->next;
    tem->next = head; // Second to last node now points to head
    free(toDelete);
}

int main() {
    int ch, val, chc;
    
    printf("--- Creation of Circular Linked List ---\n");
    do {
        printf("Enter val for the new node: ");
        scanf("%d", &val);
        insertAtEnd(val);
        printf("Do you want to create/add another node? (1 for Yes / 0 for No): ");
        scanf("%d", &chc);
    } while(chc == 1);

    while(1) {
        printf("\n--- Circular LL Operations Menu ---\n");
        printf("1. Display\n2. Insert at Beginning\n3. Insert at End\n");
        printf("4. Delete from Beginning\n5. Delete from End\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1:
                display();
                break;
            case 2:
                printf("Enter val: ");
                scanf("%d", &val);
                insertAtBeginning(val);
                break;
            case 3:
                printf("Enter val: ");
                scanf("%d", &val);
                insertAtEnd(val);
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}