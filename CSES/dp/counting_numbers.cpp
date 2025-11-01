//
// Created by wasifshahzad on 8/15/25.
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

/*
*/

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    auto cnt = [] (const int x) -> int {
        const string tmp = to_string(x);
        const int LOG = tmp.size();
        vector<vector<array<int, 2>>> dp(LOG + 1, vector<array<int, 2>>(10, {-1, -1}));
        auto f = [&] (const int i, const int prev, const bool tight, auto&& self) -> int {
            if (i == LOG) {
                return 1;
            }
            if (prev != -1 && dp[i][prev][tight] != -1)
                return dp[i][prev][tight];
            const int lmt = (tight ? tmp[i] - '0' : 9);
            int ans = 0;
            for (int j = 0; j <= lmt; j++) {
                if (prev == j) continue;
                bool new_tight = (tight && j == lmt);
                ans += self(i + 1, (prev == -1 && j == 0 ? -1 : j), new_tight, self);
            }
            if (prev != -1)
                dp[i][prev][tight] = ans;
            return ans;
        };
        return f(0, -1, true, f);
    };
    int ans = cnt(b);
    if (a >= 1)
            ans -= cnt(a - 1);
    cout << ans << '\n';
}