//
// 190E.cpp
// Created by Wasif on 11/29/25 at 12:44:05.
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
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> unvis(n);
    iota(unvis.begin(), unvis.end(), 0);
    vector<int> blocked(n, -1);

    vector<vector<int>> comps;

    while(!unvis.empty()) {
        int source = unvis.back();
        unvis.pop_back();
        queue<int> q;
        q.push(source);
        vector<int> comp;
        while(q.size()) {
            int v = q.front();
            q.pop();
            comp.push_back(v);
            for(int c: g[v]) {
                blocked[c] = v;
            }
            vector<int> next;
            for(int c: unvis) {
                if(blocked[c] == v) {
                    next.push_back(c);
                } else {
                    q.push(c);
                }
            }
            unvis.swap(next);
        }
        comps.push_back(comp);
    }

    cout << comps.size() << '\n';
    for(auto comp: comps) {
        cout << comp.size() << " ";
        for(int v: comp) cout << v + 1 << " ";
        cout << '\n';
    }
}