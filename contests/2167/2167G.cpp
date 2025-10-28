#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), c(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> c[i];
        vector<int> dp(n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            dp[i] = c[i];
            for (int j = 0; j < i; j++) {
                if (a[j] <= a[i]) dp[i] = max(dp[i], dp[j] + c[i]);
            }
            ans = max(ans, dp[i]);
        }
        cout << accumulate(c.begin(), c.end(), 0LL) - ans << '\n';
    }
}
