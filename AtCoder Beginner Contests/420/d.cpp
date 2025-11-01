//
// d.cpp
// Created by wasifshahzad on 8/26/25 at 09:16:54.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    const int oo = 1e9;
    vector<vector<array<int, 2>>> dist(h, vector<array<int, 2>>(w, {oo, oo}));
    pair<int, int> s, e;
    for (int i = 0; i < h; i++) {
        cin >> a[i];
        for (int j = 0; j < w; j++) {
            if (a[i][j] == 'S') {
                s = {i, j};
                dist[i][j][0] = 0;
            }
            if (a[i][j] == 'G') {
                e = {i, j};
            }
        }
    }
    const vector<int> dx = {1, 0, -1, 0};
    const vector<int> dy = {0, 1, 0, -1};
    queue<array<int, 4>> q;
    q.push({s.first, s.second, 0, 0});
    while (!q.empty()) {
        auto [i, j, d, flag] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k], nj = j + dy[k];
            if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
            if (a[ni][nj] == '#') continue;
            if (flag && a[ni][nj] == 'o') continue;
            if (!flag && a[ni][nj] == 'x') continue;
            if (d + 1 < dist[ni][nj][flag]) {
                dist[ni][nj][flag] = d + 1;
                if (a[ni][nj] == '?') {
                    q.push({ni, nj, d + 1, !flag});
                } else {
                    q.push({ni, nj, d + 1, flag});
                }
            }
        }
    }
    const int ans = min(dist[e.first][e.second][0], dist[e.first][e.second][1]);
    cout << (ans == oo ? -1 : ans) << '\n';
}