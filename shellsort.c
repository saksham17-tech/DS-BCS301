#include <stdio.h>
#include <stdlib.h>

void shellsort(int* arr, int n) {
    for(int gap=n/2; gap>0; gap/=2) {
        for(int i=gap; i<n; ++i) {
            int temp = arr[i];
            int j = i;
            while(j>=gap && arr[j-gap]>temp) {
                arr[j] = arr[j-gap];
                j -= gap;
            }
            arr[j] = temp;
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
    shellsort(arr,n);
    print(arr,n);
    return 0;
}
//Time Complexity: O(n^2)