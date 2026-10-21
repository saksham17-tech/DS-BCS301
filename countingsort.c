#include <stdio.h>
#include <stdlib.h>

void countingsort(int* arr, int mx, int n) {
    if(n<=0)    return;
    int* freq = (int*)calloc(mx+1,sizeof(*freq));
    for(int i=0; i<n; ++i)   freq[arr[i]]++;
    int i = 0, j = 0;
    while(i<mx+1) {
        while(freq[i]-- > 0)    arr[j++] = i;
        i++;
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
    int arr[n];
    printf("Enter %d elements in the array:\n",n);
    for(int i=0; i<n; ++i)  scanf("%d", &arr[i]);
    print(arr,n);
    int mx = arr[0];
    for(int i=0; i<n; ++i)  if(mx<arr[i])   mx = arr[i];
    countingsort(arr,mx,n);
    print(arr,n);
    return 0;
}
//Time Complexity: O(n+mx)