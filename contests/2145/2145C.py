import sys

data = sys.stdin.read().split()[2::2]

for s in data:
    t = 0
    arr = [t := t + 195 - 2 * ord(ch) for ch in s.strip()]
    n = len(arr)
    m = n
    d = {0: 0}
    i = 0

    for x in arr:
        i += 1
        m = min(m, i - d.get(x - arr[-1], -m))
        d[x] = i

    print(arr[-1] and (m % n or -1))
