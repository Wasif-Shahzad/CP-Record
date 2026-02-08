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
    cin >> m >> n;
    V<V<int>> a(n, V<int>(m));
    rep(i, 0, n) in(a[i]);
    V<int> cnt(m, 0);
    rep(i, 0, n) {
        rep(j, 0, m) {
            if(a[i][j] == 1) cnt[j]++;
        }
    }
    int ans = 1;
    rep(i, 0, m) {
        if(cnt[i] == 0) continue;
        ans *= cnt[i];
    }
    out(ans);
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