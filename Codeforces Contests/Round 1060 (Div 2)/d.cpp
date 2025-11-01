//
// d.cpp
// Created by Wasif on 10/19/25 at 21:00:11.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        for(int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> p(n, -1), nxt(n, -1);
        auto dfs = [&] (int v, int type, auto&& self) -> void{
            for(int c: g[v]) {
                if(type == 0) {
                    if(c == p[v]) continue;
                    p[c] = v;
                    self(c, 0, self);
                } else {
                    if(c == nxt[v]) continue;
                    nxt[c] = v;
                    self(c, 1, self);
                }
            }
        };
        dfs(0, 0, dfs);
        dfs(n - 1, 1, dfs);
        vector<vector<int>> ops;
        int end = 0;
        auto solve = [&] (int v, auto&& self) -> void{
            bool rm = false;
            end = v;
            for(int c: g[v]) {
                if(c == p[v] || c == nxt[v]) continue;
                if(!rm) {
                    rm = true;
                    ops.push_back({2, c});
                } else {
                    ops.push_back({1});
                    self(c, self);
                }
            }
        };
        solve(0, solve);
        while(end != 0) {
            ops.push_back({1});
            end = nxt[end];
        }
        end = nxt[0];
        ops.push_back({1});
        auto solve2 = [&] (int v, auto&& self) -> void{
            if(v == n - 1) return;
            bool rm = false;
            for(int c: g[v]) {
                if(c == p[v]) continue;
                if(c != nxt[v]) {
                    if(!rm) {
                        rm = true;
                        ops.push_back({2, c});
                    } else {
                        ops.push_back({1});
                        self(c, self);
                    }
                }
            }
            self(nxt[v], self);
        };
        solve2(end, solve2);
        cout << ops.size() << '\n';
        for(auto pp: ops) {
            if(pp.size() == 1) cout << 1 << '\n';
            else cout << 2 << " " << pp[1] + 1 << '\n';
        }
    }
}