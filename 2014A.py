R=lambda:map(int,input().split())
t,=R()
while t:
 t-=1;n,k=R();g=r=0
 for x in R():g+=x*(x>=k);d=x==0<g;g-=d;r+=d
 print(r)