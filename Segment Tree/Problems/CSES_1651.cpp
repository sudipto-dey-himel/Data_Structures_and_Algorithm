/*  Problem -->  https://cses.fi/problemset/task/1651/  */

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

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
        tree[node] = arr[b]; return;
    }
    ll mid = (b + e) >> 1;
    init(node << 1, b, mid); init((node << 1) + 1, mid + 1, e);
    tree[node] = tree[node << 1] + tree[(node << 1) + 1];
}

void update(ll node, ll b, ll e, ll i, ll j, ll v) {
    shift(node, b, e);

    if(b > j || e < i) return;

    if(b >= i && e <= j) {
        tree[node] += ((e - b + 1) * v);
        if(b != e) {
            lazy[node << 1] += v;
            lazy[(node << 1) + 1] += v;
        }
        return;
    }

    ll mid = (b + e) >> 1;

    update(node << 1, b, mid, i, j, v);
    update((node << 1) + 1, mid + 1, e, i, j, v);

    tree[node] = tree[node << 1] + tree[(node << 1) + 1];
}

ll query(ll node, ll b, ll e, ll k) {
    shift(node, b, e);

    if(b > k || e < k) return 0;
    if(b == k && e == k) return tree[node];
    ll mid = (b + e) >> 1;
    ll q1 = query(node << 1, b, mid, k);
    ll q2 = query((node << 1) + 1, mid + 1, e, k);

    return q1 + q2;
}

void solve() {
    ll n, q; cin >> n >> q;

    arr.resize(n+1); tree.resize(n*4); lazy.resize(n*4, 0);

    for(ll i=1; i<=n; i++) cin >> arr[i];

    init(1, 1, n);

    while(q--) {
        ll x; cin >> x;
        if(x == 1) {
            ll i, j, v; cin >> i >> j >> v;
            update(1, 1, n, i, j, v);
        }
        else {
            ll k; cin >> k;
            cout << query(1, 1, n, k) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // ll t; cin >> t;
    // while(t--) {
        solve();
    // }

    return 0;
}
