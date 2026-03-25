t = int(input())
for _ in range(t):
    n, d = map(int, input().split())
    print(f"Case {_ + 1}: ", end="")
    cur = 1
    num = 0
    while True:
        num += 10**(cur - 1) * d
        num %= n
        if num == 0:
            print(cur)
            break
        cur += 1
