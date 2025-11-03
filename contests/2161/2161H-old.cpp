#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcdll(ll a, ll b) {
    return b == 0 ? a : gcdll(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        ll k;
        cin >> n >> m >> k;
        vector<int> a(n), b(m);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;

        ll g = gcdll(n, m);
        ll L = (ll)n / g * m;

        ll steps = min(k, L);

        for (ll i = 0; i < steps; i++) {
            int ia = i % n;
            int ib = i % m;
            if (a[ia] > b[ib])
                swap(a[ia], b[ib]);
        }

        for (int i = 0; i < n; i++)
            cout << a[i] << (i + 1 < n ? ' ' : '\n');
        for (int i = 0; i < m; i++)
            cout << b[i] << (i + 1 < m ? ' ' : '\n');
    }
    return 0;
}