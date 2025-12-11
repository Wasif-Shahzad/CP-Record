//
// c.cpp
// Created by Wasif on 11/24/25 at 08:24:59.
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
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<array<int, 2>> dp(n + 1, {0, 0});
    dp[n][0] = dp[n][1] = 1;
    for(int i = n - 1; i >= 0; i--) {
        if(a[i] & 1) {
            for(int j = i; j < n; j++) {
                if((j - i + 1) % 2 == 0) continue;
                if(a[j] & 1) {
                    if(j + 1 == n) {
                        dp[i][1] = 1;       
                    } else {
                        dp[i][0] = max(dp[i][0], dp[j + 1][1]);
                        dp[i][1] = max(dp[i][1], dp[j + 1][0]);
                    }
                }
            }
        }
    }
    cout << (dp[0][1] ? "Yes" : "No") << '\n';
    
}