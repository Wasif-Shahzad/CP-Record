//
// 2020D.cpp
// Created by wasifshahzad on 01/04/26 at 12:50:47.
//

#include <bits/stdc++.h>
using namespace std;
// #define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

struct DSU {
    vector<int> p, sz;
    int n, comp;

    DSU(int _n) {
        p.resize(_n);
        iota(p.begin(), p.end(), 0ll);
        sz.assign(_n, 1);
        n = comp = _n;
    }

    int find(int v) {
        if(p[v] == v) return v;
        return p[v] = find(p[v]);
    }

    void merge(int x, int y) {
        x = find(x); y = find(y);
        if(x != y) {
            if(sz[x] < sz[y]) {
                swap(x, y);
            }
            sz[x] += sz[y];
            p[y] = x;
            comp--;
        }
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> vis(11, vector<int>(n + 1, 0));
        vector<vector<int>> mx(11, vector<int>(n + 1, -1));
        DSU dsu(n + 1);
        vector<array<int, 3>> in(m);
        for(int i = 0; i < m; i++) {
            cin >> in[i][0] >> in[i][1] >> in[i][2];
            auto [a, d, k] = in[i];
            mx[d][a] = max(mx[d][a], a + d * k);
        }
        for(int d = 1; d <= 10; d++) {
            for(int i = 1; i <= n; i++) {
                if(mx[d][i] >= i + d) {
                    dsu.merge(i, i + d);
                    mx[d][i + d] = max(mx[d][i + d], mx[d][i]);
                }
            }
        }
        cout << dsu.comp - 1 << '\n';
    }
}