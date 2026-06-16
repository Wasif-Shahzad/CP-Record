//
// a.cpp
// Created by wasifshahzad on 05/05/26 at 11:36:47.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<vector<array<int, 2>>> dp(n + 1, vector<array<int, 2>>(2));
    dp[n][0][0] = dp[n][1][0] = 1;
    dp[n][0][1] = dp[n][1][1] = 0;
    for(int i = n - 1; i >= 0; i--) {
        dp[i][0][0] = dp[i + 1][0][0];
        if(i + 2 <= n) dp[i][0][0] += dp[i + 2][0][0];
        dp[i][0][0] += dp[i + 1][1][1];
        dp[i][0][0] += dp[i + 1][0][1];
        dp[i][0][1] += dp[i + 1][1][1];
        if(i + 2 <= n) dp[i][0][1] += dp[i + 2][0][0];
        dp[i][1][1] += dp[i + 1][0][1];
        if(i + 2 <= n) dp[i][1][1] += dp[i + 2][0][0];
    }
    cout << dp[0][0][0] << '\n';
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