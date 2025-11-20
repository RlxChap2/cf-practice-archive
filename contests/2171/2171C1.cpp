// Codeforces C1 - Renako Amaori and XOR Game (easy version)
// Author: 0xM7md (My Coding Style) - fixed v2

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        int sa = 0, sb = 0;
        for (int i = 0; i < n; ++i) { cin >> a[i]; sa ^= a[i]; }
        for (int i = 0; i < n; ++i) { cin >> b[i]; sb ^= b[i]; }

        if (sa == sb) {
            cout << "Tie\n";
            continue;
        }

        int last_diff = -1;
        for (int i = n-1; i >= 0; --i) {
            if (a[i] != b[i]) { last_diff = i + 1; break; }
        }

        if (last_diff == -1) {
            cout << "Tie\n";
        } else if (last_diff % 2 == 1) {
            cout << "Ajisai\n";
        } else {
            cout << "Mai\n";
        }
    }

    return 0;
}
