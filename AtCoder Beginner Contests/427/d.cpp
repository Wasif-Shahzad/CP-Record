//
// d.cpp
// Created by Wasif on 10/11/25 at 16:51:29.
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
        int n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        vector<vector<int>> g(n);
        vector<int> out(n, 0);
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
        }
        vector<vector<array<int, 2>>> dp(n, vector<array<int, 2>>(2 * k + 1, {-1, -1}));
        auto f = [&] (int v, int k, int turn, auto&& self) -> int{
            if(k == 0) {
                return s[v] == 'A';
            }
            if(dp[v][k][turn] != -1) return dp[v][k][turn];
            if(turn) {
                int ans = 0;
                for(int c: g[v]) {
                    ans = max(ans, self(c, k - 1, !turn, self));
                    if(ans == 1) break;
                }
                return dp[v][k][turn] = ans;
            } else {
                int ans = 2;
                for(int c: g[v]) {
                    ans = min(ans, self(c, k - 1, !turn, self));
                    if(ans == 0) break;
                }
                return dp[v][k][turn] = ans;
            }
        };
        cout << (f(0, 2 * k, 1, f) ? "Alice" : "Bob") << '\n';
    }
}