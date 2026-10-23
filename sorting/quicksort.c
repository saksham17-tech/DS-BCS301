#include <stdio.h>
#include <stdlib.h>
//QUICK SORT
int partition(int* arr, int low, int high) {
    int p = arr[high];
    int i=low-1;
    for(int j=low;j<high;j++) {
        if(arr[j]<p) {
            int temp=arr[++i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[++i];
    arr[i]=p; 
    arr[high]=temp;
    return i;
}

void qs(int *arr, int low, int high) {
    if(low<high) {
        int pi=partition(arr,low,high);
        qs(arr,low,pi-1);
        qs(arr,pi+1,high);
    }
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
    qs(arr,0,n-1);
    printf("\n");
    display(arr,n);
}
//Time Complexity = O(n logn)