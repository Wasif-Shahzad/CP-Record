#include <bits/stdc++.h>
using namespace std;
#define int long long

struct DSU {
    int n;
    vector<int> par, sz;

    DSU(int _n) : n(_n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        sz.assign(n, 1);
    }

    int get(int v) {
        if (par[v] == v) return v;
        return par[v] = get(par[v]);
    }

    void merge(int u, int v) {
        int pu = get(u), pv = get(v);
        if (pu == pv) return;
        if (sz[pu] < sz[pv]) swap(pu, pv);
        par[pv] = pu;
        sz[pu] += sz[pv];
    }

    int get_size(int v) {
        int p = get(v);
        return sz[p];
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    DSU dsu(n);
    sort(a.rbegin(), a.rend());
    int sum = 0;
    vector<int> added(n, 0);
    for(auto [val, u]: a) {
        int our = 1;
        set<int> s;
        for(int j: g[u]) {
            if (added[j]) {
                s.insert(dsu.get(j));
            }
        }
        for(int j: s) {
            int here = dsu.get_size(j);
            sum += our * here * val;
            dsu.merge(u, j);
            our = dsu.get_size(u);
        }
        added[u] = 1;
    }
    int den = n * (n - 1);
    long double ans = 2.0L * sum / den;
    cout << fixed << setprecision(4) << ans << '\n';
}
