for _ in range(int(input())):
    n, limit = map(int, input().split())
    nums = list(map(int, input().split()))

    position = [0] * (n + 1)
    for i in range(n):
        position[nums[i]] = i + 1

    order = sorted(range(1, n + 1), key=lambda val: position[val])
    print(*order[:limit])
