//
// extra.cpp
// Created by Wasif on 09/10/25 at 18:15:46.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<int> dx = {0, -1, -1, -1, 0, 1, 1, 1};
vector<int> dy = {1, 1, 0, -1, -1, -1, 0, 1};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for(int i = 0; i < n; i++)
        cin >> g[i];

    vector<vector<int>> vis(n, vector<int>(m, 0));
    auto dfs = [&] (int i, int j, auto&& self) -> void{
        vis[i][j] = 1;
        for(int k = 0; k < 8; k++) {
            int ni = i + dx[k], nj = j + dy[k];
            if(ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
            if(g[ni][nj] == '.') continue;
            if(vis[ni][nj]) continue;
            self(ni, nj, self);
        }
    };
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(g[i][j] == '.') continue;
            if(vis[i][j]) continue;
            ans++;
            dfs(i, j, dfs);
        }
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    
}   