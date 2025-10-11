n = input()

count_lucky = sum(1 for c in n if c in '47')

def is_lucky(num):
    return num != 0 and all(ch in '47' for ch in str(num))

print("YES" if is_lucky(count_lucky) else "NO")
