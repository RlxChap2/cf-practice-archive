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
        vector<int> a(n);
        for (int &x : a) cin >> x;

        vector<int> cnt(102);
        for (int x : a) cnt[x]++;

        int ans = 0;
        for (int i = 0; i <= 100; i++) {
            if (cnt[i] == 0) {
                ans = i;
                break;
            }
        }
        cout << ans << "\n";
    }
}