from collections import deque

n, m = map(int, input().split())
s = [input() for _ in range(n)]
oo = 10 ** 9
dist = [[oo] * m for _ in range(n)]
q = deque()
q.append([0, 0])
dist[0][0] = 0
while q:
    x, y = q.popleft()
    if x + 1 < n and s[x + 1][y] != '#':
        if dist[x + 1][y] == oo:
            dist[x + 1][y] = dist[x][y] + 1
            q.append([x + 1, y])
    if y + 1 < m and s[x][y + 1] != '#':
        if dist[x][y + 1] == oo:
            dist[x][y + 1] = dist[x][y] + 1
            q.append([x, y + 1])

if dist[n - 1][m - 1] == oo:
    print(0)
else:
    dist2 = [[oo] * m for _ in range(n)]
    q.append([n - 1, m - 1])
    dist[n - 1][m - 1] = 0
    while q:
        x, y = q.popleft()
        if x - 1 >= 0 and s[x - 1][y] != '#':
            if dist2[x - 1][y] == oo:
                dist2[x - 1][y] = dist2[x][y] + 1
                q.append([x - 1, y])
        if y - 1 >= 0 and s[x][y - 1] != '#':
            if dist2[x][y - 1] == oo:
                dist2[x][y - 1] = dist2[x][y] + 1
                q.append([x, y - 1])

    cnt = [0] * (n + m + 1)
    for i in range(n):
        for j in range(m):
            if dist[i][j] == oo or dist2[i][j] == oo: continue
            cnt[dist[i][j]] += 1
    ans = 2
    for i in range(1, n + m + 1):
        if cnt[i] == 1:
            ans = 1
            break

    print(ans)