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

void solve(){
    int n, m;
    cin >> n >> m;
    V<V<int>> g(n);
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    V<int> dp(n, 0), lvl(n, 0), par(n, -1), val(n, 0);
    auto build1 = [&] (int v, auto&& self) -> void {
        for(int c: g[v]) {
            if(lvl[c] == 0) {
                par[c] = v;
                lvl[c] = lvl[v] + 1;
                self(c, self);
            } else if(c != par[v] && lvl[c] < lvl[v]) {
                val[v]++;
                val[c]--;
            }
        }
    };
    lvl[0] = 1;
    build1(0, build1);
    auto build2 = [&] (int v, auto&& self) -> void {
        dp[v] = val[v];
        for(int c: g[v]) {
            if(v != par[c]) continue;
            self(c, self);
            dp[v] += dp[c];
        }
    };
    build2(0, build2);
    V<int> bst(n, 0);
    auto f = [&] (int v, auto&& self) -> void {
        for(int c: g[v]) {
            if(v != par[c]) continue;
            self(c, self);
            bst[v] = max(bst[v], bst[c] + (dp[c] == 0));
        }
    };
    f(0, f);
    int ans = 0;
    rep(i, 0, n) {
        int mx = 0, mx2 = 0;
        for(int c: g[i]) {
            if(par[c] != i) continue;
            if(bst[c] + (dp[c] == 0) > mx) {
                mx2 = mx;
                mx = bst[c] + (dp[c] == 0);
            } else if(bst[c] + (dp[c] == 0) > mx2) {
                mx2 = bst[c] + (dp[c] == 0);
            }
        }
        ans = max(ans, mx + mx2);
    }
    cout << ans << '\n';
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