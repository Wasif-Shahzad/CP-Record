//
// Created by wasifshahzad on 8/20/25.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> score(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        vector<int> cur;
        for (int j = 0; j < n; j++) {
            if ((1 << j) & i) {
                cur.push_back(j);
            }
        }
        int w = 0;
        for (int j = 0; j < cur.size(); j++) {
            for (int k = j; k < cur.size(); k++) {
                w += a[cur[j]][cur[k]];
            }
        }
        score[i] = w;
    }
    vector<int> dp(1 << n, -1e9);
    dp[0] = 0;
    for (int i = 1; i < (1 << n); i++) {
        for (int j = i; j; j = (j - 1) & i) {
            dp[i] = max(dp[i], score[j] + dp[i - j]);
        }
    }
    cout << dp[(1 << n) - 1] << '\n';
}