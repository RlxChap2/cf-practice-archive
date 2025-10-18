R = range

n, m, k = map(int, open(0).read().split())
MOD = 998244353
total = n + m
K = k - 1

fact = [1]
for i in R(1, total + 1):
    fact.append(fact[-1] * i % MOD)

inv_fact = [0] * (total + 1)
inv_fact[total] = pow(fact[total], -1, MOD)
for i in R(total, 0, -1):
    inv_fact[i - 1] = inv_fact[i] * i % MOD

S = [1] + [0] * K
T = [int(K < 1)] + [0] * (total - 1)
h = fact[K]

for d in R(1, total):
    for t in R(min(d, K), -1, -1):
        S[t] = (S[t - 1] + t * S[t]) % MOD
    S[0] = 0
    T[d] = h * S[K] % MOD if d >= K else 0

C_n = [fact[n] * inv_fact[i] % MOD * inv_fact[n - i] % MOD for i in R(n)]
C_m = [fact[m] * inv_fact[i] % MOD * inv_fact[m - i] % MOD for i in R(m)]

ans = [0] * total
for i in R(n):
    for j in R(m):
        idx = max(n - i, m - j)
        ans[idx] = (ans[idx] + C_n[i] * C_m[j] % MOD * T[i + j]) % MOD

print(*ans[total - min(n, m):0:-1])
