//
// 2049D.cpp
// Created by wasifshahzad on 12/31/25 at 11:04:41.
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
    int T;
    cin >> T;
    while(T--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> a(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        vector<vector<int>> dp(n, vector<int>(m, 1e17));
        dp[n - 1][m - 1] = a[n - 1][m - 1];
        for(int i = m - 2; i >= 0; i--) {
            int r = m - i - 2;
            dp[n - 1][i] = min(r * k + a[n - 1][i], a[n - 1][i] + dp[n - 1][i + 1]);
        }
        for(int i = n - 2; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                if(j + 1 < m) dp[i][j] = a[i][j] + dp[i][j + 1];
                
            }
        }
    }
}