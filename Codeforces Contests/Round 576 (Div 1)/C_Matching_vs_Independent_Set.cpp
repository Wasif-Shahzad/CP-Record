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
#define vi vector<int>
const int mod1 = 1e9+7, mod2 = 998244353;

bool find(int j, vector<vi>& g, vi& btoa, vi& vis) {
    if (btoa[j] == -1) return 1;
    vis[j] = 1; int di = btoa[j];
    for (int e : g[di])
        if (!vis[e] && find(e, g, btoa, vis)) {
            btoa[e] = di;
            return 1;
        }
    return 0;
}

int dfsMatching(vector<vi>& g, vi& btoa) {
    vi vis;
    rep(i,0,sz(g)) {
        vis.assign(sz(btoa), 0);
        for (int j : g[i])
            if (find(j, g, btoa, vis)) {
                btoa[j] = i;
                break;
            }
    }
    return sz(btoa) - (int)count(all(btoa), -1);
}

void solve(){
    int n, m;
    cin >> n >> m;
    V<V<int>> g(3 * n);
    map<pair<int, int>, int> ind;
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        ind[{u, v}] = ind[{v, u}] = i;
        g[u].pb(v);
        g[v].pb(u);
    }
    V<int> edge(3 * n, -1);
    int matching = dfsMatching(g, edge);
    V<int> seen(m, 0);
    V<int> match;
    rep(i, 0, 3 * n) {
        if(edge[i] == -1) continue;
        if(seen[ind[{i, edge[i]}]]) continue;
        seen[ind[{i, edge[i]}]] = 1;
        match.pb(ind[{i, edge[i]}]);
    }
    if(sz(match) >= n) {
        cout << "Matching\n";
        for(int i = 0; i < n; i++) cout << match[i] + 1 << " ";
        cout << '\n';
        return;
    }
    vi vis(3 * n, 0), vis2(3 * n, 0);
    vi ind_set;
    rep(i, 0, 3 * n) {
        if(sz(g[i]) == 0) {
            ind_set.pb(i);
            vis[i] = 1;
        }
    }
    vi clr(3 * n, -1);
    auto is_bipartite = [&] (int i) -> bool {
        clr[i] = 1;
        queue<int> q;
        q.push(i);
        vis2[i] = 1;
        while(q.size()) {
            int v = q.front();
            q.pop();
            for(int c: g[v]) {
                if(clr[c] == -1) {
                    clr[c] = clr[v] ^ 1;
                    q.push(c);
                    vis2[c] = 1;
                    continue;
                } else if(clr[c] != clr[v] ^ 1) {
                    return false;
                }
            }
        }
        return true;
    };
    auto find = [&] (int i) -> vi {
        if(!is_bipartite(i)) return {};
        vi f, s;
        queue<pii> q;
        q.push({i, 1});
        vis[i] = 1;
        while(!q.empty()) {
            auto [v, ccc] = q.front();
            q.pop();
            if(ccc == 1) f.pb(v);
            else s.pb(v);
            for(int c: g[v]) {
                if(vis[c]) continue;
                vis[c] = 1;
                q.push({c, ccc ^ 1});
            }
        }
        if(sz(f) > sz(s)) return f;
        return s;
    };
    rep(i, 0, 3 * n) {
        if(vis[i]) continue;
        vi here = find(i);
        for(int c: here) ind_set.pb(c);
    }
    if(sz(ind_set) >= n) {
        cout << "IndSet\n";
        for(int i = 0; i < n; i++) cout << ind_set[i] + 1 << " ";
        cout << '\n';
        return;
    }
    cout << "Impossible\n";
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