def solve(n, s, a):
    if a == 0:
        return 0
    
    seconds = 0
    pos = 0
    
    while a > 0:
        start_a = a
        cycle_steps = 0
        
        for i in range(n):
            if s[(pos + i) % n] == 'A':
                a -= 1
            else:
                a //= 2
            
            cycle_steps += 1
            
            if a <= 0:
                return seconds + cycle_steps
        
        reduction = start_a - a
        
        if reduction > 0 and a > n:
            full_cycles_to_skip = (a - n) // reduction
            
            if full_cycles_to_skip > 0:
                a -= full_cycles_to_skip * reduction
                seconds += full_cycles_to_skip * n
        
        seconds += n
    
    return seconds

t = int(input())
for _ in range(t):
    n, q = map(int, input().split())
    s = input().strip()
    queries = list(map(int, input().split()))
    
    results = []
    for a in queries:
        result = solve(n, s, a)
        results.append(result)
    
    for r in results:
        print(r)