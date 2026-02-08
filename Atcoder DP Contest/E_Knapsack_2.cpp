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
    int n, w;
    cin >> n >> w;
    V<pii> a(n);
    rep(i, 0, n) cin >> a[i].ff >> a[i].ss;
    int m = 1e5 + 1;
    V<int> dp(m, 1e15);
    dp[0] = 0;
    rep(i, 0, n) {
        rev(j, m - 1, 0) {
            if(j - a[i].ss >= 0) {
                dp[j] = min(dp[j], a[i].ff + dp[j - a[i].ss]);
            }
        }
    }
    int ans = 0;
    rep(i, 1, m) {
        if(dp[i] <= w) ans = i;
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