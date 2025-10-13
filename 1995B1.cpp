// CPP v23
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        long long n, m;
        cin >> n >> m;
        map<int, long long> cnt;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            cnt[x]++;
        }

        long long ans = 0;

        for (auto& p : cnt) {
            long long k = p.first;
            long long c1 = p.second;
            long long c2 = cnt.count(k + 1) ? cnt[k + 1] : 0;


            long long buy1 = min(c1, m / k);
            long long spent = buy1 * k;
            long long remain = m - spent;

            long long buy2 = min(c2, remain / (k + 1));
            spent += buy2 * (k + 1);
            remain = m - spent;

            long long canUpgrade = min({ buy1, c2 - buy2, remain });

            long long petals = k * buy1 + (k + 1) * buy2 + canUpgrade;

            ans = max(ans, petals);
        }

        cout << ans << "\n";
    }
    return 0;
}
