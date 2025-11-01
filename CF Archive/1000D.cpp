//
// 1000D.cpp
// Created by Wasif on 09/30/25 at 20:31:18.
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
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    const int mod = 998244353;
    auto f = [&] (int i, int rem, auto&& self) -> int{
        if(i == n) return rem == 0;
        if(dp[i][rem] != -1) return dp[i][rem];
        int ans = 0;
        if(rem == 0) {
            if(a[i] > 0 && a[i] <= n) {
                ans = self(i + 1, a[i], self);
                ans = (ans + self(i + 1, 0, self)) % mod;
            } else {
                ans = self(i + 1, rem, self);
            }
        } else {
            ans = self(i + 1, rem - 1, self);
            ans = (ans + self(i + 1, rem, self)) % mod;
        }
        return dp[i][rem] = ans;
    };  
    cout << f(0, 0, f) - 1 << '\n';
}