//
// 1932F.cpp
// Created by Wasif on 10/02/25 at 08:20:56.
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
        int n, m;
        cin >> n >> m;
        vector<int> l(n + 1, 0), r(n + 1, 0);
        vector<vector<int>> end(n + 1), begin(n + 1);
        for(int i = 0; i < m; i++) {
            int L, R;
            cin >> L >> R;
            l[L]++, r[R]++;
            end[R].push_back(L);
            begin[L].push_back(R);
        }
        vector<pair<int, int>> ranges(n + 1, {-1, -1});
        vector<int> has(n + 1, 0);
        multiset<int> s;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < l[i]; j++) {
                s.insert(i);
            }
            has[i] = s.size();
            if(s.size()) 
                ranges[i].first = *s.begin();
            for(int j: end[i]) {
                s.erase(s.find(j));
            }
        }
        s.clear();
        for(int i = n; i > 0; i--) {
            for(int j = 0; j < r[i]; j++) {
                s.insert(i);
            }
            if(s.size()) 
                ranges[i].second = *s.rbegin();
            for(int j: begin[i]) {
                s.erase(s.find(j));
            }
        }
        vector<int> dp(n + 2, 0);
        for(int i = n; i > 0; i--) {
            auto [L, R] = ranges[i];
            dp[i] = dp[i + 1];
            if(R != -1) dp[i] = max(dp[i], dp[R + 1] + has[i]);
        }
        cout << dp[1] << '\n';
    }
}