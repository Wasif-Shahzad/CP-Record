#include <bits/stdc++.h>
using namespace std;
// #define int long long int
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

#define ll long long
const ll INF = 1e15;

V<V<pii>> adj;
void dijkstra(int s, vector<ll> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> u(n, false);

    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        if (d[v] == INF)
            break;

        u[v] = true;
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}

void solve(){
    int n, m, k;
    cin >> n >> m;
    adj.resize(n);
    rep(i, 0, m) {
        int u, v, x;
        cin >> u >> v >> x;
        u--, v--;
        adj[u].pb({v, x});
        adj[v].pb({u, x});
    }
    cin >> k;
    V<int> has(n, -1);
    rep(i, 0, k) {
        int v, x;
        cin >> v >> x;
        has[v - 1] = x;
    }
    int d;
    cin >> d;
    d--;
    vector<ll> dist(n, 1e15);
    vector<int> p(n, -1);
    dijkstra(d, dist, p);
    ll ans = 1e15;
    rep(i, 0, n) {
        if(has[i] >= 0) {
            ans = min(ans, dist[i] + has[i]);
        }
    }
    out(ans);
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