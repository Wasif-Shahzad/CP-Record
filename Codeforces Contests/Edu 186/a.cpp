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
    string s;
    cin >> s;
    rep(i, 0, n - 3) {
        string t = s.substr(i, 4);
        if(t == "2026") {
            out(0);
            return;
        }
    }
    rep(i, 0, n - 3) {
        string t = s.substr(i, 4);
        if(t == "2025") {
            out(1);
            return;
        }
    }
    out(0);
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