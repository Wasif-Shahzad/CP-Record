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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    map<char, vector<int>> ind;
    for(int i = 0; i < n; i++) {
        ind[s[i]].push_back(i);
    }
    while(m--) {
        char a, b;
        cin >> a >> b;
        swap(ind[a], ind[b]);
    }
    vector<char> ans(n);
    for(auto [c, v]: ind) {
        for(int j: v) ans[j] = c;
    }
    for(auto i: ans) cout << i;
    cout << '\n';
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