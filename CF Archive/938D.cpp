/*
 * the concern that ith city attends has to cost lesser than a[i]
 * 2 * d(i, j) + a[j] <= a[i]
 * 2 * d(i, j) <= a[i] - a[j]
 * d(i, j) <= (a[i] - a[j]) // 2
 * d(i, j) lesser than half of a[i] at least
 * for the city with min cost in its component, we cannot do anything
 * minimizing a[j] doesn't work because there's no correlation with d(i, j)
 * bipartite graph
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    #define ld long double
    priority_queue<array<ld, 2>, vector<array<ld, 2>>, greater<array<ld, 2>>> pq;
    vector<ld> dist(n, 8e18);
    // (v, cost, if we've to subtract 1)
    for(int i = 0; i < n; i++) {
        ld x;
        cin >> x;
        pq.push({x / 2, (ld) i});
        dist[i] = x / 2;
    }
    while(!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        if (dist[v] < d) continue;
        for(auto [c, w]: g[v]) {
            if(d + w < dist[c]) {
                dist[c] = d + w;
                pq.push({d + w, (ld) c});
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << fixed << setprecision(0) << 2 * dist[i] << " ";
    }
    cout << '\n';
}
