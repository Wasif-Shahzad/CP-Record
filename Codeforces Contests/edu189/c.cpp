//
// c.cpp
// Created by wasifshahzad on 04/21/26 at 19:56:17.
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
    array<string, 2> s;
    cin >> s[0] >> s[1];
    vector<int> dp(n + 1, 1e9);
    dp[n] = 0;
    dp[n - 1] = s[0][n - 1] != s[1][n - 1];
    for(int i = n - 2; i >= 0; i--) {
        dp[i] = (s[0][i] != s[0][i + 1]) + (s[1][i] != s[1][i + 1]) + dp[i + 2];
        dp[i] = min(dp[i], (s[0][i] != s[1][i]) + dp[i + 1]);
    }
    cout << dp[0] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}