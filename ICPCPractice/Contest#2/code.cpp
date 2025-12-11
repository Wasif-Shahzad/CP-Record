//
// code.cpp
// Created by Wasif on 11/09/25 at 14:38:57.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> vals(22);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        int msb = 63 - __builtin_clzll(a[i]);
        vals[msb].push_back(a[i]);
    }
    vector<int> dp(1 << 22, 0);
    for(int mask = 1; mask < (1 << 22); mask++) {
        for(int i = 0; i < 22; i++) {
            if((1 << i) & mask) {
                for(int j: vals[i]) {
                    int new_mask = (mask & j) ^ mask;
                    dp[mask] = max(dp[mask], 1 + dp[new_mask]);
                }
            }
        }
    }
    cout << dp[(1 << 22) - 1] << '\n';
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