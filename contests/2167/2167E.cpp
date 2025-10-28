#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long

struct Node {
    int d;
    int id;
    int state;
    bool operator<(Node const& o) const {
        if (d != o.d) return d < o.d;
        return id > o.id;
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n,k; ll x;
        cin >> n >> k >> x;
        vector<ll> a(n);
        for (int i=0;i<n;i++) cin >> a[i];
        sort(a.begin(), a.end());
        struct Interval {
            int type;
            ll L, R;
            int cur;
            int rem;
        };
        vector<Interval> iv;
        iv.push_back({0, 0, a[0], (int)a[0], (int)1});
        for (int i=0;i+1<n;i++){
            ll L=a[i], R=a[i+1];
            ll g = R - L;
            if (g <= 1) iv.push_back({1, L, R, 0, 0});
            else {
                int cur = (int)( (R - L) / 2 );
                iv.push_back({1, L, R, cur, 0});
            }
        }
        iv.push_back({2, a[n-1], x, (int)(x - a[n-1]), 1});
        priority_queue<Node> pq;
        for (int id=0; id<(int)iv.size(); ++id){
            if (iv[id].cur > 0) {
                if (iv[id].type == 1) {
                    ll g = iv[id].R - iv[id].L;
                    int t = iv[id].cur;
                    int cnt = ( (g % 2 == 0 && t == g/2) ? 1 : 2 );
                    iv[id].rem = cnt;
                } else iv[id].rem = 1;
                pq.push({iv[id].cur, id, 0});
            }
        }
        vector<ll> ans;
        ans.reserve(k);
        unordered_set<ll> used;
        used.reserve(k*2);
        while ((int)ans.size() < k && !pq.empty()) {
            Node top = pq.top(); pq.pop();
            int id = top.id;
            int d = top.d;
            if (d <= 0) break;
            ll pos = -1;
            if (iv[id].type == 0) {
                pos = iv[id].R - d;
                iv[id].cur = d - 1;
                iv[id].rem = (iv[id].cur > 0 ? 1 : 0);
                if (iv[id].cur > 0) pq.push({iv[id].cur, id, 0});
            } else if (iv[id].type == 2) {
                pos = iv[id].L + d;
                iv[id].cur = d - 1;
                iv[id].rem = (iv[id].cur > 0 ? 1 : 0);
                if (iv[id].cur > 0) pq.push({iv[id].cur, id, 0});
            } else {
                ll L = iv[id].L, R = iv[id].R;
                ll g = R - L;
                int t = d;
                int cnt = ( (g % 2 == 0 && t == g/2) ? 1 : 2 );
                if (iv[id].rem == 0) iv[id].rem = cnt;
                if (iv[id].rem == 2) {
                    pos = L + t;
                    iv[id].rem = 1;
                    pq.push({t, id, 0});
                } else {
                    pos = R - t;
                    iv[id].cur = t - 1;
                    iv[id].rem = (iv[id].cur > 0 ? ( ((R-L)%2==0 && iv[id].cur == (R-L)/2) ? 1 : 2 ) : 0);
                    if (iv[id].cur > 0) pq.push({iv[id].cur, id, 0});
                }
            }
            if (pos >= 0 && pos <= x && used.find(pos) == used.end()) {
                used.insert(pos);
                ans.push_back(pos);
            }
        }
        ll cur = 0;
        while ((int)ans.size() < k && cur <= x) {
            if (used.find(cur) == used.end()) {
                used.insert(cur);
                ans.push_back(cur);
            }
            ++cur;
        }
        for (int i=0;i<(int)ans.size();++i){
            if (i) cout << ' ';
            cout << ans[i];
        }
        cout << '\n';
    }
    return 0;
}
