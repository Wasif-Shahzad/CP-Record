//
// main.cpp
// Created by Wasif on 09/19/25 at 21:25:26.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<pair<int, int>>> g(n + 1);
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            g[i].push_back({j, j - i - 1 + a[j] - a[i]});
        }
    }
    vector<int> ans(n + 1, 1e15);
    ans[1] = 0;
    queue<array<int, 2>> q;
    q.push({1, 0});
    while(q.size()) {
        auto [v, d] = q.front();
        q.pop();
        for(auto [c, w]: g[v]) {
            if(d + w < ans[c]) {
                q.push({c, d + w});
                ans[c] = d + w;
            }
        }
    }
    cout << ans[n] << '\n';
}