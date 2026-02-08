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
    int n, m, k;
    cin >> n >> m >> k;
    V<string> a(n), b(n);
    in(a);
    V<V<int>> g(n);
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        g[v - 1].pb(u - 1);
    }
    rep(i, 1, k) {
        rep(j, 0, n) {
            if(sz(g[j]) == 0) b[j] = a[j];
            else {
                b[j] = a[j];
                for(int x: g[j]) {
                    for(int y = 0; y < b[j].size(); y++) {
                        if(b[j][y] == a[x][y]) b[j][y] = '0';
                        else b[j][y] = '1';
                    }
                }
            }
        }
        swap(a, b);
    }
    for(auto ii: a) cout << ii << " ";
    cout << '\n';
}

signed main(){
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}