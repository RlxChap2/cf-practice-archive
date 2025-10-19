#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int RAND_SEED = chrono::high_resolution_clock::now().time_since_epoch().count();
struct custom_hash {
    int operator()(int x) const { return x ^ RAND_SEED; }
};

#pragma GCC optimize("O3,unroll-all-loops")
#pragma GCC target("avx,avx2")

int n, k, s, q;
vector<int> adj[300005];
gp_hash_table<int, int, custom_hash> colorMap[300005];
map<pair<int, int>, int> queryCache;

void propagateColors(int node, int parent) {
    for (auto &[color, origin] : colorMap[node]) {
        if (colorMap[parent].find(color) != colorMap[parent].end()) {
            origin = colorMap[parent][color];
        }
    }
    for (int neighbor : adj[node]) {
        if (neighbor == parent) continue;
        propagateColors(neighbor, node);
    }
}

void solveCase() {
    cin >> n >> k >> s >> q;

    queryCache.clear();
    for (int i = 1; i <= n; i++) {
        colorMap[i].clear();
        adj[i].clear();
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= s; i++) {
        int node, color;
        cin >> node >> color;
        colorMap[node][color] = node;
    }

    propagateColors(1, 0);

    while (q--) {
        int u, v;
        cin >> u >> v;

        if (colorMap[u].size() > colorMap[v].size()) swap(u, v);

        if (queryCache.count({u, v})) {
            cout << queryCache[{u, v}] << " ";
            continue;
        }

        int matchCount = 0;
        for (auto &[color, src] : colorMap[u]) {
            auto it = colorMap[v].find(color);
            if (it != colorMap[v].end() && src == it->second) {
                matchCount++;
            }
        }

        queryCache[{u, v}] = matchCount;
        cout << matchCount << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solveCase();
}
