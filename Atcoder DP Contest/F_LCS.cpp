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

void chkmax(auto& a, auto b) {a = max(a, b);}

void solve(){
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    V<V<int>> dp(n + 1, V<int>(m + 1, 0));
    rev(i, n - 1, -1) {
        rev(j, m - 1, -1) {
            dp[i][j] = dp[i + 1][j];
            chkmax(dp[i][j], dp[i][j + 1]);
            chkmax(dp[i][j], (s[i] == t[j]) + dp[i + 1][j + 1]);
        }
    }
    string ans;
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(s[i] == t[j]) {
            ans += s[i];
            i++, j++;
        } else {
            if(dp[i + 1][j] > dp[i][j + 1]) i++;
            else j++;
        }
    }
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