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
#define outv(a) for(auto &asdlfkjas: a) { cout << asdlfkjas << " "; } cout << '\n';
#define in(a) for(auto &i: a) cin >> i;
#define pb push_back
#define pii pair<int, int>
const int mod1 = 1e9+7, mod2 = 998244353;

void solve(){
    int n; 
    cin >> n;
    V<int> a(n); in(a);
    V<int> ans;
    sort(all(a));
    if(a[0] == 0) {
        ans.pb(0);
        a.erase(a.begin());
    }
    a.erase(unique(all(a)), a.end());
    V<V<int>> con(4);
    for(int i: a) {
        string s = to_string(i);
        con[sz(s)].pb(i);
    }
    if(con[1].size()) {
        ans.pb(con[1][0]);
    }
    int j = -1;
    for(int i: con[2]) {
        if(i % 10 == 0) j = i;
    }
    if(j != -1) ans.pb(j);
    if(con[3].size()) ans.pb(100);
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