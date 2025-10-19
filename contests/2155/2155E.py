for _ in range(int(input())):
    n, m, k = map(int, input().split())
    changes = {}

    for _ in range(k):
        x, y = map(int, input().split())
        changes[y] = changes.get(y, 0) ^ 1

    winner_mimo = False

    if n == 1:
        winner_mimo = changes.get(2, 0) & 1
    else:
        for col, val in changes.items():
            if col >= 2 and val & 1:
                winner_mimo = True
                break

    print("Mimo" if winner_mimo else "Yuyu")
