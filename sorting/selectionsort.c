#include <stdio.h>
#include <stdlib.h>

void selectionsort(int* arr, int n) {
    for(int i=0; i<n-1; ++i) {
        int mn=i;
        for(int j=i+1; j<n; ++j)
            if(arr[j]<arr[mn])  mn=j;           //arr[j]>arr[mn] for descending
        if(mn!=i) {
            int t = arr[i];
            arr[i] = arr[mn];
            arr[mn] = t;
        }
    }
}

void print(int* arr, int n) {
    printf("\n");
    for(int i=0; i<n; ++i)   printf("%d  ", arr[i]);
}

int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    if(n<=0)    return -99;
    int arr[n];
    printf("Enter %d elements in the array:\n",n);
    for(int i=0; i<n; ++i)  scanf("%d", &arr[i]);
    print(arr,n);
    selectionsort(arr,n);
    print(arr,n);
    return 0;
}
//Time Complexity: O(n^2)