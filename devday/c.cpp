//
// c.cpp
// Created by wasifshahzad on 04/30/26 at 13:11:31.
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
    vector<int> a(n);
    for(int i = 0;i < n; i++) cin >> a[i];
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> dp(n);
    auto dfs = [&] (int v, int p, auto&& self) -> void {
        dp[v] = a[v];
        for(int c: g[v]) {
            if(c == p) continue;
            self(c, v, self);
            dp[v] += dp[c];
        }
    };
    dfs(0, -1, dfs);
    int ans = 1e16;
    auto go = [&] (int v, int p, auto&& self) -> void {
        for(int c: g[v]) {
            if(c == p) continue;
            int our = dp[v] - dp[c];
            ans = min(ans, abs(our - dp[c]));
            dp[c] += our;
            dp[v] = our;
            self(c, v, self);
            dp[c] -= dp[v];
            dp[v] += dp[c];
        }
    };
    go(0, -1, go);
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