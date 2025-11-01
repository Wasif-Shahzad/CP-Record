//
// 1132F.cpp
// Created by wasifshahzad on 8/22/25 at 09:31:29.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

/*
 * if in range [l, r] we are at i
 * in [l, i] we get +1 for all = s[l]
 * it'll be ranges for others
 * and (i, r] for others
 */

void chkmin(int &a, const int b) {
    a = min(a, b);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    for (int k = 2; k <= n; k++) {
        for (int l = 0; l + k - 1 < n; l++) {
            const int r = l + k - 1;
            dp[l][r] = 1 + dp[l + 1][r];
            for (int i = l + 1; i <= r; i++) {
                if (s[i] == s[l]) {
                    chkmin(dp[l][r], dp[l + 1][i - 1] + dp[i][r]);
                }
            }
        }
    }
    cout << dp[0][n - 1] << '\n';
}