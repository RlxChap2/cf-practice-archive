n,x=map(int,input().split());k=0
for i in' '*n:
 g=eval(input())
 j=x;x+=[0,g][x+g>=0]
 if x==j:k+=1
print(x,k)