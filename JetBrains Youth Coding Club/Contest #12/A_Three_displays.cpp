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
    V<int> s(n), c(n);
    in(s); in(c);
    V<int> dp1(n), dp2(n);
    rev(i, n - 1, -1) {
        dp1[i] = dp2[i] = 1e15;
        rep(j, i + 1, n) {
            if(s[j] > s[i]) {
                dp1[i] = min(dp1[i], c[i] + c[j]);
                dp2[i] = min(dp2[i], c[i] + dp1[j]); 
            }
        }
    }
    out((*min_element(all(dp2)) == (int)1e15 ? -1 : *min_element(all(dp2))));
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