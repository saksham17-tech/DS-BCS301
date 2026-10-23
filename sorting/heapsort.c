#include <stdio.h>
#include <stdlib.h>

void swap(int *arr, int a, int b) {
    int t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}

void heapify(int *arr, int i, int n) {
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n && arr[largest]<arr[left])    largest = left;         //smallest>left
    if(right<n && arr[largest]<arr[right])  largest = right;        //smallest>right for descending
    if(largest!=i) {
        swap(arr, i, largest);
        heapify(arr,largest,n);
    }
}

void buildMaxHeap(int *arr, int n) {
    for(int i=(n/2)-1; i>=0; --i)   heapify(arr,i,n);
}

int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d elements in the array:\n",n);
    for(int i=0; i<n; ++i)  scanf("%d",&arr[i]);
    printf("\nOriginal array: ");
    for(int i=0; i<n; ++i)  printf("%d  ",arr[i]);

    buildMaxHeap(arr, n);
    for(int i=n-1; i>=1; --i) {
        swap(arr,0,i);
        heapify(arr,0,i);
    }

    printf("\nSorted array: ");
    for(int i=0; i<n; ++i)  printf("%d  ",arr[i]);
}
//Time complexity: O(n logn) for all cases.