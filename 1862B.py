for s in[*open(0)][2::2]:
 *a,=map(int,s.split());r=[]
 for x,y in zip([0]+a,a):r+=[y]*-~(x>y)
 print(len(r),*r)