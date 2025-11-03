#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        long long k;
        cin >> n >> m >> k;
        vector<int> a(n), b(m);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;

        long long max_ops = 1LL * n * m;
        k = min(k, max_ops);

        for (long long i = 0; i < k; i++) {
            int ai = i % n, bi = i % m;
            if (a[ai] > b[bi]) swap(a[ai], b[bi]);
        }

        for (int x : a) cout << x << " ";
        cout << "\n";
        for (int x : b) cout << x << " ";
        cout << "\n";
    }
}
