y = int(input())

def distinct(year):
    s = str(year)
    return len(set(s)) == len(s)

while True:
    y += 1
    if distinct(y):
        print(y)
        break
