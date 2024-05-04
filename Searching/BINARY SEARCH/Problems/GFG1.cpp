/*  Problem -->  https://www.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1  */

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        vector<int> ans(2, -1);
        
        int lo = lower_bound(arr, arr+n, x) - arr;
        int up = upper_bound(arr, arr+n, x) - arr - 1;
        
        if(lo == n || arr[lo] != x) {
            lo = -1; up = -1;
        }
        
        ans[0] = lo; ans[1] = up;
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends