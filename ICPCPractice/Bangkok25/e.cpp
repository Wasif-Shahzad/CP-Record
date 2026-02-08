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

const int INF = (int)1e18;
void solve(){
    int n, m, q;
    cin >> n >> m >> q;
    map<int, vector<array<int, 3>>> has;
    rep(i, 0, m) {
        int u, v, p, w;
        cin >> u >> v >> p >> w;
        has[p].pb({u - 1, v - 1, w});
    }   
    vector<vector<array<int, 2>>> sq(n);
    vector<array<int, 2>> H; 
    vector<int> type(q);
    rep(i, 0, q) {
        int t;
        cin >> t;
        type[i] = t;
        if(t == 1) {
            int u, h;
            cin >> u >> h;
            sq[u - 1].push_back({h, i});
        } else {
            int h; cin >> h;
            H.push_back({h, i});
        }
    }
    sort(all(H));
    for(int i = 0; i < n; i++) {
        sort(all(sq[i]));
    }
    vector<vector<int>> dist(n, vector<int>(n, INF));
    vector<array<int, 2>> ans(q, {-1, -1});
    for(int i = 0; i < n; i++) dist[i][i] = 0;
    for(auto [p, E]: has) {
        for(auto [u, v, w]: E) {
            if(w < dist[u][v]) {
                dist[u][v] = w;
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < n; j++) {
                        if (dist[i][u] != INF and dist[v][j] != INF) 
                            dist[i][j] = min(dist[i][j], dist[i][u] + dist[v][j] + dist[u][v]);
                    }
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if(!sq[i].size()) continue;
            int mn = 0;
            for(int j = 0; j < n; j++) {
                mn = max(mn, dist[i][j]);
            }
            while(sq[i].size() && mn <= sq[i].back()[0]) {
                auto [h, j] = sq[i].back();
                ans[j] = {p, p};
                sq[i].pop_back();
            }
        }
        vector<int> bst(n, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                bst[i] = max(bst[i], dist[i][j]);
            }
        }
        while(H.size()) {
            auto [h, j] = H.back();
            int res = -1;
            for(int i = 0; i < n; i++) {
                if(bst[i] <= h) {
                    res = i;
                    break;
                }
            }
            if(res != -1) {
                ans[j] = {res + 1, p};
                H.pop_back();
            }
            else break;
        }
    }
    for(int i = 0; i < q; i++) {
        if(type[i] == 1) cout << ans[i][0] << '\n';
        else cout << ans[i][0] << " " << ans[i][1] << '\n';
    }
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