#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 10000005;
const int INF = 1000000000;

static unsigned char is_prime_arr[MAXN];

inline int calc_vp(int p, int x) {
    int res = 0;
    long long pw = p;
    while (pw <= x) {
        res += x / pw;
        pw *= p;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int LIMIT = MAXN - 1;
    for (int i = 2; i <= LIMIT; ++i) is_prime_arr[i] = 1;
    vector<int> small_primes;
    for (int p = 2; (long long)p * p <= LIMIT; ++p) {
        if (!is_prime_arr[p]) continue;
        small_primes.push_back(p);
        for (long long j = 1LL * p * p; j <= LIMIT; j += p) is_prime_arr[j] = 0;
    }
    for (int p = (int)sqrt(LIMIT) + 1; p <= LIMIT; ++p) if (is_prime_arr[p]) small_primes.push_back(p);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, m;
        cin >> n >> m;

        int q = n;
        while (q >= 2 && !is_prime_arr[q]) --q;

        vector<int> useful_primes;
        int f = 1;
        while ((long long)f * f <= n) {
            int p_bnd = n / f;
            int p = p_bnd;
            while (p >= 2 && !is_prime_arr[p]) --p;
            if (p >= 2) useful_primes.push_back(p);
            ++f;
        }
        sort(useful_primes.begin(), useful_primes.end());
        useful_primes.erase(unique(useful_primes.begin(), useful_primes.end()), useful_primes.end());

        ll ans = 0;

        for (int x = q; x < n; ++x) {
            int best = INF;

            for (int p : useful_primes) {
                int vx = calc_vp(p, x);
                int vn = calc_vp(p, n);
                if (vx != vn) {
                    if (vx < best) best = vx;
                    if (best == 0) break;
                }
            }
            if (best == 0) { ans += 0; continue; }

            for (int p : small_primes) {
                if (1LL * p * p > m) break;
                int base_vx = calc_vp(p, x);
                int base_vn = calc_vp(p, n);
                if (base_vx == base_vn) continue;
                long long pw = p;
                int exp = 1;
                while (pw <= m) {
                    int vx = base_vx / exp;
                    int vn = base_vn / exp;
                    if (vx != vn) {
                        if (vx < best) best = vx;
                        if (best == 0) break;
                    }
                    ++exp;
                    pw *= p;
                }
                if (best == 0) break;
            }
            if (best == INF) best = 0;

            ans += best;
        }

        cout << ans << '\n';
    }

    return 0;
}
