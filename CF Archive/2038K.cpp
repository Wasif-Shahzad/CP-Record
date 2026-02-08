//
// 2038K.cpp
// Created by wasifshahzad on 12/14/25 at 10:44:25.
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
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> p1(n + 1), p2(n + 1);
    int x = -1, y = -1, tot = 0;
    for(int i = 1; i <= n; i++) {
        p1[i] = __gcd(i, a);
        p2[i] = __gcd(i, b);
        tot += p1[i];
        if(p1[i] == 1) x = i;
        if(p2[i] == 1) y = i;
    }
    int ans = LONG_LONG_MAX, pref = 0;
    for(int i = 1; i <= (y == 1 ? x - 1: x); i++) {
        pref += p1[i] + 1;
        if(i < x) tot -= p1[i];
    } 
    if(y != 1) {
        for(int i = 2; i < y; i++) {
            pref += p2[i] + p1[x];
        }
    }
    ans = pref;
    int m = n - y + 1;
    n = n - x + 1;
    vector<vector<int>> g(n + 1, vector<int>(m + 1, 1e10));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            g[i][j] = __gcd(i + x, a) + __gcd(j + y, b);
        }
    }
    vector<vector<int>> dp(n, vector<int>(m, 1e10));
    dp[n - 1][m - 1] = g[n - 1][m - 1];
    for(int i = n - 2; i >= 0; i--) {
        dp[i][m - 1] = g[i][m - 1] + dp[i + 1][m - 1];
    }
    for(int i = m - 2; i >= 0; i--) {
        dp[n - 1][i] = g[n - 1][i] + dp[n - 1][i + 1];
    }
    for(int i = n - 2; i >= 0; i--) {
        for(int j = m - 2; j >= 0; j--) {
            dp[i][j] = g[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
        }
    }
    ans += dp[0][0];
    cout << ans << '\n';
}