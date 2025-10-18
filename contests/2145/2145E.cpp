#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int MAX_N = 500050;

int segVal[4 * MAX_N], segMin[4 * MAX_N];
int atk[MAX_N], defn[MAX_N];

#define LEFT (2 * node)
#define RIGHT (2 * node + 1)
#define MID ((l + r) >> 1)

void update(int node, int l, int r, int pos, int delta) {
    if (l == r) {
        segVal[node] += delta;
        segMin[node] = segVal[node];
        return;
    }
    if (pos <= MID) update(LEFT, l, MID, pos, delta);
    else update(RIGHT, MID + 1, r, pos, delta);

    segVal[node] = segVal[LEFT] + segVal[RIGHT];
    segMin[node] = std::min(segMin[LEFT], segVal[LEFT] + segMin[RIGHT]);
}

int query(int node, int l, int r, int acc = 0) {
    if (l == r) return l;
    if (segMin[LEFT] + acc < 0) return query(LEFT, l, MID, acc);
    return query(RIGHT, MID + 1, r, acc + segVal[LEFT]);
}

#undef LEFT
#undef RIGHT
#undef MID

void solve() {
    int baseAtk, baseDef, n;
    cin >> baseAtk >> baseDef >> n;

    for (int i = 1; i <= n; i++) cin >> atk[i];
    for (int i = 1; i <= n; i++) cin >> defn[i];

    for (int i = 1; i <= n; i++) {
        int pos = std::max(atk[i] - baseAtk, 0) + std::max(defn[i] - baseDef, 0);
        update(1, 0, n, pos, 1);
    }

    for (int i = 0; i <= n; i++) {
        update(1, 0, n, i, -1);
    }

    int m;
    cin >> m;
    for (int idx; m--; ) {
        cin >> idx;

        int oldPos = std::max(atk[idx] - baseAtk, 0) + std::max(defn[idx] - baseDef, 0);
        update(1, 0, n, oldPos, -1);

        cin >> atk[idx] >> defn[idx];
        int newPos = std::max(atk[idx] - baseAtk, 0) + std::max(defn[idx] - baseDef, 0);
        update(1, 0, n, newPos, 1);

        cout << query(1, 0, n) << "\n";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    while (t--) solve();
}
