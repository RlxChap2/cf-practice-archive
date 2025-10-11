shoes = list(map(int, input().split()))
unique_colors = len(set(shoes))
print(4 - unique_colors)