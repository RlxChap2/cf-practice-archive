for s in[*open(0)][1:]:
  n,k=map(int,s.split());m=n*n-k;print('YNEOS'[m==1::2])
  for i in range(n*(m!=1)):
   j=len(s:='RL'*(i<1<m));m-=j
   while(j:=j+1)<=n:s+=('R','LU'[i>0])[m>0];m-=1
   print(s)