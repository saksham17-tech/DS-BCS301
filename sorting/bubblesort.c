#include <stdio.h>
#include <stdlib.h>

void bubblesort(int* arr, int n) {
    for(int i=0; i<n-1; ++i) {
        int flag = -99;
        for(int j=0; j<n-i-1; ++j) {
            if(arr[j]>arr[j+1]) {
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
                flag = 99;
            }
        }
        if(flag==-99)   break;
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
    bubblesort(arr,n);
    print(arr,n);
    return 0;
}
//Time Complexity: O(n^2)