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
    int n, d, h;
    cin >> n >> d >> h;
    if(d > 2 * h) {
        out(-1);
        return;
    }
    int lst = 1;
    set<int> rem;
    for(int i = 2; i <= n; i++) rem.insert(i);
    vector<pair<int, int>> edges;
    for(int i = 1; i <= h; i++) {
        int j = *rem.begin();
        rem.erase(*rem.begin());
        edges.push_back({lst, j});
        lst = j;
    }
    lst = 1;
    for(int i = 1; i <= d - h; i++) {
        int j = *rem.begin();
        rem.erase(*rem.begin());
        edges.push_back({lst, j});
        lst = j;
    }
    if(d - h == 0 && h == 1 && (int)rem.size() > 0) {
        out(-1);
        return;
    }
    for(auto [u, v]: edges) cout << u << " " << v << '\n';
    for(int i: rem) {
        cout << (d - h > 0 ? 1 : 2) << " " << i << '\n';
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