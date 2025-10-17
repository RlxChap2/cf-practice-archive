R=lambda:[*map(int,input().split())]
exec(R()[0]*'print(max((y,i)for i,(x,y)in zip(range(R()[0]),iter(R,0))if x<11)[1]+1);')