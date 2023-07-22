#include<stdio.h>
void sort(int arr[], int n) {
    int i, j, temp;
    for(i=1; i<n; i++) {
        temp=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp) {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
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
    printf("Enter the unsorted array :: ");
    for(int i=0; i<n; i++) 
    scanf("%d", &arr[i]);
    sort(arr, n);
    printf("Sorted Array :: ");
    print(arr, n);
}
