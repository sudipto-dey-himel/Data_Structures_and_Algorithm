// Lazy Propagatioin

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define tc() ll t; cin >> t; while(t--);
#define opt() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

vector<ll> arr;
vector<ll> tree;
vector<ll> lazy;

void shift(ll node, ll b, ll e) {
    if(lazy[node]) {
        tree[node] += ((e - b + 1) * lazy[node]);
        if(b != e) {
            lazy[node << 1] += lazy[node];
            lazy[(node << 1) + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void init(ll node, ll b, ll e) {
    if(b == e) {
        tree[node] = arr[b];
        return;
    }

    ll mid = (b + e) >> 1;
    init(node << 1, b, mid); init((node << 1) + 1, mid + 1, e);

    tree[node] = tree[node << 1] + tree[(node << 1) + 1];
}

void update(ll node, ll b, ll e, ll i, ll j, ll value) {
    shift(node, b, e);

    if(e < i || b > j) return;
    if(b >= i && e <= j) {
        tree[node] += ((e - b + 1) * value);
        if(b != e) {
            lazy[node << 1] += value;
            lazy[(node << 1) + 1] += value;
        }
        return;
    } 
    ll mid = (b + e) >> 1;
    update(node << 1, b, mid, i, j, value);
    update((node << 1) + 1, mid + 1, e, i, j, value);

    tree[node] = tree[node << 1] + tree[(node << 1) + 1];
}

ll query(ll node, ll b, ll e, ll l, ll r) {
    shift(node, b, e);

    if (e < l || b > r) return 0;
    if (b >= l && e <= r) return tree[node];

    ll mid = (b + e) >> 1;
    ll q1 = query(node << 1, b, mid, l, r);
    ll q2 = query((node << 1) + 1, mid + 1, e, l, r);

    return q1 + q2;
}

void solve() {
    ll n, q; cin >> n >> q;

    arr.resize(n+1); tree.resize(n*4); lazy.resize(n*4, 0);

    for(ll i=1; i<=n; i++) cin >> arr[i];

    init(1, 1, n);

    while(q--) {
        ll t; cin >> t;
        if(t == 0) {
            ll i, j, v; cin >> i >> j >> v;
            update(1, 1, n, i, j, v);
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

/*
input :
6 3
2 3 1 1 5 3
1 3 5
0 2 4 2
1 3 5

output:
7 
11
*/