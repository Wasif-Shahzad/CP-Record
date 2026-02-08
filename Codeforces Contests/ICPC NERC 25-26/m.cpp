//
// m.cpp
// Created by wasifshahzad on 12/17/25 at 13:39:45.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        string x, y;
        cin >> x >> y;
        int n = x.size();
        vector<array<int, 2>> dp(n, {-1, -1});
        auto f = [&] (int i, int par, auto&& self) -> int {
            if(i == n) return 0;
            if(dp[i][par] != -1) return dp[i][par];
            int ans = 1e9;
            if(x[i] == '1') {
                int npar = !par;
                int cur;
                // don't flip x
                if(y[i] - '0' != npar) {
                    cur = 1 + self(i + 1, npar, self);
                } else {
                    cur = self(i + 1, npar, self);
                }
                // flip x
                if(y[i] - '0' != par) {
                    cur = min(cur, 2 + self(i + 1, par, self));
                } else {
                    cur = min(cur, 1 + self(i + 1, par, self));
                }
                ans = cur;
            } else {
                // don't flip x
                int cur;
                if(y[i] - '0' != par) {
                    cur = 1 + self(i + 1, par, self);
                } else {
                    cur = self(i + 1, par, self);
                }
                // flip x
                int npar = !par;
                if(y[i] - '0' != npar) {
                    cur = min(cur, 2 + self(i + 1, npar, self));
                } else {
                    cur = min(cur, 1 + self(i + 1, npar, self));
                }
                ans = cur;
            }
            return dp[i][par] = ans;
        };
        cout << f(0, 0, f) << '\n';
    }
}