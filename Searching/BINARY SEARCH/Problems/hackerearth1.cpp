/* Problem --> https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/monks-encounter-with-polynomial/  */

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

ll soln(ll a, ll b, ll c, ll k) {
    ll l = 0, h = 1e6, ans = 0;
    while(l <= h) {
        ll mid = (l + h) >> 1;
        ll temp = a*(mid*mid) + b*mid + c;
        if(temp >= k) {
            ans = mid; h = mid - 1;
        }
        else l = mid + 1;
    }

    return ans;
}

void solve() {
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    cout << soln(a, b, c, k) << endl;
}

int main() {
    opt();
    tc() {
        solve();
    }
    return 0;
}