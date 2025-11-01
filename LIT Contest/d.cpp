//
// d.cpp
// Created by wasifshahzad on 8/23/25 at 14:30:16.
//

#include <bits/stdc++.h>
using namespace std;
// #define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const vector<int> dx = {1, 0, -1, 0};
    const vector<int> dy = {0, 1, 0, -1};
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m)), good(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    int a;
    cin >> a;
    vector<pair<int, int>> inp(a);
    vector<vector<int>> loc(n, vector<int>(m, -1));
    for (int i = 0; i < a; i++) {
        int x, y;
        cin >> x >> y;
        good[x - 1][y - 1] = 1;
        inp[i] = {x - 1, y - 1};
        loc[x - 1][y - 1] = i;
    }
    constexpr
    int oo = 1e9;
    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(a + 1, oo)));
    queue<array<int, 4>> q;
    // (i, j, mask, dist)
    for (int i = 0; i < a; i++) {
        auto [x, y] = inp[i];
        dist[x][y][1] = g[x][y];
        q.push({x, y, 1 << i, g[x][y]});
    }
    while (!q.empty()) {
        auto [i, j, mask, d] = q.front();
        int bits = __builtin_popcount(mask);
        q.pop();
        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k], nj = j + dy[k];
            if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
            if (abs(g[i][j] - g[ni][nj]) > 1) continue;
            int x = loc[ni][nj];
            int new_cost = max(d, g[ni][nj]);
            if (x == -1 || !good[ni][nj]) {
                if (new_cost < dist[ni][nj][bits]) {
                    dist[ni][nj][bits] = new_cost;
                    q.push({ni, nj, mask, new_cost});
                }
            } else {
                if (new_cost < dist[ni][nj][bits + 1]) {
                    dist[ni][nj][bits + 1] = new_cost;
                    q.push({ni, nj, mask | (1 << x), new_cost});
                }
            }
        }
    }
    vector<int> best(a + 1, oo);
    vector<pair<int, int>> ind(a + 1, {oo, oo});
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 1; k <= a; k++) {
                if (dist[i][j][k] < best[k]) {
                    best[k] = dist[i][j][k];
                    ind[k] = {i, j};
                }
            }
        }
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int c, v;
        cin >> c >> v;
        if (best[v] > c) {
            cout << "-1 -1\n";
        } else {
            auto [i, j] = ind[v];
            cout << i + 1 << " " << j + 1 << '\n';
        }
    }
}