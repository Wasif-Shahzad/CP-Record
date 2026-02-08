//
// f.cpp
// Created by wasifshahzad on 01/03/26 at 12:53:05.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
    }
    vector<int> vis(n, 0);
    int lst = 0;
    auto dfs = [&] (int v, auto&& self) -> void {
        vis[v] = 1;
        lst = v;
        for(int c: g[v]) {
            if(vis[c]) continue;
            self(c, self);
        }
    };
    for(int i = 0; i < n; i++) {
        vis.assign(n, 0);
        dfs(i, dfs);
        int cnt = count(vis.begin(), vis.end(), 0ll);
        if(cnt <= 1) {
            int j = -1;
            for(int k = 0; k < n; k++) {
                if(!vis[k]) j = k;
            }
            if(j == -1) j = ((i - 1) % n + n) % n;
            cout << "YES\n";
            cout << lst + 1 << " " << i + 1 << '\n';
            return;
        }
    }
    cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }
}