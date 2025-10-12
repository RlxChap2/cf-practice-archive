_=input
x,y=zip(*[_().split()for i in'_'*int(_())])
print(sum(x.count(i)for i in y))