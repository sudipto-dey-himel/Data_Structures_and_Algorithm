#include<iostream>
using namespace std;

int search(int arr[], int n, int data) {
    for(int i=0; i<n; i++) {
        if(arr[i]==data)
        return i;
    }
    return -1;
}
int main() {
    int n;
    cout<<"Enter the number of elements :: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements :: ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    int data;
    cout<<"Input data to search =  ";
    cin>>data;
    int index=search(arr, n, data);
    if(index==-1)
    cout<<"Data not found!";
    else
    cout<<data<<" Found at index :: "<< index;

  return 0;
}
