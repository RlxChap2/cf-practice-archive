import sys

def ask(t, a, b):
    print(t, a, b)
    sys.stdout.flush()
    return int(input())

def main():
    T = int(input())
    for _ in range(T):
        n = int(input())

        total_a = ask(1, 1, n)
        total_b = ask(2, 1, n)
        diff = total_b - total_a

        left, right = 1, n
        first = -1

        while left <= right:
            mid = (left + right) // 2
            sum_a = ask(1, 1, mid)
            sum_b = ask(2, 1, mid)

            if sum_b - sum_a > 0:
                first = mid
                right = mid - 1
            else:
                left = mid + 1

        end = first + diff - 1
        print("!", first, end)
        sys.stdout.flush()

if __name__ == "__main__":
    main()
