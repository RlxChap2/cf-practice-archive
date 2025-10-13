// CPP 23
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using vll = vector<ll>;
#define f(i, a, b) for (ll i = a; i < b; i++)

ll gcdll(ll a, ll b) { return b == 0 ? a : gcdll(b, a % b); }

void solve() {
    ll n;
    cin >> n;
    vll a(n), b(n);
    f(i, 0, n) cin >> a[i];
    f(i, 0, n) cin >> b[i];

    map<pair<ll, ll>, ll> freq;
    ll ans = 0, zeros = 0;

    f(i, 0, n) {
        ll x = gcdll(a[i], b[i]);
        ll num = -1 * (b[i] / x);
        ll den = (a[i] / x);

        if (den < 0) {
            den *= -1;
            num *= -1;
        }

        if (a[i] == 0 && b[i] != 0) {
            num = b[i];
            den = 1;
            continue;
        } else if (b[i] == 0 && a[i] != 0) {
            num = 0;
            den = 1;
        } else if (a[i] == 0 && b[i] == 0) {
            zeros++;
            continue;
        }

        freq[{num, den}]++;
        ans = max(ans, freq[{num, den}]);
    }

    cout << ans + zeros;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
