def solve():
    t = int(input())
    
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        
        evens = [x for x in a if x % 2 == 0]
        if len(evens) >= 2:
            print(evens[0], evens[1])
            continue
        
        found = False
        for i in range(n):
            for j in range(i + 1, n):
                x, y = a[i], a[j]
                if (y % x) % 2 == 0:
                    print(x, y)
                    found = True
                    break
            if found:
                break
        
        if not found:
            print(-1)

solve()