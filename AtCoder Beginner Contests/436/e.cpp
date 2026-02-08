//
// e.cpp
// Created by wasifshahzad on 12/13/25 at 17:13:21.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n; i++) {
        int j; cin >> j;
        j--;
        g[i].push_back(j);
    }
    vector<int> vis(n, 0);
    int ans = 0, sz = 0;
    auto dfs = [&] (int v, auto&& self) -> void {
        vis[v] = 1;
        sz++;
        if(!vis[g[v][0]]) {
            self(g[v][0], self);
        }
    };
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            sz = 0;
            dfs(i, dfs);
            ans += sz * (sz - 1) / 2;
        }
    }
    cout << ans << '\n';
}