//
// d.cpp
// Created by Wasif on 12/05/25 at 20:40:09.
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
        int n, k;
        cin >> n >> k;

        if(k >= 32) {
            cout << __builtin_popcount(n) + k - 1 << '\n';
            continue;
        }

        vector<vector<array<int, 2>>> dp(33, vector<array<int, 2>>(33, {-1, -1}));
        auto f = [&] (int i, int rem, int carry, auto&& self) -> int {
            if(i == -1) return rem;
            if(rem == 0) return 0;
            if(dp[i][rem][carry] != -1) return dp[i][rem][carry];
            int ans = self(i - 1, rem, false, self);
            int zero = 0;
            for(int j = i; j >= 0; j--) {
                if(!((1 << j) & n)) {
                    if(j == i && !carry) zero++;
                    else if(j < i) zero++;
                }
                if(zero >= rem) break;
                int cost = zero + 1;
                int get = i - j + 1;
                int here = get + self(j - 1, rem - cost, true, self);
                ans = max(ans, here);
            }
            return dp[i][rem][carry] = ans;
        };

        cout << f(30, k, 0, f) << '\n';
    }
}