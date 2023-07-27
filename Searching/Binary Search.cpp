#include<iostream>
using namespace std;

int binary_search(int arr[], int left, int right, int data) {
    int mid=(left+right)/2;
    if(left>right)
    return -1;
    else {
        if(data>arr[mid])
        return binary_search(arr, mid+1, right, data);
        else if(data<arr[mid])
        return binary_search(arr, left, mid-1, data);
        else
        return mid;
    }
}

int main() {
    int n;
    cout<<"Enter the number of elements :: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements :: ";
    for(int i=0; i<n; i++)
    cin>>arr[i];

    int data;
    cout<<"Input data to find = ";
    cin>>data;
    int index=binary_search(arr, 0, n-1, data);
    if(index==-1)
    cout<<"Data not found!"<<endl;
    else
    cout<<data<<" Found at index :: "<<index<<endl;
}
