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

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
vector<vector<int>> g(501, vector<int>(501));
int n;

bool f(int x) {
    vector<vector<int>> vis(n, vector<int>(n, 0));
    auto dfs = [&] (int i, int j, auto&& self) -> int {
        int res = 1;
        vis[i][j] = 1;
        for(int k = 0; k < 4; k++) {
            int ni = i + dx[k], nj = j + dy[k];
            if(ni < 0 || nj < 0 || ni >= n || nj >= n) continue;
            if(vis[ni][nj]) continue;
            if(abs(g[ni][nj] - g[i][j]) > x) continue;
            res += self(ni, nj, self);
        }
        return res;
    };
    int bst = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!vis[i][j]) {
                bst = max(bst, dfs(i, j, dfs));
            }
        }
    }
    return bst >= (n * n + 1) / 2;
}

void solve(){
    cin >> n;
    rep(i, 0, n) {
        rep(j, 0, n) cin >> g[i][j];
    }
    int lo = -1, hi = 1e7;
    while(hi > lo + 1) {
        int mid = (hi + lo) / 2;
        if(f(mid)) hi = mid;
        else lo = mid;
    }
    out(hi);
}

signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    freopen("tractor.in", "r", stdin);
    freopen("tractor.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}