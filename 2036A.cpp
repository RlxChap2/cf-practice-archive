#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) 
    {
        int n; cin >> n;
        vector<int> a(n);

        for (int &x : a) cin >> x;
        bool ok = true;

        for (int i = 1; i < n; i++) {
            int diff = abs(a[i] - a[i - 1]);
            if (diff != 5 && diff != 7) ok = false;
        }
        
        cout << (ok ? "YES\n" : "NO\n");
    }
}
