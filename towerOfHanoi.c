#include <stdio.h>
#include <string.h>

void toh(int n, char src, char dest, char aux) {
    if(n==1) {
        printf("Moved disc from %c rod to %c rod.\n",src,dest);
        return;
    }

    toh(n-1,src,aux,dest);
    printf("Moved disc from %c rod to %c rod.\n",src,dest);
    toh(n-1,aux,dest,src);
}

int main() {
    int n;
    printf("Enter num of discs: ");
    scanf("%d", &n);
    toh(n,'A','C','B');
    return 0;
}