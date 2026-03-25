#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

int n, a, b, c;
int dp[4005];

int f(int x) {
    if(x == 0) return 0;
    if(x < 0) return -1e10;
    if(dp[x] != -1) return dp[x];
    int ans = 1 + f(x - a);
    ans = max(ans, 1 + f(x - b));
    ans = max(ans, 1 + f(x - c));
    return dp[x] = ans; 
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> a >> b >> c;
    cout << f(n) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}
