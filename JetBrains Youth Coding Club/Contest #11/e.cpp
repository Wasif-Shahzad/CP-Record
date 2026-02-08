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
    int k;
    int n;
    cin >> s >> k >> n;
    vector<vector<int>> c(26, vector<int>(26, 0));
    rep(i, 0, n) {
        char x, y;
        cin >> x >> y;
        cin >> c[x - 'a'][y - 'a'];
    }
    int m = (int)s.size();
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(k + 1, vector<int>(27, -1)));
    // dp[i][ops remaining][last character]
    auto f = [&] (int i, int rem, int lst, auto&& self) -> int {
        if(i == m) return 0;
        if(dp[i][rem][lst] != -1) return dp[i][rem][lst];
        int sc = (i > 0 ? c[lst][s[i] - 'a'] : 0) + self(i + 1, rem, s[i] - 'a', self);
        if(rem > 0) {
            for(int j = 0; j < 26; j++) {
                if(j == s[i] - 'a') continue;
                int cur = (i > 0 ? c[lst][j] : 0) + self(i + 1, rem - 1, j, self);
                sc = max(sc, cur);
            }
        }
        return dp[i][rem][lst] = sc;
    };
    cout << f(0, k, 26, f) << '\n';
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