#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int pow;
    struct Node* next;
} Node;

Node* insert(Node* head, int coeff, int pow) {
    Node* nn = (Node*)malloc(sizeof(Node));
    nn->coeff = coeff;
    nn->pow = pow;
    nn->next = NULL;

    if(!head || head->pow<pow) {                // If list is empty or new term has highest power
        nn->next = head;
        head = nn;
    }
    else {
        Node* tem = head;
        while(tem->next!=NULL && tem->next->pow>=pow) tem = tem->next;  // Traverse to find correct position
        if(tem->pow==pow) {                     // If power already exists, combine coefficients
            tem->coeff += coeff;
            free(nn);
        }
        else {
            nn->next = tem->next;
            tem->next = nn;
        }
    }
    return head;
}

void display(Node* head) {
    if(!head) {
        printf("0\n");
        return;
    }
    Node* temp = head;
    while(temp!=NULL) {
        printf("%dx^%d", temp->coeff, temp->pow);
        temp = temp->next;
        if(temp!=NULL && temp->coeff>=0)    printf(" + ");
    }
    printf("\n");
}

Node* addPolynomials(Node* p1, Node* p2) {
    Node* res = NULL;

    while(p1!=NULL && p2!=NULL) {
        if(p1->pow==p2->pow) {
            res = insert(res, p1->coeff+p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if(p1->pow>p2->pow) {
            res = insert(res, p1->coeff, p1->pow);
            p1 = p1->next;
        }
        else {
            res = insert(res, p2->coeff, p2->pow);
            p2 = p2->next;
        }
    }

    while(p1!=NULL) {
        res = insert(res, p1->coeff, p1->pow);
        p1 = p1->next;
    }
    
    while(p2!=NULL) {
        res = insert(res, p2->coeff, p2->pow);
        p2 = p2->next;
    }

    return res;
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    int coeff, pow, chc;

    printf("--- Input Polynomial 1 ---\n");
    do {
        printf("Enter coefficient and power: ");
        scanf("%d %d", &coeff, &pow);
        poly1 = insert(poly1, coeff, pow);
        printf("Add another term to Poly 1? (1 for Yes / 0 for No): ");
        scanf("%d", &chc);
    } while (chc == 1);

    printf("\n--- Input Polynomial 2 ---\n");
    do {
        printf("Enter coefficient and power: ");
        scanf("%d %d", &coeff, &pow);
        poly2 = insert(poly2, coeff, pow);
        printf("Add another term to Poly 2? (1 for Yes / 0 for No): ");
        scanf("%d", &chc);
    } while (chc == 1);

    printf("\nPolynomial 1: ");
    display(poly1);
    
    printf("Polynomial 2: ");
    display(poly2);

    Node* sum = addPolynomials(poly1, poly2);
    printf("Resultant Polynomial (Sum): ");
    display(sum);

    return 0;
}