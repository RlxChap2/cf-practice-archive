#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1000000 + 10;
const int BLOCK = 1000;
const int MOD = 1000000007LL;

int Xval, Yval, Zval;
int tmpArr[MAXN];
int answer;

vector<int> smallDP[BLOCK + 10];
vector<int> blockDP[BLOCK + 10];
int invArr[MAXN];

inline void inc(int &x, int y) {
    x = (x + y) % MOD;
}

int modPow(int base, int exp) {
    int res = 1;
    while (exp) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> Xval >> Yval >> Zval;

    smallDP[0].push_back(1);
    for (int i = 0; i < BLOCK; ++i) {
        smallDP[i + 1].resize((i + 1) * 2 + 1);
        for (int j = 0; j <= i * 2; ++j) {
            // multiply by Z (stay), by Y (shift +1), by X (shift +2)
            inc(smallDP[i + 1][j], (int)(smallDP[i][j] * Zval % MOD));
            inc(smallDP[i + 1][j + 1], (int)(smallDP[i][j] * Yval % MOD));
            inc(smallDP[i + 1][j + 2], (int)(smallDP[i][j] * Xval % MOD));
        }
    }

    int invZ = modPow(Zval, MOD - 2);
    invArr[1] = 1;
    for (int i = 2; i <= 700000; ++i)
        invArr[i] = (MOD - MOD / i) * invArr[MOD % i] % MOD;

    for (int blk = 0; blk <= 300; ++blk) {
        int len = blk * BLOCK * 2;
        int mult = blk * BLOCK;
        blockDP[blk].assign(len + 1, 0);

        blockDP[blk][0] = modPow(Zval, mult);
        for (int j = 1; j <= len; ++j) {
            long long cur = 0;
            cur = (cur + (long long)Yval * blockDP[blk][j - 1]) % MOD;
            if (j > 1) cur = (cur + (long long)Xval * blockDP[blk][j - 2] % MOD * 2) % MOD;

            cur = cur * (long long)mult % MOD;

            cur = (cur + MOD - (long long)Yval * blockDP[blk][j - 1] % MOD * (j - 1) % MOD) % MOD;
            if (j > 1) cur = (cur + MOD - (long long)Xval * blockDP[blk][j - 2] % MOD * (j - 2) % MOD) % MOD;

            blockDP[blk][j] = (long long)cur * invZ % MOD * invArr[j] % MOD;
        }
        for (int j = 1; j <= len; ++j) inc(blockDP[blk][j], blockDP[blk][j - 1]);
    }

    int Q;
    cin >> Q;
    int last = 0;
    while (Q--) {
        int n, k;
        cin >> n >> k;
        n ^= last; k ^= last;

        int big = n / BLOCK;
        int rem = n % BLOCK;
        int remLen = rem * 2;
        int bigLen = big * BLOCK * 2;

        int res = 0;
        for (int i = 0; i <= remLen && i <= k; ++i) {
            int takeFromBig = min(bigLen, k - i);
            if (takeFromBig < 0) break;
            int valSmall = smallDP[rem][i];
            int valBig = blockDP[big][takeFromBig];
            inc(res, (int)( (long long)valSmall * valBig % MOD ));
        }

        last = res;
        cout << res << '\n';
    }

    return 0;
}
