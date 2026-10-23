#include <stdio.h>
#define MAX 100

int arr[MAX];
int n;

void insert(int arr[]) {
    int pos, val;
    printf("Enter pos and val respv: ");
    scanf("%d %d", &pos, &val);
    int j=n-1;
    while(j>=(pos-1)) {
        arr[j+1] = arr[j];
        j--;
    }
    arr[pos-1] = val;
    n++;
}

void delete(int arr[]) {
    int pos;
    printf("Enter pos: ");
    scanf("%d", &pos);
    int j=pos-1;
    while(j<n) {
        arr[j] = arr[j+1];
        j++;
    }
    n--;
}

void display(int arr[]) {
    printf("\n");
    for(int i=0; i<n; ++i)  printf("%d  ", arr[i]);
}

int main() {
    printf("Enter size: ");
    scanf("%d", &n);
    printf("Enter %d elements in array: ",n);
    for(int i=0; i<n; ++i)  scanf("%d", &arr[i]);
    display(arr);
    insert(arr);
    display(arr);
    delete(arr);
    display(arr);
}