/*  Problem --> https://vjudge.net/problem/LightOJ-1043  */

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
ll c = 1;

ld calc(ld ab, ld ac, ld bc, ld ratio) {
    ld low = 0.0, high = ab, ad = 0.0;
    while (fabs(low - high) > 1e-6)
    {
        ad = (low + high) / 2;
        ld de = (ad / ab) * bc;
        ld ae = (ad / ab) * ac;

        ld s = (ad + de + ae) / 2.0;
        ld ADE = sqrt(s * (s - ad) * (s - de) * (s - ae));

        s = (ab + bc + ac) / 2.0;
        ld ABC = sqrt(s * (s - ab) * (s - bc) * (s - ac));

        ld BDEC = (ABC - ADE);

        ld ratio2 = ADE / BDEC;
        (ratio2 < ratio) ? low = ad : high = ad;
    }

    return ad;
}

void solve() {
    ld ab, ac, bc, ratio;
    cin >> ab >> ac >> bc >> ratio;
    
    ld AD = calc(ab, ac, bc, ratio);
    cout << "Case " << c++ << ": ";
    cout << fixed << setprecision(9) << AD << endl;
}

int main() {
    opt();

    tc() {
        solve();
    }

    return 0;
}