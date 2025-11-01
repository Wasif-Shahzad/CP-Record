//
// 463D.cpp
// Created by Wasif on 09/20/25 at 11:30:49.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(k, vector<int>(n));
    vector<vector<int>> loc(k, vector<int>(n));
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            loc[i][a[i][j] - 1] = j;
        }
    }
    vector<vector<int>> g(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            bool bad = false;
            for(int x = 0; x < k; x++) {
                if(loc[x][i] > loc[x][j]) {
                    bad = true;
                    break;
                }
            }
            if(!bad) g[i].push_back(j);
        }
    }
    vector<int> order, vis(n, false);
    auto dfs = [&] (int v, auto&& self) -> void{
        vis[v] = 1;
        for(int c: g[v]) {
            if(vis[c]) continue;
            self(c, self);
        }
        order.push_back(v);
    };
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i, dfs);
        }
    }
    reverse(order.begin(), order.end());
    vector<int> dp(n, 0);
    for(int i = n - 1; i >= 0; i--) {
        for(int c: g[order[i]]) {
            dp[order[i]] = max(dp[order[i]], dp[c] + 1);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) + 1 << '\n';
}