def solve():
    t = int(input())
    for _ in range(t):
        n, X = map(int, input().split())
        prices = list(map(int, input().split()))
        
        total_sum = sum(prices)
        max_loyalty = total_sum // X
        
        if max_loyalty == 0:
            print(0)
            print(*prices)
            continue
        
        sorted_prices = sorted(prices)
        
        bonus = 0
        result = []
        current_sum = 0
        available = sorted_prices[:]
        
        for level in range(1, max_loyalty + 1):
            threshold = level * X
            
            if not available:
                break
            
            crossing_item = available.pop()
            
            while available and current_sum + available[0] < threshold:
                item = available.pop(0)
                result.append(item)
                current_sum += item
            
            result.append(crossing_item)
            old_sum = current_sum
            current_sum += crossing_item
            
            if old_sum < threshold <= current_sum:
                bonus += crossing_item
        
        result.extend(available)
        
        print(bonus)
        print(*result)

solve()