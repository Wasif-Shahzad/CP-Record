//
// 1624G.cpp
// Created by wasifshahzad on 04/24/26 at 11:12:21.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

struct DSU{
    vector<int> par, sz;
    int n, cmp;

    DSU(int _n) : n(_n), cmp(_n) {
        par.resize(n);
        sz.assign(n, 1);
        iota(all(par), 0);
    }

    int get(int v) {
        if(par[v] != v) return par[v] = get(par[v]);
        return v;
    }

    void merge(int a, int b) {
        a = get(a), b = get(b);
        if(a != b) {
            if(sz[a] < sz[b]) {
                swap(a, b);
            }
            par[b] = a;
            sz[a] += sz[b];
            cmp--; 
        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> e1(m), e2;
    for(int i = 0; i < m; i++) {
        cin >> e1[i][0] >> e1[i][1] >> e1[i][2];
        e1[i][0]--, e1[i][1]--;
    }
    int ans = 0;
    for(int i = 30; i >= 0; i--) {
        DSU dsu(n);
        e2.clear();
        for(auto [u, v, w]: e1) {
            if(w & (1ll << i)) {
                continue;
            }
            dsu.merge(u, v);
            e2.push_back({u, v, w});
        }
        if(dsu.cmp == 1) {
            swap(e1, e2);
        } else {
            ans += (1ll << i);
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}