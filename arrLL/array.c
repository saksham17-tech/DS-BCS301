#include <stdio.h>
#define MAX 100

int arr[MAX];
int n;

void display() {
    printf("\n");
    for(int i=0; i<n; ++i)  printf("%d  ", arr[i]);
}

void insert() {
    int pos, val;
    printf("\nEnter pos and val respv: ");
    scanf("%d %d", &pos, &val);
    int j=n-1;
    while(j>=(pos-1)) {
        arr[j+1] = arr[j];
        j--;
    }
    arr[pos-1] = val;
    n++;
}

void delete() {
    int pos;
    printf("\nEnter pos: ");
    scanf("%d", &pos);
    int j=pos-1;
    while(j<n) {
        arr[j] = arr[j+1];
        j++;
    }
    n--;
}

void merge() {
    int n2;
    printf("\nEnter size of second array:\n");
    scanf("%d", &n2);
    int arr2[n2];
    printf("Enter %d elements in the array: ",n2);
    for(int i=0; i<n2; ++i) scanf("%d",&arr2[i]);
    int res[n+n2];
    int i=0, j=0, x=0;
    while(i<n && j<n2)  res[x++] = (arr[i]>arr2[j])?arr2[j++]:arr[i++];
    while(i<n)  res[x++] = arr[i++];
    while(j<n2) res[x++] = arr2[j++];
    printf("\nMerged: ");
    for(int k=0; k<n+n2; ++k) printf("%d ", res[k]);
}

int main() {
    printf("Enter size: ");
    scanf("%d", &n);
    printf("Enter %d elements in array:\n",n);
    for(int i=0; i<n; ++i)  scanf("%d", &arr[i]);
    display();
    insert();
    display();
    delete();
    display();
    merge();
}