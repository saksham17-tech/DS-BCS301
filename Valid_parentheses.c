#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isValid(char* s) {
    char stack[100];
    int top = -1;
    int i = 0;
    while(s[i]!='\0') {
        char ch = s[i++];
        if(ch=='(' || ch=='{' || ch=='[')    stack[++top] = ch;
        else if(ch==')' || ch=='}' || ch==']') {
            if(top==-1) return 0; // Stack underflow / mismatch
            char popped = stack[top--];
            if ((ch == ')' && popped != '(') ||
                (ch == '}' && popped != '{') ||
                (ch == ']' && popped != '['))       return 0;
        }
    }
    return top == -1;
}

int main() {
    char expr[100];
    printf("Enter bracket sequence: ");
    scanf("%s", expr);

    if (isValid(expr)) {
        printf("Valid Parentheses!\n");
    } else {
        printf("Invalid Parentheses!\n");
    }
    return 0;
}