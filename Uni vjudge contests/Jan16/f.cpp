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
    string s;
    int j;
    cin >> s >> j;
    int n = s.size();
    vector<int> p(n);
    iota(all(p), 0);
    int rm = j / n;
    rep(i, 0, n) {
        p[i] = ((p[i] - rm) % n + n) % n; 
    }
    j--;
    j %= n;
    rep(i, 0, n) {
        if(p[i] == j) out(s[i]);
    }
}

signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    freopen("cowcode.in", "r", stdin);
    freopen("cowcode.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}