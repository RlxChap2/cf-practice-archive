for _ in range(int(input())):
    n, k = map(int, input().split())
    s = input()

    cnt0 = s.count('0')
    cnt1 = s.count('1')
    cnt2 = s.count('2')

    if cnt0 + cnt1 + cnt2 == n:
        print('-' * n)
        continue

    left_side = cnt0 + cnt2
    right_side = n - (cnt1 + cnt2)

    if left_side <= right_side:
        print('-' * cnt0 + '?' * cnt2 + '+' * (right_side - left_side) + '?' * cnt2 + '-' * cnt1)
    else:
        print('-' * cnt0 + '?' * (cnt2 * 2 + right_side - left_side) + '-' * cnt1)
