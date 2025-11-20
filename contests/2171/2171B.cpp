// Codeforces Solution - B: Yuu Koito and Minimum Absolute Sum
// Author: 0xM7md (My Coding Style) - fixed

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
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> ans = a;

        bool anyKnown = false;
        for (int i = 0; i < n; i++) if (a[i] != -1) { anyKnown = true; break; }
        if (!anyKnown) {
            for (int i = 0; i < n; i++) ans[i] = 0;
            cout << 0 << "\n";
            for (int i = 0; i < n; i++) cout << ans[i] << (i+1==n?'\n':' ');
            continue;
        }

        int left = a[0], right = a[n-1];
        int minimal;
        if (left == -1 || right == -1) minimal = 0;
        else minimal = llabs(right - left);

        for (int i = 0; i < n; i++) {
            if (a[i] == -1) ans[i] = 0;
        }

        if (a[0] == -1 && a[n-1] != -1) {
            ans[0] = a[n-1];
        } else if (a[0] != -1 && a[n-1] == -1) {
            ans[n-1] = a[0];
        } else if (a[0] == -1 && a[n-1] == -1) {
            ans[0] = 0;
            ans[n-1] = 0;
        }

        cout << minimal << "\n";
        for (int i = 0; i < n; i++) cout << ans[i] << (i+1==n?'\n':' ');
    }
    return 0;
}
