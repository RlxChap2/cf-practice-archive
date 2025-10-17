c=97;s=0
for x in map(ord,input()):i=abs(c-x);s+=min(i,26-i);c=x
print(s)