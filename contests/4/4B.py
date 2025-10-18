P=print;x=lambda:[*map(int,input().split())];d,h=x();a=[x()for _ in[0]*(d)];p=q=0
for i,j in a:p+=i;q+=j
d=h-p;o=[]
for f,s in a:
	if d>0:m=min(d,s-f);d-=m;f+=m
	o+=[f]
if p<=h<=q:P("YES\n",*o)
else:P("NO")