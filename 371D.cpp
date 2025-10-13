#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int N, Q;
vector<ll> cap;
vector<int> parent;
vector<ll> filled;

int find_parent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find_parent(parent[x]);
}

void add_value(int pos, ll val) {
    int root = find_parent(pos);
    if (filled[root] + val < cap[root]) {
        filled[root] += val;
    } else {
        ll overflow = filled[root] + val - cap[root];
        filled[root] = cap[root];
        if (root < N) {
            parent[root] = root + 1;
            int next_root = find_parent(root);
            add_value(next_root, overflow);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    cap.resize(N + 1);
    parent.resize(N + 1);
    filled.resize(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> cap[i];
        parent[i] = i;
    }

    cin >> Q;
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos;
            ll val;
            cin >> pos >> val;
            add_value(pos, val);
        } else {
            int idx;
            cin >> idx;
            cout << filled[idx] << '\n';
        }
    }

    return 0;
}