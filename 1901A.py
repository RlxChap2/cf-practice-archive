R=lambda:map(int,input().split())
t,=R()
exec(t*'n,x=R();*a,=R();print(max(y-x for x,y in zip([0]+a,a+[2*x-a[-1]])));')