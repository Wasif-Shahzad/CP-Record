#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        long double d; cin >> d;
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    // dp[i][j] => we're at ith index and jth element is the last picked element
    auto f = [&] (int i, int j, auto&& self) -> int {
        if(i == n + 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(a[i] >= a[j]) {
            // pick the ith element
            ans = 1 + self(i + 1, i, self);
        }
        // skip the ith element
        ans = max(ans, self(i + 1, j, self));
        return dp[i][j] = ans;
    };
    cout << n - f(1, 0, f) << '\n';
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
