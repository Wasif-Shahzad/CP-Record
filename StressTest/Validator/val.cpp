#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

bool check(int k, int n, vector<vector<int>>& adj) {
    vector<bool> covered(n, false);

    auto dfs = [&](auto&& self, int u, int p, int target) -> bool {
        if (u == target) {
            covered[u] = true;
            return true;
        }

        for (int v : adj[u]) {
            if (v == p) continue;

            if (self(self, v, u, target)) {
                covered[u] = true;
                return true;
            }
        }
        return false;
    };

    for (int i = 1; i <= n; i++) {
        int j = k - i;

        if (j <= i) break;
        if (j > n) continue;

        dfs(dfs, i - 1, -1, j - 1);
    }

    for (int i = 0; i < n; i++) {
        if (!covered[i]) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);

    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}
