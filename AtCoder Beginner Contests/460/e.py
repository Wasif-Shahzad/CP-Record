from math import gcd
MOD = 998244353
t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    x, y = n // m, 0
    length = len(str(n))
    ans = 0
    for i in range(1, length + 1):
        l, r = 10 ** (i - 1), 10 ** (i) - 1
        den = gcd(m, r)
        M = m // den
        ans += (min(r, n) - l + 1) * (n // M)
        ans %= MOD
    print(ans)