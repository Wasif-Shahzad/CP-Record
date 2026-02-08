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
    int a, b;
    cin >> a >> b;
    int ans = 0;
    int ta = a, tb = b;
    {
        // a first
        int cur = -1;
        for(int j = 0; ; j++) {
            if(j & 1) {
                if(b >= (1ll << j)) {
                    b -= (1ll << j);
                    cur++;
                } else break;
            } else {
                if(a >= (1ll << j)) {
                    a -= (1ll << j);
                    cur++;
                } else break;
            }
        }
        ans = max(ans, cur + 1);
    }
    {
        a = ta, b = tb;
        int cur = -1;
        for(int j = 0; ; j++) {
            if(j & 1) {
                if(a >= (1ll << j)) {
                    a -= (1ll << j);
                    cur++;
                } else break;
            } else {
                if(b >= (1ll << j)) {
                    b -= (1ll << j);
                    cur++;
                } else break;
            }
        }
        ans = max(ans, cur + 1);   
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