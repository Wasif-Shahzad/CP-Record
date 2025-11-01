//
// g.cpp
// Created by wasifshahzad on 9/7/25 at 21:06:25.
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
        int n, m, q;
        cin >> n >> m >> q;
        vector<vector<int>> adj(n);
        vector<int> out(n, 0);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[v].push_back(u);
            out[u]++;
        }
        vector<vector<int>> ans(n, vector<int>(2, 0));
        auto dfs = [&] (int v, bool flag, auto&& self) -> void {
            ans[v][flag] = 1;
            for (int c: adj[v]) {
                if (ans[c][!flag] != 0) continue;
                if(!flag) self(c, true, self);
                else {
                    if(out[c] == 1) self(c, false, self);
                    out[c]--;
                }
            }
        };
        while (q--) {
            int x, v;
            cin >> x >> v;
            v--;
            if (x == 1) {
                dfs(v, 0, dfs);
                dfs(v, 1, dfs);
            } else {
                cout << (ans[v][0] == 0 ? "YES" : "NO") << "\n";
            }
        }
    }
}