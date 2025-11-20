// Codeforces D - Rae Taylor and Trees (easy version)
// Author: 0xM7md (My Coding Style)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) cin >> p[i];

        vector<int> suffix_max(n + 1, 0);
        suffix_max[n] = 0;

        for (int i = n - 1; i >= 0; --i)
            suffix_max[i] = max(suffix_max[i + 1], p[i]);

        int prefix_min = INT_MAX;
        bool possible = true;

        for (int i = 0; i < n - 1; ++i) {
            prefix_min = min(prefix_min, p[i]);
            if (prefix_min > suffix_max[i + 1]) {
                possible = false;
                break;
            }
        }

        cout << (possible ? "Yes" : "No") << '\n';
    }
    return 0;
}
