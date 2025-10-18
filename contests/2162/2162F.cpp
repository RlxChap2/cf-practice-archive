#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;

        vector<int> arr(n);
        iota(arr.begin(), arr.end(), 0);

        vector<int> prefix(n + 2, 0);
        vector<vector<pair<int, int>>> range(n + 1);

        for (int i = 0; i < q; i++) {
            int l, r;
            cin >> l >> r;
            for (int j = l; j <= r; j++)
                range[j].push_back({l, r});
            prefix[l]++;
            prefix[r + 1]--;
        }

        for (int i = 1; i <= n; i++)
            prefix[i] += prefix[i - 1];

        int pos = max_element(prefix.begin() + 1, prefix.begin() + n + 1) - prefix.begin();

        if (prefix[pos] == q) { 
            swap(arr[0], arr[pos - 1]);
        } else {
            int first = 0, second = n - 1;
            for (int i = 1; i <= n; i++) {
                int L = 1, R = n;
                for (auto [l, r] : range[i]) {
                    L = max(L, l);
                    R = min(R, r);
                }
                if (L < R) {
                    first = i - 1;
                    second = L + (i == L) - 1;
                    break;
                }
            }

            int val = 2;
            for (int i = 0; i < n; i++) {
                if (i == first || i == second) continue;
                arr[i] = val++;
            }
            arr[first] = 0;
            arr[second] = 1;
        }

        for (int i = 0; i < n; i++)
            cout << arr[i] << ' ';
        cout << '\n';
    }

    return 0;
}
