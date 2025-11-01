//
// d.cpp
// Created by Wasif on 09/17/25 at 20:23:59.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const int mod = 1e9+7;
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
        auto f = [&] (int i, int j, int k, auto&& self) -> int{
            if(i == n) return 1;
            if(dp[i][j][k] != -1) return dp[i][j][k];
            bool forbidden = (k != n && a[i] < a[k]);
            int ans = 0;
            if(!forbidden) {
                if(j == n) {
                    ans = self(i + 1, i, k, self);
                } else if(a[i] > a[j]) {
                    ans = self(i + 1, i, k, self);
                } else if(k == n && a[i] < a[j]) {
                    ans = self(i + 1, j, i, self);
                } else if(k != n && a[i] >= a[k] && a[i] < a[j]) {
                    ans = self(i + 1, j, i, self);
                } else {
                    ans = self(i + 1, j, k, self);
                }
            }
            ans = (ans + self(i + 1, j, k, self)) % mod;
            return dp[i][j][k] = ans;
        };
        cout << f(0, n, n, f) << '\n';
    }
}