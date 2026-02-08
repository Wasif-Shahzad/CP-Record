t = int(input())
for _ in range(t):
    N = 2 * 10 ** 5
    freq = [0] * (N + 1) 
    pref = [0] * (N + 1)
    n, y = map(int, input().strip().split())
    a = list(map(int, input().strip().split()))
    for i in a: 
        freq[i] += 1
    for i in range(1, N + 1):
        pref[i] += pref[i - 1] + freq[i]
    ans = -float('inf')
    for x in range(2, N + 1):
        k = 1
        cur = 0
        while True:
            l, r = (k - 1) * x, k * x
            if l > N:
                break
            if r > N:
                cnt = pref[N] - pref[l]
            else:
                cnt = pref[r] - pref[l]
            here = freq[k]
            cur += k * cnt
            cur -= max(0, (cnt - here) * y)
            k += 1
        ans = max(ans, cur)
    print(ans)    
