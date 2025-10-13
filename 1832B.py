import sys

def compute_max_sum():
    data = list(map(int, sys.stdin.buffer.read().split()))
    
    t = data[0]
    idx = 1
    results = []

    for _ in range(t):
        n = data[idx]; idx += 1
        k = data[idx]; idx += 1
        arr = data[idx:idx + n]; idx += n

        arr.sort()
        prefix = [0]
        for val in arr:
            prefix.append(prefix[-1] + val)

        best = 0
        for take in range(k + 1):
            total = prefix[n - (k - take)] - prefix[2 * take]
            best = max(best, total)
        results.append(str(best))

    sys.stdout.write("\n".join(results))


if __name__ == "__main__":
    compute_max_sum()