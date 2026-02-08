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
    int n;
    cin >> n;
    V<V<int>> g(n);
    V<int> deg(n, 0);
    rep(i, 0, n + 2) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        deg[u]++, deg[v]++;
        g[u].pb(v);
        g[v].pb(u);
    }
    int joint;
    rep(i, 0, n) {
        if(deg[i] == 4) {
            joint = i;
            break;
        }
    }
    int tail, body, head;
    vector<int> t(n);
    for(int i = 0; i < 4; i++) {
        for(int j = i + 1; j < 4; j++) {
            int x = g[joint][i], y = g[joint][j];
            vector<int> vis(n, 0);
            vis[joint] = 1;
            vector<int> tin(n, -1);
            queue<int> q;
            vis[x] = vis[y] = 1;
            q.push(x);
            q.push(y);
            tin[x] = tin[y] = 1;
            tin[joint] = 0;
            bool deg3 = false;
            while(q.size()) {
                int v = q.front();
                q.pop();
                if(deg[v] == 3) deg3 = true;
                for(int c: g[v]) {
                    if(vis[c]) continue;
                    vis[c] = 1;
                    q.push(c);
                    tin[c] = tin[v] + 1;
                }
            }
            int sm = accumulate(all(vis), 0ll);
            if(sm == n) continue;
            // we are in one of parts
            if(!deg3) tail = sm;
            else {
                body = sm;
                t = tin;
            }
        }
    }
    int x = -1, y = -1;
    rep(i, 0, n) {
        if(deg[i] == 3) {
            if(x == -1) x = i;
            else y = i;
        }
    }
    for(int a: g[x]) {
        if(a == y) continue;
        for(int b: g[y]) {
            if(b == x) continue;
            vector<int> vis(n, 0);
            vis[x] = vis[y] = 1;
            vis[a] = vis[b] = 1;
            queue<int> q;
            q.push(a); q.push(b);
            while(q.size()) {
                int v = q.front();
                q.pop();
                for(int c: g[v]) {
                    if(vis[c]) continue;
                    q.push(c);
                    vis[c] = 1;
                }
            }
            if(vis[joint]) continue;
            int sm = accumulate(vis.begin(), vis.end(), 0ll);
            head = sm;
            break;
        }
    }
    // cout << x << " " << y << '\n';
    cout << head << " " << body - head + 2 << " " << tail << '\n';
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