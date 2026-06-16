//
// 1114D.cpp
// Created by wasifshahzad on 04/14/26 at 18:24:42.
//

#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

/*
*/

void chkmin(int &a, int b) {
    a = min(a, b);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 5005);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<array<int, 2>>> dp(n, vector<array<int, 2>>(n, {100000, 100000}));
    for(int i = 0; i < n; i++) {
        dp[i][i] = {0, 0};
    }  
    for(int len = 2; len <= n; len++) {
        for(int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            dp[i][j][0] = min(dp[i + 1][j][0] + (a[i] != a[i + 1]), dp[i + 1][j][1] + (a[j] != a[i]));
            dp[i][j][1] = min(dp[i][j - 1][0] + (a[i] != a[j]), dp[i][j - 1][1] + (a[j] != a[j - 1]));
        }
    }
    cout << min(dp[0][n - 1][0], dp[0][n - 1][1]) << '\n';
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