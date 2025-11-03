for x,y,_ in[*open(0)][1:]:print(*{u+y for
u in'abcdefgh'}^{x+u for u in'12345678'})