//
// c.cpp
// Created by Wasif on 10/11/25 at 16:51:27.
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
    vector<pair<int, int>> edges;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges.push_back({u, v});
    }
    int ans = m;
    for(int mask = 0; mask < (1 << n); mask++) {
        int cur = 0;
        for(auto [u, v]: edges) {
            int c1 = ((1 << u) & mask) > 0;
            int c2 = ((1 << v) & mask) > 0;
            if(c1 == c2) {
                cur++;
            }
        }
        ans = min(ans, cur);
    }
    cout << ans;
}