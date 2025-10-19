def ask(a: int, b: int) -> int:
    print(a, b, flush=True)
    return int(input())


def solve():
    n = int(input())
    for x in range(1, n):
        for y in range(1, n - x + 1):
            response = ask(y, x + y)
            if response == 1:
                return


def main():
    t = int(input())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
