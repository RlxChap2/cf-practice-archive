#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fst first
#define snd second
#define pb push_back
#define nl "\n"

const int MAXN = 400005;
const ll MOD = 1000000007;

ll fact[MAXN];

ll addmod(ll a, ll b) { return ((a % MOD) + (b % MOD)) % MOD; }
ll submod(ll a, ll b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }
ll mulmod(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }

ll powmod(ll base, ll exp) {
    if (!exp) return 1;
    if (exp % 2) return mulmod(powmod(mulmod(base, base), exp / 2), base);
    return powmod(mulmod(base, base), exp / 2);
}

ll invmod(ll x) {
    return powmod(x, MOD - 2);
}

void precompute(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; ++i)
        fact[i] = mulmod(fact[i - 1], i);
}

void process() {
    int n;
    cin >> n;
    vector<ll> arr(n + 5);
    for (int i = 0; i <= n; ++i)
        cin >> arr[i];

    for (int i = 1; i <= n; ++i) {
        if (arr[i] == 0) continue;
        if (arr[i] > n) {
            cout << 0 << nl;
            return;
        }
        if (arr[i] != -1) {
            if (arr[arr[i]] == i || arr[arr[i]] == -1)
                arr[arr[i]] = i;
            else {
                cout << 0 << nl;
                return;
            }
        }
    }

    int freeCount = 0;
    for (int i = 1; i < n; ++i)
        if (arr[i] == -1)
            ++freeCount;

    ll res = powmod(2, freeCount);

    for (int i = 1; i * 2 <= freeCount; ++i) {
        ll term = mulmod(powmod(2, freeCount - i * 2),
                         mulmod(mulmod(fact[freeCount],
                                       invmod(powmod(2, i) * fact[freeCount - i * 2])),
                                invmod(fact[i])));
        res = addmod(res, term);
    }

    if (arr[n] == -1) {
        res = addmod(res, mulmod(freeCount, powmod(2, freeCount - 1)));
        for (int i = 1; i * 2 + 1 <= freeCount; ++i) {
            ll term = mulmod(powmod(2, freeCount - i * 2 - 1),
                             mulmod(mulmod(fact[freeCount],
                                           invmod(powmod(2, i) * fact[freeCount - i * 2 - 1])),
                                    invmod(fact[i])));
            res = addmod(res, term);
        }
    }

    cout << res << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute(MAXN - 5);
    int tc = 1;
    cin >> tc;
    while (tc--) process();
    return 0;
}