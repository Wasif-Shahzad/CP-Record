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
    int s, k;
    cin >> s >> k;
    V<int> f{1};
    int m = 1;
    while(true) {
        int cur = 0;
        rep(i, 1, k + 1) {
            if(m - i >= 0) cur += f[m - i];
            else break;
        }
        f.pb(cur);
        m++;
        if(cur > s) break;
    }
    V<int> ans;
    auto get = [&] (int x) -> int {
        for(int i = m - 1; i >= 0; i--) {
            if(f[i] <= x) return f[i];
        }
        return 0;
    };
    while(s > 0) {
        int cur = get(s);
        ans.pb(cur);
        s -= cur;
    }
    if(sz(ans) == 1) ans.pb(0);
    out(sz(ans));
    outv(ans);
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