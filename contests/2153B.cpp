#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases;
    cin >> cases;

    while (cases--) {
        int a, b, c;
        cin >> a >> b >> c;

        bool valid = true;

        for (int bit = 0; bit < 31; ++bit) {
            int A = (a >> bit) & 1;
            int B = (b >> bit) & 1;
            int C = (c >> bit) & 1;

            int sum = A + B + C;
            if (sum == 2) {
                valid = false;
                break;
            }
        }

        cout << (valid ? "YES\n" : "NO\n");
    }

    return 0;
}
