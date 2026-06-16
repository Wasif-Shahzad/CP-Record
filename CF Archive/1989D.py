n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))

A = max(a)
bst = [10 ** 7] * (A + 1)
for i in range(n):
    bst[a[i]] = min(bst[a[i]], a[i] - b[i])
for i in range(1, A + 1):
    bst[i] = min(bst[i - 1], bst[i])

dp = [0] * (A + 1)
for i in range(1, A + 1):
    if i - bst[i] >= 0: dp[i] = 2 + dp[i - bst[i]]

ans = 0
for i in c:
    if i > A:
        k = (i - A + bst[A] - 1) // bst[A]
        ans += 2 * k
        i -= bst[A] * k
    ans += dp[i]
print(ans)
