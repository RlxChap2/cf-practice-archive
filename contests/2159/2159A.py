for _ in range(int(input())):
    size = int(input()) * 2

    current = [1]
    result = [-1] * size
    used = []

    for val in range(2, size + 1):
        current.append(val)
        print("?", len(current), *current)
        resp = int(input())

        if resp != 0:
            result[val - 1] = resp
            current.pop()
            used.append(val)

    for val in range(1, size + 1):
        if val in used:
            continue
        used.append(val)
        print("?", len(used), *used)
        resp = int(input())
        result[val - 1] = resp
        used.pop()

    print("!", *result)
