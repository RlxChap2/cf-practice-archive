def solve(n,a):
    b = [0]*n
    total = 0
    for i in range(2):
        b[0]=i
        for k in range(1,n):
            b[k] = 1-b[k-1] -(a[k]-a[k-1])
        if 0<=min(b) and max(b) <= 1 and sum(b[1:])==a[0]-1:
            total+=1
    return total

g = int(input())
for _ in range(g):
    n = int(input())
    a = list(map(int,input().split()))
    print(solve(n,a))