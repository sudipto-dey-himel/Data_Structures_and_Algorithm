#include<bits/stdc++.h>
using namespace std;

int BS(vector<int> &nums, int x) {
    int l = 0, h = nums.size();
    while(l <= h) {
        int mid = (l + h) >> 1;
        if(nums[mid] == x) return mid;
        (nums[mid] > x) ? h = mid - 1 : l = mid + 1;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, q; cin >> n >> q;
    vector<int> V(n);
    for(auto &x : V) cin >> x;
    sort(V.begin(), V.end()); // array must be sorted*
    while(q--) {
        int data; cin >> data;
        cout << BS(V, data) << endl;
    }

    return 0;
}