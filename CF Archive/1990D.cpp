//
// 1990D.cpp
// Created by wasifshahzad on 01/05/26 at 11:59:04.
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
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> mask(n + 1, 15);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] <= 4) {
                mask[i] = (1 << a[i]) - 1;
            }
        }
        vector<vector<int>> dp(n, vector<int>(16, -1));
        auto f = [&] (int i, int cur, auto&& self) -> int {
            if(i == n) return 0;
            if(dp[i][cur] != -1) return dp[i][cur];
            int ans = (cur > 0 || a[i] > 4) + self(i + 1, mask[i + 1], self);
            if(cur & 1) {
                // first two have to be set
                int nmask = 0;
                if(mask[i + 1] & 4) nmask |= 4;
                if(mask[i + 1] & 8) nmask |= 8;
                ans = min(ans, 1 + (cur > 3 || a[i] > 4) + self(i + 1, nmask, self));
                if(nmask > 0) ans = min(ans, 2 + (a[i] > 4) + self(i + 1, 0, self));
            } else if(cur > 0) {
                // last two are only set 
                int nmask = mask[i + 1];
                if(nmask & 4) nmask ^= 4;
                if(nmask & 8) nmask ^= 8;
                ans = min(ans, 1 + (a[i] > 4) + self(i + 1, nmask, self));
            }
            return dp[i][cur] = ans;
        };
        cout << f(0, mask[0], f) << '\n';
    }
}