//
// d.cpp
// Created by Wasif on 10/04/25 at 06:28:00.
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
    vector<int> c(n);
    vector<set<int>> has(1e5 + 1);
    for(int i = 0; i < n; i++) {
        cin >> c[i];
        has[c[i]].insert(i);
    }
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
        has[c[u]].insert(u);
        has[c[v]].insert(v);
    }
    int sz = -1, ans = 0;
    for(int i = 1; i <= 1e5; i++) {
        if(!has[i].size()) continue;
        set<int> cur;
        for(int j: has[i]) {
            for(int v: g[j]) {
                if(c[v] == i) continue;
                cur.insert(c[v]);
            }
        }
        if((int)cur.size() > sz) {
            sz = cur.size();
            ans = i;
        }
    }
    cout << ans << '\n';
}