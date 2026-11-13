t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    f = [0] * n
    for i in a: f[i - 1] = 1
    missing = n - sum(f)
    if missing == 0:
        for i in range(k):
            print(a[i], end=' ')
        print()
        continue
    f3 = []
    if missing == 1:
        x = next(i + 1 for i, x in enumerate(f) if x == 0)
        y = next(x for x in a if x != a[-1])
        z = a[-1]
        f3 = [x, y, z]
    elif missing == 2:
        x, y = (i + 1 for i, x in enumerate(f) if x == 0)
        z = a[-1]
        f3 = [x, y, z]
    else:
        f3 = [i + 1 for i, x in enumerate(f) if x == 0][:3]
    for i in range(k // 3):
        print(*f3, end=' ')
    for i in range(k % 3):
        print(f3[i], end=' ')
    print()
