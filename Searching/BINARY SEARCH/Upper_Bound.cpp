#include<bits/stdc++.h>
using namespace std;

int upper_bound(vector<int> &nums, int target, int n) {
    int L = 0, R = n-1, ans = n;
    while(L <= R) {
        int mid = (L+R)/2;
        if(nums[mid] > target) {
            ans = mid;
            R = mid-1;
        }
        else L = mid+1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<int> arr = {1, 2, 2, 2, 2, 3, 4, 5, 5, 6, 8, 8, 9, 10};
    int target = 6;
    cout<<upper_bound(arr, target, arr.size());

    // cout<<upper_bound(V.begin(), V.end(), 0) - V.begin();  // Builtin Finction

    return 0;
}