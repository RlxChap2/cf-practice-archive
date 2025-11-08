def solve():
    T = int(input())
    
    for _ in range(T):
        n = int(input())
        a = list(map(int, input().split()))
        x = int(input())
        
        min_val = min(a)
        max_val = max(a)
        
        if min_val <= x <= max_val:
            print("YES")
        else:
            print("NO")

solve()