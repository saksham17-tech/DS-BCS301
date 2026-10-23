#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top=-1;
char stack[100];

int isEmpty() {
    return top==-1;
}

int isValid(char* s) {
    for(int i=0; i<strlen(s); ++i) {
        if(s[i]=='(')       stack[++top]=')';
        else if(s[i]=='{')  stack[++top]='}';
        else if(s[i]=='[')  stack[++top]=']';
        else if(isEmpty() || stack[top]!=s[i])     return 0;
        else top--;
    }
    return isEmpty();    
}

int main() {
    char expr[100];
    printf("Enter bracket sequence: ");
    scanf("%s", expr);
    if(isValid(expr))   printf("Valid Parentheses!\n");
    else                printf("Invalid Parentheses!\n");
    return 0;
}