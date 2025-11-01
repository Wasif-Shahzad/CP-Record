//
// 118E.cpp
// Created by wasifshahzad on 9/1/25 at 11:06:14.
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
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dp(n, 0), tin(n, 0), par(n, -1), contribution(n, 0);
    vector<pair<int, int>> span_edges, back_edges;
    vector<vector<int>> dfs_tree(n);
    int timer = 0;
    auto dfs1 = [&] (int v, int p, auto&& self) -> void {
        tin[v] = ++timer;
        par[v] = p;
        for (int c: adj[v]) {
            if (c == p) continue;
            if (tin[c] == 0) {
                span_edges.push_back({v, c});
                dfs_tree[v].push_back(c);
                self(c, v, self);
            } else if (tin[c] < tin[v]) {
                back_edges.push_back({v, c});
                contribution[v]++;
                contribution[c]--;
            }
        }
    };
    dfs1(0, -1, dfs1);
    auto dfs2 = [&] (int v, int p, auto&& self) -> void {
        dp[v] = contribution[v];
        for (int c: dfs_tree[v]) {
            self(c, v, self);
            dp[v] += dp[c];
        }
    };
    dfs2(0, -1, dfs2);
    bool has_bridge = false;
    for (int i = 1; i < n; i++) {
        if (dp[i] == 0) {
            has_bridge = true;
            break;
        }
    }
    if (has_bridge) {
        cout << 0 << '\n';
    } else {
        for (auto [u, v]: span_edges) {
            cout << u + 1 << " " << v + 1 << '\n';
        }
        for (auto [u, v]: back_edges) {
            cout << u + 1 << " " << v + 1 << '\n';
        }
    }
}