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
    V<int> a(n); in(a);
    V<int> dp(n + 1, 1e10);
    dp[n] = dp[n - 1] = 0;
    dp[n - 2] = abs(a[n - 1] - a[n - 2]);
    rev(i, n - 3, -1) {
        dp[i] = min(abs(a[i] - a[i + 1]) + dp[i + 1], abs(a[i] - a[i + 2]) + dp[i + 2]);
    }
    out(dp[0]);
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