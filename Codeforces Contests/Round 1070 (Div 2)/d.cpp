//
// d.cpp
// Created by Wasif on 12/11/25 at 20:53:14.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int mod = 998244353;
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        vector<vector<pair<int, int>>> g(n);
        vector<array<int, 3>> edges(m);
        vector<map<int, int>> dp(n);
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            edges[i] = {a[u] + a[v], u, v};
        }
        sort(edges.begin(), edges.end());
        int ans = 0;
        for(int i = m - 1; i >= 0; i--) {
            auto [need, u, v] = edges[i];
            dp[u][a[v]] += 1;
            dp[u][a[v]] %= mod;
            if(dp[v].count(need)) {
                dp[u][a[v]] = (dp[u][a[v]] + dp[v][need]) % mod;
            }
        }
        for(int i = 0; i < n; i++) {
            for(auto [v, c]: dp[i]) {
                ans = (ans + c) % mod;
            }
        }
        cout << ans << '\n';
    }
}