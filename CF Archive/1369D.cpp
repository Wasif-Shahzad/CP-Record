//
// 1369D.cpp
// Created by Wasif on 10/20/25 at 18:50:02.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int N = 2e6+5, mod = 1e9+7;
int dp[N], r[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dp[1] = dp[2] = 0;
    r[1] = r[2] = 0;
    for(int i = 3; i < N; i++) {
        dp[i] = (2 * dp[i - 2] + dp[i - 1]) % mod;
        if(r[i - 1] || r[i - 2]) {
            r[i] = 0;
        } else {
            r[i] = 1;
            dp[i] = (dp[i] + 4) % mod;
        }
    }
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
}