#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 4e5 + 5;
const int MOD = 1e9 + 7;

int n;
int arr[MAXN], ways[MAXN];

void process() {
    cin >> n;
    for (int i = 0; i <= n; i++)
        cin >> arr[i];

    int unknown = 0;

    for (int i = 1; i <= n; i++) {
        if (arr[i] <= 0) continue;

        if (arr[i] > n || (arr[arr[i]] != -1 && arr[arr[i]] != i)) {
            cout << 0 << '\n';
            return;
        }
        arr[arr[i]] = i;
    }

    for (int i = 1; i <= n; i++)
        unknown += (arr[i] == -1);

    if (arr[n] != -1)
        cout << ways[unknown] << '\n';
    else
        cout << (ways[unknown] - ways[unknown - 1] + MOD) % MOD << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ways[0] = 1;
    for (int i = 1; i <= MAXN - 5; i++) {
        ways[i] = (2 * ways[i - 1]) % MOD;
        if (i > 1)
            ways[i] = (ways[i] + (i - 1) * ways[i - 2]) % MOD;
    }

    int T;
    cin >> T;
    while (T--)
        process();

    return 0;
}
