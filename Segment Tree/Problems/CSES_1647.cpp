/*  Problem --> https://cses.fi/problemset/task/1647  */

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
 
void init(ll node, ll b, ll e) {
    if(b == e) {
        tree[node] = arr[b]; return;
    }
 
    ll mid = (b + e) >> 1;
 
    init(node << 1, b, mid);
    init((node << 1) + 1, mid + 1, e);
 
    tree[node] = min(tree[node << 1], tree[(node << 1) + 1]);
}
 
ll query(ll node, ll b, ll e, ll l, ll r) {
    if(l > e || r < b) return INF;
 
    if(l <= b && r >= e) return tree[node];
 
    ll mid = (b + e) >> 1;
 
    ll q1 = query(node << 1, b, mid, l, r);
    ll q2 = query((node << 1) + 1, mid + 1, e, l, r);
 
    return min(q1, q2);
}
 
void solve() {
    ll n, q; cin >> n >> q;
    
    arr.resize(n+1);
    tree.resize(4*n);
 
    for(ll i=1; i<=n; i++) cin >> arr[i];
 
    init(1, 1, n);
 
    while(q--) {
        ll l, r; cin >> l >> r;
 
        cout << query(1, 1, n, l, r) << endl;
    }
}
 
int main() {
    opt();
    // tc() {
        solve();
    // }
    return 0;
}
