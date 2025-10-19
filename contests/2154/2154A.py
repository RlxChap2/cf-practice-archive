t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    s = input()
    protected = [False] * n
    last1 = -k

    count = 0
    for i in range(n):
        if s[i] == '1':
            if i - last1 >= k:
                count += 1
                last1 = i
            else:
                last1 = i
    print(count)
