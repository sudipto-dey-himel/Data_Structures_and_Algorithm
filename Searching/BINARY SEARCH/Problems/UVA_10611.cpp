/* Problem --> https://vjudge.net/problem/UVA-10611   */

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

void solve() {
    ll n; cin>>n;
    vector<ll> V(n);
    for(auto &x : V) cin>>x;
    ll q; cin>>q;
    while(q--) {
        ll x; cin>>x;
        ll a = lower_bound(all(V), x) - V.begin(); 
        ll b = upper_bound(all(V), x) - V.begin();
        if(x == V[a] && a > 0 && V[b] != x && b < V.size()) {
            cout<<V[a-1]<<" "<<V[b]<<endl;
        }
        if(x == V[a] && a > 0 && V[b] != x && b == V.size()) {
            cout<<V[a-1]<<" "<<'X'<<endl;
        }
        if(x != V[a] && a > 0 && V[b] != x && b < V.size()) {
            cout<<V[a-1]<<" "<<V[b]<<endl;
        }
        if(x >= V[V.size()-1]) {
            cout<<V[V.size()-1]<<" "<<'X'<<endl;
        }
        if(a <= 0 && V[a] == x) {
            cout<<'X'<<" "<<V[b]<<endl;
        }
        if(x < V[0]) {
            cout<<'X'<<" "<<V[0]<<endl;
        }
    }
}

int main() {
    opt();
    //tc() {
        solve();
    //}
    return 0;
}