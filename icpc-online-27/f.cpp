#include <bits/stdc++.h>
using namespace std;
#define int long long

struct DSU {
    int n;
    vector<int> par, sz;

    DSU(int nodes) : n(nodes) {
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

    int getSize(int v) {
        int p = get(v);
        return sz[p];
    }
};

struct Query {
    int target;
    int index;
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> g(n + 1);
    DSU dsu(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        dsu.merge(u, v);
    }
    string result(q, '0');
    vector<vector<Query>> rem(n + 1);
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        if (dsu.get(u) != dsu.get(v)) {
            result[i] = '0';
        } else if (dsu.getSize(u) <= 6777) {
            result[i] = '1';
        } else {
            rem[u].push_back({v, i});
        }
    }
    vector<int> sources;
    for (int s = 1; s <= n; s++) {
        if (!rem[s].empty()) {
            sources.push_back(s);
        }
    }
    vector<int> vis(n + 1, 0);
    vector<int> curr;
    vector<int> nxt;
    vector<bool> inQueue(n + 1, false);
    for (int i = 0; i < sources.size(); i += 64) {
        int chunkSize = min(64ll, (int)sources.size() - i);
        curr.clear();
        for (int j = 0; j < chunkSize; j++) {
            int s = sources[i + j];
            vis[s] |= (1LL << j);
            if (!inQueue[s]) {
                curr.push_back(s);
                inQueue[s] = true;
            }
        }
        for (int d = 0; d < 6776 && !curr.empty(); d++) {
            nxt.clear();
            for (int v : curr) {
                inQueue[v] = false;
                int mask = vis[v];
                for (int c : g[v]) {
                    int newBits = mask & ~vis[c];
                    if (newBits) {
                        vis[c] |= newBits;
                        if (!inQueue[c]) {
                            nxt.push_back(c);
                            inQueue[c] = true;
                        }
                    }
                }
            }
            curr = nxt;
        }
        for (int j = 0; j < chunkSize; j++) {
            int s = sources[i + j];
            for (auto& query : rem[s]) {
                if (vis[query.target] & (1LL << j)) {
                    result[query.index] = '1';
                }
            }
        }
        fill(vis.begin(), vis.end(), 0);
        fill(inQueue.begin(), inQueue.end(), false);
    }
    cout << result << "\n";
}
