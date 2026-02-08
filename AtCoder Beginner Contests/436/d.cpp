//
// d.cpp
// Created by wasifshahzad on 12/13/25 at 17:30:11.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    vector<vector<pair<int, int>>> coords(26);
    for(int i = 0; i < h; i++) {
        cin >> g[i];
        for(int j = 0; j < w; j++) {
            if(g[i][j] == '.') continue;
            if(g[i][j] == '#') continue;
            coords[g[i][j] - 'a'].push_back({i, j});
        }
    }
    vector<vector<int>> dist(h, vector<int>(w, 1e9));
    vector<int> vis(26, 0);
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 0;
    while(q.size()) {
        auto [i, j] = q.front();
        q.pop();
        if(g[i][j] != '.' && !vis[g[i][j] - 'a']) {
            for(auto [ni, nj]: coords[g[i][j] - 'a']) {
                if(dist[ni][nj] > dist[i][j] + 1) {
                    dist[ni][nj] = dist[i][j] + 1;
                    q.push({ni, nj});
                }
            }
            vis[g[i][j] - 'a'] = 1;
        }
        for(int k = 0; k < 4; k++) {
            int ni = i + dx[k], nj = j + dy[k];
            if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
            if(g[ni][nj] == '#') continue;
            if(dist[ni][nj] > dist[i][j] + 1) {
                dist[ni][nj] = dist[i][j] + 1;
                q.push({ni, nj});
            }
        }
    }
    cout << (dist[h - 1][w - 1] == 1e9 ? -1 : dist[h - 1][w - 1]) << '\n';
}