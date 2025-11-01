//
// Created by wasifshahzad on 8/16/25.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> f(l, vector<int>(m));
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < m; j++) {
            int cost = 0;
            for (int k = i; k < n; k += l) {
                cost += (j - a[k] + m) % m;
            }
            f[i][j] = cost;
        }
    }
    vector<vector<int>> dp(l, vector<int>(m, 1e9));
    for (int i = 0; i < m; i++) {
        dp[0][i] = f[0][i];
    }
    for (int i = 1; i < l; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                const int prev = (j - k + m) % m;
                dp[i][j] = min(dp[i][j], dp[i - 1][prev] + f[i][k]);
            }
        }
    }
    cout << dp[l - 1][0] << '\n';
}