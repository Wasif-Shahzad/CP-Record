//
// 1095F.cpp
// Created by wasifshahzad on 05/10/26 at 15:59:03.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

struct DSU {
    vector<int> size, par;

    DSU(int n) {
        size.assign(n, 1);
        par.resize(n);
        iota(all(par), 0);
    }

    int get(int v) {
        if(par[v] == v) return v;
        return par[v] = get(par[v]);
    }

    void merge(int a, int b) {
        a = get(a), b = get(b);
        if(a != b) {
            if(size[b] > size[a]) swap(a, b);
            size[a] += size[b];
            par[b] = a;
        }
    }
};

void solve() {
    vector<array<int, 3>> e;
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i][0];
        a[i][1] = i;
    }
    sort(all(a));
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e.push_back({w, u - 1, v - 1});
    }
    for(int i = 1; i < n; i++) {
        e.push_back({a[i][0] + a[0][0], a[0][1], a[i][1]});
    }
    sort(all(e));
    DSU dsu(n);
    int ans = 0;
    for(auto [w, u, v]: e) {
        if(dsu.get(u) != dsu.get(v)) {
            ans += w;
            dsu.merge(u, v);
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}