# Python 2
I = input
x = map(I, ' ' * 4)
print(sum(any(i % j < 1 for j in x) for i in range(-I(), 0)))