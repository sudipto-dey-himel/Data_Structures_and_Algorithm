/*   Problem --> https://cses.fi/problemset/task/1648   */

#include <bits/stdc++.h>

typedef long long ll;
typedef double ld;

#define endl '\n'
#define fi first
#define se second 
#define pb push_back
#define ppb pop_back
#define HA cout<<"YES"<<endl
#define NA cout<<"NO"<<endl
#define mem(a, b) memset(a, b, sizeof(a))
#define tc() ll t;cin>>t;while(t--)
#define all(V) (V).begin(), (V).end()
#define bug(a) cout << #a << " : " << a << endl;
#define sumV(a) accumulate(a.begin(), a.end(), 0LL)
#define mxV(V) *max_element(V.begin(), V.end())
#define mnV(V) *min_element(V.begin(), V.end())
#define mx(a, b, c) max(a, max(b, c))
#define mn(a, b, c) min(a, min(b, c))
#define ceiling(a, b) ((a / b) + (a % b != 0))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a * b) / gcd(a, b))
#define opt() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int MAX_SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX;
const ld EPS = LLONG_MIN;

using namespace std;

vector<ll> arr;
vector<ll> tree;

void init(ll node, ll begin, ll end) {
    if(begin == end) {
        tree[node] = arr[begin]; return;
    }

    ll mid = (begin + end) >> 1;

    init(node << 1, begin, mid); 
    init((node << 1) + 1, mid + 1, end);

    tree[node] = tree[node << 1] + tree[(node << 1) + 1];
}

ll query(ll node, ll begin, ll end, ll l, ll r) {
    if(l > end || r < begin) return 0;
    if(l <= begin && r >= end) return tree[node];

    ll mid = (begin + end) >> 1;

    ll sumL = query(node << 1, begin, mid, l, r);
    ll sumR = query((node << 1) + 1, mid + 1, end, l, r);

    return (sumL+sumR);
}

void update(ll node, ll begin, ll end, ll i, ll value) {
    if(i > end || i < begin) return;
    if(i <= begin && i >= end) {
        tree[node] = value; return;
    }

    ll mid = (begin + end) >> 1;

    update(node << 1, begin, mid, i, value);
    update((node << 1) + 1, mid + 1, end, i, value);

    tree[node] = tree[node << 1] + tree[(node << 1) + 1];
}

void solve() {
    ll n, q; cin >> n >> q;

    arr.resize(n+1); tree.resize(4*n);

    for(ll i = 1; i <= n; i++) cin >> arr[i];

    init(1, 1, n);

    while(q--) {
        ll x; cin >> x;
        if(x == 1) {
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