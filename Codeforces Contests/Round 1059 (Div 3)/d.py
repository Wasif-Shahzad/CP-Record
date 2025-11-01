def ask(r, type):
    print(f"{type} 1 {r}", flush=True)
    resp = int(input())
    return resp

t = int(input())

for _ in range(t):
    n = int(input())
    l, r = 0, n + 1
    c1, c2 = [-1] * (n + 2), [-1] * (n + 2)
    while r > l + 1:
        mid = (l + r) // 2
        resp = ask(mid, 1)
        resp2 = ask(mid, 2)
        if resp != resp2:
            l = mid
        else:
            r = mid
        c1[mid] = resp
        c2[mid] = resp2
    
    R = l
    l, r = 0, R

    while r > l + 1:
        mid = (l + r) // 2
        if c1[mid]:
            resp = c1[mid]
            resp2 = c2[mid]
        else:
            resp = ask(mid, 1)
            resp2 = ask(mid, 2)
        if(resp == resp2):
            l = mid
        else:
            r = mid

    L = l + 1
    print(f"! {L} {R}", flush=True)