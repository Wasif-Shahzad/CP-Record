//
// e.cpp
// Created by wasifshahzad on 8/27/25 at 07:50:40.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct DSU{
    vector<int> par, sz, val;
    DSU(const int n) {
        par.resize(n);
        sz.assign(n, 1);
        val.assign(n, 0);
        iota(par.begin(), par.end(), 0);
    }

    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        par[b] = a;
        val[a] += val[b];
    }

    void add(int v, int x) {
        val[find(v)] += x;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> cur(n + 1, 0);
    DSU dsu(n + 1);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, v;
            cin >> u >> v;
            dsu.unite(u, v);
        } else if (t == 2) {
            int v;
            cin >> v;
            if (cur[v]) dsu.add(v, -1);
            else dsu.add(v, 1);
            cur[v] ^= 1;
        } else {
            int v;
            cin >> v;
            int p = dsu.find(v);
            if (dsu.val[p] > 0) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}