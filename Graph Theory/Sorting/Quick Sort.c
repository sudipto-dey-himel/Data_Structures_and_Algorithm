#include<stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
     *a = *b;
     *b = temp;
}
int partition(int arr[], int start, int end) {
    int i, j, pivot;
    pivot=arr[start];
    i=start;
    j=end;
    while(i<j) {
        while(arr[i]<=pivot && i<=j) 
        i++;
        while(arr[j]>pivot)
        j--;
        if(i<j)
        swap(&arr[i], &arr[j]);
    }
    swap(&arr[start], &arr[j]);
    return j;
}
int sort(int arr[], int start, int end) {
    int k;
    if(start<end) {
        k=partition(arr, start, end);
        sort(arr, start, k-1);
        sort(arr, k+1, end);
    }
}
void print(int arr[], int n) {
    for(int i=0; i<n; i++) 
    printf("%d  ", arr[i]);
}
int main() {
    int n;
    printf("Enter the number of elements :: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements :: ");
    for(int i=0; i<n; i++) 
    scanf("%d", &arr[i]);
    sort(arr, 0, n-1);
    printf("Sorted Array :: ");
    print(arr, n);
}
