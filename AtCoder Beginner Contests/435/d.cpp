//
// d.cpp
// Created by Wasif on 12/06/25 at 17:09:11.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> rev(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        rev[v].push_back(u);
    }
    vector<int> vis(n, 0);
    auto dfs = [&] (int v, auto&& self) -> void {
        vis[v] = 1;
        for(int c: rev[v]) {
            if(vis[c]) continue;
            self(c, self);
        }
    };
    int q;
    cin >> q;
    while(q--) {
        int t, v;
        cin >> t >> v;
        v--;
        if(t == 1) {
            if(vis[v]) continue;
            dfs(v, dfs);
        } else {
            cout << (vis[v] ? "Yes" : "No") << '\n';
        }
    }
}