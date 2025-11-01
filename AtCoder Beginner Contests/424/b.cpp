//
// b.cpp
// Created by Wasif on 09/20/25 at 17:01:52.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

bool valid(int a, int b) {
    for(int j = 0; j <= 10; j++) {
        bool x = (1 << j) & a, y = (1 << j) & b;
        if(x && y) {
            x = (1 << (j + 1)) & a, y = (1 << (j + 1)) & b;
            if(x && y) return false;
        }
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n, 0);
        for(int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for(int j = 0; j < m; j++) {
                if(s[j] == '#') a[i] += (1 << j);
            }
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(1 << m, vector<int>(1 << m, -1)));
        auto f = [&] (int i, int prev_mask, int cur_mask, auto&& self) -> int{
            if(i == n) return 0;
            if(dp[i][prev_mask][cur_mask] != -1) return dp[i][prev_mask][cur_mask];
            int ans = 1e9;
            if(!valid(prev_mask, cur_mask)) {
                for(int j = 0; j < m; j++) {
                    if(((1 << j) & prev_mask) && ((1 << j) & cur_mask)) {
                        if(((1 << (j + 1)) & prev_mask) && ((1 << (j + 1)) & cur_mask)) {
                            if(valid(prev_mask, cur_mask ^ (1 << j))) {
                                ans = min(ans, 1 + self(i + 1, cur_mask ^ (1 << j), (i + 1 < n ? a[i + 1] : 0), self));
                            } else {
                                ans = min(ans, 1 + self(i, prev_mask, cur_mask ^ (1 << j), self));
                            }
                            if(valid(prev_mask, cur_mask ^ (1 << (j + 1)))) {
                                ans = min(ans, 1 + self(i + 1, cur_mask ^ (1 << (j + 1)), (i + 1 < n ? a[i + 1] : 0), self));
                            } else {
                                ans = min(ans, 1 + self(i, prev_mask, cur_mask ^ (1 << (j + 1)), self));
                            }
                        }
                    }
                }
            } else {
                ans = min(ans, self(i + 1, cur_mask, (i + 1 < n ? a[i + 1] : 0), self));
            }
            return dp[i][prev_mask][cur_mask] = ans;
        };
        cout << f(1, a[0], a[1], f) << '\n';
    }
}