//
// 1882D.cpp
// Created by wasifshahzad on 06/13/26 at 10:49:14.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    // if we assume that every subtree of our child have same values respectively
    // (not necessarily same as each other)
    // and we go with the assumption that each subtree becomes equal to the value of the root
    // then its about making our children's values equal to us
    // which is sub[c] * (a[v] ^ a[c])
    // we have to find a way to reroot this
    // we just reroot sizes of subtrees?
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> g(n);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> dp(n, 0), sz(n, 1);
    auto dfs1 = [&] (int v, int p, auto&& self) -> void {
        for(int c: g[v]) {
            if(c == p) continue;
            self(c, v, self);
            sz[v] += sz[c];
            dp[v] += sz[c] * (a[v] ^ a[c]) + dp[c];
        }
    };
    dfs1(0, -1, dfs1);
    vector<int> ans(n);
    ans[0] = dp[0];
    auto dfs2 = [&] (int v, int p, auto&& self) -> void {
        for(int c: g[v]) {
            if(c == p) continue;
            dp[v] -= sz[c] * (a[v] ^ a[c]) + dp[c];
            sz[v] -= sz[c];
            sz[c] += sz[v];
            dp[c] += sz[v] * (a[v] ^ a[c]) + dp[v];
            ans[c] = dp[c];
            self(c, v, self);
            dp[c] -= sz[v] * (a[v] ^ a[c]) + dp[v];
            sz[c] -= sz[v];
            sz[v] += sz[c];
            dp[v] += sz[c] * (a[v] ^ a[c]) + dp[c];
        }
    };
    dfs2(0, -1, dfs2);
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << '\n';
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