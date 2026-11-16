#include <stdio.h>

int recBS(int arr[], int low, int high, int key) {
    if(low<=high) {
        int mid = low + (high-low)/2;
        if(key==arr[mid])       return mid;
        else if(arr[mid]>key)   return recBS(arr,low,mid-1,key);
        else                    return recBS(arr,mid+1,high,key);
    }
    return -1;
}

int main() {
    int n, key;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements in the array:\n",n);
    for(int i=0; i<n; ++i)  scanf("%d", &arr[i]);
    printf("\nEnter value to be searched: ");
    scanf("%d", &key);
    printf("\nArray: ");
    for(int i=0; i<n;  ++i) printf("%d  ",arr[i]);
    int pos = recBS(arr,0,n-1,key);
    if(pos==-1) printf("\nELEMENT NOT FOUND!!");
    else        printf("\nElement %d found at position: %d.",key,pos+1);
    return 0;
}