def solve(n):
    total = 0
    while n >= 3:
        m1 = n // 3
        total += m1
        n = n - 2 * m1
    
    return total

t = int(input())
for _ in range(t):
    n = int(input())
    print(solve(n))