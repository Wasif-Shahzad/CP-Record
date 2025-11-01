//
// 1288D.cpp
// Created by Wasif on 09/20/25 at 16:04:41.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    auto f = [&] (int x, bool print=false) -> bool{
        vector<array<int, 2>> dp(1 << m, {-1, -1});
        vector<int> rm(n, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(a[i][j] < x) rm[i] += (1 << j);
            }
        }
        auto pick = [&] (int i, int mask) -> int{
            return (mask & rm[i]);
        };
        vector<int> indices;
        auto go = [&] (int c, int mask, auto&& self) -> int{
            if(mask == 0 && c == 2) return 1;
            if(c == 2) return 0;
            if(dp[mask][c] != -1) return dp[mask][c];
            int ans = 0;
            for(int i = 0; i < n; i++) {
                int tmp = pick(i, mask);
                if(tmp == 0) indices.push_back(i);
                ans |= self(c + 1, tmp, self);
                if(ans == 1 && c == 0) indices.push_back(i);
                if(ans == 1) break;
            }
            return dp[mask][c] = ans;
        };
        int ans = go(0, (1 << m) - 1, go);
        if(print) {
            cout << indices[0] + 1 << " " << indices[1] + 1 << '\n';
        }
        return ans;
    };
    int lo = -1, hi = 1e9 + 5;
    while(hi > lo + 1) {
        int mid = (hi + lo) / 2;
        if(f(mid)) lo = mid;
        else hi = mid;
    }
    f(lo, true);
}