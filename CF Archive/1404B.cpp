//
// 1404B.cpp
// Created by wasifshahzad on 04/11/26 at 22:21:41.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    a--, b--;
    vector<vector<int>> g(n);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> dist(n, 0);
    auto dfs1 = [&] (int v, int p, auto&& self) -> void {
        for(int c: g[v]) {
            if(c == p) continue;
            dist[c] = dist[v] + 1;
            self(c, v, self);
        }
    };
    dfs1(a, -1, dfs1);
    if(da >= dist[b]) {
        cout << "Alice\n";
        return;
    }
    int v = max_element(all(dist)) - dist.begin();
    dist[v] = 0;
    dfs1(v, -1, dfs1);
    int dia = *max_element(all(dist));
    if(2 * da >= dia) {
        cout << "Alice\n";
        return;
    }
    if(db > 2 * da) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}