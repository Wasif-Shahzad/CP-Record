//
// e.cpp
// Created by wasifshahzad on 12/31/25 at 20:49:12.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

int power(int a, int b, int m) {
    int ans = 1;
    while(b > 0) {
        if(b & 1) ans = ans * a % m;
        a = a * a % m;
        b /= 2;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        auto f = [&] (int i, int len, auto&& self) -> int {
            if(len == 1) {
                int rem = n - i - 1;
                int ans = power(n, rem, m);
                int here = n - rem + 1;
                ans = ans * here % m;
                return ans;
            }
            if(dp[i][len] != -1) return dp[i][len];
            int lim = n - len;
            int ans = 0;
            for(int k = i + 1; k <= lim; k++) {
                int dist = k - i;
                int vals = n - dist + 1;
                int here = self(k, len - 1, self);
                here = ((here % m) * (vals % m)) % m;
                ans = (ans + here) % m;
            }
            return dp[i][len] = ans;
        };
        int ans = 0;
        for(int i = 1; i <= n - 1; i++) {
            int here = f(0, i, f);
            ans = (ans + here) % m;
        }
        cout << ans << '\n';
    }
}