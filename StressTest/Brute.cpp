//
// 449B.cpp
// Created by wasifshahzad on 06/23/26 at 18:50:17.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    const int oo = 1e16;
    vector<int> freq(n, 0), bst(n, oo);
    vector<vector<pair<int, int>>> g(n);
    vector<array<int, 3>> edge(m);
    vector<array<int, 2>> train(k);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edge[i] = {u, v, w};
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for(int i = 0; i < k; i++) {
        int v, w;
        cin >> v >> w;
        v--;
        train[i] = {v, w};
        g[0].push_back({v, w});
        g[v].push_back({0, w});
        freq[v]++;
        bst[v] = min(bst[v], w);
    }
    auto dijkstra = [&n, &oo] (vector<vector<pair<int, int>>>& g) -> vector<int> {
        vector<int> dist(n, oo);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[0] = 0;
        pq.push({0, 0});
        while(!pq.empty()) {
            auto [d, v] = pq.top();
            pq.pop();
            if(d != dist[v]) continue;
            for(auto [c, w]: g[v]) {
                if(d + w < dist[c]) {
                    dist[c] = d + w;
                    pq.push({d + w, c});
                }
            }
        }
        return dist;
    };
    auto d1 = dijkstra(g);
    int ans = 0;
    for(int i = 0; i < k; i++) {
        for(int x = 0; x < n; x++) g[x].clear();
        for(int j = 0; j < k; j++) {
            if(i == j) continue;
            auto [v, w] = train[j];
            g[0].push_back({v, w});
            g[v].push_back({0, w});
        }
        for(auto [u, v, w]: edge) {
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        auto d = dijkstra(g);
        bool diff = false;
        for(int j = 0; j < n; j++) {
            if(d[j] != d1[j]) {
                diff = true;
                break;
            }
        }
        if(not diff) ans++;
    }
    cout << ans << '\n';
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