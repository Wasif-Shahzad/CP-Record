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
    V<array<int, 3>> a(n);
    rep(i, 0, n) cin >> a[i][0] >> a[i][1] >> a[i][2];
    V<array<int, 3>> dp(n);
    dp[n - 1] = a[n - 1];
    rev(i, n - 2, -1) {
        rep(j, 0, 3) {
            dp[i][j] = 0;
            rep(k, 0, 3) {
                if(j == k) continue;
                dp[i][j] = max(dp[i][j], a[i][j] + dp[i + 1][k]);
            }
        }
    }
    out(max({dp[0][0], dp[0][1], dp[0][2]}));
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