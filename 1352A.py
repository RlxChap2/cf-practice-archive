for s in[*open(0)][1:]:a=[c+i*'0'for i,c in
enumerate(s[-2::-1])if'0'<c];print(len(a),*a)