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
    int n, k;
    cin >> n >> k;
    V<int> a(n); in(a);
    V<int> dp(n + 1, 1e10);
    dp[n] = dp[n - 1] = 0;
    rev(i, n - 2, -1) {
        rep(j, 1, k + 1) {
            if(i + j < n) {
                dp[i] = min(dp[i], abs(a[i] - a[i + j]) + dp[i + j]);
            }
        }
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