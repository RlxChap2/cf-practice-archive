#include <bits/stdc++.h>
using namespace std;

#define int long long

void run_case() {
    int len;
    cin >> len;

    map<int, int> freqMap;
    for (int i = 0; i < len; ++i) {
        int val;
        cin >> val;
        ++freqMap[val];
    }

    bool allUnique = true;
    for (auto &entry : freqMap) {
        if (entry.second > 1) {
            allUnique = false;
            break;
        }
    }

    if (allUnique) {
        cout << 0 << '\n';
        return;
    }

    long long totalSum = 0;
    vector<int> oddKeys;

    for (auto &kv : freqMap) {
        int key = kv.first, count = kv.second;
        if (count & 1) {
            totalSum += key * (count - 1);
            oddKeys.push_back(key);
        } else {
            totalSum += key * count;
        }
    }

    sort(oddKeys.begin(), oddKeys.end(), greater<int>());

    if (oddKeys.empty()) {
        if (len > 2) {
            cout << totalSum << '\n';
            return;
        }
    }

    if (oddKeys.size() == 1) {
        long long temp = totalSum;
        if (oddKeys[0] < temp) {
            cout << temp + oddKeys[0] << '\n';
            return;
        }
        if (len - (int)oddKeys.size() > 2) {
            cout << totalSum << '\n';
            return;
        }
    }

    for (int i = 0; i + 1 < (int)oddKeys.size(); ++i) {
        long long x = totalSum + oddKeys[i + 1];
        if (oddKeys[i] < x) {
            cout << x + oddKeys[i] << '\n';
            return;
        }
    }

    for (int k : oddKeys) {
        long long tmp = totalSum;
        if (k < tmp) {
            cout << tmp + k << '\n';
            return;
        }
    }

    if (len - (int)oddKeys.size() > 2) {
        cout << totalSum << '\n';
        return;
    }

    cout << 0 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases;
    cin >> cases;
    while (cases--) {
        run_case();
    }
    return 0;
}