#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;

    for (int i = n - 1; i > 0; i--) {
        if (s[i] == '1' && s[i - 1] == '0') {
            swap(s[i], s[i - 1]);
        } else if (s[i] == '1' && s[i - 1] == '1') {
            s.erase(s.begin() + i - 1);
        }
    }

    cout << s << '\n';
    return 0;
}