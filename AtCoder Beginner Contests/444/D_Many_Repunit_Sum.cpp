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
    V<int> pref(2e5 + 1, 0);
    rep(i, 0, n) {
        int x = a[i];
        pref[x]--;
        pref[0]++;
    }
    rep(i, 1, 2e5 + 1) {
        pref[i] += pref[i - 1];
    }
    string ans;
    int cur = 0;
    rep(i, 0, 2e5+1) {
        cur += pref[i];
        if(cur != 0) {
            ans += to_string(cur % 10);
            cur /= 10;
        }
    }
    while(cur > 0) {
        ans += to_string(cur % 10);
        cur /= 10;
    }
    reverse(all(ans));
    out(ans);
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