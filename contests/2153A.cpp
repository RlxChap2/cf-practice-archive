#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endlChar '\n'
#define allElements(v) v.begin(), v.end()

const ll MAX_SIZE = 1e5 + 5;
const ll INF = (1LL << 60);

const int dirX[] = {0, 1, -1, 0};
const int dirY[] = {1, 0, 0, -1};
const int knightX[] = {1, 1, -1, -1, 2, 2, -2, -2};
const int knightY[] = {2, -2, 2, -2, 1, -1, 1, -1};

void solve() {
    int n;
    cin >> n;

    set<int> uniqueValues;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        uniqueValues.insert(x);
    }

    cout << uniqueValues.size() << endlChar;
}

signed main() {
#ifdef DAVIDsPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testCases = 1;
    cin >> testCases;
    for (int i = 1; i <= testCases; ++i) {
        solve();
    }

    return 0;
}