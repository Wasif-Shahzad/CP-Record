#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int)a.size()
#define V vector
#define ff first
#define ss second
#define rep(i, a, n) for (int i = a; i < n; i++)
#define rev(i, a, n) for(int i = a; i > n; i--)
#define out(a) cout << a << "\n"
#define outv(a) rep(i, 0, (int)a.size()) cout << a[i] << " "; cout << endl;
#define in(a) for(auto &i: a) cin >> i;
#define pb push_back
#define pii pair<int, int>
const int mod1 = 1e9+7, mod2 = 998244353;

void chkmax(auto& a, auto b) { a = max(a, b); }

void solve(){
    int n, m;
    cin >> n >> m;
    V<V<int>> g(n);
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        g[u - 1].pb(v - 1);
    }
    V<int> order, vis(n, 0);
    auto dfs = [&] (int v, auto&& self) -> void {
        vis[v] = 1;
        for(int c: g[v]) {
            if(vis[c]) continue;
            self(c, self);
        }
        order.pb(v);
    };
    rep(i, 0, n) {
        if(!vis[i]) {
            dfs(i, dfs);
        }
    }
    reverse(all(order));
    V<int> dp(n, 0);
    rev(i, n - 1, -1) {
        for(int c: g[order[i]]) {
            chkmax(dp[order[i]], 1 + dp[c]);
        }
    }
    out(*max_element(all(dp)));
}

signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}