#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;

Node* create(int val) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->val = val;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

void display() {
    if(!head) {
        printf("Empty LL.\n");
        return;
    }
    printf("DLL: ");
    Node* tem = head;
    while(tem) {
        printf("%d<->", tem->val);
        tem = tem->next;
    }
    printf("NULL\n");
}

void insertAtBeginning(int val) {
    Node* nn = create(val);
    nn->prev = NULL;
    nn->next = head;
    if(head)    head->prev = nn;
    head = nn;
}

void insertAtEnd(int val) {
    if(head == NULL) {
        insertAtBeginning(val);
        return;
    }
    Node* nn = create(val);
    Node* tem = head;
    while(tem->next)    tem = tem->next;
    tem->next = nn;
    nn->prev = tem;
    nn->next = NULL;
}

void insertAtPosition(int val, int pos) {
    if(pos<1)   return;
    if(pos == 1 || !head) {
        insertAtBeginning(val);
        return;
    }
    Node* tem = head;
    int cp = 1;
    while(cp<pos-1 && tem) { 
        tem = tem->next;
        cp++;
    }
    if(!tem)   return;
    Node* nn = create(val);
    nn->next = tem->next;
    nn->prev = tem;
    if(nn->next)    nn->next->prev = nn;
    tem->next = nn;
}

void deleteAtBeginning() {
    if(!head)   return;
    Node* tem = head;
    head = tem->next;
    if(head != NULL)   head->prev = NULL;  
    free(tem);
}

void deleteAtEnd() {
    if(!head)   return;
    if(!head->next) {
        free(head);
        head = NULL;
        return;
    }
    Node* tem = head;
    while(tem->next->next != NULL)  tem = tem->next;
    free(tem->next);
    tem->next = NULL;
}

void deleteAtPosition(int pos) {
    if(!head || pos < 1)  return;
    if(pos == 1) {
        deleteAtBeginning();
        return;
    }
    Node *tem = head;
    int cp = 1;
    while(cp < pos - 1 && tem != NULL) {
        tem = tem->next;
        cp++;
    }
    if(!tem || !(tem->next))    return;
    Node* db = tem->next;
    tem->next = db->next;
    if(db->next != NULL)    db->next->prev = tem;
    free(db);
}

int main() {
    int ch, val, pos, chc;
    printf("--- Creation of Doubly Linked List ---\n");
    do {
        printf("Enter val for the new node: ");
        scanf("%d", &val);
        insertAtEnd(val);
        printf("Do you want to create/add another node? (1 for Yes / 0 for No): ");
        scanf("%d", &chc);
    } while(chc == 1);

    while(1) {
        printf("\n--- DLL Operations Menu ---\n");
        printf("1. Display\n2. Insert at Beginning\n3. Insert at End\n4. Insert at Position\n");
        printf("5. Delete from Beginning\n6. Delete from End\n7. Delete from Position\n8. Exit\n");
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
                printf("Enter val and position: ");
                scanf("%d %d", &val, &pos);
                insertAtPosition(val, pos);
                break;
            case 5:
                deleteAtBeginning();
                break;
            case 6:
                deleteAtEnd();
                break;
            case 7:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}