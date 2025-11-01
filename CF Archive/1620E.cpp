//
// 1620E.cpp
// Created by wasifshahzad on 9/6/25 at 12:20:46.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct DSU {
    vector<int> par, label, sz;

    DSU(int n) {
        sz.resize(n + 1, 1);
        par.resize(n + 1);
        iota(par.begin(), par.end(), 0);
        label.resize(n + 1, -1);
    }

    int find(int v) {
        if (v == par[v]) return v;
        return par[v] = find(v);
    }

    void unite(int a, int b, int req) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (sz[a] < sz[b]) swap(a, b);
            sz[a] += sz[b];
            par[b] = a;
            
        }
    }

    void add(int i, int v) {
        par[i] = v;
        sz[v]++;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    DSU dsu(q + 1);
    
}