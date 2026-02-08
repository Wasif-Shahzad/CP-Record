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

template<int M>
struct modint {
 
    static int _pow(int n, int k) {
        int r = 1;
        for (; k > 0; k >>= 1, n = (n*n)%M)
            if (k&1) r = (r*n)%M;
        return r;
    }
 
    int v; modint(int n = 0) : v(n%M) { v += (M&(0-(v<0))); }
    
    friend string to_string(const modint n) { return to_string(n.v); }
    friend istream& operator>>(istream& i, modint& n) { return i >> n.v; }
    friend ostream& operator<<(ostream& o, const modint n) { return o << n.v; }
    template<typename T> explicit operator T() { return T(v); }
 
    friend bool operator==(const modint n, const modint m) { return n.v == m.v; }
    friend bool operator!=(const modint n, const modint m) { return n.v != m.v; }
    friend bool operator<(const modint n, const modint m) { return n.v < m.v; }
    friend bool operator<=(const modint n, const modint m) { return n.v <= m.v; }
    friend bool operator>(const modint n, const modint m) { return n.v > m.v; }
    friend bool operator>=(const modint n, const modint m) { return n.v >= m.v; }
 
    modint& operator+=(const modint n) { v += n.v; v -= (M&(0-(v>=M))); return *this; }
    modint& operator-=(const modint n) { v -= n.v; v += (M&(0-(v<0))); return *this; }
    modint& operator*=(const modint n) { v = (v*n.v)%M; return *this; }
    modint& operator/=(const modint n) { v = (v*_pow(n.v, M-2))%M; return *this; }
    friend modint operator+(const modint n, const modint m) { return modint(n) += m; }
    friend modint operator-(const modint n, const modint m) { return modint(n) -= m; }
    friend modint operator*(const modint n, const modint m) { return modint(n) *= m; }
    friend modint operator/(const modint n, const modint m) { return modint(n) /= m; }
    modint& operator++() { return *this += 1; }
    modint& operator--() { return *this -= 1; }
    modint operator++(signed) { modint t = *this; return *this += 1, t; }
    modint operator--(signed) { modint t = *this; return *this -= 1, t; }
    modint operator+() { return *this; }
    modint operator-() { return modint(0) -= *this; }
 
    // O(logk) modular exponentiation
    modint pow(const int k) const {
        return k < 0 ? _pow(v, M-1-(-k%(M-1))) : _pow(v, k);
    }
    modint inv() const { return _pow(v, M-2); }
}; 
using mint = modint<mod1>; // check mod

void solve(){
    int n, k;
    cin >> n >> k;
    V<V<int>> g(n);
    rep(i, 1, n) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int> clr(n, -1);
    int root = 0;
    rep(i, 0, k) {
        int v, c;
        cin >> v >> c;
        clr[v - 1] = c - 1;
        root = v - 1;
    }
    V<array<mint, 3>> dp(n, {0, 0, 0});
    V<array<int, 3>> vis(n, {0, 0, 0});
    auto dfs = [&] (int v, int c, int p, auto&& self) -> mint {
        if(clr[v] != -1 && clr[v] != c) return 0;
        if(sz(g[v]) == 1 && g[v][0] == p) return 1;
        if(vis[v][c]) return dp[v][c];
        mint ans = 0;
        for(int ch: g[v]) {
            if(ch == p) continue;
            rep(x, 0, 3) {
                if(x == c) continue;
                ans += self(ch, x, v, self);
            }
        }
        return dp[v][c] = ans;
    };
    mint ans = 0;
    if(clr[root] == -1) {
        ans = dfs(root, 0, -1, dfs);
        ans += dfs(root, 1, -1, dfs);
        ans += dfs(root, 2, -1, dfs);
    } else {
        ans = dfs(root, clr[root], -1, dfs);
    }
    out(ans);
}

signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    // freopen("barnpainting.in", "r", stdin);
    // freopen("barnpainting.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}