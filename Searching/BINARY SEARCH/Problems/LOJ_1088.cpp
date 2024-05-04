/*  Problem --> https://vjudge.net/problem/LightOJ-1088  */

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


ll c = 1;

void solve() {
    ll n, q; cin >> n >> q;
    vector<ll> V(n);
    for(auto &x : V) cin >> x;

    cout << "Case " << c++ << ": " << endl;

    while(q--) {
        ll l, r; cin >> l >> r;

        ll lo = lower_bound(V.begin(), V.end(), l) - V.begin();
        ll up = upper_bound(V.begin(), V.end(), r) - V.begin();

        // cout << lo << " " << up << endl;
        cout << (up - lo) << endl;
    }
}

int main() {
    opt();
    tc() {
        solve();
    }
    return 0;
}