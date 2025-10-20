for s in[*open(0)][1:]:
 a,b,n=map(int,s.split());i=0
 while b<=n:a,b=max(a,b),a+b;i+=1
 print(i)