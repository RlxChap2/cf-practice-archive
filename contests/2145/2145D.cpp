#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, i, j, k, t;

    basic_string<int> seq[31][905], tempSeq;

    for (i = 0; i <= 30; i++) {
        for (j = 0; j <= 900; j++) {
            if ((i + j == 0) || !seq[i][j].empty()) {
                for (k = 1; k + i <= 30; k++) {
                    tempSeq = {};
                    for (t = 1; t <= k; t++) tempSeq += (i + t);
                    seq[i + k][j + (k * k + k) / 2] = tempSeq + seq[i][j];
                }
            }
        }
    }

    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;

        m = (n * n + n) / 2 - m;

        if (seq[n][m].empty()) {
            cout << "0";
        } else {
            for (auto x : seq[n][m]) cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}
