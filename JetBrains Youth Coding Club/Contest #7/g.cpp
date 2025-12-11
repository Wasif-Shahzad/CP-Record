//
// g.cpp
// Created by Wasif on 11/24/25 at 21:17:09.
//

#include <bits/stdc++.h>
using namespace std;
// #define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<vector<int>> up(n, vector<int>(21, n - 1));
    vector<int> order, take(n, 0), depth(n, 0);
    auto dfs = [&] (int v, int p, auto&& self) -> void {
        order.push_back(v);
        for(int c: g[v]) {
            if(c == p) continue;
            up[c][0] = v;
            depth[c] = depth[v] + 1;
            self(c, v, self);
        }
    };
    dfs(n - 1, -1, dfs);

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < 21; j++) {
            int prev = up[order[i]][j - 1];
            up[order[i]][j] = up[prev][j - 1];
        }
    }

    take[n - 1] = 1;
    int rem = n - k - 1;
    for(int i = n - 2; i >= 0 && rem > 0; i--) {
        if(take[i]) continue;
        // get distance to first colored ancestor
        int v = i;
        for(int j = 20; j >= 0; j--) {
            if(!take[up[v][j]]) v = up[v][j];
        }
        int dist = depth[i] - depth[v] + 1;
        if(dist <= rem) {
            rem -= dist;
            v = i;
            while(!take[v]) {
                take[v] = 1;
                v = up[v][0];
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(!take[i]) cout << i + 1 << " ";
    }
    cout << '\n';
}