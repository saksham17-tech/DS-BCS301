#include <stdio.h>

int main() {
    int n = 5;
    int arr[] = {1,2,3,4,5};
    int l=0, h=n-1;
    while(l<h) {
        int t = arr[l];
        arr[l++] = arr[h];
        arr[h--] = t;
    }
    for(int i=0; i<n; ++i)  printf("%d  ",arr[i]);
    return 0;
}