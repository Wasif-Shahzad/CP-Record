//
// d.cpp
// Created by Wasif on 12/06/25 at 13:57:19.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define ar array<int, 3>

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<pair<int, int>> b;
        int v = a[0], idx = 0;
        b.push_back({v, idx});
        for(int i = 1; i < n; i++) {
            if(a[i] > v) {
                b.push_back({a[i], i});
                v = a[i], idx = i;
            }
        }
        if(idx != n - 1) {
            b.push_back({v, n - 1});
        }
        n = b.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(k + 1, 0)));
        dp[0][b[0].first][b[0].first] = b[0].first;
        vector<int> best_prev(k + 1, 0);
        for(int i = 1; i < n; i++) {
            auto [v, l] = b[i];
            for(int m = 0; m <= v; m++) {
                for(int s = m; s <= k; s++) {
                    best_prev[s] = max(best_prev[s], dp[i - 1][s][m]);
                }

                for(int s = m; s <= k; s++) {
                    int skip = (l - b[i - 1].second) * m;
                    dp[i][s][m] = skip + dp[i - 1][s][m];
                    
                }
            }
        }
    }
}