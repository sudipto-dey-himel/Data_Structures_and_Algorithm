/*  Problem --> https://lightoj.com/problem/horrible-queries  */

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define mx 400010

ll tree[mx];
ll lazy[mx];

ll c = 1;

void shift(ll node, ll b, ll e) {
    if(lazy[node]) {
        tree[node] += ((e - b + 1) * lazy[node]);
        if(b != e) {
            lazy[node*2] += lazy[node];
            lazy[(node*2) + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(ll node, ll b, ll e, ll i, ll j, ll value) {
    shift(node, b, e);

    if(b > j || e < i) return;
    if(b >= i && e <= j) {
        tree[node] += ((e - b + 1) * value);
        if(b != e) {
            lazy[node*2] += value;
            lazy[(node*2) + 1] += value;
        }
        return;
    }

    ll mid = (b + e) >> 1;

    update(node*2, b, mid, i, j, value);
    update((node*2) + 1, mid + 1, e, i, j, value);

    tree[node] = tree[node*2] + tree[(node*2) + 1];
}

ll query(ll node, ll b, ll e, ll l, ll r) {
    shift(node, b, e);

    if(e < l || b > r) return 0;
    if(b >= l && e <= r) return tree[node];

    ll mid = (b + e) >> 1;
    ll q1 = query(node*2, b, mid, l, r);
    ll q2 = query((node*2) + 1, mid + 1, e, l, r);

    return q1 + q2;
}

void solve() {
    ll n, q; cin >> n >> q;
    mem(tree, 0); mem(lazy, 0);
    cout <<"Case "<< c++ << ":\n";
    while(q--) {
        ll type; cin >> type;
        if(type == 0) {
            ll left, right, value;
            cin >> left >> right >> value;
            update(1, 0, n-1, left, right, value);
        }
        else {
            ll l, r; cin >> l >> r;
            cout  << query(1, 0, n-1, l, r) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll t; cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}