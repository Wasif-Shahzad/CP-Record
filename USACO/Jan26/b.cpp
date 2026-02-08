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

struct eq {
    int c, d;
    eq(int _c = 0, int _d = 0) : c(_c), d(_d) {}
    eq operator-(const eq other) {
        return eq(c - other.c, d - other.d);
    }
    int calc(int x) {
        return c * x + d;
    }
};

void solve(){
    int n, m;
    cin >> n >> m;
    V<int> l(n), r(n);
    in(l); in(r);
    vector<vector<pair<int, int>>> g(n);
    map<pair<int, int>, int> val;
    bool bad = false;
    rep(i, 0, m) {
        int x, y, z;
        cin >> x >> y >> z;
        x--, y--;
        if(x == y && z % 2 == 1) bad = true;
        if(val.count({x, y}) && val[{x, y}] != z) bad = true;
        if(!val.count({x, y})) {
            g[x].pb({y, z});
            g[y].pb({x, z});
            val[{x, y}] = z;
        }
    }    
    if(bad) {
        out(-1);
        return;
    }
    V<int> vis(n, 0), cur, par(n, -1);
    V<eq> e(n);
    rep(i, 0, n) {
        if(!vis[i]) {
            cur.clear();
            e[i].c = 1;
            queue<pair<int, eq>> q;
            q.push({i, e[i]});
            vis[i] = 1;
            cur.pb(i);
            while(!q.empty()) {
                auto [v, E] = q.front();
                q.pop();
                for(auto [c, w]: g[v]) {
                    if(vis[c]) {
                        continue;
                    }
                    eq new_eq = eq(0, w) - E;
                    e[c] = new_eq;
                    vis[c] = 1;
                    q.push({c, new_eq});
                    cur.pb(c);
                }
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}