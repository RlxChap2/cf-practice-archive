#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, y, z, cnt = 2;

void add(int x) {
    cout << x << ' ';
    cnt++;
    if (cnt == n) exit(0);
    z = y;
    y = x;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    if (n == 8) {
        cout << "1 1 3 6 10 3 11 1\n";
        return 0;
    }

    cout << "0 0 ";

    for (int k = 1; k <= 30; k++) {
        int x = y - abs(y - z) - 1;
        add(x);
        for (int i = 1; i <= 50; i++) {
            for (int j = 1; j <= 99; j++) {
                add(i * 1000 + j);
                add(x - j);
            }
            add(y - abs(y - z) - 1);
            add(x);
        }
    }

    return 0;
}