#include <stdio.h>
#include <string.h>
#define MAX 100

int top=-1;
char stack[MAX];

void push(char ch) {
    if(top==MAX-1)  return;
    stack[++top] = ch;
}

char pop() {
    if(top==-1) return '\0';
    return stack[top--];
}

void reverseString(char *str) {
    int n = strlen(str);
    for(int i=0; i<n; ++i)  push(str[i]);
    for(int i=0; i<n; ++i)  str[i] = pop();
}

int main() {
    char str[50];
    printf("Enter a string: ");
    scanf("%s", str);
    printf("\nOriginal String: %s\n", str);
    reverseString(str);
    printf("Reversed String: %s\n", str);
    return 0;
}