//
// c.cpp
// Created by Wasif on 09/17/25 at 19:29:35.
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
    while(T--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        for(int i = 1; i < n; i++) {
            int u, v, x, y;
            cin >> u >> v >> x >> y;
            u--, v--;
            if(x > y) g[u].push_back(v);
            else g[v].push_back(u);
        }
        vector<int> ans(n, 0), vis(n, 0);
        vector<int> order;
        auto dfs = [&] (int v, auto&& self) -> void{
            vis[v] = 1;
            for(int c: g[v]) {
                if(vis[c]) continue;
                self(c, self);
            }
            order.push_back(v);
        };
        for(int i = 0; i < n; i++) {
            if(!vis[i]) dfs(i, dfs);
        }
        reverse(order.begin(), order.end());
        for(int i = 0, c = n; i < n; c--, i++) {
            ans[order[i]] = c;
        }
        for(int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << '\n';
    }
}