def solve():
    n, k, x = map(int, input().split())
    friends = list(map(int, input().split()))
    
    friends.sort()
    
    if k >= n:
        result = list(friends)
        pos = 0
        while len(result) < k:
            if pos not in result and pos <= x:
                result.append(pos)
            pos += 1
        print(*result[:k])
        return
    
    def check(min_dist):
        teleports = []
        i = 0
        
        while i < n:
            pos = min(friends[i] + min_dist, x)
            
            if not teleports:
                pos = friends[i] + min_dist
                if pos > x:
                    return False
            else:
                if abs(friends[i] - teleports[-1]) <= min_dist:
                    i += 1
                    continue
                pos = friends[i] + min_dist
                if pos > x:
                    pos = x
                if abs(friends[i] - pos) > min_dist:
                    return False
            
            teleports.append(pos)
            if len(teleports) > k:
                return False
            
            while i < n and abs(friends[i] - pos) <= min_dist:
                i += 1
        
        return len(teleports) <= k
    
    lo, hi = 0, x
    ans = 0
    
    while lo <= hi:
        mid = (lo + hi) // 2
        if check(mid):
            ans = mid
            lo = mid + 1
        else:
            hi = mid - 1
    
    teleports = []
    i = 0
    while i < n:
        if teleports and abs(friends[i] - teleports[-1]) <= ans:
            i += 1
            continue
        pos = min(friends[i] + ans, x)
        teleports.append(pos)
        while i < n and abs(friends[i] - pos) <= ans:
            i += 1
    
    while len(teleports) < k:
        pos = 0
        while pos in teleports and pos <= x:
            pos += 1
        if pos <= x:
            teleports.append(pos)
        else:
            break
    
    print(*teleports[:k])

t = int(input())
for _ in range(t):
    solve()