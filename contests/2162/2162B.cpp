#include <bits/stdc++.h>
using namespace std;
#define int long long

bool is_pal(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        if (is_pal(s)) {
            cout << 0 << '\n';
            continue;
        }

        string x;
        for (char c : s) if (c != '0') x += c;
        if (is_pal(x)) {
            vector<int> idx;
            for (int i = 0; i < n; i++) if (s[i] == '0') idx.push_back(i + 1);
            cout << idx.size() << '\n';
            for (int i = 0; i < (int)idx.size(); i++)
                cout << idx[i] << (i + 1 == idx.size() ? '\n' : ' ');
            continue;
        }

        x.clear();
        for (char c : s) if (c != '1') x += c;
        if (is_pal(x)) {
            vector<int> idx;
            for (int i = 0; i < n; i++) if (s[i] == '1') idx.push_back(i + 1);
            cout << idx.size() << '\n';
            for (int i = 0; i < (int)idx.size(); i++)
                cout << idx[i] << (i + 1 == idx.size() ? '\n' : ' ');
            continue;
        }

        cout << -1 << '\n';
    }
}