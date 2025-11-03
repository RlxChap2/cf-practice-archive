for s in[*open(0)][2::2]:
 p,*a=map(int,s.split());d={p:0};f=0
 for x in a:f|=d.get(x-1,1)&d.get(x+1,1);d[x]=0
 print('YNEOS'[f::2])