from sys import stdin
input = stdin.readline

t = int(input())
for _ in range(t):
    u, v = map(int, input().strip().split())
    if u > v:
        print("No")
        continue
    bad = False
    msb = 0
    for k in range(30):
        if (1 << k) & v:
            msb = k
    has = 0
    inLine = False
    for k in range(30):
        if (1 << k) & u:
            has += 1
        if (1 << k) & v:
            if has > 0:
                has -= 1
                if k != msb:
                    inLine = True
            else:
                bad = True
                break
            if k == msb:
                if (1 << k) & u:
                    if inLine:
                        has = 0
                else:
                    has = 0
    if has > 0:
        bad = True
    print("Yes" if not bad else "No")
