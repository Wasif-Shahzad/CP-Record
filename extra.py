t = int(input())
ans = []
for _ in range(t):
    n, m = map(int, input().split())
    x = input()
    s = input()
    ops = 0
    while len(x) < len(s):
        x += x
        ops += 1
    if s in x:
        ans.append(ops)
    else:
        x += x
        ops += 1
        if s in x:
            ans.append(ops)
        else:
            ans.append(-1)

for d in ans:
    print(d)