R=lambda:map(int,input().split())
t,=R()
while t:
 t-=1;n,s,m=R();a=[0]
 while n:n-=1;a+=R()
 print('YNEOS'[all(y-x<s for x,y in zip(a[::2],a[1::2]+[m]))::2])