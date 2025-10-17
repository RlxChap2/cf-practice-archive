c=m=s=0
for i in map(int,[*open(0)][1].split()):c=[c+1,1][i<=s];m=max(m,c);s=i
print(m)