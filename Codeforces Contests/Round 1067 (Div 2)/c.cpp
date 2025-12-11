//
// c.cpp
// Created by Wasif on 11/29/25 at 19:30:35.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int mx = a[0], cur = a[0];
    for(int i = 1; i < n; i++) {
        if(cur + a[i] < a[i]) {
            cur = a[i];
        } else {
            cur += a[i];
        }
        mx = max(mx, cur);
    }
    if(k % 2 == 0) {
        cout << mx << '\n';
        return;
    }
    vector<array<int, 2>> dp(n);
    dp[0][0] = a[0];
    dp[0][1] = a[0] + b[0];
    int ans = dp[0][1];
    for(int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0] + a[i], a[i]);
        dp[i][1] = max({dp[i - 1][1] + a[i], dp[i - 1][0] + a[i] + b[i], a[i] + b[i]});
        ans = max({ans, dp[i][1], dp[i][0]});
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
}