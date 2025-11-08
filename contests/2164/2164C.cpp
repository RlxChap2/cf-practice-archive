#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Monster { 
    int b, c; 
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    if(!(cin >> T)) return 0;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        vector<Monster> mons(m);
        for (int i = 0; i < m; ++i) cin >> mons[i].b;
        for (int i = 0; i < m; ++i) cin >> mons[i].c;

        sort(a.begin(), a.end());
        sort(mons.begin(), mons.end(), [](const Monster &x, const Monster &y){
            return x.b < y.b;
        });

        multiset<int> swords(a.begin(), a.end());
        priority_queue<int> pq;
        int j = 0;
        int kills = 0;

        while (!swords.empty()) {
            int s = *swords.begin();
            swords.erase(swords.begin());

            while (j < m && mons[j].b <= s) {
                pq.push(mons[j].c);
                ++j;
            }

            if (pq.empty()) {
                continue;
            }

            int bestc = pq.top(); pq.pop();
            ++kills;
            if (bestc > 0) {
                int newd = max(s, bestc);
                swords.insert(newd);
            }
        }

        cout << kills << '\n';
    }
    return 0;
}
