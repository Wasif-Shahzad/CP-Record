//
// f.cpp
// Created by wasifshahzad on 12/16/25 at 08:35:08.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

struct DSU{
    vector<int> par, size;
    int n, cmp;

    DSU(int _n) {
        par.resize(_n);
        iota(par.begin(), par.end(), 0);
        size.resize(_n, 1);
        n = _n;
        cmp = _n;
    }

    int get(int v) {
        if(v == par[v]) return par[v];
        return par[v] = get(par[v]);
    }

    void unite(int a, int b) {
        a = get(a), b = get(b);
        if(a != b) {
            if(size[a] < size[b]) swap(a, b);
            par[b] = a;
            size[a] += size[b];
            cmp--;
        }
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for(int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--;
        edges[i].second--;
    }
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        DSU dsu(n);
        for(int i = 0; i < l; i++) {
            auto [u, v] = edges[i];
            dsu.unite(u, v);
        }
        for(int i = r + 1; i < m; i++) {
            auto [u, v] = edges[i];
            dsu.unite(u, v);
        }
        cout << dsu.cmp << '\n';
    }
}