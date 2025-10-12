#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; if (!(cin >> t)) return 0;
    while (t--) {
        long long n; cin >> n;
        int m = (n == 0 ? 1 : 64 - __builtin_clzll(n));
        bool ok = false;
        for (int L = m; L <= 2*m; ++L) {
            vector<int> s(L, 0);
            for (int i = 0; i < L; ++i) {
                if (i < m) s[i] = ( (n >> i) & 1LL ) ? 1 : 0;
                else s[i] = 0;
            }
            bool pal = true;
            for (int i = 0; i < L; ++i) {
                if (s[i] != s[L-1-i]) { pal = false; break; }
            }
            if (!pal) continue;
            if ((L % 2) == 1 && s[L/2] != 0) continue;
            ok = true;

            vector<int> x(L, 0);
            x[L-1] = 1;
            for (int i = L-2; i >= 0; --i) {
                x[i] = x[L-1-i] ^ s[i];
            }

            break;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}