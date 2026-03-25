//
// 191C.cpp
// Created by wasifshahzad on 03/23/26 at 14:28:29.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<pair<int, int>> in(n - 1);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        in[i - 1] = {u, v};
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vector<int>> up(22, vector<int>(n, 0));
    vector<int> depth(n, 0);
    auto dfs = [&] (int v, int p, auto&& self) -> void {
        if(p != -1) up[0][v] = p;
        for(int c: g[v]) {
            if(c == p) continue;
            depth[c] = depth[v] + 1;
            self(c, v, self);
        }
    };
    dfs(0, -1, dfs);
    for(int j = 1; j < 22; j++) {
        for(int i = 0; i < n; i++) {
            up[j][i] = up[j - 1][up[j - 1][i]];
        }
    }
    auto walk = [&] (int v, int d) -> int {
        for(int i = 0; i < 22; i++) {
            if((1 << i) & d) v = up[i][v];
        }
        return v;
    };
    auto find_lca = [&] (int u, int v) -> int {
        if(depth[u] > depth[v]) swap(u, v);
        int ch = depth[v] - depth[u];
        v = walk(v, ch);
        if(u == v) return u;
        for(int j = 21; j >= 0; j--) {
            if(up[j][u] != up[j][v]) {
                u = up[j][u], v = up[j][v];
            }
        }
        return up[0][u];
    };
    vector<int> add(n, 0), rm(n, 0), tot(n, 0);
    int k;
    cin >> k;
    while(k--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        add[u]++, add[v]++;
        int lca = find_lca(u, v);
        rm[lca] += 2;
    }
    map<pair<int, int>, int> ans;
    auto go = [&] (int v, auto&& self) -> void {
        for(int c: g[v]) {
            if(c == up[0][v]) continue;
            self(c, self);
            tot[v] += tot[c];
            ans[{v, c}] = ans[{c, v}] = tot[c];
        }
        tot[v] += add[v] - rm[v];
    };
    go(0, go);
    for(auto i: in) {
        cout << ans[i] << " ";
    }
    cout << '\n';
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