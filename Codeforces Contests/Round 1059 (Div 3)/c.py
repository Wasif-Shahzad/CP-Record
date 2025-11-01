# 100100100
t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    ans = []
    bad = False
    for i in range(30, -1, -1):
        if (1 << i) & b:
            if (1 << i) & a:
                continue
            if (1 << i) <= a:
                ans.append(1 << i)
                a ^= (1 << i)
            else:
                bad = True
                break
    for i in range(30, -1, -1):
        if not (1 << i) & b:
            if (1 << i) & a:
                ans.append(1 << i)

    if bad:
        print(-1)
    else:
        print(len(ans))    
        for x in ans:
            print(x, end=" ")
        if(len(ans)):
            print()