#include <stdio.h>
#include <stdlib.h>
//MERGE SORT

void conquer(int *arr, int si, int mid, int ei) {
    int sz = ei-si+1;
    int merged[sz];
    int x1=si;
    int x2=mid+1;
    int x=0;
    while(x1<=mid && x2<=ei) {
        if(arr[x1]<arr[x2]) merged[x++]=arr[x1++];          //arr[x1]>arr[x2] for descending
        else                merged[x++]=arr[x2++];
    }
    while(x1<=mid)  merged[x++]=arr[x1++];
    while(x2<=ei)   merged[x++]=arr[x2++];
    for(int i=0,j=si;i<sz;i++,j++)   arr[j]=merged[i];
}

void divide(int *arr, int si, int ei) {
    if(si>=ei)  return;
    int mid  = si+(ei-si)/2;
    divide(arr,si,mid);
    divide(arr,mid+1,ei);
    conquer(arr,si,mid,ei);
}

void display(int *arr, int n) {
    for(int i=0; i<n; ++i)  printf("%d  ",arr[i]);
}

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d integers in the array:\n",n);
    for(int i=0; i<n; ++i)  scanf("%d",&arr[i]);
    printf("\n");
    display(arr,n);
    divide(arr,0,n-1);
    printf("\n");
    display(arr,n);
}
//Time Complexity = O(n logn)