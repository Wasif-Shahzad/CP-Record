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
    V<string> g(n); in(g);
    V<V<int>> dp(n + 1, V<int>(n + 1, 1e9));
    V<V<int>> cnt(n, V<int>(n, 0)), suff(n, V<int>(n + 1, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cnt[i][j] = (g[i][j] == '#');
            if(j > 0) cnt[i][j] += cnt[i][j - 1];
        }
        for(int j = n - 1; j >= 0; j--) {
            suff[i][j] = (g[i][j] == '.');
            if(j + 1 < n) suff[i][j] += suff[i][j + 1];
        }
    }
    dp[0][n] = cnt[0][n - 1];
    for(int i = n - 1; i >= 0; i--) {
        int here = (i > 0 ? cnt[0][i - 1] : 0) + suff[0][i];
        dp[0][i] = here;
        if(i + 1 < n) dp[0][i] = min(dp[0][i], dp[0][i + 1]);
    }
    for(int i = 1; i < n; i++) {
        for(int j = n - 1; j >= 0; j--) {
            dp[i - 1][j] = min(dp[i - 1][j], dp[i - 1][j + 1]);
        }
        for(int j = 0; j <= n; j++) {
            int here = (j > 0 ? cnt[i][j - 1] : 0) + suff[i][j];
            dp[i][j] = here + dp[i - 1][j];
        }
    }
    cout << *min_element(all(dp[n - 1])) << '\n';
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