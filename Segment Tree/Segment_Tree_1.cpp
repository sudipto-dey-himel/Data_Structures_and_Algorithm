#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define tc() ll t; cin >> t; while(t--);
#define opt() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

vector<ll> arr;
vector<ll> tree;

void  init(ll node, ll begin, ll end) {
    if(begin == end) {
        tree[node] = arr[begin]; return;
    }

    ll mid = (begin + end) >> 1;

    init(node << 1, begin, mid);
    init((node << 1) + 1, mid + 1, end);

    tree[node] = tree[node << 1] + tree[(node << 1) + 1];
}

ll query(ll node, ll begin, ll end, ll left, ll right) {
    if(left > end || right < begin) return 0;

    if(left <= begin && right >= end) return tree[node];

    ll mid = (begin + end) >> 1;
    ll sumL = query(node << 1, begin, mid, left, right);
    ll sumR = query((node << 1) + 1, mid + 1, end, left, right);

    return (sumL + sumR);
}

void update(ll node, ll begin, ll end, ll i, ll value) {
    if(i > end || i < begin) return;

    if(i <= begin && i >= end) {
        tree[node] = value; return;
    }

    ll mid = (begin + end) >> 1;

    update(node << 1, begin, mid, i, value);
    update((node << 1) + 1, mid+1, end, i, value);

    tree[node] = tree[node << 1] + tree[(node << 1) + 1];
}

void solve() {
    ll n, q; cin >> n >> q;

    arr.resize(n+1); tree.resize(4*n);

    for(ll i=1; i<=n; i++) cin >> arr[i];

    init(1, 1, n);

    while(q--) {
        ll type; cin >> type;
        if(type == 1) {
            ll i, v; cin >> i >> v;
            update(1, 1, n, i, v);
        }
        else {
            ll l, r; cin >> l >> r;
            cout << query(1, 1, n, l, r) << endl;
        }
    }
}

int main() {
    opt();
    // tc() {
        solve();
    // }

    return 0;
}


/* Input :
8 4
3 2 4 5 1 1 5 3
2 1 4
2 5 6
1 3 1
2 1 4

output :
14
2
11

*/
