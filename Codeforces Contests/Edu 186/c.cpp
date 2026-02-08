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
const int mod1 = 1e9, mod2 = 998244353;

void solve(){
    int n;
    cin >> n;
    V<int> a(n), b(n), c(n);
    in(a); in(b); in(c);
    V<int> val(n, 0);
    rep(i, 0, n) {
        bool bad = false;
        rep(j, 0, n) {
            if(b[j] >= c[j]) {
                bad = true;
                break;
            }
        }
        if(!bad) {
            rep(j, 0, n) val[j]++;
        }
        rotate(c.begin(), c.begin() + 1, c.end());
    }
    int ans = 0;
    V<int> order(n);
    iota(order.begin(), order.end(), 0);
    rep(i, 0, n) {
        bool bad = false;
        rep(j, 0, n) {
            if(a[j] >= b[order[j]]) {
                bad = true;
                break;
            }
        }
        if(!bad) {
            ans += val[order[0]] * n;
        }
        rotate(order.begin(), order.begin() + 1, order.end());
    }
    out(ans);
}

signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}