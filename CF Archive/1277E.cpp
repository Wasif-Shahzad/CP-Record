//
// 1277E.cpp
// Created by wasifshahzad on 9/3/25 at 12:30:35.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        a--, b--;
        vector<vector<int>> g(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for (int i = 0; i < n; i++) {
            sort(g[i].begin(), g[i].end());
            g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
        }
        vector<int> par(n, -1), sub(n, 1), dp(n, 0), tin(n, 0);
        int timer = 0;
        auto dfs1 = [&] (int v, auto&& self) -> void {
            tin[v] = ++timer;
            for (int c: g[v]) {
                if (c == par[v]) continue;
                if (!tin[c]) {
                    par[c] = v;
                    self(c, self);
                    sub[v] += sub[c];
                } else if (tin[c] < tin[v]) {
                    dp[v]++;
                    dp[c]--;
                }
            }
        };
        dfs1(a, dfs1);
        vector<int> vis(n, 0);
        auto dfs2 = [&] (int v, auto&& self) -> void {
            vis[v] = 1;
            for (int c: g[v]) {
                if (par[c] == v && !vis[c]) {
                    self(c, self);
                    dp[v] += dp[c];
                }
            }
        };
        dfs2(a, dfs2);
        bool bad = false;
        int cur = b, path = 0;
        int subB = sub[b], subA;
        int lst = cur;
        while (cur != -1) {
            if (par[cur] != -1 && dp[cur] != 0) {
                bad = true;
                break;
            }
            path++;
            cur = par[cur];
            if (cur != a && cur != -1) lst = cur;
        }
        subA = n - sub[lst];
        const int ans = (subA - 1) * (subB - 1);
        cout << (bad ? 0 : ans) << '\n';
    }
}