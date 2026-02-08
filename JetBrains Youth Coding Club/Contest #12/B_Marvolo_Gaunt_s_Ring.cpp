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
    int n, p, q, r;
    cin >> n >> p >> q >> r;
    V<int> a(n);
    in(a);
    V<int> dp1(n + 1, LLONG_MIN), dp2(n + 1, LLONG_MIN), dp3(n + 1, LLONG_MIN);
    rev(i, n - 1, -1) {
        dp1[i] = max(dp1[i + 1], r * a[i]);
        dp2[i] = max(dp2[i + 1], q * a[i] + dp1[i]);
        dp3[i] = max(dp3[i + 1], p * a[i] + dp2[i]);
    }
    out(dp3[0]);
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