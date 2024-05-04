/*  Problem --> https://www.spoj.com/problems/BSEARCH1/en/  */

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

ll binary_search(vector<ll> &V, ll x) {
    ll l = 0, r = V.size()-1;
    ll ans = -1;
    while(l <= r) {
        ll m = (l+r)/2;
        if(x == V[m]) ans = m;
        (x <= V[m]) ? r = m-1 :  l = m+1;
    }
    return ans;
}

void solve() {
    ll n, q; cin>>n>>q;
    vector<ll> V(n);
    for(auto &i : V) cin>>i;
    while(q--) {
        ll x; cin>>x;
        cout<<binary_search(V, x)<<endl;
    }
}

int main() {
    opt();
    //tc() {
        solve();
    //}
    return 0;
}