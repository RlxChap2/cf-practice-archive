// Problem: A - Shizuku Hoshikawa and Farm Legs
// Author: 0xM7md (My Coding Style)

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
        int cnt = 0;

        // cows = x, chickens = y
        for (int cows = 0; cows <= n / 4; cows++) {
            int remaining = n - cows * 4;
            if (remaining >= 0 && remaining % 2 == 0) {
                cnt++;
            }
        }

        cout << cnt << "\n";
    }
    return 0;
}
