import sys, math
input = sys.stdin.readline

for _ in range(int(input())):
    n, m = map(int, input().split())
    arr_a = list(map(int, input().split()))
    arr_b = list(map(int, input().split()))
    
    lcm_val = 1
    for val in arr_a:
        lcm_val = lcm_val * val // math.gcd(lcm_val, val)
    
    step = 0
    count = 0
    seen = {}
    
    while step < m:
        idx = count % len(arr_a)
        key = (idx, step % lcm_val)
        
        if key in seen:
            cycle_len = step - seen[key][1]
            if cycle_len == 0:
                print(-1)
                break
            num_cycles = (m - step - 1) // cycle_len
            if num_cycles > 0:
                count += num_cycles * (count - seen[key][0])
                step += num_cycles * cycle_len
                seen.clear()
                continue
        
        seen[key] = (count, step)
        step += (step + 1) % arr_a[idx] != arr_b[idx]
        count += 1
    else:
        print(count)
