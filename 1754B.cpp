#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, j = 1;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            a[i] = j++;
        }

        if (n % 2 == 0) {
            int i = 0, p = (n - 1) / 2, q = p;
            while (i <= q) {
                cout << a[p + 1] << " " << a[i] << " ";
                i++;
                p++;
            }
            cout << endl;
        } else {
            int i = 0, p = (n - 1) / 2, q = p;
            while (i < q) {
                cout << a[p] << " " << a[i] << " ";
                i++;
                p++;
            }
            cout << a[n - 1] << endl;
        }
    }
    return 0;
}