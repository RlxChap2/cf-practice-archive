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
        for (int a = 1; a <= 26; a++) {
            for (int b = 1; b <= 26; b++) {
                int c = n - a - b;
                if (c >= 1 && c <= 26) {
                    cout << char('a' + a - 1)
                         << char('a' + b - 1)
                         << char('a' + c - 1)
                         << "\n";
                    a = b = 27; // break both loops
                }
            }
        }
    }
}
