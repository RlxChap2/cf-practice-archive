for _ in[0]*int(input()):print(sum(min(i,9-i,j,9-j)+1for
i in range(10)for j,x in enumerate(input())if'.'<x))