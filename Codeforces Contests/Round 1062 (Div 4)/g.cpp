//
// g.cpp
// Created by Wasif on 10/28/25 at 20:18:59.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n + 1, 0), c(n + 1);
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++) {
            cin >> c[i];
        }
        auto b = a;
        sort(b.begin(), b.end());
        for(int i = 1; i <= n; i++) {
            a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        }
        // vector<vector<int>> dp(n + 1, vector<int>(n + 2, -1));
        // auto f = [&] (int i, int mx, auto&& self) -> int {
        //     if(i == n) return 0;
        //     if(dp[i][mx] != -1) return dp[i][mx];
        //     if(a[i] < mx) {
        //         // forced to change
        //         return dp[i][mx] = c[i] + self(i + 1, mx, self);
        //     } else {
        //         int ans = 1e14;
        //         ans = c[i] + self(i + 1, mx, self);
        //         ans = min(ans, self(i + 1, a[i], self));
        //         return dp[i][mx] = ans;
        //     }
        // };
        // cout << f(0, 0, f) << '\n';
        vector<int> dp(n + 2, 0);
        for(int i = n; i > 0; i--) {
            vector<int> ndp = dp;
            for(int j = 0; j <= n; j++) {
                if(j > a[i]) {
                    ndp[j] = c[i] + dp[j];
                } else {
                    ndp[j] = min(c[i] + dp[j], dp[a[i]]);
                }
            }
            dp = ndp;
        }
        cout << min(dp[0], dp[a[1]]) << '\n';
    }
}