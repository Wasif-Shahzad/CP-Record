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
    V<int> a(n + 1, -1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    V<V<int>> dp(n + 2, V<int>(n + 2, 1e15));
    rep(i, 1, n + 1) dp[i][i] = 1;
    rep(i, 0, n) {
        rep(j, 0, i) dp[i][j] = 0;
    }
    for(int k = 2; k <= n; k++) {
        for(int l = 1; l + k - 1 <= n; l++) {
            int r = l + k - 1;
            dp[l][r] = min((a[l] != a[r]) + dp[l + 1][r], (a[l] != a[r]) + dp[l][r - 1]);
            for(int x = l + 1; x < r; x++) {
                dp[l][r] = min(dp[l][r], dp[l][x] + dp[x + 1][r] - (a[r] == a[l]));
            }
        }
    }
    out(dp[1][n]);
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