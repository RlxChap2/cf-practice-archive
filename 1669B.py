from collections import*
for s in[*open(0)][2::2]:k,v=Counter(s.split()).most_common()[0];print((k,-1)[v<3])