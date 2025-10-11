#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll calc(int i, vector<ll> &v, vector<ll> &dp) {
    if (i <= 0) return 1e18;

    if (i == 1)
        return dp[i] = abs(v[1] - v[0]);

    if (i == 2) {
        ll mx = max({v[i], v[i - 1], v[i - 2]});
        ll mn = min({v[i], v[i - 1], v[i - 2]});
        return dp[i] = abs(mx - mn);
    }

    if (dp[i] != -1) return dp[i];

    ll option1 = abs(v[i] - v[i - 1]) + calc(i - 2, v, dp);

    ll mx = max({v[i], v[i - 1], v[i - 2]});
    ll mn = min({v[i], v[i - 1], v[i - 2]});
    ll option2 = abs(mx - mn) + calc(i - 3, v, dp);

    return dp[i] = min(option1, option2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> v(n);
        for (auto &x : v) cin >> x;

        ll best = LLONG_MAX;
        vector<ll> rotated(n);

        for (int shift = 0; shift < 3; ++shift) {
            for (int j = 0; j < n; ++j)
                rotated[j] = v[(j + shift) % n];

            vector<ll> dp(n, -1);
            best = min(best, calc(n - 1, rotated, dp));
        }

        cout << best << '\n';
    }

    return 0;
}