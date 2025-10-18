def main():
    import sys
    data = list(map(int, sys.stdin.read().split()))
    it = iter(data)
    T = next(it)

    for _ in range(T):
        n = next(it)
        m = next(it)

        freq = [0] * (n + 1)
        for _ in range(n):
            val = next(it)
            freq[val] += 1

        limits = list(range(n + 1))
        for _ in range(m):
            l, r = next(it), next(it)
            limits[r] = min(limits[r], l)

        for i in range(n - 1, 0, -1):
            limits[i] = min(limits[i], limits[i + 1])

        dp = [[0]]
        prev_c = prev_d = [-10**9] * (n + 1)

        for i in range(1, n + 1):
            start = limits[i] - 1
            base = dp[start]
            curr_c = [-10**9] * (i + 1)
            curr_d = curr_c.copy()

            for j in range(limits[i]):
                curr_c[j + 1] = max(curr_c[j + 1], base[j])
                curr_d[j] = max(curr_d[j], base[j] + 1)

            for j in range(i):
                curr_c[j + 1] = max(curr_c[j + 1], prev_c[j])
                curr_d[j] = max(curr_d[j], prev_d[j] + 1)

            dp.append([max(a, b) for a, b in zip(curr_c, curr_d)])
            prev_c, prev_d = curr_c, curr_d

        u = 0
        res = []
        for k in freq[1:]:
            u += k
            res.append('1' if dp[n][u - k] >= n - u else '0')

        print(''.join(res))


if __name__ == "__main__":
    main()
