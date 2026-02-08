//
// 678E.cpp
// Created by wasifshahzad on 01/02/26 at 15:39:44.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<long double>> a(n, vector<long double>(n));
    for(auto &r: a) {
        for(auto &i: r) cin >> i;
    }
    vector<vector<long double>> dp(1 << n, vector<long double>(n, -1));
    auto f = [&] (int mask, int i, auto&& self) -> long double {
        if(mask == (1 << n) - 1) return i == 0;
        if(dp[mask][i] > -0.5) return dp[mask][i];
        long double res = 0;
        for(int j = 0; j < n; j++) {
            if((1 << j) & mask) continue;
            long double us = a[i][j] * self(mask | (1 << j), i, self);
            long double them = a[j][i] * self(mask | (1 << j), j, self);
            res = max(res, us + them);
        }
        return dp[mask][i] = res;
    };
    long double ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, f(1 << i, i, f));
    }
    cout << setprecision(10) << fixed << ans << '\n';
}