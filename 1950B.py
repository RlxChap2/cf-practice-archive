for n in[*open(0)][1:]:
 for i in range(n:=int(n)*2):j=i//2%2*2;print(('##..'*n)[j:j+n])