#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> dp(n, 1), par(n, -1);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto fill_par = [&] (int v, int p, auto&& self) -> void {
        par[v] = p;
        for(int c: g[v]) {
            if (c == p) continue;
            self(c, v, self);
            dp[v] += dp[c];
        }
    };
    fill_par(0, -1, fill_par);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if (g[i].size() >= 3) {
            sort(g[i].begin(), g[i].end(), [&dp] (int x, int y) {
                return dp[x] > dp[y];
            });
            ans = max(ans, dp[g[i][2]]);
        }
    }
    ans = n - ans;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
