//
// F.cpp
// Created by wasifshahzad on 8/21/25 at 20:24:26.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int timer = 0;
void dfs(int v, int p, vector<vector<int>>& g,
    vector<int>& tin, vector<int>& tout, vector<int>& low,
    vector<int>& vis, vector<pair<int, int>>& bridges) {
    vis[v] = 1;
    tin[v] = low[v] = timer++;
    for (int c: g[v]) {
        if (c == p) continue;
        if (vis[c]) {
            low[v] = min(low[v], tin[c]);
        } else {
            dfs(c, v, g, tin, tout, low, vis, bridges);
            low[v] = min(low[v], low[c]);
            if (low[c] > tin[v]) {
                bridges.push_back({min(v, c), max(v, c)});
            }
        }
    }
    tout[v] = timer++;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        timer = 0;
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(n);
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            if (u > v) swap(u, v);
            g[u].push_back(v);
            g[v].push_back(u);
            mp[{u, v}] = i;
        }
        vector<int> tin(n), tout(n), low(n), vis(n);
        vector<pair<int, int>> bridges;
        dfs(0, -1, g, tin, tout, low, vis, bridges);
        auto isCrucial = [&] (int v, int u) -> bool {
            return tin[v] < tin[u] && tout[v] > tout[u] && tin[u] <= tin[n - 1] && tout[u] >= tout[n - 1];
        };
        vector<pair<int, int>> imp;
        for (auto [u, v]: bridges) {
            if (isCrucial(u, v) || isCrucial(v, u)) {
                imp.push_back({u, v});
            }
        }
        vector<pair<int, int>> dist(n, {1e9, -1});
        for (auto [u, v]: imp) {
            int i = mp[{u, v}];
            if (dist[u].first == 1e9) {
                dist[u] = {0, i};
            } else {
                dist[u].second = min(dist[u].second, i);
            }
            if (dist[v].first == 1e9) {
                dist[v] = {0, i};
            } else {
                dist[v].second = min(dist[v].second, i);
            }
        }
        queue<array<int, 3>> q;
        for (int i = 0; i < n; i++) {
            if (dist[i].first != 1e9) {
                q.push({i, dist[i].first, dist[i].second});
            }
        }
        while (!q.empty()) {
            auto [v, d, i] = q.front();
            q.pop();
            for (int c: g[v]) {
                if (d + 1 < dist[c].first) {
                    dist[c] = {d + 1, i};
                    q.push({c, d + 1, i});
                } else if (d + 1 == dist[c].first) {
                    if (i < dist[c].second) {
                        dist[c] = {d + 1, i};
                        q.push({c, d + 1, i});
                    }
                }
            }
        }
        int Q;
        cin >> Q;
        while (Q--) {
            int v;
            cin >> v;
            v--;
            if (dist[v].first == 1e9) cout << -1 << " ";
            else cout << dist[v].second + 1 << " ";
        }
        cout << '\n';
    }
}