t = int(input().strip())
results = []

for _ in range(t):
    n = int(input().strip())
    arr = list(map(int, input().split()))
    
    zeros = arr.count(0)
    ones = arr.count(1)
    rest_sum = sum(x for x in arr if x >= 2)
    
    total = zeros + ones + rest_sum
    results.append(total)

print("\n".join(map(str, results)))