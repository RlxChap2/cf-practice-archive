for _ in range(int(input())):
    size = int(input())

    if size == 2:
        print(-1)

    elif size == 3:
        print(1, 3)
        print(2, 3)

    elif size == 4:
        print(1, 2)
        print(1, 3)
        print(1, 4)

    else:
        print(1, 2)
        print(2, 3)
        print(3, 4)
        print(1, size)
        for node in range(5, size):
            print(2, node)
