#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int* arr, int n) {
    for(int i=1; i<n; ++i) {
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key) {                 //arr[j]<key for descending
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = key;
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
    insertion_sort(arr,n);
    print(arr,n);
    return 0;
}
//Time Complexity: O(n^2)