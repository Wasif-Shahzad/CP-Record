//
// f.cpp
// Created by Wasif on 10/28/25 at 20:56:12.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> g(n);
        for(int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> dp(n, 1);
        auto dfs1 = [&] (int u, int p, auto&& self) -> void{
            for(int c: g[u]) {
                if(c == p) continue;
                self(c, u, self);
                dp[u] += dp[c];
            }
        };
        dfs1(0, -1, dfs1);
        int ans = 0;
        for(int i: dp) {
            if(i >= k) ans++;
        }
        vector<int> out(n);
        out[0] = ans;
        auto dfs2 = [&] (int v, int p, auto&& self) -> void{
            for(int c: g[v]) {
                if(c == p) continue;
                if(dp[v] >= k && dp[v] - dp[c] < k) ans--;
                dp[v] -= dp[c];
                if(dp[c] < k && dp[c] + dp[v] >= k) ans++;
                dp[c] += dp[v];
                out[c] = ans;
                self(c, v, self);
                if(dp[c] >= k && dp[c] - dp[v] < k) ans--;
                dp[c] -= dp[v];
                if(dp[v] < k && dp[v] + dp[c] >= k) ans++;
                dp[v] += dp[c];
            }
        };
        dfs2(0, -1, dfs2);
        int tot = 0;
        for(int i = 0; i < n; i++) tot += out[i];
        cout << tot << '\n';
    }
}