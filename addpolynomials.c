#include <stdio.h>
#include <stdlib.h>

// Node structure using typedef for polynomial term
typedef struct Node {
    int coeff;
    int pow;
    struct Node* next;
} Node;

// Function to insert a term while keeping powers in descending order
void insertTerm(Node** head, int coeff, int pow) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->coeff = coeff;
    new->pow = pow;
    new->next = NULL;

    // If list is empty or new term has highest power
    if (*head == NULL || (*head)->pow < pow) {
        new->next = *head;
        *head = new;
    } else {
        Node* temp = *head;
        // Traverse to find correct position
        while (temp->next != NULL && temp->next->pow >= pow) {
            temp = temp->next;
        }
        // If power already exists, combine coefficients
        if (temp->pow == pow) {
            temp->coeff += coeff;
            free(new);
        } else {
            new->next = temp->next;
            temp->next = new;
        }
    }
}

// Function to display polynomial
void display(Node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->pow);
        temp = temp->next;
        if (temp != NULL && temp->coeff >= 0) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to add two polynomials
Node* addPolynomials(Node* p1, Node* p2) {
    Node* result = NULL;
    while (p1 != NULL && p2 != NULL) {
        if (p1->pow == p2->pow) {
            insertTerm(&result, p1->coeff + p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->pow > p2->pow) {
            insertTerm(&result, p1->coeff, p1->pow);
            p1 = p1->next;
        } else {
            insertTerm(&result, p2->coeff, p2->pow);
            p2 = p2->next;
        }
    }
    // Append remaining terms of p1
    while (p1 != NULL) {
        insertTerm(&result, p1->coeff, p1->pow);
        p1 = p1->next;
    }
    // Append remaining terms of p2
    while (p2 != NULL) {
        insertTerm(&result, p2->coeff, p2->pow);
        p2 = p2->next;
    }
    return result;
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    int coeff, pow, chc;

    printf("--- Input Polynomial 1 ---\n");
    do {
        printf("Enter coefficient and power: ");
        scanf("%d %d", &coeff, &pow);
        insertTerm(&poly1, coeff, pow);
        printf("Add another term to Poly 1? (1 for Yes / 0 for No): ");
        scanf("%d", &chc);
    } while (chc == 1);

    printf("\n--- Input Polynomial 2 ---\n");
    do {
        printf("Enter coefficient and power: ");
        scanf("%d %d", &coeff, &pow);
        insertTerm(&poly2, coeff, pow);
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