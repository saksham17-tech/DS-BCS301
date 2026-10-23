#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int exp;
    struct Node* next;
} Node;

// Create a new polynomial term node
Node* createNode(int coeff, int exp) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->coeff = coeff;
    new->exp = exp;
    new->next = NULL;
    return new;
}

// Insert node at the end of the polynomial list
Node* insertEnd(Node* head, int coeff, int exp) {
    Node* new = createNode(coeff, exp);
    if (!head) return new;
    Node* tem = head;
    while (tem->next) tem = tem->next;
    tem->next = new;
    return head;
}

// Display the polynomial
void display(Node* head) {
    if (!head) {
        printf("0\n");
        return;
    }
    Node* tem = head;
    while (tem) {
        printf("%dx^%d", tem->coeff, tem->exp);
        if (tem->next) printf(" + ");
        tem = tem->next;
    }
    printf("\n");
}

// Function to add two polynomials
Node* addPolynomials(Node* p1, Node* p2) {
    Node* result = NULL;

    while (p1 && p2) {
        if (p1->exp == p2->exp) {
            int sum = p1->coeff + p2->coeff;
            if(sum!=0) // If coefficients don't cancel out
                result = insertEnd(result, sum, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        } 
        else if (p1->exp > p2->exp) {
            result = insertEnd(result, p1->coeff, p1->exp);
            p1 = p1->next;
        } 
        else {
            result = insertEnd(result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }

    // Append remaining terms of p1, if any
    while (p1) {
        result = insertEnd(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    // Append remaining terms of p2, if any
    while (p2) {
        result = insertEnd(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

int main() {
    Node* p1 = NULL;
    Node* p2 = NULL;

    // Polynomial 1: 3x^2 + 5x^1 + 6x^0
    p1 = insertEnd(p1, 3, 2);
    p1 = insertEnd(p1, 5, 1);
    p1 = insertEnd(p1, 6, 0);

    // Polynomial 2: 4x^1 + 2x^0
    p2 = insertEnd(p2, 4, 1);
    p2 = insertEnd(p2, 2, 0);

    printf("Polynomial 1: ");
    display(p1);

    printf("Polynomial 2: ");
    display(p2);

    Node* sum = addPolynomials(p1, p2);
    printf("Resultant Polynomial: ");
    display(sum);

    return 0;
}