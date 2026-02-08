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
    rep(i, 0, n) {
        cin >> a[i].ff >> a[i].ss;
    }
    V<int> dp(w + 1, 0);
    dp[0] = 0;
    rep(i, 0, n) {
        rev(j, w, 0) {
            if(j - a[i].ff >= 0) {
                dp[j] = max(dp[j], dp[j - a[i].ff] + a[i].ss);
            }
        }
    }
    out(*max_element(all(dp)));
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