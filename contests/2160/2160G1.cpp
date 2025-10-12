#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

const ll INF_VAL = 0x3f3f3f3f3f3f3f3f;

void run_case() {
    int n;
    cin >> n;
    vector<ll> seq(1);
    for (int i = 1; i <= n; ++i) {
        ll val;
        cin >> val;
        while (val <= seq.back())
            seq.pop_back();
        seq.push_back(val);
    }

    n = seq.size() - 1;
    vector<ll> dp(n + 2, INF_VAL);
    dp[n + 1] = 0;

    for (int i = n; i >= 1; --i) {
        dp[i] = dp[i + 1] + 1;
        if (i != n) {
            ll limit1 = max(seq[i + 1], 2 * seq[i]);
            ll limit2 = max(seq[i + 1], 3 * seq[i]);
            int idx1 = upper_bound(seq.begin() + i + 1, seq.end(), limit1) - seq.begin() - 1;
            int idx2 = upper_bound(seq.begin() + i + 1, seq.end(), limit2) - seq.begin() - 1;

            dp[i] = min(dp[i], dp[idx1 + 1] + (seq[idx1] + seq[i] - 1) / seq[i]);
            dp[i] = min(dp[i], dp[idx2 + 1] + (seq[idx2] + seq[i] - 1) / seq[i]);
        }
    }

    cout << dp[1] << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) run_case();
    return 0;
}