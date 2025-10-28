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
        for (int &x : a) cin >> x;

        int g = a[0];
        for (int i = 1; i < n; i++) g = gcd(g, a[i]);

        int ans = -1;
        for (int x = 2; x <= 100; x++) {
            if (__gcd(g, (int)x) == 1) {
                ans = x;
                break;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
