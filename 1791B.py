d={'L':-1,'R':1,'U':1001,'D':-1001}
for s in[*open(0)][2::2]:
 r=f=0
 for x in s[:-1]:r+=d[x];f|=r==1002
 print('NYOE S'[f::2])