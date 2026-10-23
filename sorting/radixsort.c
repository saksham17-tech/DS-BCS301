#include <stdio.h>
#include <stdlib.h>

void countingsort(int* arr, int exp, int n) {
    int* op = calloc(n,sizeof(*op));
    int freq[10] = {0};
    for(int i=0; i<n; ++i)      freq[(arr[i]/exp)%10]++;
    for(int i=1; i<10; ++i)     freq[i] += freq[i-1];
    for(int i=n-1; i>=0; --i)   op[--freq[(arr[i]/exp)%10]] = arr[i];
    for(int i=0; i<n; ++i)      arr[i] = op[i];
    free(op);
}

void radixsort(int* arr, int n) {
    if(n<=0)    return;
    int mx = arr[0];
    for(int i=0; i<n; ++i)  if(mx<arr[i])   mx = arr[i];
    for(int exp=1; mx/exp>0; exp*=10)   countingsort(arr,exp,n);
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
    radixsort(arr,n);
    print(arr,n);
    return 0;
}
//Time Complexity: O(d*(n+b))