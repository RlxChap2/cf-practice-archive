#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; cin >> n;
        vector<long long> b(n+1);
        for (int i = 1; i <= n; ++i) cin >> b[i];

        vector<long long> d(n+1);
        d[1] = b[1];
        for (int i = 2; i <= n; ++i) d[i] = b[i] - b[i-1];

        vector<int> a(n+1, 0);
        int next_label = 0;
        for (int i = 1; i <= n; ++i) {
            long long di = d[i];
            long long p = i - di;
            if (p == 0) {
                ++next_label;
                a[i] = next_label;
            } else {
                a[i] = a[p];
            }
        }

        for (int i = 1; i <= n; ++i) {
            cout << a[i] << (i==n?'\n':' ');
        }
    }
    return 0;
}
