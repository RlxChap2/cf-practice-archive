// Codeforces C2 - Renako Amaori and XOR Game (hard)
// Author: 0xM7md (My Coding Style)

#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        int SA = 0, SB = 0;
        for (int i = 0; i < n; ++i) { cin >> a[i]; SA ^= a[i]; }
        for (int i = 0; i < n; ++i) { cin >> b[i]; SB ^= b[i]; }

        if (SA == SB) {
            cout << "Tie\n";
            continue;
        }

        int X = SA ^ SB;
        int k = 31;
        while (k >= 0 && ((X >> k) & 1) == 0) --k;

        int last = -1;
        for (int i = n - 1; i >= 0; --i) {
            int ai = (a[i] >> k) & 1;
            int bi = (b[i] >> k) & 1;
            if (ai != bi) { last = i + 1; break; }
        }

        if (last == -1) {
            cout << "Tie\n"; 
        } else if (last % 2 == 1) {
            cout << "Ajisai\n";
        } else {
            cout << "Mai\n";
        }
    }
    return 0;
}
