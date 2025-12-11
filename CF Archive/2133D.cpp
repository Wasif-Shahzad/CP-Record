//
// 2133D.cpp
// Created by Wasif on 12/03/25 at 10:05:15.
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
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<array<int, 3>> dp(n, {-1, -1, -1});
        auto f = [&] (int i, int j, auto&& self) -> int {
            if(i == n) return 0;
            if(dp[i][j] != -1) return dp[i][j];

            int cur = a[i];
            if(j == 1) cur--;
            else if(j == 2) cur -= i;
            int new_next = self(i + 1, 0, self);
            if(cur <= 0) {
                return dp[i][j] = min(self(i + 1, 1, self), new_next);
            }
            int ans = cur;
            if(j == 0) {
                int fall_next = self(i + 1, 2, self);
                ans += min(fall_next, new_next);
                return dp[i][j] = ans;
            }
            int fall_next = self(i + 1, 1, self);
            ans += min(fall_next, new_next);
            return dp[i][j] = ans;
        };
        
        cout << f(0, 0, f) << '\n';
    }
}