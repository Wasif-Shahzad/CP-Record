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
const long double eps = 1e-6;

void solve(){
    int n;
    cin >> n;
    V<double> a(n); in(a);
    V<V<long double>> dp(n + 1, V<long double> (n + 1, -1));
    auto f = [&] (int heads, int tails, auto&& self) -> long double {
        if(heads + tails == n) return (heads > tails);
        if(abs(dp[heads][tails] - (-1)) > eps) return dp[heads][tails];
        long double here;
        int i = heads + tails;
        here = (1 - a[i]) * self(heads, tails + 1, self);
        here += a[i] * self(heads + 1, tails, self);
        return dp[heads][tails] = here;
    };
    cout << fixed << setprecision(9) << f(0, 0, f) << '\n';
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