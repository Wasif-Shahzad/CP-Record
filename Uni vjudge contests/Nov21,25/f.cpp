//
// f.cpp
// Created by Wasif on 11/21/25 at 21:34:04.
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
    int s, a, b;
    cin >> s >> a >> b;
    s--, a--, b--;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> d1(n, 1e9), d2(n, 1e9), d3(n, 1e9);
    auto bfs = [&] (int st, vector<int>& d) -> void {
        queue<int> q;
        q.push(st);
        vector<int> vis(n, 0);
        vis[st] = 0;
        d[st] = 0;
        while(q.size()) {
            int v = q.front();
            q.pop();
            for(int c: g[v]) {
                if(vis[c]) continue;
                if(d[v] + 1 < d[c]) {
                    d[c] = d[v] + 1;
                    q.push(c);
                    vis[c] = 1;
                }
            }
        }
    };
    bfs(s, d1);
    bfs(a, d2);
    bfs(b, d3);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(d1[i] + d2[i] == d1[a] && d1[i] + d3[i] == d1[b]) {
            ans = max(ans, d1[i]);
        }
    }
    cout << ans << '\n';
}