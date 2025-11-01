//
// 2002D1.cpp
// Created by Wasif on 10/18/25 at 08:17:46.
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
        int n, q;
        cin >> n >> q;
        vector<array<int, 2>> g(n, {-1, -1});
        vector<int> par(n, -1);
        for(int i = 1; i < n; i++) {
            int p;
            cin >> p;
            p--;
            par[i] = p;
            if(g[p][0] == -1) g[p][0] = i;
            else g[p][1] = i;
        }
        vector<int> p(n);
        for(int i = 0; i < n; i++) {
            cin >> p[i];
            p[i]--;
        }
        vector<int> depth(n, 0);
        for(int i = 1; i < n; i++) {
            depth[i] = depth[par[i]] + 1;
        }
        vector<int> order;
        auto dfs = [&] (int v, auto&& self) -> void{
            order.push_back(v);
            if(g[v][0] != -1) {
                self(g[v][0], self);
                self(g[v][1], self);
            }
        };
        dfs(0, dfs);
        vector<set<int>> valid(25);
        for(int i = 0; i < order.size(); i++) {
            valid[depth[order[i]]].insert(i);
        }
        set<int> bad;
        for(int i = 0; i < n; i++) {
            if(!valid[depth[p[i]]].count(i)) {
                bad.insert(p[i]);
            }
        }
        
    }
}