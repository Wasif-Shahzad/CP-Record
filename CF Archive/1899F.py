t = int(input())
for _ in range(t):
    n, q = map(int, input().split())
    arr = [int(input()) for _ in range(q)]
    u, v1, v2 = n, 1, n - 1
    for i in range(2, n):
        print(i - 1, i)
    print(1, n)
    for d in arr:
        p = v2 - d + 1
        if p == v1:
            print("-1 -1 -1")
        else:
            print(u, v1, p)
            v1 = p
