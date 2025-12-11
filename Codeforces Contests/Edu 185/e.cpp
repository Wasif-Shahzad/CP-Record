//
// e.cpp
// Created by Wasif on 11/28/25 at 21:55:33.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int mod = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        vector<int> lim(n + 1, 0);
        for(int i = 0; i < m; i++) {
            int l, r;
            cin >> l >> r;
            lim[r] = max(lim[r], l);
        }

        for(int i = 1; i <= n; i++) {
            lim[i] = max(lim[i], lim[i - 1]);
        }

        vector<int> pref(n + 1, 0), dp(n + 1, 0);
        dp[0] = pref[0] = 2;
        for(int i = 1; i <= n; i++) {
            dp[i] = pref[i - 1];
            if(lim[i] > 0) {
                dp[i] = ((dp[i] - pref[lim[i] - 1]) % mod + mod) % mod;
            }
            pref[i] = (pref[i - 1] + dp[i]) % mod;
        }

        cout << dp[n] << '\n';
    }    
}