#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define sz(x) x.size()
#define forn(i, s, n) for(int i = s; i < n; i++)
#define pb push_back

struct LCA {
	int N; vector<vi> par, adj; vi depth;
	void init(int _N) {  N = _N;
		int d = 1; while ((1<<d) < N) ++d;
		par.assign(d,vi(N)); adj.resize(N); depth.resize(N);
	}
	void ae(int x, int y) { adj[x].pb(y), adj[y].pb(x); }
	void gen(int R = 0) { par[0][R] = R; dfs(R); }
	void dfs(int x = 0) {
		forn(i,1,sz(par)) par[i][x] = par[i-1][par[i-1][x]];
		for(auto y : adj[x]) if (y != par[0][x])
			depth[y] = depth[par[0][y]=x]+1, dfs(y);
	}
	int jmp(int x, int d) {
		if(depth[x] < d) return -1;
		forn(i,0,sz(par)) if ((d>>i)&1) x = par[i][x];
		return x; }
	int lca(int x, int y) {
		if (depth[x] < depth[y]) swap(x,y);
		x = jmp(x,depth[x]-depth[y]); if (x == y) return x;
		for(int i = (int)sz(par) - 1; i >= 0; i--) {
			int X = par[i][x], Y = par[i][y];
			if (X != Y) x = X, y = Y;
		}
		return par[0][x];
	}
	int dist(int x, int y) { // # edges on path
		return depth[x]+depth[y]-2*depth[lca(x,y)]; }
};

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    LCA lca;
    lca.init(n + 1);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
        lca.ae(u, v);
    }
    if (n % 2 == 0) {
        cout << n + 1 << '\n';
        return;
    }
    lca.gen();
    // check n, n + 1, n + 2
    // we skip n, (n + 1) / 2, 1
    auto check = [&] (int k) -> bool {
        vector<int> depth(n, 0), rm(n, 0), dp(n, 0);
        auto dfs = [&] (int v, int p, auto&& self) -> void {
            for(int c: g[v]) {
                if (c == p) continue;
                depth[c] = depth[v] + 1;
                self(c, v, self);
            }
        };
        dfs(0, -1, dfs);
        for(int i = 1; i <= n; i++) {
            int j = k - i;
            if (j <= i) continue;
            if (j <= 0 || j > n) continue;
            int u = i - 1, v = j - 1;
            int h = lca.lca(u, v);
            dp[u]++, dp[v]++;
            rm[h] += 2;
        }
        bool root = false;
        auto dfs2 = [&] (int v, int p, auto&& self) -> void {
            for(int c: g[v]) {
                if (c == p) continue;
                self(c, v, self);
                dp[v] += dp[c];
            }
            if (v == 0) root = dp[v] > 0;
            dp[v] -= rm[v];
        };
        dfs2(0, -1, dfs2);
        for(int i = 1; i < n; i++) {
            if (dp[i] == 0) return false;
        }
        return root;
    };
    for(int k: {n, n + 1, n + 2}) {
        if (check(k)) {
            cout << k << '\n';
            return;
        }
    }
    cout << n + 2 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
