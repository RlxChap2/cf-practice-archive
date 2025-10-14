R=lambda:map(int,input().split())
t,=R()
exec(t*"n,k=R();*a,=R();print('YNEOS'[a>sorted(a)and k<2::2]);")