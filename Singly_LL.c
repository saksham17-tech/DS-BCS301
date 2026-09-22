#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* create(int val) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->val = val;
    new->next = NULL;
    return new;
}

void display(Node* head) {
    if(!head) { 
        printf("Empty LL");
        return;
    }
    printf("LL: ");
    Node* tem = head;
    while(tem) {
        printf("%d->", tem->val);
        tem = tem->next;
    }
    printf("NULL\n");
}

Node* insertAtBeginning(Node* head, int val) {
    Node* new = create(val);
    new->next = head;
    head = new;
    return head;
}

Node* insertAtEnd(Node* head, int val) {
    if(!head)   return create(val);
    Node* new = create(val);
    new->next = NULL;
    Node* tem = head;
    while(tem->next)    tem = tem->next;
    tem->next = new;
    return head;
}

Node* insertAtPosition(Node* head, int val, int pos) {
    if(pos < 1)  return head;
    if(pos == 1) {
        return insertAtBeginning(head, val);
    }
    Node* tem = head;
    int cp = 1;
    while(cp<pos-1 && tem) { 
        tem = tem->next;
        cp++;
    }
    if(!tem)   return head;
    Node* new = create(val);
    new->next = tem->next;
    tem->next = new;
    return head;
}

Node* deleteAtBeginning(Node* head) {
    if(!head)   return head;
    Node* tem = head;
    head = tem->next;
    free(tem);
    return head;
}

Node* deleteAtEnd(Node* head) {
    if(!head)  return head;
    if(head->next == NULL) {
        free(head);
        head = NULL;
        return head;
    }
    Node* tem = head;
    while(tem->next->next)  tem = tem->next;
    free(tem->next);
    tem->next = NULL;
    return head;
}

Node* deleteAtPosition(Node* head, int pos) {
    if(!head || pos<1)  return head;
    if(pos==1)    return deleteAtBeginning(head);
    Node* tem = head;
    int cp = 1;
    while(cp<pos-1 && tem) {
        tem = tem->next;
        cp++;
    }
    if(!tem || !(tem->next))   return head;
    Node* db = tem->next;
    tem->next = db->next;
    free(db);
    return head;
}

Node* reverse(Node* head) {
    if(!head || !(head->next))    return head;
    Node* curr = head;
    Node* pre = NULL; Node* pos = NULL;
    while(curr) {
        pos = curr->next;
        curr->next = pre;
        pre = curr;
        curr = pos;
    }
    head = pre;
    return head;
}

int main() {
    Node* head = NULL;
    int ch, val, pos, chc;
    printf("--- Creation of Singly Linked List ---\n");
    do {
        printf("Enter val for the new node: ");
        scanf("%d", &val);
        head = insertAtEnd(head, val);
        printf("Do you want to create/add another node? (1 for Yes / 0 for No): ");
        scanf("%d", &chc);
    } while(chc == 1);

    while(1) {
        printf("\n--- SLL Operations Menu ---\n");
        printf("1. Display\n2. Insert at Beginning\n3. Insert at End\n4. Insert at Position\n");
        printf("5. Delete from Beginning\n6. Delete from End\n7. Delete from Position\n8. Reverse\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                display(head);
                break;
            case 2:
                printf("Enter val: ");
                scanf("%d", &val);
                head = insertAtBeginning(head, val);
                break;
            case 3:
                printf("Enter val: ");
                scanf("%d", &val);
                head = insertAtEnd(head, val);
                break;
            case 4:
                printf("Enter val and position: ");
                scanf("%d %d", &val, &pos);
                head = insertAtPosition(head, val, pos);
                break;
            case 5:
                head = deleteAtBeginning(head);
                break;
            case 6:
                head = deleteAtEnd(head);
                break;
            case 7:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                head = deleteAtPosition(head, pos);
                break;
            case 8: 
                head = reverse(head);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}