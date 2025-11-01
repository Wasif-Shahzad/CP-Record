//
// 2144C.cpp
// Created by Wasif on 09/16/25 at 21:18:44.
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
    const int mod = 998244353;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n + 1), b(n + 1);
        a[0] = b[0] = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        vector<array<int, 2>> dp(n + 1, {-1, -1});
        auto f = [&] (int i, bool flip, auto&& self) -> int{
            if(i == n + 1) return 1;
            if(dp[i][flip] != -1) return dp[i][flip];
            int ans = 0;
            if(flip) {
                if(b[i - 1] <= a[i] && a[i - 1] <= b[i]) {
                    ans += self(i + 1, false, self);
                }
                if(b[i - 1] <= b[i] && a[i - 1] <= a[i]) {
                    ans = (ans + self(i + 1, true, self)) % mod;
                }
            } else {
                if(a[i - 1] <= a[i] && b[i - 1] <= b[i]) {
                    ans = (ans + self(i + 1, false, self)) % mod;
                }
                if(a[i - 1] <= b[i] && b[i - 1] <= a[i]) {
                    ans = (ans + self(i + 1, true, self)) % mod;
                }
            }
            return dp[i][flip] = ans;
        };
        cout << f(1, 0, f) << '\n';
    }
}