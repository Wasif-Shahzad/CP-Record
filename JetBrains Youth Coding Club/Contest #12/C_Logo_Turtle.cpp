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
    cin >> s;
    int m; cin >> m;
    int n = s.size();
    map<array<int, 5>, int> dp;
    // implement if we have odd ops on i
    auto f = [&] (int loc, int i, int rem, int dir, int flag, auto&& self) -> int {
        if(i == n) return (rem > 0 ? 0 : abs(loc));
        if(dp.count({loc, i, rem, dir, flag})) return dp[{loc, i, rem, dir, flag}];
        char other = (s[i] == 'T' ? 'F' : 'T');
        int ans = 0;
        int here = s[i];
        if(flag) here = other;
        if(flag) other = s[i];
        if(here == 'F') {
            ans = self(loc + dir, i + 1, rem, dir, 0, self);
        } else {
            ans = self(loc, i + 1, rem, (dir == 1 ? -1 : 1), 0, self);
        }
        if(rem > 0) {
            if(other == 'F') {
                ans = max(ans, self(loc + dir, i + 1, rem - 1, dir, 0, self));
                ans = max(ans, self(loc, i, rem - 1, dir, !flag, self));
            } else {
                ans = max(ans, self(loc, i + 1, rem - 1, (dir == 1 ? -1 : 1), 0, self));
                ans = max(ans, self(loc, i, rem - 1, dir, !flag, self));
            }
        }
        return dp[{loc, i, rem, dir, flag}] = ans;
    };
    cout << f(0, 0, m, 1, 0, f) << '\n';
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