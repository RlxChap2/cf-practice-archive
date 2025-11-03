#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long R0, X, D;
        int n;
        cin >> R0 >> X >> D >> n;
        string s;
        cin >> s;

        long long R = R0;
        int rated = 0;

        for (char c : s) {
            if (c == '1') {
                rated++;
                if (R >= X) {
                    R = max(R - D, 0LL);
                } else {
                    R = min(R + D, X - 1);
                }
            } else {
                if (R < X) {
                    rated++;
                    R = min(R + D, X - 1);
                }
            }
        }

        cout << rated << "\n";
    }

    return 0;
}
