//
// 1242B.cpp
// Created by Wasif on 11/29/25 at 12:21:59.
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
    vector<set<int>> g(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].insert(v);
        g[v].insert(u);
    }

    int cnt = 0;
    vector<int> unvis(n);
    iota(unvis.begin(), unvis.end(), 0);
    vector<int> comps;
    
    while(unvis.size()) {
        int s = unvis.back();
        unvis.pop_back();

        cnt++;
        queue<int> q;
        q.push(s);
        int sz = 0;

        while(!q.empty()) {
            int v = q.front();
            q.pop();
            sz++;

            vector<int> next;
            for(int c: unvis) {
                if(g[v].count(c)) {
                    next.push_back(c);
                } else {
                    q.push(c);
                }
            }
            unvis.swap(next);
        }

        comps.push_back(sz);
    }

    sort(comps.begin(), comps.end());
    cout << cnt << '\n';
    for(int i: comps) cout << i << " ";
    cout << '\n';
}