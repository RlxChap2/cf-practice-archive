#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
constexpr i64 MOD = 998244353;
constexpr i64 INF = 0x3f3f3f3f3f3f3f3f;

int ask(vector<int>& v) {
    cout << "? " << v.size();
    for (int& i : v) cout << ' ' << i + 1;
    cout << endl;
    int res;
    cin >> res;
    return res;
}

void process() {
    int n;
    cin >> n;
    vector<int> leftSet, rightSet;
    leftSet.reserve(n);
    rightSet.reserve(n);
    leftSet.push_back(0);
    vector<int> result(2 * n);

    for (int i = 1, res; i < 2 * n; ++i) {
        leftSet.push_back(i);
        res = ask(leftSet);
        if (res) {
            result[i] = res;
            leftSet.pop_back();
            rightSet.push_back(i);
        }
    }

    for (int& i : leftSet) {
        rightSet.push_back(i);
        result[i] = ask(rightSet);
        rightSet.pop_back();
    }

    cout << "! ";
    for (int& x : result) cout << x << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) process();
    return 0;
}