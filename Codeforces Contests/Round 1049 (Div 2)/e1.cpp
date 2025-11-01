//
// e1.cpp
// Created by Wasif on 09/09/25 at 21:22:41.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int rm(int x, int i) {
    int num = 0, num2 = 0;
    for(int j = i - 1; j >= 0; j--) {
        if((1ll << j) & x) num += (1ll << j);
    }
    for(int j = i + 1; j <= 20; j++) {
        if((1 << j) & x) num2 += (1 << j);
    }
    num2 >>= 1;
    num += num2;
    return num;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        int k;
        cin >> k;
        vector<int> good(n, 0);
        for(int i = 0; i < k; i++) {
            int j;
            cin >> j;
            good[j - 1] = 1;
        }
        vector<vector<int>> dp(1 << n, vector<int>(2, -1));
        dp[0][0] = dp[0][1] = 1;
        auto f = [&] (int mask, bool turn, auto&& self) -> int{
            if(dp[mask][turn] != -1) return dp[mask][turn];
            int len = __lg(mask) + 1;
            int here = 1;
            for(int i = 0; i < len; i++) {
                if(good[i]) {
                    int new_mask = rm(mask, i);
                    if(self(new_mask, !turn, self) == 2) {
                        
                    }
                }
            }
        };
    }
}