#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios::sync_with_stdio(false); cin.tie(nullptr);

signed main() {
    fast;
    int t; cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (a == b) {
            cout << 0 << "\n";
            continue;
        }
        int x = a ^ b;
        if (x <= a) {
            cout << 1 << "\n" << x << "\n";
            continue;
        }
        bool found = false;
        int x1_ans = -1, x2_ans = -1;
        for (int bit = 0; bit < 31; bit++) {
            if ( (x >> bit) & 1 ) {
                int x1 = (1LL << bit);
                if (x1 <= a) {
                    int a1 = a ^ x1;
                    int x2 = a1 ^ b;
                    if (x2 <= a1) {
                        found = true;
                        x1_ans = x1;
                        x2_ans = x2;
                        break;
                    }
                }
            }
        }
        if (found) {
            cout << 2 << "\n" << x1_ans << " " << x2_ans << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
}
